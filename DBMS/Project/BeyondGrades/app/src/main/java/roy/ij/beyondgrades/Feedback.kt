package roy.ij.beyondgrades

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.Spinner
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase


class Feedback : AppCompatActivity() {

    private lateinit var festNameinFeedback: TextView
    private lateinit var festyearInFeedback: TextView
    private lateinit var feedbackRecyclerView: RecyclerView
    private lateinit var feedbackAdapter: FeedbackAdapter
    private lateinit var feedbackList: MutableList<FeedbackDataClass>
    private lateinit var database: FirebaseDatabase
    private lateinit var usersRef: DatabaseReference
    private lateinit var festsRef: DatabaseReference

    private val roleLevels = mapOf(
        "OC" to 1,           // Top level
        "Core" to 2,         // Second level
        "Coordinator" to 3,  // Third level
        "Volunteer" to 4     // Bottom level
    )

    private val skillComparisons = mapOf(
        "Leadership Skills" to "all",
        "Work Ethics" to "all",
        "Resilience" to "all",
        "Communication Skills" to "all",
        "Critical Thinking Skills" to "all",
        "Time Management Skills" to "all"
    )

    /*
    private val skillComparisons = mapOf(
        "Leadership Skills" to "below",
        "Work Ethics" to "same_and_above",
        "Resilience" to "above_and_below",
        "Communication Skills" to "same",
        "Critical Thinking Skills" to "below",
        "Time Management Skills" to "below_and_same"
    )
    */
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_feedback)

        // Initialize views
        festNameinFeedback = findViewById(R.id.festNameinFeedback)
        festyearInFeedback = findViewById(R.id.festyearInFeedback)
        feedbackRecyclerView = findViewById(R.id.feedbackRecyclerViewEvents)

        // Initialize Firebase
        database = FirebaseDatabase.getInstance()
        festsRef = database.reference.child("fests")
        usersRef = database.reference.child("users")

        // Get festID from intent
        val festID = intent.getStringExtra("festID").orEmpty()

        if (festID.isEmpty()) {
            showToast("Invalid fest ID")
            finish()
            return
        }

        fetchFestDetails(festID)

        val sortSpinner: Spinner = findViewById(R.id.sortSpinner)

// Array of sorting options
        val sortingOptions = arrayOf("Sort by Skill Name", "Sort by User Name","Sort by User Role")

        val adapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, sortingOptions)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        sortSpinner.adapter = adapter

// Set up the listener to detect selection changes
        sortSpinner.onItemSelectedListener = object : AdapterView.OnItemSelectedListener {
            override fun onItemSelected(parentView: AdapterView<*>, view: View?, position: Int, id: Long) {
                when (position) {
                    0 -> feedbackAdapter.sortBySkill()
                    1 -> feedbackAdapter.sortByName()
                    2 -> feedbackAdapter.sortByPost()
                }
            }

            override fun onNothingSelected(parentView: AdapterView<*>) {
                feedbackAdapter.sortBySkill()
            }
        }


        // Initialize RecyclerView
        feedbackList = mutableListOf()
        feedbackAdapter = FeedbackAdapter(feedbackList, this)
        feedbackRecyclerView.layoutManager = LinearLayoutManager(this)
        feedbackRecyclerView.adapter = feedbackAdapter
    }

    // Show toast for user feedback
    private fun showToast(message: String) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show()
    }

    private fun getUserLevel(userId: String, festId: String, festMap: Map<String, Any>): Int {
        val organizingTeam = festMap["organizingTeam"] as? Map<String, String>
        val userRole = organizingTeam?.get(userId)
        return roleLevels[userRole] ?: Int.MAX_VALUE
    }

    private fun compareSkillLevel(userLevel: Int, targetLevel: Int, skill: String): Boolean {
        return when (skillComparisons[skill]) {
            "below" -> userLevel < targetLevel
            "same" -> userLevel == targetLevel
            "above" -> userLevel > targetLevel
            "same_and_above" -> userLevel >= targetLevel
            "below_and_same" -> userLevel <= targetLevel
            "above_and_below" -> userLevel != targetLevel
            "all" -> true
            else -> false
        }
    }

    private fun fetchFestDetails(festID: String) {
        val festRef = festsRef.child(festID)

        festRef.get().addOnSuccessListener { snapshot ->
            val festName = snapshot.child("festName").getValue(String::class.java).orEmpty()
            val festYear = snapshot.child("festYear").getValue(Int::class.java)?.toString().orEmpty()

            festNameinFeedback.text = festName
            festyearInFeedback.text = festYear

            // Fetch participants only after fest details are loaded
            val organizingTeamRef = festRef.child("organizingTeam")
            fetchParticipants(organizingTeamRef, festID, snapshot)
        }.addOnFailureListener {
            showToast("Failed to load fest details")
            Log.e("FetchFestDetails", "Error loading fest details", it)
        }
    }

    private fun fetchParticipants(organizingTeamRef: DatabaseReference, festID: String, festSnapshot: DataSnapshot) {
        organizingTeamRef.get().addOnSuccessListener { snapshot ->
            val participantIds = snapshot.value as? Map<String, String> ?: emptyMap()
            fetchUserDetails(participantIds, festID, festSnapshot)
        }.addOnFailureListener {
            showToast("Failed to load participants")
            Log.e("FetchParticipants", "Error loading participants", it)
        }
    }

    private fun fetchUserDetails(participantIds: Map<String, String>, festID: String, festSnapshot: DataSnapshot) {
        val loggedInUserID = FirebaseAuth.getInstance().currentUser?.uid.orEmpty()

        participantIds.forEach { (userId, post) ->
            if (userId != loggedInUserID) {
                usersRef.child(userId).get().addOnSuccessListener { userSnapshot ->
                    val user = userSnapshot.getValue(User::class.java)
                    user?.let {
                        ensureSkillsNodeExistsForUser(userId, festID, festSnapshot, user)
                    }
                }.addOnFailureListener {
                    Log.e("FetchUser", "Error fetching user details for ID: $userId", it)
                }
            }
        }
    }

    private fun ensureSkillsNodeExistsForUser(userId: String, festID: String, festSnapshot: DataSnapshot, user: User) {
        val skillsRef = usersRef.child(userId).child("skills")

        skillsRef.get().addOnSuccessListener { snapshot ->
            if (!snapshot.exists()) {
                createDefaultSkillsNode(userId, festID, festSnapshot, user)
            } else {
                processFeedbackForSkills(userId, user, festID, festSnapshot)
            }
        }.addOnFailureListener {
            Log.e("Feedback", "Failed to check if skills node exists for user $userId", it)
        }
    }

    private fun createDefaultSkillsNode(userId: String, festID: String, festSnapshot: DataSnapshot, user: User) {
        val skillsToAdd = mutableMapOf<String, Any>()
        skillComparisons.keys.forEach { skill ->
            skillsToAdd[skill] = mapOf(
                "rating" to 0.0,
                "feedbacks" to mapOf<String, Any>()
            )
        }

        usersRef.child(userId).child("skills").setValue(skillsToAdd).addOnSuccessListener {
            Log.d("Feedback", "Skills created for user $userId")
            processFeedbackForSkills(userId, user, festID, festSnapshot)
        }.addOnFailureListener {
            Log.e("Feedback", "Failed to create skills for user $userId", it)
        }
    }

    private fun processFeedbackForSkills(userId: String, user: User, festID: String, festSnapshot: DataSnapshot) {
        val skillsSnapshot = user.skills ?: return

        val festMap = festSnapshot.value as? Map<String, Any> ?: emptyMap()
        val loggedInUserID = FirebaseAuth.getInstance().currentUser?.uid.orEmpty()

        val loggedInUserLevel = getUserLevel(loggedInUserID, festID, festMap)

        skillsSnapshot.entries.forEach { skillSnapshot ->
            val skill = skillSnapshot.key ?: return@forEach

            val comparisonResult = compareSkillLevel(
                loggedInUserLevel,
                getUserLevel(userId, festID, festMap),
                skill
            )

            if (comparisonResult) {
                checkExistingFeedback(userId, festID, loggedInUserID, skill, user)
            }
        }
    }

    private fun checkExistingFeedback(userId: String, festID: String, loggedInUserID: String, skill: String, user: User) {
        getUserRoleFromFest(userId, festID) { userRole ->
            if (userRole != null) {
                // Process feedback logic here with the retrieved role
                val feedbackRef = usersRef.child(userId).child("skills").child(skill).child("feedbacks").child(festID).child(loggedInUserID)
                feedbackRef.get().addOnSuccessListener { snapshot ->
                    val feedback = FeedbackDataClass(
                        userName = user.name,
                        userRollNumber = user.rollNumber,
                        userId = userId,
                        userPost = userRole,
                        skillName = skill,
                        festID = festID
                    )
                    feedbackList.add(feedback)
                    feedbackAdapter.notifyDataSetChanged()  // Notify adapter of changes
                }.addOnFailureListener {
                    Log.e("Feedback", "Error checking feedback for $userId on skill $skill", it)
                }
            } else {
                Log.e("Feedback", "User role not found for $userId in fest $festID")
            }
        }
    }


    private fun getUserRoleFromFest(userId: String, festID: String, callback: (String?) -> Unit) {
        // Fetch the fest details using festID (it seems you already have a reference to the fest data)
        val festRef = festsRef.child(festID)

        // Attempt to get the role of the user from the fest's organizing team
        festRef.child("organizingTeam").get().addOnSuccessListener { snapshot ->
            val organizingTeam = snapshot.value as? Map<String, String>
            val userRole = organizingTeam?.get(userId) // Retrieve the role for the given userId

            // Invoke the callback with the user role (or null if not found)
            callback(userRole)
        }.addOnFailureListener {
            // Log an error or handle failure to fetch the role
            Log.e("Feedback", "Failed to get user role from fest $festID for user $userId", it)
            callback(null) // If failed, pass null to the callback
        }
    }

    // Mock user class
    data class User(
        val name: String = "",
        val rollNumber: String = "",
        val skills: Map<String, Map<String, Any>>? = null
    )
}


/*
class Feedback : AppCompatActivity() {

    private lateinit var festNameinFeedback: TextView
    private lateinit var festyearInFeedback: TextView
    private lateinit var feedbackRecyclerView: RecyclerView
    private lateinit var feedbackAdapter: FeedbackAdapter
    private lateinit var feedbackList: MutableList<FeedbackDataClass>
    private lateinit var database: FirebaseDatabase
    private lateinit var usersRef: DatabaseReference
    private lateinit var festsRef: DatabaseReference

    // Maps for role levels and skill comparisons
    private val roleLevels = mapOf(
        "OC" to 1,           // Top level
        "Core" to 2,         // Second level
        "Coordinator" to 3,  // Third level
        "Volunteer" to 4     // Bottom level
    )

    private val skillComparisons = mapOf(
        "Leadership Skills" to "below",
        "Work Ethics" to "same_and_above",
        "Resilience" to "above_and_below",
        "Communication Skills" to "same",
        "Critical Thinking Skills" to "below",
        "Time Management Skills" to "below_and_same"
    )

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_feedback)

        // Initialize views
        festNameinFeedback = findViewById(R.id.festNameinFeedback)
        festyearInFeedback = findViewById(R.id.festyearInFeedback)
        feedbackRecyclerView = findViewById(R.id.feedbackRecyclerViewEvents)

        // Initialize Firebase
        database = FirebaseDatabase.getInstance()
        festsRef = database.reference.child("fests")
        usersRef = database.reference.child("users")

        // Get festID from intent
        val festID = intent.getStringExtra("festID").orEmpty()

        if (festID.isEmpty()) {
            Toast.makeText(this, "Invalid fest ID", Toast.LENGTH_SHORT).show()
            finish()
            return
        }

        fetchFestDetails(festID)

        // Initialize RecyclerView
        feedbackList = mutableListOf()
        feedbackAdapter = FeedbackAdapter(feedbackList, this)
        feedbackRecyclerView.layoutManager = LinearLayoutManager(this)
        feedbackRecyclerView.adapter = feedbackAdapter
    }

    // Function to get the user level based on the role
    private fun getUserLevel(userId: String, festId: String, festMap: Map<String, Any>): Int {
        // Get the organizing team map from the fest details
        val organizingTeam = festMap["organizingTeam"] as? Map<String, String>

        // Get the user's role from the organizing team map
        val userRole = organizingTeam?.get(userId)

        // Return the corresponding level for the user's role, or Int.MAX_VALUE if not found
        return roleLevels[userRole] ?: Int.MAX_VALUE
    }





    // Function to compare skill level between user and others
    private fun compareSkillLevel(userLevel: Int, targetLevel: Int, skill: String): Boolean {
        return when (skillComparisons[skill]) {
            "below" -> userLevel < targetLevel // Corrected this condition
            "same" -> userLevel == targetLevel
            "above" -> userLevel > targetLevel // Corrected this condition
            "same_and_above" -> userLevel >= targetLevel // Corrected this condition
            "below_and_same" -> userLevel <= targetLevel // Corrected this condition
            "above_and_below" -> userLevel != targetLevel
            "all" -> true
            else -> false
        }
    }


    private fun fetchFestDetails(festID: String) {
        val festRef = festsRef.child(festID)

        festRef.get().addOnSuccessListener { snapshot ->
            val festName = snapshot.child("festName").getValue(String::class.java).orEmpty()
            val festYear = snapshot.child("festYear").getValue(Int::class.java)?.toString().orEmpty()

            festNameinFeedback.text = festName
            festyearInFeedback.text = festYear

            // Fetch participants only after fest details are loaded
            val organizingTeamRef = festRef.child("organizingTeam")
            fetchParticipants(organizingTeamRef, festID, snapshot)
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to load fest details", Toast.LENGTH_SHORT).show()
            Log.e("FetchFestDetails", "Error loading fest details", it)
        }
    }

    private fun fetchParticipants(organizingTeamRef: DatabaseReference, festID: String, festSnapshot: DataSnapshot) {
        organizingTeamRef.get().addOnSuccessListener { snapshot ->
            val participantIds = snapshot.value as? Map<String, String> ?: emptyMap()
            fetchUserDetails(participantIds, festID, festSnapshot)
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to load participants", Toast.LENGTH_SHORT).show()
            Log.e("FetchParticipants", "Error loading participants", it)
        }
    }

    private fun fetchUserDetails(participantIds: Map<String, String>, festID: String, festSnapshot: DataSnapshot) {
        val loggedInUserID = FirebaseAuth.getInstance().currentUser?.uid.orEmpty()

        participantIds.forEach { (userId, post) ->
            if (userId != loggedInUserID) {
                // Only fetch details of non-logged-in users
                usersRef.child(userId).get().addOnSuccessListener { userSnapshot ->
                    val user = userSnapshot.getValue(User::class.java)
                    user?.let {
                        // Ensure skills node exists before processing feedback
                        ensureSkillsNodeExistsForUser(userId, festID, festSnapshot, user)
                    }
                }.addOnFailureListener {
                    Log.e("FetchUser", "Error fetching user details for ID: $userId", it)
                }
            }
        }
    }

    // Function to ensure skills node exists before processing feedback
    private fun ensureSkillsNodeExistsForUser(userId: String, festID: String, festSnapshot: DataSnapshot, user: User) {
        val skillsRef = usersRef.child(userId).child("skills")

        skillsRef.get().addOnSuccessListener { snapshot ->
            if (!snapshot.exists()) {
                // Skills node doesn't exist, create it with default values
                createDefaultSkillsNode(userId, festID, festSnapshot, user)
            } else {
                // Skills node exists, proceed to process feedback
                processFeedbackForSkills(userId, user, festID, festSnapshot)
            }
        }.addOnFailureListener {
            Log.e("Feedback", "Failed to check if skills node exists for user $userId", it)
        }
    }

    // Function to create a default skills node
    private fun createDefaultSkillsNode(userId: String, festID: String, festSnapshot: DataSnapshot, user: User) {
        val skillsToAdd = mutableMapOf<String, Any>()
        skillComparisons.keys.forEach { skill ->
            skillsToAdd[skill] = mapOf(
                "rating" to 0.0,  // Default rating
                "feedbacks" to mapOf<String, Any>()  // Empty feedbacks initially
            )
        }

        // Store the newly created skills in Firebase
        usersRef.child(userId).child("skills").setValue(skillsToAdd).addOnSuccessListener {
            Log.d("Feedback", "Skills created for user $userId")
            processFeedbackForSkills(userId, user, festID, festSnapshot)
        }.addOnFailureListener {
            Log.e("Feedback", "Failed to create skills for user $userId", it)
        }
    }

    // Function to process feedback for the user's skills
    private fun processFeedbackForSkills(userId: String, user: User, festID: String, festSnapshot: DataSnapshot) {
        val skillsSnapshot = user.skills ?: return

        // Fetch the fest map and logged-in user's ID
        val festMap = festSnapshot.value as? Map<String, Any> ?: emptyMap()
        val loggedInUserID = FirebaseAuth.getInstance().currentUser?.uid.orEmpty()

        // Get the logged-in user's level for comparison
        val loggedInUserLevel = getUserLevel(loggedInUserID, festID, festMap)

        // Loop through each skill and decide whether to add feedback
        skillsSnapshot.entries.forEach { skillSnapshot ->
            val skill = skillSnapshot.key ?: return@forEach

            // Compare the user's skill level based on the role comparison
            val comparisonResult = compareSkillLevel(loggedInUserLevel, getUserLevel(userId, festID, festMap), skill)
            Log.d("Feedback", "LoggedInUserID: $loggedInUserID, UserRole: ${getUserRoleFromFest(loggedInUserID, festID, festSnapshot)}")
            Log.d("Feedback", "UserID: $userId, UserRole: ${getUserRoleFromFest(userId, festID, festSnapshot)}")
            Log.d("Feedback", "Skill: $skill, UserLevel: $loggedInUserLevel, TargetLevel: ${getUserLevel(userId, festID, festMap)}, ComparisonResult: $comparisonResult")

            Log.d("SkillComparison", "User: $userId, Skill: $skill, ComparisonResult: $comparisonResult")

            // Add feedback only if the skill comparison is valid
            if (comparisonResult) {
                val newFeedback = FeedbackDataClass(
                    userName = user.name ?: "Unknown",
                    userRollNumber = user.rollNumber ?: "Unknown",
                    userId = userId,
                    userPost = getUserRoleFromFest(userId, festID, festSnapshot) ?: "Unknown",
                    skillName = skill,
                    festID = festID
                )

                // Add feedback to the list if it's valid
                feedbackList.add(newFeedback)
                feedbackAdapter.notifyItemInserted(feedbackList.size - 1)  // Notify RecyclerView that a new item is added
            } else {
                Log.d("SkillComparison", "Feedback not added for User: $userId, Skill: $skill due to failed comparison")
            }
        }
    }

    // Function to get the user role from the fest's organizing team
    private fun getUserRoleFromFest(userId: String, festID: String, festSnapshot: DataSnapshot): String? {
        val festMap = festSnapshot.value as? Map<String, Any>
        val organizingTeam = festMap?.get("organizingTeam") as? Map<String, String>

        // Fetch the user's role from the organizing team map
        return organizingTeam?.get(userId)
    }

}
*/

/*
class Feedback : AppCompatActivity() {

    private lateinit var festNameinFeedback: TextView
    private lateinit var festyearInFeedback: TextView
    private lateinit var feedbackRecyclerView: RecyclerView
    private lateinit var feedbackAdapter: FeedbackAdapter
    private lateinit var feedbackList: MutableList<FeedbackDataClass>
    private lateinit var database: FirebaseDatabase
    private lateinit var usersRef: DatabaseReference
    private lateinit var festsRef: DatabaseReference

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_feedback)

        // Initialize views
        festNameinFeedback = findViewById(R.id.festNameinFeedback)
        festyearInFeedback = findViewById(R.id.festyearInFeedback)
        feedbackRecyclerView = findViewById(R.id.feedbackRecyclerViewEvents)

        // Initialize Firebase
        database = FirebaseDatabase.getInstance()
        festsRef = database.reference.child("fests")
        usersRef = database.reference.child("users")

        val festID = intent.getStringExtra("festID").orEmpty()
        val userID = intent.getStringExtra("userID").orEmpty()

        if (festID.isEmpty() || userID.isEmpty()) {
            Toast.makeText(this, "Invalid fest or user ID", Toast.LENGTH_SHORT).show()
            finish()
            return
        }

        fetchFestDetails(festID)

        // Initialize RecyclerView
        feedbackList = mutableListOf()
        feedbackAdapter = FeedbackAdapter(feedbackList, this)
        feedbackRecyclerView.layoutManager = LinearLayoutManager(this)
        feedbackRecyclerView.adapter = feedbackAdapter
    }

    private fun fetchFestDetails(festID: String) {
        val festRef = festsRef.child(festID)

        festRef.get().addOnSuccessListener { snapshot ->
            val festName = snapshot.child("festName").getValue(String::class.java).orEmpty()
            val festYear = snapshot.child("festYear").getValue(Int::class.java)?.toString().orEmpty()

            festNameinFeedback.text = festName
            festyearInFeedback.text = festYear

            val organizingTeamRef = festRef.child("organizingTeam")
            fetchParticipants(organizingTeamRef, festID)
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to load fest details", Toast.LENGTH_SHORT).show()
            Log.e("FetchFestDetails", "Error loading fest details", it)
        }
    }

    private fun fetchParticipants(organizingTeamRef: DatabaseReference, festID: String) {
        organizingTeamRef.get().addOnSuccessListener { snapshot ->
            val participantIds = snapshot.value as? Map<String, String> ?: emptyMap()
            fetchUserDetails(participantIds, festID)
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to load participants", Toast.LENGTH_SHORT).show()
            Log.e("FetchParticipants", "Error loading participants", it)
        }
    }

    private fun fetchUserDetails(participantIds: Map<String, String>, festID: String) {
        val loggedInUserID = intent.getStringExtra("userID").orEmpty()

        participantIds.forEach { (userId, post) ->
            if (userId != loggedInUserID) {
                usersRef.child(userId).get().addOnSuccessListener { userSnapshot ->
                    val user = userSnapshot.getValue(roy.ij.beyondgrades.User::class.java)
                    user?.let {
                        val skillsSnapshot = userSnapshot.child("skills")
                        for (skillSnapshot in skillsSnapshot.children) {
                            val skill = skillSnapshot.key ?: continue
                            val newFeedback = FeedbackDataClass(
                                userName = user.name ?: "Unknown",
                                userRollNumber = user.rollNumber ?: "Unknown",
                                userId = userId,
                                userPost = post,
                                skillName = skill,  // Dynamic skill name
                                festID = festID
                            )
                            feedbackList.add(newFeedback)
                            feedbackAdapter.notifyItemInserted(feedbackList.size - 1)
                        }
                    }
                }.addOnFailureListener {
                    Log.e("FetchUser", "Error fetching user details for ID: $userId", it)
                }
            }
        }
    }

    private fun storeFeedback(userId: String, feedbackText: String, ratingValue: Double, skill: String, festID: String) {
        val loggedInUserID = intent.getStringExtra("userID").orEmpty()

        val feedbackRef = usersRef.child(userId)
            .child("skills").child(skill)
            .child("feedbacks").child(festID)
            .child(loggedInUserID)

        val feedbackData = mapOf(
            "comments" to feedbackText,
            "rating" to ratingValue
        )

        feedbackRef.setValue(feedbackData).addOnSuccessListener {
            Toast.makeText(this, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
            Log.e("StoreFeedback", "Error storing feedback", it)
        }
    }

    fun onSubmitFeedback(userId: String, feedbackText: String, ratingValue: Double, skill: String, festID: String) {
        storeFeedback(userId, feedbackText, ratingValue, skill, festID)
    }
}
*/


/*
class Feedback : AppCompatActivity() {

    private lateinit var festNameinFeedback: TextView
    private lateinit var festyearInFeedback: TextView
    private lateinit var feedbackRecyclerView: RecyclerView
    private lateinit var feedbackAdapter: FeedbackAdapter
    private lateinit var feedbackList: MutableList<FeedbackDataClass>
    private lateinit var database: FirebaseDatabase
    private lateinit var usersRef: DatabaseReference
    private lateinit var festsRef: DatabaseReference

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_feedback)

        // Initialize views
        festNameinFeedback = findViewById(R.id.festNameinFeedback)
        festyearInFeedback = findViewById(R.id.festyearInFeedback)
        feedbackRecyclerView = findViewById(R.id.feedbackRecyclerViewEvents)

        // Initialize Firebase
        database = FirebaseDatabase.getInstance()
        festsRef = database.reference.child("fests")
        usersRef = database.reference.child("users")

        val festID = intent.getStringExtra("festID").orEmpty()
        val userID = intent.getStringExtra("userID").orEmpty()

        if (festID.isEmpty() || userID.isEmpty()) {
            Toast.makeText(this, "Invalid fest or user ID", Toast.LENGTH_SHORT).show()
            finish()
            return
        }

        fetchFestDetails(festID)

        // Initialize RecyclerView
        feedbackList = mutableListOf()
        feedbackAdapter = FeedbackAdapter(feedbackList, this)
        feedbackRecyclerView.layoutManager = LinearLayoutManager(this)
        feedbackRecyclerView.adapter = feedbackAdapter
    }

    private fun fetchFestDetails(festID: String) {
        val festRef = festsRef.child(festID)

        festRef.get().addOnSuccessListener { snapshot ->
            val festName = snapshot.child("festName").getValue(String::class.java).orEmpty()
            val festYear = snapshot.child("festYear").getValue(Int::class.java)?.toString().orEmpty()

            festNameinFeedback.text = festName
            festyearInFeedback.text = festYear

            val organizingTeamRef = festRef.child("organizingTeam")
            fetchParticipants(organizingTeamRef, festID)
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to load fest details", Toast.LENGTH_SHORT).show()
        }
    }

    private fun fetchParticipants(organizingTeamRef: DatabaseReference, festID: String) {
        organizingTeamRef.get().addOnSuccessListener { snapshot ->
            val participantIds = snapshot.value as? Map<String, String> ?: emptyMap()
            fetchUserDetails(participantIds, festID)
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to load participants", Toast.LENGTH_SHORT).show()
        }
    }

    private fun fetchUserDetails(participantIds: Map<String, String>, festID: String) {
        val loggedInUserID = intent.getStringExtra("userID").orEmpty()

        participantIds.forEach { (userId, post) ->
            if (userId != loggedInUserID) {
                usersRef.child(userId).get().addOnSuccessListener { userSnapshot ->
                    val user = userSnapshot.getValue(roy.ij.beyondgrades.User::class.java)
                    user?.let {
                        val newFeedback = FeedbackDataClass(
                            userName = user.name ?: "Unknown",
                            userRollNumber = user.rollNumber ?: "Unknown",
                            userId = userId,
                            userPost = post,
                            skillName = "Work Ethics",  // Example skill
                            festID = festID
                        )
                        feedbackList.add(newFeedback)
                        feedbackAdapter.notifyItemInserted(feedbackList.size - 1)
                    }
                }.addOnFailureListener {
                    Log.e("FetchUser", "Error fetching user details for ID: $userId", it)
                }
            }
        }
    }

    private fun storeFeedback(userId: String, feedbackText: String, ratingValue: Double, skill: String) {
        val loggedInUserID = intent.getStringExtra("userID").orEmpty()

        val feedbackRef = usersRef.child(userId).child("skills").child(skill)
            .child("feedbacks").child(loggedInUserID)

        val feedbackData = mapOf(
            "comments" to feedbackText,
            "rating" to ratingValue
        )

        feedbackRef.setValue(feedbackData).addOnSuccessListener {
            Toast.makeText(this, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
        }.addOnFailureListener {
            Toast.makeText(this, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
        }
    }

    fun onSubmitFeedback(userId: String, feedbackText: String, ratingValue: Double, skill: String) {
        storeFeedback(userId, feedbackText, ratingValue, skill)
    }
}
*/

/*
class Feedback : AppCompatActivity() {
    private lateinit var festNameinFeedback: TextView
    private lateinit var festyearInFeedback: TextView
    private lateinit var feedbackRecyclerView: RecyclerView
    private lateinit var feedbackAdapter: FeedbackAdapter
    private lateinit var feedbackList: MutableList<FeedbackDataClass>
    private lateinit var database: FirebaseDatabase
    private lateinit var usersRef: DatabaseReference
    private lateinit var festsRef: DatabaseReference

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_feedback)

        // Initialize views
        festNameinFeedback = findViewById(R.id.festNameinFeedback)
        festyearInFeedback = findViewById(R.id.festyearInFeedback)
        feedbackRecyclerView = findViewById(R.id.feedbackRecyclerViewEvents)

        // Initialize Firebase
        database = FirebaseDatabase.getInstance()
        festsRef = database.reference.child("fests")
        usersRef = database.reference.child("users")

        // Get fest details from the intent
        val festName = intent.getStringExtra("festName") ?: ""
        val festYear = intent.getStringExtra("festYear") ?: ""

        // Set the fest name and year in the TextViews
        festNameinFeedback.text = festName
        festyearInFeedback.text = festYear

        // Initialize RecyclerView
        feedbackList = mutableListOf()
        feedbackAdapter = FeedbackAdapter(feedbackList)
        feedbackRecyclerView.layoutManager = LinearLayoutManager(this)
        feedbackRecyclerView.adapter = feedbackAdapter

        // Fetch the participants from the "organizingTeam" of the fest
        fetchParticipants(festName)
    }

    private fun fetchParticipants(festName: String) {
        val organizingTeamRef = festsRef.child(festName).child("organizingTeam")

        organizingTeamRef.get().addOnSuccessListener { snapshot ->
            val participantIds = snapshot.value as? Map<String, String> ?: return@addOnSuccessListener
            fetchUserDetails(participantIds.keys.toList())
        }.addOnFailureListener {
            // Handle error
            Toast.makeText(this, "Failed to load participants", Toast.LENGTH_SHORT).show()
        }
    }

    private fun fetchUserDetails(participantIds: List<String>) {
        participantIds.forEach { userId ->
            usersRef.child(userId).get().addOnSuccessListener { userSnapshot ->
                val user = userSnapshot.getValue(roy.ij.beyondgrades.User::class.java)
                if (user != null) {
                    feedbackList.add(FeedbackDataClass(user.name ?: "Unknown", user.rollNumber ?: "Unknown", userId))
                    feedbackAdapter.notifyDataSetChanged()
                }
            }.addOnFailureListener {
                Log.e("FetchUser", "Error fetching user details for ID: $userId", it)
            }
        }
    }

    /*
    private fun fetchUserDetails(participantIds: List<String>) {
        // Fetch user details for each participant
        participantIds.forEach { userId ->
            usersRef.child(userId).get().addOnSuccessListener { userSnapshot ->
                val user = userSnapshot.getValue(User::class.java)
                if (user != null) {
                    // Add user to feedback list and notify adapter
                    feedbackList.add(Feedback(user.name, user.rollNumber, userId))
                    feedbackAdapter.notifyDataSetChanged()
                }
            }
        }
    }
    */
}
*/
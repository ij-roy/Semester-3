package roy.ij.beyondgrades

import android.content.Intent
import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.Menu
import android.view.MenuInflater
import android.view.MenuItem
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.google.android.material.dialog.MaterialAlertDialogBuilder
import com.google.android.material.textfield.TextInputEditText
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase

class ProfileFragment : Fragment() {
    // Variables
    private lateinit var database: DatabaseReference
    private lateinit var eventsRecyclerView: RecyclerView
    private lateinit var eventsAdapter: EventsAdapter
    private val eventsList = mutableListOf<Event>()

    // Add TextViews to show name and roll number
    private lateinit var nameTextProfile: TextView
    private lateinit var rollNumberTextProfile: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setHasOptionsMenu(true) // Enable options menu in this fragment
        // Initialize Firebase Database reference
        database = FirebaseDatabase.getInstance().reference
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val rootView = inflater.inflate(R.layout.fragment_profile, container, false)

        // Initialize RecyclerView and adapter
        eventsRecyclerView = rootView.findViewById(R.id.recyclerViewEvents)
        eventsAdapter = EventsAdapter(eventsList)
        eventsRecyclerView.layoutManager = LinearLayoutManager(requireContext())
        eventsRecyclerView.adapter = eventsAdapter

        // Initialize TextViews for name and roll number
        nameTextProfile = rootView.findViewById(R.id.nameTextProfile)
        rollNumberTextProfile = rootView.findViewById(R.id.rollNumberTextProfile)

        // Set up Toolbar as ActionBar
        val toolbar: Toolbar = rootView.findViewById(R.id.toolbar)
        (activity as AppCompatActivity).setSupportActionBar(toolbar)

        // Fetch user data from Firebase
        getUserData()

        return rootView
    }

    override fun onCreateOptionsMenu(menu: Menu, menuInflater: MenuInflater) {
        super.onCreateOptionsMenu(menu, menuInflater)
        menuInflater.inflate(R.menu.menu_profile_options, menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_edit -> {
                openEditUserInfoDialog()
                true
            }
            R.id.action_sign_out -> {
                signOut()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    private fun getUserData() {
        val user = FirebaseAuth.getInstance().currentUser
        if (user != null) {
            val userId = user.uid
            database.child("users").child(userId).get().addOnSuccessListener {
                if (it.exists()) {
                    val name = it.child("name").value.toString()
                    val rollNumber = it.child("rollNumber").value.toString()

                    // Update UI with user data
                    nameTextProfile.text = name
                    rollNumberTextProfile.text = rollNumber

                    // Fetch events participated in by the user
                    getUserEvents(userId)
                } else {
                    Log.e("ProfileFragment", "User not found!")
                }
            }.addOnFailureListener {
                Log.e("ProfileFragment", "Failed to fetch data", it)
            }
        } else {
            Log.e("ProfileFragment", "User not authenticated")
            // Optionally handle the case where user is not authenticated
        }
    }

    private fun getUserEvents(userId: String) {
        database.child("fests").get().addOnSuccessListener { festSnapshot ->
            if (festSnapshot.exists()) {
                eventsList.clear()
                for (fest in festSnapshot.children) {
                    val festID = fest.key.toString()  // Fetch the fest ID (which is the key in the "fests" node)
                    val festName = fest.child("festName").value.toString()
                    val festYear = fest.child("festYear").value.toString()
                    val organizingTeam = fest.child("organizingTeam")

                    if (organizingTeam.hasChild(userId)) {
                        // Fetch the post (Coordinator, OC, etc.)
                        val festPost = organizingTeam.child(userId).value.toString()

                        // Add the event to the list with festID
                        eventsList.add(Event(festName, festYear, festPost, festID))
                    }
                }
                eventsAdapter.notifyDataSetChanged()
            } else {
                Log.e("ProfileFragment", "No fests found!")
            }
        }.addOnFailureListener {
            Log.e("ProfileFragment", "Failed to fetch events", it)
        }
    }


    private fun openEditUserInfoDialog() {
        val dialogView = LayoutInflater.from(requireContext()).inflate(R.layout.dialog_edit_profile, null)
        val editName = dialogView.findViewById<TextInputEditText>(R.id.editName)
        val editRollNumber = dialogView.findViewById<TextInputEditText>(R.id.editRollNumber)

        MaterialAlertDialogBuilder(requireContext())
            .setTitle("Edit User Info")
            .setView(dialogView)
            .setPositiveButton("Update") { _, _ ->
                val newName = editName.text.toString()
                val newRollNumber = editRollNumber.text.toString()
                updateUserProfile(newName, newRollNumber)
            }
            .setNegativeButton("Cancel", null)
            .show()
    }

    private fun updateUserProfile(name: String, rollNumber: String) {
        val userId = FirebaseAuth.getInstance().currentUser?.uid ?: return
        val updates = mapOf("name" to name, "rollNumber" to rollNumber)

        database.child("users").child(userId).updateChildren(updates).addOnCompleteListener { task ->
            if (task.isSuccessful) {
                Log.d("ProfileFragment", "Profile updated successfully")
            } else {
                Log.e("ProfileFragment", "Failed to update profile", task.exception)
            }
        }
    }

    private fun signOut() {
        FirebaseAuth.getInstance().signOut()
        val intent = Intent(requireContext(), SignIn::class.java)
        startActivity(intent)
        activity?.finish()
    }
}


/*
class ProfileFragment : Fragment() {
    // Variables
    private lateinit var database: DatabaseReference
    private lateinit var eventsRecyclerView: RecyclerView
    private lateinit var eventsAdapter: EventsAdapter
    private val eventsList = mutableListOf<Event>()

    // Add TextViews to show name and roll number
    private lateinit var nameTextProfile: TextView
    private lateinit var rollNumberTextProfile: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setHasOptionsMenu(true) // Enable options menu in this fragment
        // Initialize Firebase Database reference
        database = FirebaseDatabase.getInstance().reference
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val rootView = inflater.inflate(R.layout.fragment_profile, container, false)

        // Initialize RecyclerView and adapter
        eventsRecyclerView = rootView.findViewById(R.id.recyclerViewEvents)
        eventsAdapter = EventsAdapter(eventsList)
        eventsRecyclerView.layoutManager = LinearLayoutManager(requireContext())
        eventsRecyclerView.adapter = eventsAdapter

        // Initialize TextViews for name and roll number
        nameTextProfile = rootView.findViewById(R.id.nameTextProfile)
        rollNumberTextProfile = rootView.findViewById(R.id.rollNumberTextProfile)

        // Set up Toolbar as ActionBar
        val toolbar: Toolbar = rootView.findViewById(R.id.toolbar)
        (activity as AppCompatActivity).setSupportActionBar(toolbar)

        // Fetch user data from Firebase
        getUserData()

        return rootView
    }

    override fun onCreateOptionsMenu(menu: Menu, menuInflater: MenuInflater) {
        super.onCreateOptionsMenu(menu, menuInflater)
        menuInflater.inflate(R.menu.menu_profile_options, menu)
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_edit -> {
                openEditUserInfoDialog()
                true
            }
            R.id.action_sign_out -> {
                signOut()
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    private fun getUserData() {
        val user = FirebaseAuth.getInstance().currentUser
        if (user != null) {
            val userId = user.uid
            database.child("users").child(userId).get().addOnSuccessListener {
                if (it.exists()) {
                    val name = it.child("name").value.toString()
                    val rollNumber = it.child("rollNumber").value.toString()

                    // Update UI with user data
                    nameTextProfile.text = name
                    rollNumberTextProfile.text = rollNumber

                    // Fetch events participated in by the user
                    getUserEvents(userId)
                } else {
                    Log.e("ProfileFragment", "User not found!")
                }
            }.addOnFailureListener {
                Log.e("ProfileFragment", "Failed to fetch data", it)
            }
        } else {
            Log.e("ProfileFragment", "User not authenticated")
        }
    }

    private fun getUserEvents(userId: String) {
        database.child("fests").get().addOnSuccessListener { festSnapshot ->
            if (festSnapshot.exists()) {
                eventsList.clear()
                for (fest in festSnapshot.children) {
                    val festName = fest.child("festName").value.toString()
                    val festYear = fest.child("festYear").value.toString()
                    val organizingTeam = fest.child("organizingTeam")
                    if (organizingTeam.hasChild(userId)) {
                        // Fetch the post (Coordinator, OC, etc.)
                        val festPost = organizingTeam.child(userId).value.toString()

                        // Add the event to the list
                        eventsList.add(Event(festName, festYear, festPost))
                    }

                }
                eventsAdapter.notifyDataSetChanged()
            } else {
                Log.e("ProfileFragment", "No fests found!")
            }
        }.addOnFailureListener {
            Log.e("ProfileFragment", "Failed to fetch events", it)
        }
    }

    private fun openEditUserInfoDialog() {
        val dialogView = LayoutInflater.from(requireContext()).inflate(R.layout.dialog_edit_profile, null)
        val editName = dialogView.findViewById<TextInputEditText>(R.id.editName)
        val editRollNumber = dialogView.findViewById<TextInputEditText>(R.id.editRollNumber)

        MaterialAlertDialogBuilder(requireContext())
            .setTitle("Edit User Info")
            .setView(dialogView)
            .setPositiveButton("Update") { _, _ ->
                val newName = editName.text.toString()
                val newRollNumber = editRollNumber.text.toString()
                updateUserProfile(newName, newRollNumber)
            }
            .setNegativeButton("Cancel", null)
            .show()
    }

    private fun updateUserProfile(name: String, rollNumber: String) {
        val userId = FirebaseAuth.getInstance().currentUser?.uid ?: return
        val updates = mapOf("name" to name, "rollNumber" to rollNumber)

        database.child("users").child(userId).updateChildren(updates).addOnCompleteListener { task ->
            if (task.isSuccessful) {
                Log.d("ProfileFragment", "Profile updated successfully")
            } else {
                Log.e("ProfileFragment", "Failed to update profile", task.exception)
            }
        }
    }

    private fun signOut() {
        FirebaseAuth.getInstance().signOut()
        val intent = Intent(requireContext(), SignIn::class.java)
        startActivity(intent)
        activity?.finish()
    }
}
*/

// Adapter class to display events


/*
// Working till kebab menu
class ProfileFragment : Fragment() {
    // Variables
    private lateinit var database: DatabaseReference
    private lateinit var nameTextView: TextView
    private lateinit var rollNumberTextView: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setHasOptionsMenu(true) // Enable options menu in this fragment
        // Initialize Firebase Database reference
        database = FirebaseDatabase.getInstance().reference
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val rootView = inflater.inflate(R.layout.fragment_profile, container, false)

        // Initialize views
        nameTextView = rootView.findViewById(R.id.nameTextProfile)
        rollNumberTextView = rootView.findViewById(R.id.rollNumberTextProfile)

        // Set up Toolbar as ActionBar
        val toolbar: Toolbar = rootView.findViewById(R.id.toolbar)
        (activity as AppCompatActivity).setSupportActionBar(toolbar)

        // Fetch user data from Firebase
        getUserData()

        return rootView
    }

    // Inflate the menu from your resources (kebab menu)
    override fun onCreateOptionsMenu(menu: Menu, menuInflater: MenuInflater) {
        super.onCreateOptionsMenu(menu, menuInflater)
        menuInflater.inflate(R.menu.menu_profile_options, menu) // Inflate the kebab menu
    }

    // Handle the menu item clicks (Edit Name, Edit Roll Number, Sign Out)
    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return when (item.itemId) {
            R.id.action_edit -> {
                openEditUserInfoDialog()  // Show edit profile dialog when Edit option is selected
                true
            }
            R.id.action_sign_out -> {
                signOut()  // Sign out when Sign Out option is selected
                true
            }
            else -> super.onOptionsItemSelected(item)
        }
    }

    // Fetch user data from Firebase
    private fun getUserData() {
        val user = FirebaseAuth.getInstance().currentUser
        if (user != null) {
            val userId = user.uid  // Use the UID of the currently authenticated user

            // Get reference to the user node in Firebase
            database.child("users").child(userId).get().addOnSuccessListener {
                if (it.exists()) {
                    val name = it.child("name").value.toString()
                    val rollNumber = it.child("rollNumber").value.toString()

                    // Update UI with the fetched data
                    nameTextView.text = name
                    rollNumberTextView.text = rollNumber
                } else {
                    Log.e("ProfileFragment", "User not found!")
                }
            }.addOnFailureListener {
                Log.e("ProfileFragment", "Failed to fetch data", it)
            }
        } else {
            Log.e("ProfileFragment", "User not authenticated")
        }
    }

    // Implementing the edit user info dialog
    private fun openEditUserInfoDialog() {
        // Inflate the dialog layout
        val dialogView = LayoutInflater.from(requireContext()).inflate(R.layout.dialog_edit_profile, null)

        // Initialize the EditText views inside the dialog
        val editName = dialogView.findViewById<TextInputEditText>(R.id.editName)
        val editRollNumber = dialogView.findViewById<TextInputEditText>(R.id.editRollNumber)

        // Pre-fill the fields with current values
        editName.setText(nameTextView.text.toString())
        editRollNumber.setText(rollNumberTextView.text.toString())

        // Create and show the dialog
        MaterialAlertDialogBuilder(requireContext())
            .setTitle("Edit User Info")  // Title of the dialog
            .setView(dialogView)  // Set the custom dialog view
            .setPositiveButton("Update") { _, _ ->
                // Get the new values entered by the user
                val newName = editName.text.toString()
                val newRollNumber = editRollNumber.text.toString()

                // Call the method to update the user's info in Firebase
                updateUserProfile(newName, newRollNumber)
            }
            .setNegativeButton("Cancel", null)
            .show()
    }

    // Update user profile info in Firebase
    private fun updateUserProfile(name: String, rollNumber: String) {
        val userId = FirebaseAuth.getInstance().currentUser?.uid ?: return

        val updates = mapOf(
            "name" to name,
            "rollNumber" to rollNumber
        )

        // Update the Firebase database
        database.child("users").child(userId).updateChildren(updates).addOnCompleteListener { task ->
            if (task.isSuccessful) {
                nameTextView.text = name
                rollNumberTextView.text = rollNumber
                Log.d("ProfileFragment", "Profile updated successfully")
            } else {
                Log.e("ProfileFragment", "Failed to update profile", task.exception)
            }
        }
    }

    // Sign out from Firebase and redirect to LoginActivity
    private fun signOut() {
        // Sign out from Firebase Authentication
        FirebaseAuth.getInstance().signOut()

        // Redirect to the login activity
        val intent = Intent(requireContext(), SignIn::class.java)
        startActivity(intent)

        // Optional: finish the current activity so the user can't go back
        activity?.finish()
    }
}
*/

/*
class ProfileFragment : Fragment() {
    // Variables
    private lateinit var database: DatabaseReference
    private lateinit var nameTextView: TextView
    private lateinit var rollNumberTextView: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setHasOptionsMenu(true) // Enable options menu in this fragment
        // Initialize Firebase Database reference
        database = FirebaseDatabase.getInstance().reference
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val rootView = inflater.inflate(R.layout.fragment_profile, container, false)

        // Initialize views
        nameTextView = rootView.findViewById(R.id.nameTextProfile)
        rollNumberTextView = rootView.findViewById(R.id.rollNumberTextProfile)

        // Set up Toolbar as ActionBar
        val toolbar: Toolbar = rootView.findViewById(R.id.toolbar)
        (activity as AppCompatActivity).setSupportActionBar(toolbar)

        // Fetch user data from Firebase
        getUserData()

        // Add menu provider for the kebab menu (3 vertical dots)
        val menuHost: MenuHost = requireActivity()
        menuHost.addMenuProvider(object : MenuProvider {
            override fun onCreateMenu(menu: Menu, menuInflater: MenuInflater) {
                // Inflate the menu (this is where the kebab icon is added)
                menuInflater.inflate(R.menu.kabab_icon_menu, menu)  // Make sure your kebab menu XML exists
            }

            override fun onMenuItemSelected(menuItem: MenuItem): Boolean {
                return when (menuItem.itemId) {
                    R.id.action_edit -> {
                        // When the "Edit" option is selected, show the dialog to edit name and roll number
                        showEditProfileDialog()
                        true
                    }
                    else -> false
                }
            }
        }, viewLifecycleOwner, Lifecycle.State.RESUMED)

        return rootView
    }

    private fun getUserData() {
        val user = FirebaseAuth.getInstance().currentUser
        if (user != null) {
            val userId = user.uid  // Use the UID of the currently authenticated user

            // Get reference to the user node in Firebase
            database.child("users").child(userId).get().addOnSuccessListener {
                if (it.exists()) {
                    val name = it.child("name").value.toString()
                    val rollNumber = it.child("rollNumber").value.toString()

                    // Update UI with the fetched data
                    nameTextView.text = name
                    rollNumberTextView.text = rollNumber
                } else {
                    Log.e("ProfileFragment", "User not found!")
                }
            }.addOnFailureListener {
                Log.e("ProfileFragment", "Failed to fetch data", it)
            }
        } else {
            Log.e("ProfileFragment", "User not authenticated")
        }
    }

    private fun showEditProfileDialog() {
        val dialogView = LayoutInflater.from(requireContext()).inflate(R.layout.dialog_edit_profile, null)
        val editName = dialogView.findViewById<TextView>(R.id.editName)
        val editRollNumber = dialogView.findViewById<TextView>(R.id.editRollNumber)

        editName.text = nameTextView.text.toString()
        editRollNumber.text = rollNumberTextView.text.toString()

        MaterialAlertDialogBuilder(requireContext())
            .setTitle("Edit Profile")
            .setView(dialogView)
            .setPositiveButton("Update") { _, _ ->
                val newName = editName.text.toString()
                val newRollNumber = editRollNumber.text.toString()
                updateUserProfile(newName, newRollNumber)
            }
            .setNegativeButton("Cancel", null)
            .show()
    }

    private fun updateUserProfile(name: String, rollNumber: String) {
        val userId = FirebaseAuth.getInstance().currentUser?.uid ?: return

        val updates = mapOf(
            "name" to name,
            "rollNumber" to rollNumber
        )

        database.child("users").child(userId).updateChildren(updates).addOnCompleteListener { task ->
            if (task.isSuccessful) {
                nameTextView.text = name
                rollNumberTextView.text = rollNumber
                Log.d("ProfileFragment", "Profile updated successfully")
            } else {
                Log.e("ProfileFragment", "Failed to update profile", task.exception)
            }
        }
    }

}
*/


//
//// TODO: Rename parameter arguments, choose names that match
//// the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
//private const val ARG_PARAM1 = "param1"
//private const val ARG_PARAM2 = "param2"
//
///**
// * A simple [Fragment] subclass.
// * Use the [ProfileFragment.newInstance] factory method to
// * create an instance of this fragment.
// */
//
//class ProfileFragment : Fragment() {
//    // TODO: Rename and change types of parameters
//    private var param1: String? = null
//    private var param2: String? = null
//
//    // Firebase Realtime Database reference
//    private lateinit var database: DatabaseReference
//    private lateinit var nameTextView: TextView
//    private lateinit var rollNumberTextView: TextView
//
//    override fun onCreate(savedInstanceState: Bundle?) {
//        super.onCreate(savedInstanceState)
//        arguments?.let {
//            param1 = it.getString(ARG_PARAM1)
//            param2 = it.getString(ARG_PARAM2)
//        }
//        setHasOptionsMenu(true) // Enable options menu in this fragment
//        // Initialize Firebase Database reference
//        database = FirebaseDatabase.getInstance().reference
//    }
//
//    override fun onCreateView(
//        inflater: LayoutInflater, container: ViewGroup?,
//        savedInstanceState: Bundle?
//    ): View? {
//        // Inflate the layout for this fragment
//        val rootView = inflater.inflate(R.layout.fragment_profile, container, false)
//
//        // Initialize views
//        nameTextView = rootView.findViewById(R.id.nameTextProfile)
//        rollNumberTextView = rootView.findViewById(R.id.rollNumberTextProfile)
//
//        // Fetch user data from Firebase
//        getUserData()
//
//        val menuHost: MenuHost = requireActivity()
//        menuHost.addMenuProvider(object : MenuProvider {
//            override fun onCreateMenu(menu: Menu, menuInflater: MenuInflater) {
//                menuInflater.inflate(R.menu.kabab_icon_menu, menu)
//            }
//
//            override fun onMenuItemSelected(menuItem: MenuItem): Boolean {
//                return when (menuItem.itemId) {
//                    R.id.action_edit -> {
//                        showEditProfileDialog()
//                        true
//                    }
//                    else -> false
//                }
//            }
//        }, viewLifecycleOwner, Lifecycle.State.RESUMED)
//
//            return rootView
//    }
//
//    private fun getUserData() {
//        val user = FirebaseAuth.getInstance().currentUser
//        if (user != null) {
//            val userId = user.uid  // Use the UID of the currently authenticated user
//
//            // Get reference to the user node in Firebase
//            database.child("users").child(userId).get().addOnSuccessListener {
//                if (it.exists()) {
//                    val name = it.child("name").value.toString()
//                    val rollNumber = it.child("rollNumber").value.toString()
//
//                    // Update UI with the fetched data
//                    nameTextView.text = name
//                    rollNumberTextView.text = rollNumber
//                } else {
//                    Log.e("ProfileFragment", "User not found!")
//                }
//            }.addOnFailureListener {
//                Log.e("ProfileFragment", "Failed to fetch data", it)
//            }
//        } else {
//            Log.e("ProfileFragment", "User not authenticated")
//        }
//
//    }
//
//    private fun showEditProfileDialog() {
//        val dialogView = LayoutInflater.from(requireContext()).inflate(R.layout.dialog_edit_profile, null)
//        val editName = dialogView.findViewById<TextView>(R.id.editName)
//        val editRollNumber = dialogView.findViewById<TextView>(R.id.editRollNumber)
//
//        editName.text = nameTextView.text.toString()
//        editRollNumber.text = rollNumberTextView.text.toString()
//
//        MaterialAlertDialogBuilder(requireContext())
//            .setTitle("Edit Profile")
//            .setView(dialogView)
//            .setPositiveButton("Update") { _, _ ->
//                val newName = editName.text.toString()
//                val newRollNumber = editRollNumber.text.toString()
//                updateUserProfile(newName, newRollNumber)
//            }
//            .setNegativeButton("Cancel", null)
//            .show()
//    }
//
//    private fun updateUserProfile(name: String, rollNumber: String) {
//        val userId = FirebaseAuth.getInstance().currentUser?.uid ?: return
//
//        val updates = mapOf(
//            "name" to name,
//            "rollNumber" to rollNumber
//        )
//
//        database.child("users").child(userId).updateChildren(updates).addOnCompleteListener { task ->
//            if (task.isSuccessful) {
//                nameTextView.text = name
//                rollNumberTextView.text = rollNumber
//                Log.d("ProfileFragment", "Profile updated successfully")
//            } else {
//                Log.e("ProfileFragment", "Failed to update profile", task.exception)
//            }
//        }
//    }
//
//
//    companion object {
//        /**
//         * Use this factory method to create a new instance of
//         * this fragment using the provided parameters.
//         *
//         * @param param1 Parameter 1.
//         * @param param2 Parameter 2.
//         * @return A new instance of fragment ProfileFragment.
//         */
//        // TODO: Rename and change types and number of parameters
//        @JvmStatic
//        fun newInstance(param1: String, param2: String) =
//            ProfileFragment().apply {
//                arguments = Bundle().apply {
//                    putString(ARG_PARAM1, param1)
//                    putString(ARG_PARAM2, param2)
//                }
//            }
//    }
//}
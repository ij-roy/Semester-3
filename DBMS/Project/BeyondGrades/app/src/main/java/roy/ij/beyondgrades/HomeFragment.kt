package roy.ij.beyondgrades

import android.os.Bundle
import android.util.Log
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.firebase.ui.database.FirebaseRecyclerOptions
import com.google.firebase.auth.FirebaseAuth

import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase

// TODO: Rename parameter arguments, choose names that match
// the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
private const val ARG_PARAM1 = "param1"
private const val ARG_PARAM2 = "param2"

/**
 * A simple [Fragment] subclass.
 * Use the [HomeFragment.newInstance] factory method to
 * create an instance of this fragment.
 */



class HomeFragment : Fragment() {

    private var param1: String? = null
    private var param2: String? = null

    private lateinit var database: DatabaseReference
    private lateinit var recyclerView: RecyclerView
    private lateinit var adapter: SkillAdapter
    private lateinit var overallEPA: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        arguments?.let {
            param1 = it.getString(ARG_PARAM1)
            param2 = it.getString(ARG_PARAM2)
        }

        // Initialize Firebase Database reference
        database = FirebaseDatabase.getInstance().reference.child("users")

        val userId = FirebaseAuth.getInstance().currentUser?.uid ?: return

        // Fetch data and calculate average ratings
        database.child(userId).child("skills").get().addOnSuccessListener { snapshot ->
            if (snapshot.exists()) {
                var totalEPA = 0.0
                var totalSkills = 0

                // Iterate through each skill
                for (skill in snapshot.children) {
                    val skillName = skill.key ?: continue
                    val feedbacks = skill.child("feedbacks")
                    var totalRating = 0.0
                    var count = 0

                    // Calculate the total rating for each skill
                    for (fest in feedbacks.children) {
                        for (feedback in fest.children) {
                            val rating = feedback.child("rating").getValue(Double::class.java) ?: 0.0
                            totalRating += rating
                            count++
                        }
                    }

                    // Calculate the average rating for the skill
                    val averageRating = if (count > 0) totalRating / count else 0.0

                    // Update the skill's average rating
                    database.child(userId).child("skills").child(skillName).child("rating").setValue(averageRating)

                    // Add to overall EPA calculation
                    totalEPA += averageRating
                    totalSkills++
                }

                // Calculate and update the overall EPA for the user
                if (totalSkills > 0) {
                    val overallEPAValue = totalEPA / totalSkills
                    database.child(userId).child("epa").setValue(overallEPAValue)

                    // Display the overall EPA in the TextView
                    overallEPA.text = "%.2f".format(overallEPAValue)
                }

                // Load RecyclerView after updating ratings
                loadSkillsIntoRecyclerView(userId)
            }
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_home, container, false)

        // Initialize the RecyclerView and TextView for displaying overall EPA
        recyclerView = view.findViewById(R.id.dashboardRecyclerViewEvents)
        recyclerView.layoutManager = LinearLayoutManager(context)

        overallEPA = view.findViewById(R.id.overallEPA)  // Reference to the TextView that shows overall EPA

        return view
    }

    private fun loadSkillsIntoRecyclerView(userId: String) {
        val query = database.child(userId).child("skills")
        val options = FirebaseRecyclerOptions.Builder<Skill>()
            .setQuery(query, Skill::class.java)
            .build()

        adapter = SkillAdapter(options)
        recyclerView.adapter = adapter
        adapter.startListening()
    }

    override fun onDestroyView() {
        super.onDestroyView()
        if (::adapter.isInitialized) adapter.stopListening()
    }

    companion object {
        const val ARG_PARAM1 = "param1"
        const val ARG_PARAM2 = "param2"

        @JvmStatic
        fun newInstance(param1: String, param2: String) =
            HomeFragment().apply {
                arguments = Bundle().apply {
                    putString(ARG_PARAM1, param1)
                    putString(ARG_PARAM2, param2)
                }
            }
    }
}

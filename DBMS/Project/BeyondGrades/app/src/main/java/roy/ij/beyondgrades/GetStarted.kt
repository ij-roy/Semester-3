package roy.ij.beyondgrades

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowCompat
import androidx.core.view.WindowInsetsCompat
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.ktx.database
import com.google.firebase.firestore.FirebaseFirestore
import com.google.firebase.ktx.Firebase
import roy.ij.beyondgrades.databinding.ActivityGetStartedBinding


class GetStarted : AppCompatActivity() {

    private lateinit var binding: ActivityGetStartedBinding
    private lateinit var database: DatabaseReference
    private lateinit var auth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        binding = ActivityGetStartedBinding.inflate(layoutInflater)
        setContentView(binding.root)

        database = Firebase.database.reference
        auth = FirebaseAuth.getInstance()

        binding.getStartedButton.setOnClickListener {
            Log.d("GetStarted", "Get Started button clicked")
            saveUserData()
        }

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }

    private fun saveUserData() {
        val name = binding.nameEditText.text.toString().trim()
        val rollNumber = binding.rollNumberEditText.text.toString().trim().uppercase()

        // Validation
        if (name.isEmpty()) {
            binding.nameEditText.error = "Please enter your name"
            return
        }
        if (rollNumber.isEmpty()) {
            binding.rollNumberEditText.error = "Please enter your roll number"
            return
        }

        // Retrieve the current user ID from FirebaseAuth
        val userId = auth.currentUser?.uid
        if (userId == null) {
            Toast.makeText(this, "User not authenticated", Toast.LENGTH_SHORT).show()
            return
        }

        // Update only name and rollNumber in the existing user data
        database.child("users").child(userId).updateChildren(
            mapOf(
                "name" to name,
                "rollNumber" to rollNumber
            )
        ).addOnSuccessListener {
            Toast.makeText(this, "User data updated successfully", Toast.LENGTH_SHORT).show()
            // Navigate to HomePage
            startActivity(Intent(this, HomePage::class.java))
            finish()
        }.addOnFailureListener { e ->
            Toast.makeText(this, "Failed to update user data", Toast.LENGTH_SHORT).show()
            Log.e("GetStarted", "Error updating user data", e)
        }
    }

    private fun showLoading(isLoading: Boolean) {
        binding.progressBar.visibility = if (isLoading) View.VISIBLE else View.GONE
        binding.getStartedButton.isEnabled = !isLoading
    }

    private fun enableEdgeToEdge() {
        WindowCompat.setDecorFitsSystemWindows(window, false)
    }
}


/*
class GetStarted : AppCompatActivity() {

    private lateinit var binding: ActivityGetStartedBinding
    private lateinit var database: DatabaseReference
    private lateinit var auth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        // Initialize ViewBinding
        binding = ActivityGetStartedBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Initialize Firebase instances
        database = Firebase.database.reference
        auth = FirebaseAuth.getInstance()

        // Handle the 'Get Started' button click
        binding.getStartedButton.setOnClickListener {
            Log.d("GetStarted", "Get Started button clicked")
            saveUserData()
            Log.d("GetStarted", "saveUserData function complete")
        }

        // Optional: Handle edge-to-edge behavior
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }

    private fun saveUserData() {
        val name = binding.nameEditText.text.toString().trim()
        val rollNumber = binding.rollNumberEditText.text.toString().trim().uppercase()

        // Validation
        if (name.isEmpty()) {
            binding.nameEditText.error = "Please enter your name"
            return
        }
        if (rollNumber.isEmpty()) {
            binding.rollNumberEditText.error = "Please enter your roll number"
            return
        }

        // Retrieve the current user ID from FirebaseAuth
        val userId = auth.currentUser?.uid
        if (userId == null) {
            Toast.makeText(this, "User not authenticated", Toast.LENGTH_SHORT).show()
            return
        }

        // Create a map to store user data
        val userData = mapOf(
            "name" to name,
            "rollNumber" to rollNumber,
            "skills" to emptyMap<String, Any>(),  // Placeholder for skills
            "feedbacks" to emptyMap<String, Any>()  // Placeholder for feedbacks
        )

        // Save user data to Firebase Realtime Database
        database.child("users").child(userId).setValue(userData)
            .addOnSuccessListener {
                Toast.makeText(this, "User data saved successfully", Toast.LENGTH_SHORT).show()
                // Navigate to HomePage
                startActivity(Intent(this, HomePage::class.java))
                finish()
            }
            .addOnFailureListener { e ->
                Toast.makeText(this, "Failed to save user data", Toast.LENGTH_SHORT).show()
                Log.e("GetStarted", "Error saving user data", e)
            }
    }
}
*/

//class GetStarted : AppCompatActivity() {
//
//    private lateinit var binding: ActivityGetStartedBinding
//    private lateinit var firestore: FirebaseFirestore
//    private lateinit var auth: FirebaseAuth
//
//    override fun onCreate(savedInstanceState: Bundle?) {
//        super.onCreate(savedInstanceState)
//        enableEdgeToEdge()
//
//        binding = ActivityGetStartedBinding.inflate(layoutInflater)
//        setContentView(binding.root)
//        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
//            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
//            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
//            insets
//        }
//        firestore = FirebaseFirestore.getInstance()
//        auth = FirebaseAuth.getInstance()
//
//        // Handle 'Get Started' button click
//        binding.getStartedButton.setOnClickListener {
//            saveUserData()
//        }
//    }
//
//    private fun saveUserData() {
//        val name = binding.nameEditText.text.toString().trim()
//        val rollNumber = binding.rollNumberEditText.text.toString().trim().lowercase() // Convert to lowercase
//
//        // Validation
//        if (name.isEmpty()) {
//            binding.nameEditText.error = "Please enter your name"
//            return
//        }
//        if (rollNumber.isEmpty()) {
//            binding.rollNumberEditText.error = "Please enter your roll number"
//            return
//        }
//
//        // Retrieve current user ID from FirebaseAuth
//        val userId = auth.currentUser?.uid ?: return
//
//        // Create a map to store user data
//        val userData = hashMapOf(
//            "name" to name,
//            "rollNumber" to rollNumber
//        )
//
//        // Save user data to Firestore
//        firestore.collection("users").document(userId)
//            .set(userData)
//            .addOnSuccessListener {
//                Toast.makeText(this, "User data saved successfully", Toast.LENGTH_SHORT).show()
//                // Navigate to HomePage
//                startActivity(Intent(this, HomePage::class.java))
//                finish()
//            }
//            .addOnFailureListener { e ->
//                Toast.makeText(this, "Failed to save user data", Toast.LENGTH_SHORT).show()
//                Log.e("GetStarted", "Error saving user data", e)
//            }
//    }
//
//}
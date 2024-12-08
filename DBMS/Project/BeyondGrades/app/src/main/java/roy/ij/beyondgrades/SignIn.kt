package roy.ij.beyondgrades

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.auth.api.signin.GoogleSignInClient
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.android.gms.common.api.ApiException
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import com.google.firebase.auth.GoogleAuthProvider
import com.google.firebase.auth.OAuthProvider
import com.google.firebase.database.FirebaseDatabase
import roy.ij.beyondgrades.databinding.ActivitySignInBinding

class SignIn : AppCompatActivity() {
    private lateinit var auth: FirebaseAuth
    private lateinit var database: FirebaseDatabase
    private lateinit var binding: ActivitySignInBinding
    private lateinit var googleSignInClient: GoogleSignInClient

    private val RC_SIGN_IN = 1001 // Request code for Google Sign-In

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = ActivitySignInBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Initialize FirebaseAuth and FirebaseDatabase
        auth = FirebaseAuth.getInstance()
        database = FirebaseDatabase.getInstance()

        // Configure Google Sign-In
        val gso = GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
            .requestIdToken(getString(R.string.default_web_client_id))
            .requestEmail()
            .build()
        googleSignInClient = GoogleSignIn.getClient(this, gso)

        binding.googleButton.setOnClickListener {
            signInWithGoogle()
        }

        binding.microsoftButton.setOnClickListener {
            if (auth.currentUser != null) {
                checkUserData(auth.currentUser!!)
            } else {
                signInWithMicrosoft()
            }
        }
    }

    private fun signInWithMicrosoft() {
        val provider = OAuthProvider.newBuilder("microsoft.com")
        auth.startActivityForSignInWithProvider(this, provider.build())
            .addOnCompleteListener { task ->
                if (task.isSuccessful) {
                    Toast.makeText(this, "Microsoft Sign-In Successful", Toast.LENGTH_LONG).show()
                    checkUserData(auth.currentUser!!)
                } else {
                    Toast.makeText(this, "Microsoft Sign-In Failed", Toast.LENGTH_LONG).show()
                    Log.e("Auth", "Microsoft Sign-In Error", task.exception)
                }
            }
    }

    private fun signInWithGoogle() {
        val signInIntent = googleSignInClient.signInIntent
        startActivityForResult(signInIntent, RC_SIGN_IN)
    }

    @Deprecated("Deprecated in Java")
    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        if (requestCode == RC_SIGN_IN) {
            val task = GoogleSignIn.getSignedInAccountFromIntent(data)
            try {
                val account = task.getResult(ApiException::class.java)
                firebaseAuthWithGoogle(account.idToken!!)
            } catch (e: ApiException) {
                Toast.makeText(this, "Google Sign-In Failed", Toast.LENGTH_LONG).show()
                Log.e("Auth", "Google Sign-In Error", e)
            }
        }
    }

    private fun firebaseAuthWithGoogle(idToken: String) {
        val credential = GoogleAuthProvider.getCredential(idToken, null)
        auth.signInWithCredential(credential)
            .addOnCompleteListener(this) { task ->
                if (task.isSuccessful) {
                    Toast.makeText(this, "Google Sign-In Successful", Toast.LENGTH_LONG).show()
                    checkUserData(auth.currentUser!!)
                } else {
                    Toast.makeText(this, "Authentication Failed", Toast.LENGTH_LONG).show()
                    Log.e("Auth", "Google Sign-In Error", task.exception)
                }
            }
    }

    private fun checkUserData(user: FirebaseUser) {
        val userRef = database.reference.child("users").child(user.uid)
        userRef.get().addOnSuccessListener { dataSnapshot ->
            if (dataSnapshot.exists()) {
                startActivity(Intent(this, HomePage::class.java))
            } else {
                startActivity(Intent(this, GetStarted::class.java))
            }
            finish()
        }.addOnFailureListener {
            Toast.makeText(this, "Error checking user data", Toast.LENGTH_SHORT).show()
            Log.e("DatabaseError", "Error checking user data", it)
        }
    }
}


/*
only microsoft
class SignIn : AppCompatActivity() {
    private lateinit var auth: FirebaseAuth
    private lateinit var database: FirebaseDatabase
    private lateinit var binding: ActivitySignInBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = ActivitySignInBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Initialize FirebaseAuth and FirebaseDatabase
        auth = FirebaseAuth.getInstance()
        database = FirebaseDatabase.getInstance()

        binding.microsoftButton.setOnClickListener {
            // Check if user is already signed in
            if (auth.currentUser != null) {
                checkUserData(auth.currentUser!!)
            } else {
                // Proceed with Microsoft Sign-In
                signInWithMicrosoft()
            }
        }
    }

    private fun signInWithMicrosoft() {
        val provider = OAuthProvider.newBuilder("microsoft.com")
        auth.startActivityForSignInWithProvider(this, provider.build())
            .addOnCompleteListener { task ->
                if (task.isSuccessful) {
                    Toast.makeText(this, "Microsoft Sign-In Successful", Toast.LENGTH_LONG).show()
                    checkUserData(auth.currentUser!!)
                } else {
                    Toast.makeText(this, "Microsoft Sign-In Failed", Toast.LENGTH_LONG).show()
                    Log.e("Auth", "Microsoft Sign-In Error", task.exception)
                }
            }
    }

    private fun checkUserData(user: FirebaseUser) {
        val userRef = database.reference.child("users").child(user.uid)

        userRef.get().addOnSuccessListener { dataSnapshot ->
            if (dataSnapshot.exists()) {
                // User data exists; proceed to HomePage
                startActivity(Intent(this, HomePage::class.java))
            } else {
                // New user; go to GetStarted activity
                startActivity(Intent(this, GetStarted::class.java))
            }
            finish()
        }.addOnFailureListener {
            Toast.makeText(this, "Error checking user data", Toast.LENGTH_SHORT).show()
            Log.e("DatabaseError", "Error checking user data", it)
        }
    }
}
*/

//class SignIn : AppCompatActivity() {
//    private lateinit var auth: FirebaseAuth
//    private lateinit var binding: ActivitySignInBinding
//    private lateinit var database: FirebaseDatabase
//
//    override fun onCreate(savedInstanceState: Bundle?) {
//        super.onCreate(savedInstanceState)
//        enableEdgeToEdge()
//        binding = ActivitySignInBinding.inflate(layoutInflater)
//        setContentView(binding.root)
//        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
//            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
//            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
//            insets
//        }
//        auth = FirebaseAuth.getInstance()
//        database = FirebaseDatabase.getInstance()
//        binding.microsoftButton.setOnClickListener{
//            signInWithMicrosoft()
//        }
//    }
//
//    private fun checkUserData() {
//        val currentUser = auth.currentUser
//        val userRef = database.reference.child("users").child(currentUser!!.uid)
//
//        userRef.get().addOnCompleteListener { task ->
//            if (task.isSuccessful) {
//                val userSnapshot = task.result
//                if (userSnapshot.exists()) {
//                    // Data exists, proceed to HomePage
//                    startActivity(Intent(this, HomePage::class.java))
//                    finish()
//                } else {
//                    // Data doesn't exist, redirect to GetStarted activity
//                    startActivity(Intent(this, GetStarted::class.java))
//                    finish()
//                }
//            } else {
//                Toast.makeText(this, "Error checking user data", Toast.LENGTH_SHORT).show()
//
//            }
//        }
//
//    }
//
//    private fun signInWithMicrosoft() {
//        val provider = OAuthProvider.newBuilder("microsoft.com")
//
//        auth.startActivityForSignInWithProvider(this,provider.build())
//            .addOnCompleteListener { task ->
//                if (task.isSuccessful) {
//                    Toast.makeText(this, "Microsoft Sign-In Successful", Toast.LENGTH_LONG).show()
//                    checkUserData()
////                    startActivity(Intent(this, HomePage::class.java))
//                }else{
//                    Toast.makeText(this, "Microsoft Sign-In Failed", Toast.LENGTH_LONG).show()
//                    Log.e("Auth", "Microsoft Sign-In Error", task.exception)
//                }
//            }
//    }
//}
package roy.ij.helloworldlrc.firebase

import android.content.Intent
import android.os.Bundle
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import roy.ij.helloworldlrc.MainActivity
import roy.ij.helloworldlrc.R
import roy.ij.helloworldlrc.databinding.FirebaseActivitySignOutBinding

class FirebaseSignOutActivity : AppCompatActivity() {
    private lateinit var binding: FirebaseActivitySignOutBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = FirebaseActivitySignOutBinding.inflate(layoutInflater)
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        binding.signout.setOnClickListener {
//            FirebaseAuth.getInstance().signOut()
            val gso = GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN).requestIdToken(getString(
                R.string.default_web_client_id
            )).requestEmail().build()
            GoogleSignIn.getClient(this,gso).signOut()
            startActivity(Intent(this, MainActivity::class.java))
        }
        binding.createNewNote.setOnClickListener {
            Toast.makeText(this,"Button 2 Clicked", Toast.LENGTH_LONG).show()
            startActivity(Intent(this, FirebaseAddNote::class.java))
            Toast.makeText(this,"Button Clicked", Toast.LENGTH_LONG).show()
        }
        binding.openNewNote.setOnClickListener {
            Toast.makeText(this,"Button 1 Clicked", Toast.LENGTH_LONG).show()
            startActivity(Intent(this, FirebaseAllNotes::class.java))
        }
    }
}
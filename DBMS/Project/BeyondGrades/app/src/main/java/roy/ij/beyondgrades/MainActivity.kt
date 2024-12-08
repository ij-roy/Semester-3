package roy.ij.beyondgrades

import android.content.Intent
import android.os.Bundle
import android.os.Handler
import android.os.Looper
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.firebase.auth.FirebaseAuth

class MainActivity : AppCompatActivity() {
    private lateinit var auth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        auth = FirebaseAuth.getInstance()

        // Delay the authentication check for 3 seconds
        Handler(Looper.getMainLooper()).postDelayed({
            if (auth.currentUser != null) {
                // User is already signed in, navigate to HomePage
                startActivity(Intent(this, HomePage::class.java))
            } else {
                // User is not signed in, navigate to SignIn
                startActivity(Intent(this, SignIn::class.java))
            }
            finish()  // Close the current activity
        }, 1000) // 3-second delay
    }
}

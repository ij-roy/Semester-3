package roy.ij.helloworldlrc.firebase

import android.os.Bundle
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import roy.ij.helloworldlrc.R
import roy.ij.helloworldlrc.databinding.FirebaseActivityAddNoteBinding

class FirebaseAddNote : AppCompatActivity() {
    private val binding : FirebaseActivityAddNoteBinding by lazy {
        FirebaseActivityAddNoteBinding.inflate(layoutInflater)
    }
    private lateinit var databaseReference: DatabaseReference
    private lateinit var  auth:FirebaseAuth
    override fun onCreate(savedInstanceState: Bundle?) {
        Toast.makeText(this,"Page Reached",Toast.LENGTH_LONG).show()
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        Toast.makeText(this,"Page Reached",Toast.LENGTH_LONG).show()
        //initialize firebase database reference
        databaseReference = FirebaseDatabase.getInstance().reference
        auth = FirebaseAuth.getInstance()
        binding.saveNoteButton.setOnClickListener {

            // Get text from edit text
            val title = binding.etTitle.text.toString()
            val description = binding.etDescription.text.toString()
            if (title.isEmpty() || description.isEmpty()){
                Toast.makeText(this,"Title or Description cannot be Empty",Toast.LENGTH_LONG).show()
            }else{
                val currentUser = auth.currentUser
                currentUser?.let { user ->
                    binding.saveNoteButton.isEnabled = false
                    // Generate a unique key for the note
                    val noteKey = databaseReference.child("users").child(user.uid).child("notes").push().key
                    // note Item Instance
                    val noteItem = FirebaseNoteItem(title, description,noteKey?:"")
                    if (noteKey!= null){
                        // add notes to the user note
                        databaseReference
                            .child("users")
                            .child(user.uid)
                            .child("notes")
                            .child(noteKey)
                            .setValue(noteItem)
                            .addOnCompleteListener { task ->
                                binding.saveNoteButton.isEnabled = false
                                if (task.isSuccessful){
                                    Toast.makeText(this,"Note Saved Successfully",Toast.LENGTH_LONG).show()
                                    finish()
                                }else{
                                    Toast.makeText(this,"Note Saving Failed\nSome Error Occured",Toast.LENGTH_LONG).show()
                                }
                            }
                    }
                }
            }
        }
    }
}
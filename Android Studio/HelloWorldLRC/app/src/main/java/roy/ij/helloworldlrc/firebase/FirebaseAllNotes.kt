package roy.ij.helloworldlrc.firebase

import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.ViewGroup
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AlertDialog
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.DatabaseReference
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import roy.ij.helloworldlrc.R
import roy.ij.helloworldlrc.databinding.FirebaseActivityAllNotesBinding
import roy.ij.helloworldlrc.databinding.FirebaseDialogUpdateNoteBinding

class FirebaseAllNotes : AppCompatActivity() , FirebaseNoteAdapter.OnItemClickListener {
    private val binding : FirebaseActivityAllNotesBinding by lazy {
        FirebaseActivityAllNotesBinding.inflate(layoutInflater)
    }
    private lateinit var databaseReference: DatabaseReference
    private lateinit var auth: FirebaseAuth
    private lateinit var recyclerView: RecyclerView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
        recyclerView = binding.noteRecyclerView
        recyclerView.layoutManager = LinearLayoutManager(this)
        //Initialize
        databaseReference = FirebaseDatabase.getInstance().reference
        auth = FirebaseAuth.getInstance()

        val currentUser = auth.currentUser
        currentUser?.let { user ->
            val noteReference = databaseReference
                .child("users")
                .child(user.uid)
                .child("notes")
            noteReference.addValueEventListener(object : ValueEventListener{
                override fun onDataChange(snapshot: DataSnapshot) {
                    val noteList = mutableListOf<FirebaseNoteItem>()
                    for (noteSnapshot in snapshot.children){
                        val note = noteSnapshot.getValue(FirebaseNoteItem::class.java)
                        Log.i("note","$note")
                        note?.let {
                            noteList.add(it)
                        }
                    }
                    noteList.reverse()
                    val adapter = FirebaseNoteAdapter(noteList,this@FirebaseAllNotes)
                    recyclerView.adapter = adapter
                    Log.i("note","$noteList")
                    Log.i("AllNotes", "Data Retrieved")
                }
                override fun onCancelled(error: DatabaseError) {
                    TODO("Not yet implemented")
                }

            })
        }
    }

    override fun onDeleteClick(noteId: String) {
        val currentUser = auth.currentUser
        currentUser?.let {user ->
            val noteReference = databaseReference.child("users").child(user.uid).child("notes")
            noteReference.child(noteId).removeValue()
        }
    }

    override fun onUpdateClick(noteId: String, currentTitle: String, currentDescription: String) {
        val dialogBinding = FirebaseDialogUpdateNoteBinding.inflate(LayoutInflater.from(this))
        val dialog = AlertDialog.Builder(this).setView(dialogBinding.root)
//            .setTitle("Update Notes")
//            .setPositiveButton("Update"){ dialog,_ ->
//                val newtitle = dialogBinding.updateNoteTitle.text.toString()
//                val newdescription = dialogBinding.updateNoteDescription.text.toString()
//                updateNoteDatabase(noteId,newtitle,newdescription)
//                dialog.dismiss()
//            }
//            .setNegativeButton("Cancel1"){dialog,_ ->
//                dialog.dismiss()
//            }
            .create()
        dialog.setOnShowListener {
            dialog.window?.setLayout(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT)
        }
        dialogBinding.updateNoteTitle.setText(currentTitle)
        dialogBinding.updateNoteDescription.setText(currentDescription)
        dialogBinding.cancelButton.setOnClickListener {
            dialog.dismiss()
        }
        dialogBinding.saveButton.setOnClickListener {
            val newtitle = dialogBinding.updateNoteTitle.text.toString()
            val newdescription = dialogBinding.updateNoteDescription.text.toString()
            updateNoteDatabase(noteId,newtitle,newdescription)
            dialog.dismiss()
        }
        dialog.show()
    }

    private fun updateNoteDatabase(noteId: String, newtitle: String, newdescription: String) {
        val currentUser = auth.currentUser
        currentUser?.let { user ->
            val noteReference = databaseReference.child("users").child(user.uid).child("notes")
            Log.i("ij","$noteReference")
            val updateNote = FirebaseNoteItem(newtitle,newdescription,noteId)
            noteReference.child(noteId).setValue(updateNote)
                .addOnCompleteListener { task ->
                    if (task.isSuccessful){
                        Toast.makeText(this,"Note Updated Successfully",Toast.LENGTH_LONG).show()
                    }else{
                        Toast.makeText(this,"Failed to Update Note",Toast.LENGTH_LONG).show()
                    }
                }
        }
    }
}
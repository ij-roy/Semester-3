package roy.ij.helloworldlrc.firebase

import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import roy.ij.helloworldlrc.databinding.FirebaseNotesItemBinding

class FirebaseNoteAdapter(private val notes: List<FirebaseNoteItem>,private val itemClickListener: OnItemClickListener) : RecyclerView.Adapter<FirebaseNoteAdapter.NoteViewHolder>() {

    interface OnItemClickListener {
        fun onDeleteClick(noteId:String)
        fun onUpdateClick(noteId: String, title: String, description: String)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): NoteViewHolder {
        val binding = FirebaseNotesItemBinding.inflate(LayoutInflater.from(parent.context),parent,false)
        return NoteViewHolder(binding)
    }

    override fun onBindViewHolder(holder: NoteViewHolder, position: Int) {
        val note = notes[position]
        holder.bind(note)
        holder.binding.updateButton.setOnClickListener {
            itemClickListener.onUpdateClick(note.noteId,note.title,note.description)
        }
        holder.binding.deleteButton.setOnClickListener {
            itemClickListener.onDeleteClick(note.noteId)
        }
    }
    override fun getItemCount(): Int {
        return notes.size
    }

    class NoteViewHolder(val binding: FirebaseNotesItemBinding): RecyclerView.ViewHolder(binding.root) {
        fun bind(note: FirebaseNoteItem) {
            binding.titleTextView.text = note.title
            binding.descriptionTextView.text = note.description
        }

    }
}
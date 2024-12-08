package roy.ij.beyondgrades

import android.view.View
import android.widget.Button
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class NotesViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
    val festNameTextView: TextView = itemView.findViewById(R.id.festNameText)
    val festYearTextView: TextView = itemView.findViewById(R.id.festYearText)
    val festPostTextView: TextView = itemView.findViewById(R.id.festPostText)
    val giveFeedbackButton: Button = itemView.findViewById(R.id.giveFestFeedbackButton)
}
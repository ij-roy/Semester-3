package roy.ij.beyondgrades

import android.content.Intent
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.google.firebase.auth.FirebaseAuth

class EventsAdapter(private val eventsList: MutableList<Event>) : RecyclerView.Adapter<EventsAdapter.EventViewHolder>() {

    inner class EventViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val festNameText: TextView = view.findViewById(R.id.festNameText)
        val festYearText: TextView = view.findViewById(R.id.festYearText)
        val festPostText: TextView = view.findViewById(R.id.festPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFestFeedbackButton)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): EventViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.notes_item, parent, false)
        return EventViewHolder(view)
    }

    override fun onBindViewHolder(holder: EventViewHolder, position: Int) {
        val event = eventsList[position]

        holder.festNameText.text = event.festName
        holder.festYearText.text = event.festYear.toString()  // Ensure festYear is displayed as a String
        holder.festPostText.text = event.festPost

        holder.giveFeedbackButton.setOnClickListener {
            val context = holder.itemView.context
            val festID = event.festID  // Assuming 'festID' is a field in your 'Event' class
            val userID = FirebaseAuth.getInstance().currentUser?.uid ?: ""  // Get the current user ID

            val intent = Intent(context, Feedback::class.java).apply {
                putExtra("festID", festID)  // Pass festID as the key to fetch data from Firebase
                putExtra("userID", userID)  // Pass userID to fetch the specific post for the user
            }

            // Log the data passed for debugging
            Log.d("EventsAdapter", "Starting Feedback with festID=${festID} and userID=${userID}")

//            Toast.makeText(context, "Starting Feedback with festID=${festID} and userID=${userID}", Toast.LENGTH_LONG).show()

            context.startActivity(intent)
        }
    }

    override fun getItemCount(): Int = eventsList.size
}


/*
class EventsAdapter(private val eventsList: MutableList<Event>) : RecyclerView.Adapter<EventsAdapter.EventViewHolder>() {

    inner class EventViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val festNameText: TextView = view.findViewById(R.id.festNameText)
        val festYearText: TextView = view.findViewById(R.id.festYearText)
        val festPostText: TextView = view.findViewById(R.id.festPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFestFeedbackButton)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): EventViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.notes_item, parent, false)
        return EventViewHolder(view)
    }

    override fun onBindViewHolder(holder: EventViewHolder, position: Int) {
        val event = eventsList[position]

        holder.festNameText.text = event.festName
        holder.festYearText.text = event.festYear
        holder.festPostText.text = event.festPost

        holder.giveFeedbackButton.setOnClickListener {
            // Intent to start Feedback Activity
            val intent = Intent(holder.itemView.context,Feedback::class.java)
            intent.putExtra("festName", event.festName)
            intent.putExtra("festYear", event.festYear.toString())

            // You might want to pass other data if necessary, for example, the event ID
            intent.putExtra("eventID", event.festName) // You can pass the event ID for database queries
            holder.itemView.context.startActivity(intent)
        }
    }

    override fun getItemCount(): Int = eventsList.size
}
*/
package roy.ij.beyondgrades

import android.app.Activity
import android.app.AlertDialog
import android.content.Context
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.EditText
import android.widget.SeekBar
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.FirebaseDatabase
import java.math.BigDecimal
import java.math.RoundingMode


class FeedbackAdapter(private val feedbackList: MutableList<FeedbackDataClass>, private val context: Context) : RecyclerView.Adapter<FeedbackAdapter.FeedbackViewHolder>() {

    inner class FeedbackViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val userNameText: TextView = view.findViewById(R.id.userNameText)
        val userPostText: TextView = view.findViewById(R.id.userPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFeedbackButton)
        val userskillName: TextView = view.findViewById(R.id.userSkillName)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FeedbackViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.feedback_item, parent, false)
        return FeedbackViewHolder(view)
    }

    private fun checkExistingFeedback(userID: String, skillName: String, onComplete: (Boolean) -> Unit) {
        val skillRef = FirebaseDatabase.getInstance()
            .getReference("users/$userID/skills/$skillName/feedbacks")

        skillRef.get().addOnSuccessListener { dataSnapshot ->
            val feedbackExists = dataSnapshot.children.any { it.hasChild(userID) } // Check if feedback already exists
            onComplete(feedbackExists)
        }.addOnFailureListener {
            Toast.makeText(context, "Failed to fetch existing feedback", Toast.LENGTH_SHORT).show()
            onComplete(false)
        }
    }

    override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
        val feedback = feedbackList[position]

        holder.userNameText.text = feedback.userName ?: "Unknown User"
        holder.userPostText.text = feedback.userPost ?: "No Role Available"
        holder.userskillName.text = feedback.skillName ?: "Error"

        // Update button UI based on feedback submission status
        if (feedback.isFeedbackSubmitted) {
            holder.giveFeedbackButton.text = "Submitted"
            holder.giveFeedbackButton.isEnabled = false
        } else {
            holder.giveFeedbackButton.text = "Give Feedback"
            holder.giveFeedbackButton.isEnabled = true
        }

        holder.giveFeedbackButton.setOnClickListener {
            val userName = feedback.userName ?: "Unknown User"
            val skills = feedback.skillName?.let { listOf(it) } ?: listOf("No Skills Found")

            val remainingSkills = mutableListOf<String>()
            val skillFeedbackStatus = mutableMapOf<String, Boolean>()

            skills.forEach { skill ->
                checkExistingFeedback(feedback.userId, skill) { exists ->
                    skillFeedbackStatus[skill] = exists
                    if (!exists) remainingSkills.add(skill)

                    if (skillFeedbackStatus.size == skills.size) {
                        if (remainingSkills.isEmpty()) {
                            Toast.makeText(context, "Feedback already submitted for all skills!", Toast.LENGTH_SHORT).show()
                        } else {
                            val nextSkill = remainingSkills.first()
                            showFeedbackDialog(userName, nextSkill, feedback.userId, feedback.festID, remainingSkills) { skill ->
                                feedback.isFeedbackSubmitted = true
                                holder.giveFeedbackButton.text = "Submitted"
                                holder.giveFeedbackButton.isEnabled = false

                                feedbackList.sortBy { it.isFeedbackSubmitted }
                                val newPosition = feedbackList.indexOf(feedback)

                                notifyItemMoved(position, newPosition)
                                notifyItemChanged(newPosition)
                            }
                        }
                    }
                }
            }
        }
    }

    override fun getItemCount(): Int = feedbackList.size

    private fun showFeedbackDialog(userName: String, skillName: String, userID: String, festID: String, remainingSkills: List<String>, onSubmit: (String) -> Unit) {
        val dialogView = LayoutInflater.from(context).inflate(R.layout.dialog_feedback, null)

        val skillNameTextView = dialogView.findViewById<TextView>(R.id.skillName)
        val tvSliderTitle = dialogView.findViewById<TextView>(R.id.tvSliderTitle)
        val tvSelectedValue = dialogView.findViewById<TextView>(R.id.tvSelectedValue)
        val seekBar = dialogView.findViewById<SeekBar>(R.id.seekBarValue)
        val etFeedback = dialogView.findViewById<EditText>(R.id.etFeedback)

        skillNameTextView.text = skillName
        tvSliderTitle.text = "How much would you rate $skillName of $userName?"

        seekBar.max = 100
        seekBar.progress = 0

        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
            override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                val value = progress / 10f
                tvSelectedValue.text = "Selected Value: %.1f".format(value)
                etFeedback.hint = "Please explain why you chose %.1f".format(value)
            }

            override fun onStartTrackingTouch(seekBar: SeekBar?) {}
            override fun onStopTrackingTouch(seekBar: SeekBar?) {}
        })

        val alertDialog = AlertDialog.Builder(context)
            .setView(dialogView)
            .create()

        dialogView.findViewById<Button>(R.id.btnCancel).setOnClickListener {
            alertDialog.dismiss()
        }

        dialogView.findViewById<Button>(R.id.btnSubmit).setOnClickListener {
            val feedbackText = etFeedback.text.toString()
            val ratingValue = seekBar.progress / 10f

            if (feedbackText.isBlank()) {
                Toast.makeText(context, "Feedback cannot be empty", Toast.LENGTH_SHORT).show()
            } else {
                submitFeedback(userID, skillName, festID, feedbackText, ratingValue) {
                    alertDialog.dismiss()
                    onSubmit(skillName)
                }
            }
        }

        alertDialog.show()
    }

    private fun submitFeedback(userID: String, skillName: String, festID: String, feedbackText: String, ratingValue: Float, onSuccess: () -> Unit) {
        val roundedRating = BigDecimal(ratingValue.toDouble()).setScale(1, RoundingMode.HALF_UP).toFloat()

        val feedbackRef = FirebaseDatabase.getInstance()
            .getReference("users/$userID/skills/$skillName/feedbacks/$festID")

        val reviewerID = FirebaseAuth.getInstance().currentUser?.uid ?: "Anonymous"

        if (userID != reviewerID) {
            val feedbackData = mapOf(
                "$reviewerID/comments" to feedbackText,
                "$reviewerID/rating" to roundedRating
            )

            feedbackRef.updateChildren(feedbackData)
                .addOnSuccessListener {
                    Toast.makeText(context, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
                    onSuccess()
                }
                .addOnFailureListener {
                    Toast.makeText(context, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
                }
        } else {
            Toast.makeText(context, "You cannot give feedback to yourself", Toast.LENGTH_SHORT).show()
        }
    }

    // Sorting Methods
    fun sortBySkill() {
        feedbackList.sortBy { it.skillName }
        notifyDataSetChanged()
    }

    fun sortByName() {
        feedbackList.sortBy { it.userName }
        notifyDataSetChanged()
    }

    fun sortByPost() {
        feedbackList.sortBy { it.userPost }
        notifyDataSetChanged()
    }
}



/*
class FeedbackAdapter(private val feedbackList: MutableList<FeedbackDataClass>, private val context: Context) : RecyclerView.Adapter<FeedbackAdapter.FeedbackViewHolder>() {

    inner class FeedbackViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val userNameText: TextView = view.findViewById(R.id.userNameText)
        val userPostText: TextView = view.findViewById(R.id.userPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFeedbackButton)
        val userskillName: TextView = view.findViewById(R.id.userSkillName)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FeedbackViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.feedback_item, parent, false)
        return FeedbackViewHolder(view)
    }

    private fun checkExistingFeedback(userID: String, skillName: String, onComplete: (Boolean) -> Unit) {
        val skillRef = FirebaseDatabase.getInstance()
            .getReference("users/$userID/skills/$skillName/feedbacks")

        skillRef.get().addOnSuccessListener { dataSnapshot ->
            val feedbackExists = dataSnapshot.children.any { it.hasChild(userID) } // Check if feedback already exists
            onComplete(feedbackExists)
        }.addOnFailureListener {
            Toast.makeText(context, "Failed to fetch existing feedback", Toast.LENGTH_SHORT).show()
            onComplete(false)
        }
    }

    override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
        val feedback = feedbackList[position]

        holder.userNameText.text = feedback.userName ?: "Unknown User"
        holder.userPostText.text = feedback.userPost ?: "No Role Available"
        holder.userskillName.text = feedback.skillName ?: "Error"

        // Update button UI based on feedback submission status
        if (feedback.isFeedbackSubmitted) {
            holder.giveFeedbackButton.text = "Submitted"
            holder.giveFeedbackButton.isEnabled = false
        } else {
            holder.giveFeedbackButton.text = "Give Feedback"
            holder.giveFeedbackButton.isEnabled = true
        }

        // Check if feedback is already submitted for the current user and fest
        val feedbackRef = FirebaseDatabase.getInstance()
            .getReference("users/${feedback.userId}/skills/${feedback.skillName}/feedbacks/${feedback.festID}")

        feedbackRef.get().addOnSuccessListener { dataSnapshot ->
            val feedbackSubmitted = dataSnapshot.exists() &&
                    dataSnapshot.hasChild(FirebaseAuth.getInstance().currentUser?.uid ?: "")

            if (feedbackSubmitted && !feedback.isFeedbackSubmitted) {
                (context as Activity).runOnUiThread {
                    feedback.isFeedbackSubmitted = true
                    feedbackList.sortBy { it.isFeedbackSubmitted }

                    // Notify that the item has moved
                    val newPosition = feedbackList.indexOf(feedback)
                    notifyItemMoved(position, newPosition)
                    notifyItemChanged(newPosition)  // Update the button UI for the moved item
                }
            }
        }.addOnFailureListener {
            Toast.makeText(context, "Failed to fetch feedback status", Toast.LENGTH_SHORT).show()
        }

        holder.giveFeedbackButton.setOnClickListener {
            val userName = feedback.userName ?: "Unknown User"
            val skills = feedback.skillName?.let { listOf(it) } ?: listOf("No Skills Found")

            val remainingSkills = mutableListOf<String>()
            val skillFeedbackStatus = mutableMapOf<String, Boolean>()

            skills.forEach { skill ->
                checkExistingFeedback(feedback.userId, skill) { exists ->
                    skillFeedbackStatus[skill] = exists
                    if (!exists) remainingSkills.add(skill)

                    if (skillFeedbackStatus.size == skills.size) {
                        if (remainingSkills.isEmpty()) {
                            Toast.makeText(context, "Feedback already submitted for all skills!", Toast.LENGTH_SHORT).show()
                        } else {
                            val nextSkill = remainingSkills.first()
                            showFeedbackDialog(userName, nextSkill, feedback.userId, feedback.festID, remainingSkills) { skill ->
                                feedback.isFeedbackSubmitted = true
                                holder.giveFeedbackButton.text = "Submitted"
                                holder.giveFeedbackButton.isEnabled = false

                                feedbackList.sortBy { it.isFeedbackSubmitted }
                                val newPosition = feedbackList.indexOf(feedback)

                                notifyItemMoved(position, newPosition)
                                notifyItemChanged(newPosition)
                            }
                        }
                    }
                }
            }
        }
    }

    override fun getItemCount(): Int = feedbackList.size

    private fun showFeedbackDialog(userName: String, skillName: String, userID: String, festID: String, remainingSkills: List<String>, onSubmit: (String) -> Unit) {
        val dialogView = LayoutInflater.from(context).inflate(R.layout.dialog_feedback, null)

        val skillNameTextView = dialogView.findViewById<TextView>(R.id.skillName)
        val tvSliderTitle = dialogView.findViewById<TextView>(R.id.tvSliderTitle)
        val tvSelectedValue = dialogView.findViewById<TextView>(R.id.tvSelectedValue)
        val seekBar = dialogView.findViewById<SeekBar>(R.id.seekBarValue)
        val etFeedback = dialogView.findViewById<EditText>(R.id.etFeedback)

        skillNameTextView.text = skillName
        tvSliderTitle.text = "How much would you rate $skillName of $userName?"

        seekBar.max = 100
        seekBar.progress = 0

        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
            override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                val value = progress / 10f
                tvSelectedValue.text = "Selected Value: %.1f".format(value)
                etFeedback.hint = "Please explain why you chose %.1f".format(value)
            }

            override fun onStartTrackingTouch(seekBar: SeekBar?) {}
            override fun onStopTrackingTouch(seekBar: SeekBar?) {}
        })

        val alertDialog = AlertDialog.Builder(context)
            .setView(dialogView)
            .create()

        dialogView.findViewById<Button>(R.id.btnCancel).setOnClickListener {
            alertDialog.dismiss()
        }

        dialogView.findViewById<Button>(R.id.btnSubmit).setOnClickListener {
            val feedbackText = etFeedback.text.toString()
            val ratingValue = seekBar.progress / 10f

            if (feedbackText.isBlank()) {
                Toast.makeText(context, "Feedback cannot be empty", Toast.LENGTH_SHORT).show()
            } else {
                submitFeedback(userID, skillName, festID, feedbackText, ratingValue) {
                    alertDialog.dismiss()
                    onSubmit(skillName)
                }
            }
        }

        alertDialog.show()
    }

    private fun submitFeedback(userID: String, skillName: String, festID: String, feedbackText: String, ratingValue: Float, onSuccess: () -> Unit) {
        val roundedRating = BigDecimal(ratingValue.toDouble()).setScale(1, RoundingMode.HALF_UP).toFloat()
        Log.e("roundedRating", "$roundedRating")

        val feedbackRef = FirebaseDatabase.getInstance()
            .getReference("users/$userID/skills/$skillName/feedbacks/$festID")

        val reviewerID = FirebaseAuth.getInstance().currentUser?.uid ?: "Anonymous"

        if (userID != reviewerID) {
            val feedbackData = mapOf(
                "$reviewerID/comments" to feedbackText,
                "$reviewerID/rating" to roundedRating
            )

            feedbackRef.updateChildren(feedbackData)
                .addOnSuccessListener {
                    Toast.makeText(context, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
                    onSuccess()
                }
                .addOnFailureListener {
                    Toast.makeText(context, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
                }
        } else {
            Toast.makeText(context, "You cannot give feedback to yourself", Toast.LENGTH_SHORT).show()
        }
    }
}
*/

/*
override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
    val feedback = feedbackList[position]

    holder.userNameText.text = feedback.userName ?: "Unknown User"
    holder.userPostText.text = feedback.userPost ?: "No Role Available"
    holder.userskillName.text = feedback.skillName ?: "Error"

    // Check if feedback is already submitted for the current user and fest
    val feedbackRef = FirebaseDatabase.getInstance()
        .getReference("users/${feedback.userId}/skills/${feedback.skillName}/feedbacks/${feedback.festID}")

    feedbackRef.get().addOnSuccessListener { dataSnapshot ->
        val feedbackSubmitted = dataSnapshot.exists() && dataSnapshot.hasChild(FirebaseAuth.getInstance().currentUser?.uid ?: "")

        if (feedbackSubmitted) {
            // Disable button if feedback is already submitted
            (context as Activity).runOnUiThread {
                holder.giveFeedbackButton.text = "Submitted"
                holder.giveFeedbackButton.isEnabled = false

                // Move the item to the bottom if feedback is already submitted
                feedbackList[position].isFeedbackSubmitted = true
                feedbackList.sortBy { it.isFeedbackSubmitted }

                // Notify adapter that the item has moved to the bottom
                notifyItemMoved(position, feedbackList.size - 1)
                notifyDataSetChanged()  // Refresh the list to reflect changes
            }
        }
    }.addOnFailureListener {
        Toast.makeText(context, "Failed to fetch feedback status", Toast.LENGTH_SHORT).show()
    }

    holder.giveFeedbackButton.setOnClickListener {
        val userName = feedback.userName ?: "Unknown User"
        val skills = feedback.skillName?.let { listOf(it) } ?: listOf("No Skills Found")

        val remainingSkills = mutableListOf<String>()
        val skillFeedbackStatus = mutableMapOf<String, Boolean>()

        skills.forEach { skill ->
            checkExistingFeedback(feedback.userId, skill) { exists ->
                skillFeedbackStatus[skill] = exists
                if (!exists) remainingSkills.add(skill)

                if (skillFeedbackStatus.size == skills.size) {
                    if (remainingSkills.isEmpty()) {
                        Toast.makeText(context, "Feedback already submitted for all skills!", Toast.LENGTH_SHORT).show()
                    } else {
                        val nextSkill = remainingSkills.first()
                        showFeedbackDialog(userName, nextSkill, feedback.userId, feedback.festID, remainingSkills) { skill ->
                            // Update feedback submission status and move item to the bottom
                            feedbackList[position].isFeedbackSubmitted = true // Mark feedback as submitted
                            holder.giveFeedbackButton.text = "Submitted"
                            holder.giveFeedbackButton.isEnabled = false

                            // Sort feedbackList so that submitted feedback items are at the bottom
                            feedbackList.sortBy { it.isFeedbackSubmitted }

                            // Move the item to the bottom
                            notifyItemMoved(position, feedbackList.size - 1)
                            notifyDataSetChanged()  // Refresh the entire list to reflect changes
                        }
                    }
                }
            }
        }
    }
}
*/
/*
class FeedbackAdapter(
    private val feedbackList: MutableList<FeedbackDataClass>,
    private val context: Context
) : RecyclerView.Adapter<FeedbackAdapter.FeedbackViewHolder>() {

    inner class FeedbackViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val userNameText: TextView = view.findViewById(R.id.userNameText)
        val userPostText: TextView = view.findViewById(R.id.userPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFeedbackButton)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FeedbackViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.feedback_item, parent, false)
        return FeedbackViewHolder(view)
    }

    override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
        val feedback = feedbackList[position]

        // Check for null or missing values and handle accordingly
        holder.userNameText.text = feedback.userName ?: "Unknown User"

        // Set the userPostText, ensuring it's not null
        val userPost = feedback.userPost ?: "No Role Available"
        holder.userPostText.text = userPost

        holder.giveFeedbackButton.setOnClickListener {
            // Show the feedback dialog when the button is clicked
            showFeedbackDialog(feedback.userName, feedback.skillName, feedback.userId, feedback.festID)
        }
    }

    override fun getItemCount(): Int = feedbackList.size

    private fun showFeedbackDialog(userName: String, skillName: String, userID: String, festID: String) {
        val dialogView = LayoutInflater.from(context).inflate(R.layout.dialog_feedback, null)

        val skillNameTextView = dialogView.findViewById<TextView>(R.id.skillName)
        val tvSliderTitle = dialogView.findViewById<TextView>(R.id.tvSliderTitle)
        val tvSelectedValue = dialogView.findViewById<TextView>(R.id.tvSelectedValue)
        val seekBar = dialogView.findViewById<SeekBar>(R.id.seekBarValue)
        val etFeedback = dialogView.findViewById<EditText>(R.id.etFeedback)

        // Set skill name in the dialog
        skillNameTextView.text = "$skillName"
        tvSliderTitle.text = "How much would you rate $skillName of $userName?"

        // Set SeekBar max to 100 for precision (0.0 to 10.0 range)
        seekBar.max = 100
        seekBar.progress = 0

        // Update displayed value when SeekBar is moved
        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
            override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                val value = progress / 10f // Divide by 10 to get a float value between 0.0 and 10.0
                tvSelectedValue.text = "Selected Value: %.1f".format(value)
                etFeedback.hint = "Please explain why you choose $value"
            }

            override fun onStartTrackingTouch(seekBar: SeekBar?) {}
            override fun onStopTrackingTouch(seekBar: SeekBar?) {}
        })

        val alertDialog = AlertDialog.Builder(context)
            .setView(dialogView)
            .create()

        // Cancel button click listener
        dialogView.findViewById<Button>(R.id.btnCancel).setOnClickListener {
            alertDialog.dismiss()
        }

        // Submit button click listener
        dialogView.findViewById<Button>(R.id.btnSubmit).setOnClickListener {
            val feedbackText = etFeedback.text.toString()
            val ratingValue = seekBar.progress / 10f // Convert to float value with precision

            if (feedbackText.isBlank()) {
                Toast.makeText(context, "Feedback cannot be empty", Toast.LENGTH_SHORT).show()
            } else {
                submitFeedback(userID, skillName, festID, feedbackText, ratingValue)
                alertDialog.dismiss()
            }
        }

        alertDialog.show()
    }

    private fun submitFeedback(userID: String, skillName: String, festID: String, feedbackText: String, ratingValue: Float) {
        val roundedRating = BigDecimal(ratingValue.toDouble()).setScale(1, RoundingMode.HALF_UP).toFloat()

        val feedbackRef = FirebaseDatabase.getInstance()
            .getReference("users/$userID/skills/$skillName/feedbacks/$festID")
        val reviewerID = FirebaseAuth.getInstance().currentUser?.uid ?: "Anonymous"

        // Ensure only valid users are submitting feedback
        if (userID != reviewerID) {
            // Store feedback data in Firebase
            val feedbackData = mapOf(
                "comments" to feedbackText,
                "rating" to roundedRating  // Store the rounded rating
            )

            feedbackRef.child(reviewerID).setValue(feedbackData)
                .addOnSuccessListener {
                    Toast.makeText(context, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
                }
                .addOnFailureListener {
                    Toast.makeText(context, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
                }
        } else {
            Toast.makeText(context, "You cannot give feedback to yourself", Toast.LENGTH_SHORT).show()
        }
    }
}
*/

/*
class FeedbackAdapter(
    private val feedbackList: MutableList<FeedbackDataClass>,
    private val context: Context
) : RecyclerView.Adapter<FeedbackAdapter.FeedbackViewHolder>() {

    inner class FeedbackViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val userNameText: TextView = view.findViewById(R.id.userNameText)
        val userPostText: TextView = view.findViewById(R.id.userPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFeedbackButton)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FeedbackViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.feedback_item, parent, false)
        return FeedbackViewHolder(view)
    }

    override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
        val feedback = feedbackList[position]
        holder.userNameText.text = feedback.userName
        holder.userPostText.text = feedback.userPost

        holder.giveFeedbackButton.setOnClickListener {
            showFeedbackDialog(feedback.userName, feedback.skillName, feedback.userId, feedback.festID)
        }
    }

    override fun getItemCount(): Int = feedbackList.size

    private fun showFeedbackDialog(userName: String, skillName: String, userID: String, festID: String) {
        val dialogView = LayoutInflater.from(context).inflate(R.layout.dialog_feedback, null)

        val skillNameTextView = dialogView.findViewById<TextView>(R.id.skillName)
        val tvSliderTitle = dialogView.findViewById<TextView>(R.id.tvSliderTitle)
        val tvSelectedValue = dialogView.findViewById<TextView>(R.id.tvSelectedValue)
        val seekBar = dialogView.findViewById<SeekBar>(R.id.seekBarValue)
        val etFeedback = dialogView.findViewById<EditText>(R.id.etFeedback)

        skillNameTextView.text = "Rate $skillName"
        tvSliderTitle.text = "Rate $userName for $skillName"

        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
            override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                tvSelectedValue.text = "Selected Value: $progress"
            }

            override fun onStartTrackingTouch(seekBar: SeekBar?) {}
            override fun onStopTrackingTouch(seekBar: SeekBar?) {}
        })

        val alertDialog = AlertDialog.Builder(context)
            .setView(dialogView)
            .create()

        dialogView.findViewById<Button>(R.id.btnCancel).setOnClickListener {
            alertDialog.dismiss()
        }

        dialogView.findViewById<Button>(R.id.btnSubmit).setOnClickListener {
            val feedbackText = etFeedback.text.toString()
            val ratingValue = seekBar.progress

            if (feedbackText.isBlank()) {
                Toast.makeText(context, "Feedback cannot be empty", Toast.LENGTH_SHORT).show()
            } else {
                submitFeedback(userID, skillName, festID, feedbackText, ratingValue)
                alertDialog.dismiss()
            }
        }

        alertDialog.show()
    }

    private fun submitFeedback(userID: String, skillName: String, festID: String, feedbackText: String, ratingValue: Int) {
        val feedbackRef = FirebaseDatabase.getInstance()
            .getReference("users/$userID/skills/$skillName/feedbacks/$festID")

        val reviewerID = FirebaseAuth.getInstance().currentUser?.uid ?: "Anonymous"

        val feedbackData = mapOf(
            "comments" to feedbackText,
            "rating" to ratingValue
        )

        feedbackRef.child(reviewerID).setValue(feedbackData)
            .addOnSuccessListener {
                Toast.makeText(context, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
            }
            .addOnFailureListener {
                Toast.makeText(context, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
            }
    }
}
*/


/*

class FeedbackAdapter(private val feedbackList: MutableList<FeedbackDataClass>, private val context: Context) : RecyclerView.Adapter<FeedbackAdapter.FeedbackViewHolder>() {

    inner class FeedbackViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val userNameText: TextView = view.findViewById(R.id.userNameText)
        val userPostText: TextView = view.findViewById(R.id.userPostText)
        val giveFeedbackButton: Button = view.findViewById(R.id.giveFeedbackButton)  // Add reference to the "Give Feedback" button
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FeedbackViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.feedback_item, parent, false)
        return FeedbackViewHolder(view)
    }

    override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
        val feedback = feedbackList[position]
        holder.userNameText.text = feedback.userName
        holder.userPostText.text = feedback.userPost

        // Set the OnClickListener for the "Give Feedback" button
        holder.giveFeedbackButton.setOnClickListener {
            // Show the feedback dialog when the button is clicked
            showFeedbackDialog(context, feedback.userId)
        }
    }

    override fun getItemCount(): Int = feedbackList.size

    // Function to display the feedback dialog
    private fun showFeedbackDialog(context: Context, userID: String) {
        // Inflate the feedback dialog layout
        val dialogView = LayoutInflater.from(context).inflate(R.layout.dialog_feedback, null)

        // Get references to the views inside the dialog
        val skillNameTextView = dialogView.findViewById<TextView>(R.id.skillName)
        val tvSliderTitle = dialogView.findViewById<TextView>(R.id.tvSliderTitle)
        val tvSelectedValue = dialogView.findViewById<TextView>(R.id.tvSelectedValue)
        val seekBar = dialogView.findViewById<SeekBar>(R.id.seekBarValue)
        val etFeedback = dialogView.findViewById<EditText>(R.id.etFeedback)

        // Set dynamic values (optional)
        skillNameTextView.text = "Rate the skill"
        tvSliderTitle.text = "How would you rate this user?"

        // Set up the SeekBar listener to update the rating value
        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener {
            override fun onProgressChanged(seekBar: SeekBar?, progress: Int, fromUser: Boolean) {
                tvSelectedValue.text = "Selected Value: $progress"
            }
            override fun onStartTrackingTouch(seekBar: SeekBar?) {}
            override fun onStopTrackingTouch(seekBar: SeekBar?) {}
        })

        // Create and show the AlertDialog
        val alertDialogBuilder = AlertDialog.Builder(context)
        alertDialogBuilder.setView(dialogView)

        val alertDialog = alertDialogBuilder.create()

        // Cancel button listener
        dialogView.findViewById<Button>(R.id.btnCancel).setOnClickListener {
            alertDialog.dismiss()
        }

        // Submit button listener
        dialogView.findViewById<Button>(R.id.btnSubmit).setOnClickListener {
            val feedbackText = etFeedback.text.toString()
            val ratingValue = seekBar.progress

            // Call the function to save the feedback to Firebase or another database
            submitFeedback(userID, feedbackText, ratingValue)
            alertDialog.dismiss()
        }

        // Show the dialog
        alertDialog.show()
    }

    // Function to submit the feedback to the database (Firebase in this case)
    private fun submitFeedback(userID: String, feedbackText: String, ratingValue: Int) {
        val feedbackRef = FirebaseDatabase.getInstance().getReference("feedback")
        val feedbackData = mapOf(
            "userID" to userID,
            "feedbackText" to feedbackText,
            "ratingValue" to ratingValue
        )

        // Save feedback to Firebase
        feedbackRef.push().setValue(feedbackData)
            .addOnSuccessListener {
                Toast.makeText(context, "Feedback submitted successfully!", Toast.LENGTH_SHORT).show()
            }
            .addOnFailureListener {
                Toast.makeText(context, "Failed to submit feedback", Toast.LENGTH_SHORT).show()
            }
    }
}
*/

/*
class FeedbackAdapter(private val feedbackList: MutableList<FeedbackDataClass>) : RecyclerView.Adapter<FeedbackAdapter.FeedbackViewHolder>() {

    inner class FeedbackViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val userNameText: TextView = view.findViewById(R.id.userNameText)
        val userPostText: TextView = view.findViewById(R.id.userPostText)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FeedbackViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.feedback_item, parent, false)
        return FeedbackViewHolder(view)
    }

    override fun onBindViewHolder(holder: FeedbackViewHolder, position: Int) {
        val feedback = feedbackList[position]
        holder.userNameText.text = feedback.userName
        holder.userPostText.text = feedback.userPost
    }

    override fun getItemCount(): Int = feedbackList.size
}
*/
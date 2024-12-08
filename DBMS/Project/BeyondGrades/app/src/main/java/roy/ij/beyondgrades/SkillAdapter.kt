package roy.ij.beyondgrades

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.firebase.ui.database.FirebaseRecyclerAdapter
import com.firebase.ui.database.FirebaseRecyclerOptions

class SkillAdapter(options: FirebaseRecyclerOptions<Skill>) : FirebaseRecyclerAdapter<Skill, SkillAdapter.SkillViewHolder>(options) {

    class SkillViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val skillName: TextView = itemView.findViewById(R.id.skillNameDashBoard)
        val epaScore: Button = itemView.findViewById(R.id.epaScore)

        fun bind(skill: Skill) {
            skillName.text = skill.name.replace("Skills", "\nSkills")
            epaScore.text = "${String.format("%.1f", skill.rating)} Credits"

            // Optional: Handle button click for more details
            epaScore.setOnClickListener {
                Toast.makeText(
                    itemView.context,
                    "Details for ${skill.name}: EPA Score ${String.format("%.1f", skill.rating)}",
                    Toast.LENGTH_SHORT
                ).show()
            }
        }
    }

    override fun onBindViewHolder(holder: SkillViewHolder, position: Int, model: Skill) {
        // Get the key (skill name) from Firebase
        val skillName = getRef(position).key ?: "Unknown Skill"

        // Set the skill name manually
        model.name = skillName

        // Bind the data to the ViewHolder
        holder.bind(model)
    }


    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): SkillViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.dashboard_item, parent, false)
        return SkillViewHolder(view)
    }

    override fun getItemViewType(position: Int): Int {
        // Optionally differentiate between different item types if needed.
        return super.getItemViewType(position)
    }
}


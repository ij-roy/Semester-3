package roy.ij.shayariapp

import android.content.Context
import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import roy.ij.shayariapp.databinding.RvItemBinding

class RvAdapter(
    var context:Context,
    var shayariList: List<DataEntity>
) : RecyclerView.Adapter<RvAdapter.ViewHolder>() {
    class ViewHolder(var binding:RvItemBinding) : RecyclerView.ViewHolder(binding.root){

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view=RvItemBinding.inflate(LayoutInflater.from(context),parent,false)
        return ViewHolder(view)
    }

    override fun getItemCount(): Int {
        return shayariList.size
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.binding.textView.text=shayariList.get(position).shayari
    }
}
package roy.ij.shayariapp

import android.content.Intent
import android.os.Bundle
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import androidx.navigation.findNavController
import androidx.navigation.ui.AppBarConfiguration
import androidx.navigation.ui.navigateUp
import androidx.navigation.ui.setupActionBarWithNavController
import android.view.Menu
import android.view.MenuItem
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import roy.ij.shayariapp.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding
    public var shayariList = ArrayList<DataEntity>()
    private lateinit var myViewModel: MyViewModel
//     54:33
    private val rvAdapter by lazy{
        RvAdapter(this,shayariList)
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        myViewModel = ViewModelProvider(this).get(MyViewModel::class.java)
        binding.rv.layoutManager=LinearLayoutManager(this)


        binding.fab.setOnClickListener { view ->
//            startActivity(Intent(this,AddEditActivity::class.java))
            rvAdapter.shayariList= myViewModel.shayariList
            rvAdapter.notifyDataSetChanged()
//            binding.rv.adapter=rvAdapter
        }
    }
}
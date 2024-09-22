package roy.ij.helloworldlrc

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.main_menu)

//        super.onCreate(savedInstanceState)
//        enableEdgeToEdge()
//        setContentView(R.layout.activity_main)
//        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
//            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
//            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
//            insets
//        }
//        // Code goes here
//        Toast.makeText(this,"Can you see me?",
//            Toast.LENGTH_LONG).show()
//
//        Log.i("info","Done creating the app")
    }
    fun topClick(v:View){
        Toast.makeText(this,"Top button clicked",Toast.LENGTH_SHORT).show()

        Log.i("info","The user clicked the top button")
    }
    fun bottomClick(v:View){
        Toast.makeText(this,"Bottom button clicked",Toast.LENGTH_SHORT).show()

        Log.i("info","The user clicked the bottom button")
    }
    fun loadConstraintLayout(v:View){
        setContentView(R.layout.activity_main)
    }
    fun loadTableLayout(v:View){
        setContentView(R.layout.my_table_layout)
    }
    fun loadMenuLayout(vv:View){
        setContentView(R.layout.main_menu)
    }
}
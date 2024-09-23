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
        setContentView(R.layout.activity_main)

        Toast.makeText(this, "In onCreate",
            Toast.LENGTH_SHORT).show()

        Log.i("info", "In onCreate")
 
    }

    override fun onStart() {
        // First call the “official” version of this method
        super.onStart();

        Toast.makeText(this, "In onStart",
            Toast.LENGTH_SHORT).show();

        Log.i("info", "In onStart");
    }

    override fun onResume() {
        // First call the "official” version of this method
        super.onResume();

        Toast.makeText(this, "In onResume",
            Toast.LENGTH_SHORT).show();

        Log.i("info", "In onResume");
    }

    override fun onPause() {
        // First call the "official” version of this method
        super.onPause();

        Toast.makeText(this, "In onPause",
            Toast.LENGTH_SHORT).show();

        Log.i("info", "In onPause");
    }

    override fun onStop() {
        // First call the "official" version of this method
        super.onStop();

        Toast.makeText(this, "In onStop",
            Toast.LENGTH_SHORT).show();

        Log.i("info", "In onStop");
    }

    override fun onDestroy() {
        // First call the "official” version of this method
        super.onDestroy();

        Toast.makeText(this, "In onDestroy",
            Toast.LENGTH_SHORT).show();

        Log.i("info", "In onDestroy");
    }


}



// Till Chapter 5
//class MainActivity : AppCompatActivity() {
//    override fun onCreate(savedInstanceState: Bundle?) {
//        super.onCreate(savedInstanceState)
//        setContentView(R.layout.main_layout)
//
////        super.onCreate(savedInstanceState)
////        enableEdgeToEdge()
////        setContentView(R.layout.activity_main)
////        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
////            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
////            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
////            insets
////        }
////        // Code goes here
////        Toast.makeText(this,"Can you see me?",
////            Toast.LENGTH_LONG).show()
////
////        Log.i("info","Done creating the app")
//    }
//    fun topClick(v:View){
//        Toast.makeText(this,"Top button clicked",Toast.LENGTH_SHORT).show()
//
//        Log.i("info","The user clicked the top button")
//    }
//    fun bottomClick(v:View){
//        Toast.makeText(this,"Bottom button clicked",Toast.LENGTH_SHORT).show()
//
//        Log.i("info","The user clicked the bottom button")
//    }
//    fun loadConstraintLayout(v:View){
//        setContentView(R.layout.activity_main)
//    }
//    fun loadTableLayout(v:View){
//        setContentView(R.layout.my_table_layout)
//    }
//    fun loadMenuLayout(vv:View){
//        setContentView(R.layout.main_menu)
//    }
//}
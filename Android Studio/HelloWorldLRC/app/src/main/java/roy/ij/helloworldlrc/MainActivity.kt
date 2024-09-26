package roy.ij.helloworldlrc

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import roy.ij.helloworldlrc.basicClasses.Carrier
import roy.ij.helloworldlrc.basicClasses.Destroyer
import roy.ij.helloworldlrc.basicClasses.Shipyard


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.express_yourself)

        val friendlyDestroyer = Destroyer("Invincible")
        val friendlyCarrier = Carrier("Indomitable")

        val enemyDestroyer = Destroyer("Grey Death")
        val enemyCarrier = Carrier("Big Grey Death")

        val friendlyShipyard = Shipyard()

        friendlyDestroyer.takeDamage(enemyDestroyer.shootShell())
        friendlyDestroyer.takeDamage(enemyCarrier.launchAerialAttack())
        enemyCarrier.takeDamage(friendlyCarrier.launchAerialAttack())
        enemyCarrier.takeDamage(friendlyDestroyer.shootShell())

        // Take stock of the supplies situation
        Log.d("${friendlyDestroyer.name} ammo = ",
            "${friendlyDestroyer.name} ammo = ${friendlyDestroyer.ammo}")

        Log.d("${friendlyCarrier.name} attacks = ",
            "${friendlyCarrier.name} attacks = ${friendlyCarrier.attacksRemaining}")

        // Dock at the shipyard
        friendlyShipyard.serviceCarrier(friendlyCarrier)
        friendlyShipyard.serviceDestroyer(friendlyDestroyer)

        // Take stock of the supplies situation
        Log.d("${friendlyDestroyer.name} ammo = ",
            "${friendlyDestroyer.name} ammo = ${friendlyDestroyer.ammo}")

        Log.d("${friendlyCarrier.name} attacks = ",
            "${friendlyCarrier.name} attacks = ${friendlyCarrier.attacksRemaining}")


        // Finish off the enemy
        enemyDestroyer.takeDamage(friendlyDestroyer.shootShell())
        enemyDestroyer.takeDamage(friendlyCarrier.launchAerialAttack())
        enemyDestroyer.takeDamage(friendlyDestroyer.shootShell())

    }
}




/*
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.express_yourself)

// First declare an instance of Soldier called soldier1
        val soldier1 = Soldier()
        soldier1.getStatus()

        // Now access and print each of the variables
        Log.i("Name =","${soldier1.name}")
        Log.i("Rank =","${soldier1.rank}")
        Log.i("Missing =","${soldier1.missing}")

        // Mission to rescue Private Ryan succeeds
        soldier1.missing = false;

        // Ryan behaved impeccably
        soldier1.rank = "Private First Class"

        // Now access and print each of the variables
        Log.i("Name =","${soldier1.name}")
        Log.i("Rank =","${soldier1.rank}")
        Log.i("Missing =","${soldier1.missing}")

        // In onCreate or some other function/class from our app
        // Create a new instance of the Soldier class
        val soldier = Soldier()
        // Access the value of bullets
        Log.i("bullets = ","${soldier.bullets}")// Code in getter will execute
        soldier.bullets--
        Log.i("bullets =","${soldier.bullets}")// Code in setter will execute


        // Create a soldier
        val strongSoldier = Soldier()
        // Print out the totalWeight value
        Log.i("totalWeight =","${strongSoldier.totalWeight}")

        // Change the value of packWeight
        strongSoldier.packWeight = 300
        // Print out the totalWeight value again
        Log.i("totalWeight =","${strongSoldier.totalWeight}")



//        var satelliteController = SatelliteController()






        // This still doesn't work which is what we want
        // satelliteController.gpsCoordinates = "1.2345, 5.6789"

        // But this will print the gpsCoordinates
//        Log.i("Coords=","$satelliteController.gpsCoordinates")


        // Instantiate a Book using the primary constructor
//        val book = Book("Animal Farm", 20000000)


        // Book two meetings
        // First when we don't yet know the time
//        val meeting = Meeting("Thursday", "Bob")

        // And secondly when we do know the time
//        val anotherMeeting = Meeting("Wednesday","Dave","3 PM")

    }
}

class Soldier{

    // members
    var name = "Ryan"
    var rank = "Private"
    var missing = true

    var bullets = 100
        get() {
            Log.i("Getter being used","Value = $field")
            return field
        }
        set(value) {
            field = if (value < 0) 0 else value
            Log.i("Setter being used","New value = $field")
        }

    var packWeight = 150
    val gunWeight = 30
    var totalWeight = packWeight + gunWeight
        get() = packWeight + gunWeight


    // member function
    fun getStatus() {
        var status = "$rank $name"
        if(missing){
            status = "$status is missing!"
        }else{
            status = "$status ready for duty."
        }

        Log.i("Status",status)
    }


}
*/



/*
Day 6
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.express_yourself)

        var name = "IJ Roy"
        val yearOfBirth = 2005
        var currentYear = 2024
        var age: Int

        age = currentYear - yearOfBirth
        Log.i("info","$age")

        currentYear++
        Log.i("info","$name was born in $yearOfBirth and is $age years old. Next year he will be ${currentYear-yearOfBirth} years old")

        name = "Nile"
        when (name) {
            "Atlantic","Pacific", "Arctic" ->
                Log.i("Found:", "$name is an ocean")

            "Thames","Nile", "Mississippi" ->
                Log.i("Found:", "$name is a river")

            "Labrador","Beagle", "Jack Russel" ->
                Log.i("Found:", "$name is a dog")

            else -> {
                Log.i("Not found:", "$name is not in database")
            }
        }

    }
}
*/




/*
Day 5
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
*/


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
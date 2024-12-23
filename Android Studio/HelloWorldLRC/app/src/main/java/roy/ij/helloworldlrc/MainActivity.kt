package roy.ij.helloworldlrc

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.auth.api.signin.GoogleSignInAccount
import com.google.android.gms.auth.api.signin.GoogleSignInClient
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.firebase.Firebase
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.GoogleAuthProvider
import com.google.firebase.auth.auth
import roy.ij.helloworldlrc.databinding.FirebaseActivityMainBinding
import roy.ij.helloworldlrc.firebase.FirebaseSignOutActivity

//1:30:00
class MainActivity : AppCompatActivity(){

    private lateinit var auth: FirebaseAuth
    private lateinit var binding: FirebaseActivityMainBinding
    private lateinit var googleSignInClient: GoogleSignInClient
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = FirebaseActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        supportActionBar?.hide()

        val gso = GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN).requestIdToken(getString(R.string.default_web_client_id)).requestEmail().build()
        googleSignInClient = GoogleSignIn.getClient(this,gso)
        auth = Firebase.auth
        binding.button7.setOnClickListener {
            auth.createUserWithEmailAndPassword(
                binding.email.text.toString(),
                binding.password.text.toString()
            )
                .addOnCompleteListener(this) { task ->
                    if (task.isSuccessful) {
                        Log.i("info", "createUserWithEmail: success")
                        val user = auth.currentUser
                        Toast.makeText(this, task.result.toString(), Toast.LENGTH_LONG).show()
                    }
                    else {
                        Log.i("info", "createUserWithEmail: Failure")
                        Toast.makeText(this,"Authentication Failed",Toast.LENGTH_LONG).show()
                    }
                }
        }
        binding.google.setOnClickListener{
            val signInClient = googleSignInClient.signInIntent
//            startActivity(signInClient)
            //55:34
            launcher.launch(signInClient)
        }
    }
    private val launcher = registerForActivityResult(ActivityResultContracts.StartActivityForResult()){
        result ->
        if (result.resultCode == Activity.RESULT_OK){
            val task = GoogleSignIn.getSignedInAccountFromIntent(result.data)
            if(task.isSuccessful){
                val account:GoogleSignInAccount?=task.result
                val credential = GoogleAuthProvider.getCredential(account?.idToken,null)
                auth.signInWithCredential(credential).addOnCompleteListener{
                    if (it.isSuccessful){
                        Toast.makeText(this,"Done",Toast.LENGTH_LONG).show()
                        startActivity(Intent(this, FirebaseSignOutActivity::class.java))
                    }else{
                        Toast.makeText(this,"Failed1",Toast.LENGTH_LONG).show()
                    }
                }
            }
        }else{
            Toast.makeText(this,"Failed",Toast.LENGTH_LONG).show()
        }
    }

//    override fun onStart() {
//        super.onStart()
//        if (auth.currentUser != null){
//            startActivity(Intent(this,FirebaseSignOutActivity::class.java))
//        }
//    }
}

/*
Day 15
class MainActivity : AppCompatActivity(){

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var ourArray = IntArray(5)
        ourArray[0] = 25
        ourArray[1] = 50
        ourArray[2] = 125
        ourArray[3] = 68
        ourArray[4] = 47

        Log.i("ij","Here is our Array")
//        Log.i("ij","[0] = ${ourArray[0]}")
        var answer = 0
        for (i in 0 until 5){
            Log.i("ij","[$i] = ${ourArray[i]}")
            answer+= ourArray[i]
        }
        Log.i("ij","Answer = ${answer}")
        ourArray = IntArray(1000)
        for (i in 0..999){
            ourArray[i] = i*5
            Log.i("ij","i = $i")
            Log.i("ij","ourArray[$i] = ${ourArray[i]}")
        }
    }
}
*/
/*
Chapter 14 Note to Self
class MainActivity : AppCompatActivity(){

    private var tempNote = Note()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.note_to_self_activity_main)

        val fab = findViewById<FloatingActionButton>(R.id.fab)

        fab.setOnClickListener {
            val dialog = DialogNewNote()
            dialog.show(supportFragmentManager, "")
        }

        val button = findViewById<View>(R.id.button6) as Button
        button.setOnClickListener {
            // Create a new DialogShowNote called dialog
            val dialog = DialogShowNote()

            // Send the note via the sendNoteSelected method
            dialog.sendNoteSelected(tempNote)

            // Create the dialog
            dialog.show(supportFragmentManager, "123")
        }
    }

    fun createNewNote(n: Note) {
        tempNote = n
    }
}
*/
/*
Dialog Demo
class MainActivity : AppCompatActivity(){

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.dialog_demo)
        val button = findViewById<Button>(R.id.button5)
        button.setOnClickListener {
            val myDialog = MyDialog()
            myDialog.show(supportFragmentManager,"123")

        }
    }

}
*/

/*
Day 14
class MainActivity :AppCompatActivity(){
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.exploration_layout)
        var checkBoxTransparency = findViewById<CheckBox>(R.id.checkBoxTransparency)
        var imageView = findViewById<ImageView>(R.id.imageView2)
        checkBoxTransparency.setOnCheckedChangeListener({
            view,isChecked ->
            if (isChecked){
                imageView.alpha = .1f
            }else{
                imageView.alpha = 1f
            }
        })
        var checkboxTint = findViewById<CheckBox>(R.id.checkBoxTint)
        checkboxTint.setOnCheckedChangeListener({
            view,isChecked ->
            if (isChecked){
                imageView.setColorFilter(Color.argb( 150,255,0,0))
            }else{
                imageView.setColorFilter(Color.argb(0,0,0,0))
            }
        })
        var checkBoxReSize = findViewById<CheckBox>(R.id.checkBoxResize)
        checkBoxReSize.setOnCheckedChangeListener({
            view,isChecked ->
            if (isChecked){
                imageView.scaleX = 2f
                imageView.scaleY = 2f
            }else{
                imageView.scaleX = 1f
                imageView.scaleY = 1f
            }
        })
        var radioGroup = findViewById<RadioGroup>(R.id.radioGroup)
        var textClock = findViewById<TextClock>(R.id.textClock)
        radioGroup.setOnCheckedChangeListener{
            group,checkedId ->
            val rb = group.findViewById<View>(checkedId) as RadioButton

            when (rb.id){
                R.id.radioButtonLondon ->
                    textClock.timeZone = "Europe/London"
                R.id.radioButtonBeiging ->
                    textClock.timeZone = "CST6CDT"
                R.id.radioButtonNewYork ->
                    textClock.timeZone = "America/New_York"
                R.id.radioButtonEuropeanEmpire ->
                    textClock.timeZone = "Europe/Brussels"
                R.id.radioButtonIndia ->
                    textClock.timeZone = "Asia/Kolkata"
            }
        }
        var button = findViewById<Button>(R.id.button4)
        var textView = findViewById<TextView>(R.id.textView5)
        var editText = findViewById<EditText>(R.id.editText)
        button.setOnClickListener{
            textView.text = editText.text
        }
        var switch1 = findViewById<Switch>(R.id.switch1)
        switch1.setOnCheckedChangeListener{
            buttonView, isChecked ->
            if (isChecked){
                textView.visibility = View.VISIBLE
            }else{
                textView.visibility = View.INVISIBLE
            }
        }
    }
}
*/


/*
Day 12
class MainActivity : AppCompatActivity() , View.OnClickListener{

    private var value = 0
    // Declare your buttons and text view
    private lateinit var btnAdd: Button
    private lateinit var btnTake: Button
    private lateinit var txtValue: TextView
    private lateinit var btnGrow: Button
    private lateinit var btnShrink: Button
    private lateinit var btnReset: Button
    private lateinit var btnHide: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.kotlin_meets_ui)

        btnAdd = findViewById(R.id.btnAdd)
        btnTake = findViewById(R.id.btnTake)
        txtValue = findViewById(R.id.txtValue)
        btnGrow = findViewById(R.id.btnGrow)
        btnShrink = findViewById(R.id.btnShrink)
        btnReset = findViewById(R.id.btnReset)
        btnHide = findViewById(R.id.btnHide)

        btnAdd.setOnClickListener(this)
        btnTake.setOnClickListener(this)
        txtValue.setOnClickListener(this)
        btnGrow.setOnClickListener(this)
        btnShrink.setOnClickListener(this)
        btnReset.setOnClickListener(this)
        btnHide.setOnClickListener(this)


    }

    override fun onClick(v: View) {
        // A local variable to use later
        val size: Float

        when (v.id) {
            R.id.btnAdd -> {
                value++
                txtValue.text = "$value"
            }

            R.id.btnTake -> {
                value--
                txtValue.text = "$value"
            }

            R.id.btnReset -> {
                value = 0
                txtValue.text = "$value"
            }

            R.id.btnGrow -> {
                size = txtValue.textScaleX
                txtValue.textScaleX = size + 1
            }

            R.id.btnShrink -> {
                size = txtValue.textScaleX
                txtValue.textScaleX = size - 1
            }

            R.id.btnHide -> if (txtValue.visibility == View.VISIBLE) {
                // Currently visible so hide it
                txtValue.visibility = View.INVISIBLE

                // Change text on the button
                btnHide.text = "SHOW"

            } else {
                // Currently hidden so show it
                txtValue.visibility = View.VISIBLE

                // Change text on the button
                btnHide.text = "HIDE"
            }
        }
    }

}
*/

/*
Day 11
class MainActivity : AppCompatActivity(),View.OnClickListener {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.kotlin_meets_ui)
    }

    override fun onClick(v: View?) {
        TODO("Not yet implemented")
    }
}
*/

/*
Day 10
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val friendlyDestroyer = Destroyer("Invincible")
        val friendlyCarrier = Carrier("Indomitable")

        val enemyDestroyer = Destroyer("Grey Death")
        val enemyCarrier = Carrier("Big Grey Death")

        val friendlyShipyard = ShipYard()

        // A small battle
        friendlyDestroyer.takeDamage(enemyDestroyer.attack())
        friendlyDestroyer.takeDamage(enemyCarrier.attack())
        enemyCarrier.takeDamage(friendlyCarrier.attack())
        enemyCarrier.takeDamage(friendlyDestroyer.attack())

        // Take stock of the supplies situation
        friendlyDestroyer.showStats()
        friendlyCarrier.showStats()

        // Dock at the shipyard
        friendlyShipyard.serviceShip(friendlyCarrier)
        friendlyShipyard.serviceShip(friendlyDestroyer)

        // Take stock of the supplies situation
        friendlyDestroyer.showStats()
        friendlyCarrier.showStats()

        // Finish off the enemy
        enemyDestroyer.takeDamage(friendlyDestroyer.attack())
        enemyDestroyer.takeDamage(friendlyCarrier.attack())
        enemyDestroyer.takeDamage(friendlyDestroyer.attack())
    }
}
*/


/*
Day 9
class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val soldier = Soldier()
        soldier.shoot()

        val specialForces = SpecialForces()
        specialForces.shoot()
        specialForces.SneakUpOnEnemy()

        val paratrooper = Paratrooper()
        paratrooper.shoot()
        paratrooper.jumpOutOfPlane()

        val sniper = Sniper()
        sniper.getIntoPosition()
        sniper.shoot()
        sniper.shoot()
        sniper.shoot()
        sniper.shoot()

    }
}
*/

/*
Day 8
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
*/

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
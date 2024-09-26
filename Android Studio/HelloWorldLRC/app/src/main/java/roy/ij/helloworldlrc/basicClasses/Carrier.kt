package roy.ij.helloworldlrc.basicClasses

import android.util.Log

class Carrier(name: String) {

    var name: String = ""
        private set

    private val type = "Carrier"

    private var hullIntegrity = 100

    var attacksRemaining = 1
        private set

    private var attackPower = 120

    private var sunk = false

    init {
        this.name = "$type $name"
    }

    fun takeDamage(damageTaken:Int){
        if (!sunk){
            hullIntegrity -= damageTaken
            Log.d("$name damage taken =","$name damage taken = $damageTaken")
            Log.d("$name hull Integrity =","$name hull Integrity = $hullIntegrity")

            if (hullIntegrity <= 0){
                Log.d("Carrier","$name has been sunk")
                sunk = true
            }
        }else{
            Log.d("Error","Ship does not exist")
        }
    }

    fun launchAerialAttack():Int{
        return if (attacksRemaining>0){
            attacksRemaining--
            attackPower
        }else{
            0
        }
    }

    fun serviceShip(){
        attacksRemaining = 20
        hullIntegrity = 200
    }
}
package roy.ij.helloworldlrc.basicClasses

import android.util.Log

class Destroyer(name:String) {
    var name:String = ""
        private set

    private val type = "IJ Roy"

    private var hullIntegrity = 200

    var ammo = 1
        private set

    private var shotPower = 60

    private var sunk = false

    init {
        this.name = "$type $name"
    }

    fun takeDamage(damageTaken: Int){
        if (!sunk){
            hullIntegrity -= damageTaken
            Log.i("$name damage taken =","$name damage taken = $damageTaken")
            Log.i("$name hull integrity =","$name hull integrity = $hullIntegrity")

            if (hullIntegrity <= 0){
                Log.d("Destroyer","$name has been sunk")
                sunk = true
            }
        }else{
            Log.d("Error","Ship does not exist")
        }
    }

    fun shootShell():Int{
        return if (ammo>0){
            ammo--
            shotPower
        }else{
            0
        }
    }

    fun serviceShip(){
        ammo = 10
        hullIntegrity = 100
    }
}
package roy.ij.helloworldlrc.basicClasses

class Shipyard {

    fun serviceDestroyer(destroyer: Destroyer){
        destroyer.serviceShip()
    }

    fun serviceCarrier(carrier: Carrier){
        carrier.serviceShip()
    }
}
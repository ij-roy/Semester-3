package roy.ij.beyondgrades


data class User(
    val name: String = "",
    val rollNumber: String = "",
    val skills: Map<String, Skill> = emptyMap()
)



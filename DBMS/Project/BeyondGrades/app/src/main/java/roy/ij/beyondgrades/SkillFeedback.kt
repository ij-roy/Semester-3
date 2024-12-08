package roy.ij.beyondgrades

data class SkillFeedback(
    val skillName: String,
    val ratings: List<Double>,
    val averageRating: Double
)

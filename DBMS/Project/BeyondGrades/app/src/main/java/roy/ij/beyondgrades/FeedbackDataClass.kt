package roy.ij.beyondgrades

data class FeedbackDataClass(
    val userName: String,
    val userRollNumber: String,
    val userId: String,
    val userPost: String, // Stores user's role
    val skillName: String, // Skill being evaluated
    val festID: String ,    // Unique ID for the fest/event
    var isFeedbackSubmitted: Boolean = false
)

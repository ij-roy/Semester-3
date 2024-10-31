package roy.ij.helloworldlrc.firebase

data class FirebaseNoteItem(val title: String , val description : String , val noteId : String){
    constructor():this("","","")
}

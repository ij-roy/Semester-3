package roy.ij.shayariapp

class AppRepository private constructor(){
    val list = SampleData.data
    companion object{
        val instant=AppRepository()
    }
}
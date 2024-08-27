package roy.ij.shayariapp

import java.util.ArrayList
import java.util.Calendar
import java.util.Date
import java.util.GregorianCalendar

object SampleData {
    val data1 = "this is data 1"
    val data2 = "this is data 2"
    fun getDate(diff : Int):Date{
        val calendar = GregorianCalendar()
        calendar.add(Calendar.MILLISECOND,diff)

        return calendar.time
    }
    val data : List<DataEntity>
        get(){
            val  tempList : MutableList<DataEntity> = ArrayList()
            tempList.add(DataEntity(1, getDate(45), data1))
            tempList.add(DataEntity(2, getDate(46), data2))
            return tempList
        }
}

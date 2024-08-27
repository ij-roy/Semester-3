package roy.ij.shayariapp

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey
import java.util.Date
@Entity("shayari_table")
data class DataEntity(
    @PrimaryKey(true)
    @ColumnInfo("id")
    var id:Int,
    @ColumnInfo("Date")
    var date:Date,
    @ColumnInfo("shayari")
    var shayari:String
){

}

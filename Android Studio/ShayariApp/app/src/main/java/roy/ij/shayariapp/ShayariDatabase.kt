package roy.ij.shayariapp

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverters

@Database(entities = [DataEntity::class], version = 1, exportSchema = true)
@TypeConverters(DateConverter::class)
abstract class ShayariDatabase : RoomDatabase(){
    abstract fun getShayariDao():ShayariDao
    private var INSTANCE:ShayariDatabase?=null
    fun getDatabase(context: Context):ShayariDatabase{
        if (INSTANCE!=null){
            synchronized(this){
                INSTANCE = Room.databaseBuilder(context.applicationContext,ShayariDatabase::class.java,"shayari_database").build()
            }
        }
        return INSTANCE!!
    }
}
package roy.ij.shayariapp

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.OnConflictStrategy
import androidx.room.Query
import androidx.room.Update

@Dao
interface ShayariDao {
    @Insert( onConflict =  OnConflictStrategy.IGNORE)
    suspend fun insertShayari(dataEntity: DataEntity)
    @Delete
    suspend fun deleteShaayri(dataEntity: DataEntity)
    @Update
    suspend fun updateShayari(dataEntity: DataEntity)
    @Query("SELECT * FROM SHAYARI_TABLE ORDER BY DATE DESC")
    fun getAllShayari() : List<DataEntity>
}
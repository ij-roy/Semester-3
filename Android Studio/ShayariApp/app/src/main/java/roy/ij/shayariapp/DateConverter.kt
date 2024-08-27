package roy.ij.shayariapp

import java.util.Date

class DateConverter {
    public fun toTimeStamp(date: Date):Long?{
        return date?.time
    }
    public fun toDate(long: Long):Date?{
        return long.let { Date(it) }
    }

}
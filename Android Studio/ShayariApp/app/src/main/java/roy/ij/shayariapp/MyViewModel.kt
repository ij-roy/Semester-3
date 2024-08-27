package roy.ij.shayariapp

import android.app.Application
import androidx.lifecycle.AndroidViewModel

class MyViewModel(application: Application):AndroidViewModel(application) {
    public var shayariList = AppRepository.instant.list
}
package roy.ij.helloworldlrc.dialogDemo

import android.app.AlertDialog
import android.app.Dialog
import android.os.Bundle
import androidx.fragment.app.DialogFragment

class MyDialog : DialogFragment() {
    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        val builder = AlertDialog.Builder(this.requireActivity())
        builder.setMessage("Make a Selection")
            .setPositiveButton("OK",{dialog,id->})
            .setNegativeButton("Cancel",{dialog,id->})
        return builder.create()
    }
}
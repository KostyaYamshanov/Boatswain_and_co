package com.esoft.accounting.presentation.dialogFragments

import android.app.Dialog
import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.view.Window
import androidx.fragment.app.DialogFragment
import com.esoft.accounting.R
import com.esoft.accounting.databinding.DialogCheckEmailBinding

class EmailCheckFragment(val text: String): DialogFragment() {

    lateinit var checkEmailBinding: DialogCheckEmailBinding

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View {
        checkEmailBinding = DialogCheckEmailBinding.inflate(inflater, container, false)
        onClick()
        checkEmailBinding.infoText.text = text
        return checkEmailBinding.root
    }


    private fun onClick() {
        checkEmailBinding.okBtn.setOnClickListener {
            dismiss()
        }
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        val dialog = super.onCreateDialog(savedInstanceState)
        dialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
        dialog.window!!.setBackgroundDrawable(ColorDrawable(Color.TRANSPARENT));
        dialog.window!!.setLayout(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
        dialog.setCanceledOnTouchOutside(false);
        dialog.setContentView(R.layout.dialog_check_email);
        return dialog
    }

}
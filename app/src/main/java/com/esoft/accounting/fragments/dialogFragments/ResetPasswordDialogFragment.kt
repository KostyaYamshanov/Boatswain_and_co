package com.esoft.accounting.fragments.dialogFragments

import android.app.Dialog
import android.content.DialogInterface
import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.view.Window
import android.widget.Toast
import androidx.fragment.app.DialogFragment
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.R
import com.esoft.accounting.databinding.ResetPasswordDialogFragmentBinding

class ResetPasswordDialogFragment : DialogFragment() {

    private lateinit var bindingReset: ResetPasswordDialogFragmentBinding
    private lateinit var viewModel: ResetPasswordDialogViewModel
    private lateinit var emailCheckFragment: EmailCheckFragment

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        viewModel = ViewModelProvider(this, ResetPasswordViewModelFactory(requireContext())).get(ResetPasswordDialogViewModel::class.java)
        val dialog = super.onCreateDialog(savedInstanceState)
        dialog.requestWindowFeature(Window.FEATURE_NO_TITLE)
        dialog.window!!.setBackgroundDrawable(ColorDrawable(Color.TRANSPARENT))
        dialog.setCanceledOnTouchOutside(false);
        dialog.setContentView(R.layout.reset_password_dialog_fragment)
        return dialog
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View? {
        bindingReset = ResetPasswordDialogFragmentBinding.inflate(inflater, container, false)
        onClick()
        emailCheckFragment = EmailCheckFragment(getString(R.string.textResetEmailSend))
        return bindingReset.root
    }

    private fun onClick() {
        bindingReset.resetBtn.setOnClickListener {
            val email = bindingReset.textLoginReset.text.toString()
            viewModel.resetPassword(email = email)
            viewModel.getTaskReset().observe(this, {
                if (!it) {
                    bindingReset.textField1.error = getString(R.string.failed_email)
                }else{
                    bindingReset.textField1.error = null
                    fragmentManager?.let { it1 -> emailCheckFragment.show(it1, "dialogResetEmailSend") }
                    dismiss()
                }
            })
        }

        bindingReset.cancel.setOnClickListener {
            dismiss()
            bindingReset.textField1.error = null
            bindingReset.textLoginReset.text = null
        }
    }
}
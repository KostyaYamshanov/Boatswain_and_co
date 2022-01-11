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
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.R
import com.esoft.accounting.databinding.ResetPasswordDialogFragmentBinding

class ResetPasswordDialogFragment : DialogFragment() {

    private lateinit var bindingReset: ResetPasswordDialogFragmentBinding
    private lateinit var viewModel: ResetPasswordDialogViewModel

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        viewModel = ViewModelProvider(this, ResetPasswordViewModelFactory(requireActivity().application)).get(ResetPasswordDialogViewModel::class.java)
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
        return bindingReset.root
    }

    private fun onClick() {
        bindingReset.resetBtn.setOnClickListener {
            val email = bindingReset.textLoginReset.text.toString()
            viewModel.resetPassword(email = email)
            viewModel.getTaskLiveData().observe(this, {
                if (!it) {
                    bindingReset.textField1.error = getString(R.string.failed_email)
                    bindingReset.resetLayout.visibility = View.VISIBLE
                    bindingReset.resetMsgSendLayout.visibility = View.GONE
                }else{
                    bindingReset.textField1.error = null
                    bindingReset.resetLayout.visibility = View.GONE
                    bindingReset.resetMsgSendLayout.visibility = View.VISIBLE

                }
            })
        }

        bindingReset.cancel.setOnClickListener {
            dismiss()
            bindingReset.textField1.error = null
            bindingReset.textLoginReset.text = null
        }

        bindingReset.sendOk.setOnClickListener {
            dismiss()
            bindingReset.textField1.error = null
            bindingReset.textLoginReset.text = null
        }
    }
}
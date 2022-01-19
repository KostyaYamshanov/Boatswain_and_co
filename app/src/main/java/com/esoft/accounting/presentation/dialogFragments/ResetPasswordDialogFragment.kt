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
import org.koin.androidx.viewmodel.ext.android.viewModel

class ResetPasswordDialogFragment : DialogFragment() {

    private var _binding: ResetPasswordDialogFragmentBinding? = null
    private val binding get() = _binding!!

    private val viewModel by viewModel<ResetPasswordDialogViewModel>()

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
        val dialog = super.onCreateDialog(savedInstanceState)
        dialog.requestWindowFeature(Window.FEATURE_NO_TITLE)
        dialog.window!!.setBackgroundDrawable(ColorDrawable(Color.TRANSPARENT))
        dialog.setCanceledOnTouchOutside(false)
        dialog.setContentView(R.layout.reset_password_dialog_fragment)
        return dialog
    }

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View? {
        _binding = ResetPasswordDialogFragmentBinding.inflate(inflater, container, false)
        onClick()
        return binding.root
    }

    override fun onDestroy() {
        super.onDestroy()
        _binding = null
    }

    private fun onClick() {
        binding.resetBtn.setOnClickListener {
            val email = binding.textLoginReset.text.toString()
            viewModel.resetPassword(email = email)
            viewModel.getTaskLiveData().observe(this, {
                if (!it) {
                    binding.textFieldEmail.error = getString(R.string.failed_email)
                    binding.resetLayout.visibility = View.VISIBLE
                    binding.resetMsgSendLayout.visibility = View.GONE
                }else{
                    binding.textFieldEmail.error = null
                    binding.resetLayout.visibility = View.GONE
                    binding.resetMsgSendLayout.visibility = View.VISIBLE

                }
            })
        }

        binding.cancel.setOnClickListener {
            dismiss()
            binding.textFieldEmail.error = null
            binding.textLoginReset.text = null
        }

        binding.sendOk.setOnClickListener {
            dismiss()
            binding.textFieldEmail.error = null
            binding.textLoginReset.text = null
        }
    }
}
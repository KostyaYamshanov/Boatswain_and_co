package com.esoft.accounting.presentation.dialogFragments

import android.app.Dialog
import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.os.Bundle
import android.view.View
import android.view.Window
import android.widget.Toast
import androidx.fragment.app.DialogFragment
import com.esoft.accounting.R
import com.esoft.accounting.databinding.ResetPasswordDialogFragmentBinding
import com.esoft.accounting.helpers.error_invalid_email
import com.esoft.accounting.helpers.error_user_not_found
import org.koin.androidx.viewmodel.ext.android.viewModel

class ResetPasswordDialogFragment : DialogFragment(R.layout.reset_password_dialog_fragment) {

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

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        viewModel.errorCode.observe(this, ::showErrorCode)
        viewModel.resetLiveData.observe(this, ::getResetStatus)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = ResetPasswordDialogFragmentBinding.bind(view)
        onClick()
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

    private fun showErrorCode(error: String) {
        when(error) {
            error_invalid_email -> {
                binding.textFieldEmail.error = getString(R.string.ERROR_INVALID_EMAIL)
            }
            error_user_not_found -> {
                binding.textFieldEmail.error = getString(R.string.ERROR_USER_NOT_FOUND)
            }
        }
        Toast.makeText(requireContext(), error, Toast.LENGTH_LONG).show()
    }

    private fun getResetStatus(status: Boolean) {
        if (status){
            binding.resetLayout.visibility = View.GONE
            binding.resetMsgSendLayout.visibility = View.VISIBLE
        }
    }

    private fun onClick() {
        binding.resetBtn.setOnClickListener {
            val email = binding.textLoginReset.text.toString()
            viewModel.resetPassword(email = email)
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
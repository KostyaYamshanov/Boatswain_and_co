package com.esoft.accounting.presentation.loginFragment

import android.app.ProgressDialog
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import android.widget.Toast
import androidx.navigation.fragment.findNavController
import com.esoft.accounting.databinding.FragmentLoginBinding
import com.esoft.accounting.R
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.helpers.error_invalid_email
import com.esoft.accounting.helpers.error_user_not_found
import com.esoft.accounting.helpers.error_wrong_password
import com.esoft.accounting.presentation.dialogFragments.ResetPasswordDialogFragment
import org.koin.androidx.viewmodel.ext.android.viewModel

class LoginFragment : Fragment(R.layout.fragment_login) {

    private var _binding: FragmentLoginBinding? = null
    private val binding get() = _binding!!

    private val viewModel by viewModel<LoginViewModel>()

    private var progressDialog: ProgressDialog? = null
    private var resetPasswordDialog: ResetPasswordDialogFragment? = null

    private companion object {
        const val dialogTag = "dialogResetPassword"
    }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        resetPasswordDialog = ResetPasswordDialogFragment()
        initProgressDialog()

        viewModel.errorCode.observe(this, ::showErrorMsg)
        viewModel.authState.observe(this, ::getAuthState)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentLoginBinding.bind(view)
        onBtnClick()

        viewModel.userLiveData.observe(viewLifecycleOwner) {
            if (it) {
                findNavController().navigate(R.id.action_loginFragment_to_listFragment)
            }
        }
    }

    private fun getAuthState(authState: AuthState) {
        if (authState.auth) {
            progressDialog!!.dismiss()
            if (findNavController().currentDestination?.id == R.id.loginFragment) {
                findNavController().navigate(R.id.action_loginFragment_to_listFragment)
            }
        }else{
            progressDialog!!.dismiss()
            Toast.makeText(requireContext(), getString(R.string.ERROR_EMAIL_NOT_VERIFIED), Toast.LENGTH_LONG).show()
        }
    }

    private fun showErrorMsg(error: String) {
        when(error) {
            error_user_not_found -> {
                binding.textFieldEmail.error = getString(R.string.ERROR_USER_NOT_FOUND)
            }
            error_wrong_password -> {
                binding.textFieldPassword.error = getString(R.string.ERROR_WRONG_PASSWORD)
            }
            error_invalid_email -> {
                binding.textFieldEmail.error = getString(R.string.ERROR_INVALID_EMAIL)
            }
        }
        Toast.makeText(requireContext(), "AuthResult - $error", Toast.LENGTH_LONG).show()
        progressDialog!!.dismiss()
    }

    private fun onBtnClick() {
        binding.buttonRegister.setOnClickListener {
            findNavController().navigate(R.id.action_loginFragment_to_registerFragment)
        }

        binding.buttonLogin.setOnClickListener {
            val email = binding.textLoginInput.text.toString()
            val password = binding.textPassInput.text.toString()
            checkField(email = email, password = password)
            if (email.isNotEmpty() && password.isNotEmpty()) {
                viewModel.login(email = email, password = password)
                progressDialog!!.show()
            }
        }

        binding.textResetPassword.setOnClickListener {
            fragmentManager?.let { it1 -> resetPasswordDialog!!.show(it1, dialogTag) }
        }
    }

    private fun initProgressDialog() {
        progressDialog = ProgressDialog(this.context)
        progressDialog!!.setTitle(getString(R.string.wait))
        progressDialog!!.setMessage(getString(R.string.login))
    }

    private fun checkField(email: String, password: String) {
        if (email.isEmpty()) {
            binding.textFieldEmail.apply {
                error = getString(R.string.enter_email)
                requestFocus()
            }
            return
        }else {
            binding.textFieldEmail.error = null
        }

        if (password.isEmpty()) {
            binding.textFieldPassword.apply {
                error = getString(R.string.enter_password)
                requestFocus()
            }
            return
        }else {
            binding.textFieldEmail.error = null
        }

    }


    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}

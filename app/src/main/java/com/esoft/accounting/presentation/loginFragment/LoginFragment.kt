package com.esoft.accounting.presentation.loginFragment

import android.app.ProgressDialog
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import android.widget.Toast
import androidx.navigation.fragment.findNavController
import com.esoft.accounting.databinding.FragmentLoginBinding
import com.esoft.accounting.R
import com.esoft.accounting.presentation.dialogFragments.ResetPasswordDialogFragment
import org.koin.androidx.viewmodel.ext.android.viewModel

class LoginFragment : Fragment(R.layout.fragment_login) {

    private var _binding: FragmentLoginBinding? = null
    private val binding get() = _binding!!

    private val loginViewModel by viewModel<LoginViewModel>()

    private var progressDialog: ProgressDialog? = null
    private var resetPasswordDialog: ResetPasswordDialogFragment? = null

    private companion object {
        const val dialogTag = "dialogResetPassword"

        const val error_user_not_found = "ERROR_USER_NOT_FOUND"
        const val error_wrong_password = "ERROR_WRONG_PASSWORD"
        const val error_invalid_email = "ERROR_INVALID_EMAIL"
    }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        loginViewModel.getUser()

        resetPasswordDialog = ResetPasswordDialogFragment()

        progressDialog = ProgressDialog(this.context)
        progressDialog!!.setTitle(getString(R.string.wait))
        progressDialog!!.setMessage(getString(R.string.login))
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentLoginBinding.bind(view)

        loginViewModel.userLiveData.observe(viewLifecycleOwner) {
            if (it) {
                findNavController().navigate(R.id.action_loginFragment_to_listFragment)
            }
        }

        binding.buttonRegister.setOnClickListener {
           findNavController().navigate(R.id.action_loginFragment_to_registerFragment)
        }

        binding.buttonLogin.setOnClickListener {
            val email = binding.textLoginInput.text.toString()
            val password = binding.textPassInput.text.toString()
            checkField(email = email, password = password)
            if (email.isNotEmpty() && password.isNotEmpty()) {
                loginViewModel.login(email = email, password = password)
                progressDialog!!.show()
                loginViewModel.authState.observe(viewLifecycleOwner) {
                    if (it.auth) {
                        progressDialog!!.dismiss()
                        if (findNavController().currentDestination?.id == R.id.loginFragment) {
                            findNavController().navigate(R.id.action_loginFragment_to_listFragment)
                        }
                    }
                    else{
                        when(it.error) {
                            error_user_not_found ->
                                Toast.makeText(requireContext(), getString(R.string.ERROR_USER_NOT_FOUND), Toast.LENGTH_LONG).show()
                            error_wrong_password ->
                                Toast.makeText(requireContext(), getString(R.string.ERROR_WRONG_PASSWORD), Toast.LENGTH_LONG).show()
                            error_invalid_email ->
                                Toast.makeText(requireContext(), getString(R.string.ERROR_INVALID_EMAIL), Toast.LENGTH_LONG).show()
                        }
                    }
                    Toast.makeText(requireContext(), "AuthResult - ${it.error}", Toast.LENGTH_LONG).show()
                    progressDialog!!.dismiss()
                }
            }
        }

        binding.textResetPassword.setOnClickListener {
            fragmentManager?.let { it1 -> resetPasswordDialog!!.show(it1, dialogTag) }
        }

    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
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
}

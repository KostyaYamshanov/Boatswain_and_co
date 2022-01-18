package com.esoft.accounting.presentation.loginFragment

import android.annotation.SuppressLint
import android.app.ProgressDialog
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import androidx.core.view.get
import androidx.navigation.NavController
import androidx.navigation.Navigation
import com.esoft.accounting.databinding.FragmentLoginBinding
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.R
import com.esoft.accounting.presentation.dialogFragments.ResetPasswordDialogFragment

class LoginFragment : Fragment(R.layout.fragment_login) {

    private var _binding: FragmentLoginBinding? = null
    private val binding get() = _binding!!

    private var navController: NavController? = null
    private var loginViewModel: LoginViewModel? = null

    private var progressDialog: ProgressDialog? = null

    private var resetPasswordDialog: ResetPasswordDialogFragment? = null

    private companion object {
        const val dialogTag = "dialogResetPassword"
    }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        loginViewModel = ViewModelProvider(
            this,
            LoginViewModelFactory(application = requireActivity().application)
        ).get(LoginViewModel::class.java)

        resetPasswordDialog = ResetPasswordDialogFragment()

        progressDialog = ProgressDialog(this.context)
        progressDialog!!.setTitle(getString(R.string.wait))
        progressDialog!!.setMessage(getString(R.string.login))


        loginViewModel!!.getUserLiveData().observe(this,
            { firebaseUser ->
                if (firebaseUser != null && firebaseUser.isEmailVerified) {
                    navController!!.navigate(R.id.action_loginFragment_to_listFragment)
                }
            })

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentLoginBinding.bind(view)
        navController = Navigation.findNavController(requireActivity(), R.id.nav_host_fragment)

        binding.buttonRegister.setOnClickListener {
            navController!!.navigate(R.id.action_loginFragment_to_registerFragment)
        }

        binding.buttonLogin.setOnClickListener {
            val email = binding.textLoginInput.text.toString()
            val password = binding.textPassInput.text.toString()
            checkField(email = email, password = password)
            if (email.isNotEmpty() && password.isNotEmpty()) {
                loginViewModel!!.login(email = email, password = password)
                progressDialog!!.show()
                loginViewModel!!.getTaskLiveData().observe(viewLifecycleOwner, {
                    if (it) {
                        if (navController!!.currentDestination?.id == R.id.loginFragment) {
                            navController!!.navigate(R.id.action_loginFragment_to_listFragment)
                        }
                    }
                    progressDialog!!.dismiss()
                })
            }
        }

        binding.textResetPassword.setOnClickListener {
            fragmentManager?.let { it1 -> resetPasswordDialog!!.show(it1, dialogTag) }
        }

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

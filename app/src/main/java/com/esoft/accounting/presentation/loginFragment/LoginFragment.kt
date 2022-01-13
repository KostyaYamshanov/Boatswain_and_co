package com.esoft.accounting.presentation.loginFragment

import android.annotation.SuppressLint
import android.app.ProgressDialog
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import androidx.navigation.NavController
import androidx.navigation.Navigation
import com.esoft.accounting.databinding.FragmentLoginBinding
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.R
import com.esoft.accounting.presentation.dialogFragments.ResetPasswordDialogFragment

class LoginFragment : Fragment(R.layout.fragment_login) {

    private lateinit var loginBinding: FragmentLoginBinding
    private lateinit var navController: NavController
    private lateinit var loginViewModel: LoginViewModel
    private lateinit var progressDialog: ProgressDialog
    private lateinit var resetPasswordDialog: ResetPasswordDialogFragment


    @SuppressLint("ResourceType")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        navController = Navigation.findNavController(requireActivity(), R.id.nav_host_fragment)
        loginViewModel = ViewModelProvider(
            this,
            LoginViewModelFactory(application = requireActivity().application)
        ).get(LoginViewModel::class.java)

        resetPasswordDialog = ResetPasswordDialogFragment()

        progressDialog = ProgressDialog(this.context)
        progressDialog.setTitle("Подождите")
        progressDialog.setMessage("Вход")


        loginViewModel.getUserLiveData().observe(this,
            { firebaseUser ->
                if (firebaseUser != null && firebaseUser.isEmailVerified) {
                    navController.navigate(R.id.action_loginFragment_to_listFragment)
                }
            })

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        loginBinding = FragmentLoginBinding.bind(view)

        loginBinding.buttonRegister.setOnClickListener {
            navController.navigate(R.id.action_loginFragment_to_registerFragment)
        }

        loginBinding.buttonLogin.setOnClickListener {
            val email = loginBinding.textLoginInput.text.toString()
            val password = loginBinding.textPassInput.text.toString()
            checkField(email = email, password = password)
            if (email.isNotEmpty() && password.isNotEmpty()) {
                loginViewModel.login(email = email, password = password)
                progressDialog.show()
                loginViewModel.getTaskLiveData().observe(viewLifecycleOwner, {
                    if (it) {
                        if (navController.currentDestination?.id == R.id.loginFragment) {
                            navController.navigate(R.id.action_loginFragment_to_listFragment)
                        }
                    }
                    progressDialog.dismiss()
                })
            }
        }

        loginBinding.textResetPassword.setOnClickListener {
            fragmentManager?.let { it1 -> resetPasswordDialog.show(it1, "dialogResetPassword") }
        }

    }

    private fun checkField(email: String, password: String) {
        if (email.isEmpty()) {
            loginBinding.textFieldEmail.apply {
                error = "Введите email"
                requestFocus()
            }
            return
        }else {
            loginBinding.textFieldEmail.error = null
        }

        if (password.isEmpty()) {
            loginBinding.textFieldPassword.apply {
                error = "Введите пароль"
                requestFocus()
            }
            return
        }else {
            loginBinding.textFieldEmail.error = null
        }

    }

}

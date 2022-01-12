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
    lateinit var navController: NavController
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
            loginViewModel.getUserLiveData().observe(viewLifecycleOwner,
                { firebaseUser ->
                    if (firebaseUser != null && firebaseUser.email != email) {
                        loginBinding.textField1.error = "Пользователь не найден"
                    } else {
                        if (email.isNotEmpty() && password.isNotEmpty()) {
                            loginViewModel.login(email = email, password = password)
                            loginBinding.textField1.error = null
                            loginBinding.textField2.error = null
                            progressDialog.show()
                            loginViewModel.getTaskLiveData().observe(viewLifecycleOwner, {
                                if (it) {
                                    progressDialog.dismiss()
                                    if (navController.currentDestination?.id == R.id.loginFragment) {
                                        navController.navigate(R.id.action_loginFragment_to_listFragment)
                                    }
                                }
                                progressDialog.dismiss()
                            })
                        } else {
                            if (email.isEmpty()) {
                                loginBinding.textField1.error = "Введите email"
                            } else {
                                loginBinding.textField1.error = null
                            }
                            if (password.isEmpty()) {
                                loginBinding.textField2.error = "Введите пароль"
                            } else {
                                loginBinding.textField2.error = null
                            }
                        }
                    }
                })
        }

        loginBinding.textResetPassword.setOnClickListener {
            fragmentManager?.let { it1 -> resetPasswordDialog.show(it1, "dialogResetPassword") }
        }

    }
}

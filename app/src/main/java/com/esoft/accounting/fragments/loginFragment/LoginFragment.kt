package com.esoft.accounting.fragments.loginFragment

import android.app.ProgressDialog
import android.os.Bundle
import android.view.LayoutInflater
import androidx.fragment.app.Fragment
import android.view.View
import android.view.ViewGroup
import androidx.navigation.NavController
import androidx.navigation.Navigation
import com.esoft.accounting.databinding.FragmentLoginBinding
import android.widget.Toast
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.R
import com.esoft.accounting.fragments.dialogFragments.ResetPasswordDialogFragment
import com.esoft.accounting.settings.Settings

class LoginFragment : Fragment(R.layout.fragment_login) {

    private lateinit var loginBinding: FragmentLoginBinding
    lateinit var navController: NavController
    private lateinit var loginViewModel: LoginViewModel
    private lateinit var progressDialog: ProgressDialog
    private lateinit var resetPasswordDialog: ResetPasswordDialogFragment
    private lateinit var settings: Settings

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        navController = Navigation.findNavController(requireActivity(), R.id.nav_host_fragment)
        loginViewModel = ViewModelProvider(this, LoginViewModelFactory(requireContext())).get(LoginViewModel::class.java)

        settings = Settings(this.requireContext())
        resetPasswordDialog = ResetPasswordDialogFragment()

        progressDialog = ProgressDialog(this.context)
        progressDialog.setTitle("Подождите")
        progressDialog.setMessage("Вход")

        if (settings.getSaveMePref()) {
            loginViewModel.userLiveData.observe(viewLifecycleOwner,
                { firebaseUser ->
                    if (firebaseUser != null && firebaseUser.isEmailVerified) {
                        navController.navigate(R.id.action_loginFragment_to_listFragment)
                    }
                })
        }
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
            if (email.isNotEmpty() && password.isNotEmpty()) {
                loginViewModel.login(email = email, password = password)
                loginBinding.textField1.error = null
                loginBinding.textField2.error = null
                progressDialog.show()
                loginViewModel.taskLogin.observe(viewLifecycleOwner, {
                    if (it) {
                        progressDialog.dismiss()
                        navController.navigate(R.id.action_loginFragment_to_listFragment)
                    }
                    progressDialog.dismiss()
                })
            }else {

                if (email.isEmpty()) {
                    loginBinding.textField1.error = "Введите email"
                }else{
                    loginBinding.textField1.error = null
                }
                if (password.isEmpty()) {
                    loginBinding.textField2.error = "Введите пароль"
                }else{
                    loginBinding.textField2.error = null
                }
            }
        }

        loginBinding.saveLoginAc.setOnCheckedChangeListener { compoundButton, b ->
            if (loginBinding.saveLoginAc.isChecked) {
                settings.saveMePref(true)
            }else{
                settings.saveMePref(false)
            }
        }

        loginBinding.textResetPassword.setOnClickListener {
            fragmentManager?.let { it1 -> resetPasswordDialog.show(it1, "dialogResetPassword") }
        }

    }
}

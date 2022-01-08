package com.esoft.accounting.fragments.loginFragment

import android.app.ProgressDialog
import android.content.Context
import android.content.SharedPreferences
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import androidx.navigation.NavController
import androidx.navigation.Navigation
import com.esoft.accounting.databinding.FragmentLoginBinding
import android.widget.Toast
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.R
import com.esoft.accounting.settings.MY_PREF
import com.esoft.accounting.settings.Settings

class LoginFragment : Fragment(R.layout.fragment_login) {

    private lateinit var loginBinding: FragmentLoginBinding
    lateinit var navController: NavController
    private lateinit var loginViewModel: LoginViewModel
    private lateinit var progressDialog: ProgressDialog
    private lateinit var settings: Settings

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        navController = Navigation.findNavController(requireActivity(), R.id.nav_host_fragment)
        loginViewModel = ViewModelProvider(this).get(LoginViewModel::class.java)

        settings = Settings(this.requireContext())

        progressDialog = ProgressDialog(this.context)
        progressDialog.setTitle("Подождите")
        progressDialog.setMessage("Вход")

        if (settings.getSaveMePref()) {
            loginViewModel.getUserLiveData().observe(this,
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
                progressDialog.show()
                loginViewModel.getTaskLogin().observe(viewLifecycleOwner, {
                    if (it) {
                        progressDialog.dismiss()
                        navController.navigate(R.id.action_loginFragment_to_listFragment)
                    }
                    progressDialog.dismiss()
                })
            } else {
                Toast.makeText(
                    this.context,
                    "Пожалуйста введите почту и пароль!",
                    Toast.LENGTH_LONG
                ).show()
            }

        }

        loginBinding.saveLoginAc.setOnCheckedChangeListener { compoundButton, b ->
            if (loginBinding.saveLoginAc.isChecked) {
                settings.saveMePref(true)
            }else{
                settings.saveMePref(false)
            }
        }

    }

    override fun onDestroyView() {
        super.onDestroyView()
    }
}

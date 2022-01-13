package com.esoft.accounting.presentation.registerFragment

import android.app.ProgressDialog
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import android.widget.Toast
import androidx.navigation.NavController
import androidx.navigation.Navigation
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentRegisterBinding
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.presentation.dialogFragments.EmailCheckFragment


class RegisterFragment : Fragment(R.layout.fragment_register) {

    lateinit var registerBinding: FragmentRegisterBinding
    lateinit var navController: NavController
    private lateinit var viewModel: RegisterViewModel
    private lateinit var dialogEmailCheck: EmailCheckFragment
    private lateinit var progressDialog: ProgressDialog

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        viewModel = ViewModelProvider(this, RegisterViewModelFactory(requireActivity().application)).get(RegisterViewModel::class.java)
        dialogEmailCheck = EmailCheckFragment(getString(R.string.verification))

        progressDialog = ProgressDialog(this.context)
        progressDialog.setTitle("Подождите")
        progressDialog.setMessage("Регистация пользователя")

    }


    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        registerBinding = FragmentRegisterBinding.bind(view)
        navController = Navigation.findNavController(requireActivity(), R.id.nav_host_fragment)

        registerBinding.buttonRegister.setOnClickListener {
            val email = registerBinding.textLoginInput.text.toString()
            val password = registerBinding.textPasswordInput.text.toString()
            val name = registerBinding.textNameInput.text.toString()
            val female = registerBinding.textFemaleInput.text.toString()
            checkFields(email = email, name = name, female = female, password = password)

            if (email.isNotEmpty() && password.isNotEmpty() && name.isNotEmpty() && female.isNotEmpty()) {
                viewModel.register(email = email, password = password, name = name, female = female)
                progressDialog.show()
                viewModel.getTaskLiveData().observe(viewLifecycleOwner,
                    {
                        if (it) {
                            fragmentManager?.let { it1 -> dialogEmailCheck.show(it1, "dialogEmailCheck") }
                            navController.navigateUp()
                        }
                        progressDialog.dismiss()
                    })
            } else {
                Toast.makeText(this.context, "Заполните данные!", Toast.LENGTH_LONG).show()
            }
        }

        registerBinding.backArrow.setOnClickListener {
            navController.navigateUp()
        }
    }

    private fun checkFields(email: String, name: String, female: String, password: String) {
        if(email.isEmpty()) {
            registerBinding.textFieldEmail.apply {
                error = "Введите почту"
                requestFocus()
            }
            return
        }else {
            registerBinding.textFieldEmail.error = null
        }

        if(name.isEmpty()) {
            registerBinding.textFieldName.apply {
                error = "Введите имя"
                requestFocus()
            }
            return
        }else {
            registerBinding.textFieldName.error = null
        }
        if(female.isEmpty()) {
            registerBinding.textFieldFemale.apply {
                error = "Введите фамилию"
                requestFocus()
            }
            return
        }else {
            registerBinding.textFieldFemale.error = null

        }

        if(password.isEmpty()) {
            registerBinding.textFieldPassword.apply {
                error = "Введите пароль"
                requestFocus()
            }
            return
        }else {
            registerBinding.textFieldPassword.error = null
        }
        if(password.length < 6) {
            registerBinding.textFieldPassword.apply {
                error = "Пароль должен быть 6 символов"
                requestFocus()
            }
            return
        }else {
            registerBinding.textFieldPassword.error = null
        }

    }

}
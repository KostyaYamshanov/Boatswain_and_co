package com.esoft.accounting.presentation.registerFragment

import android.app.ProgressDialog
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentRegisterBinding
import androidx.navigation.fragment.findNavController
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.presentation.dialogFragments.EmailCheckFragment
import org.koin.androidx.viewmodel.ext.android.viewModel


class RegisterFragment : Fragment(R.layout.fragment_register) {

    private var _binding: FragmentRegisterBinding? = null
    private val binding get() = _binding!!

    private val viewModel by viewModel<RegisterViewModel>()

    private var dialogEmailCheck: EmailCheckFragment? = null
    private var progressDialog: ProgressDialog? = null

    private companion object {
        const val dialogTag = "dialogEmailCheck"
        const val error_email_use = "ERROR_EMAIL_ALREADY_IN_USE"
        const val error_invalid_email = "ERROR_INVALID_EMAIL"
        const val error_email_not_verified = "Email не подтвержден"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        dialogEmailCheck = EmailCheckFragment()

        progressDialog = ProgressDialog(this.context)
        progressDialog!!.setTitle(getString(R.string.wait))
        progressDialog!!.setMessage(getString(R.string.user_registration))
    }


    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentRegisterBinding.bind(view)

        val toolbar = binding.registerToolbar
        (activity as AppCompatActivity).setSupportActionBar(toolbar)
        toolbar.title = getString(R.string.create_account)
        toolbar.setNavigationIcon(R.drawable.ic_arrow_back_black_24dp)
        toolbar.setNavigationOnClickListener {
            findNavController().navigateUp()
        }

        binding.buttonRegister.setOnClickListener {
            val email = binding.textLoginInput.text.toString()
            val password = binding.textPasswordInput.text.toString()
            val name = binding.textNameInput.text.toString()
            val surname = binding.textFemaleInput.text.toString()

            checkFields(email = email, name = name, surname = surname, password = password)

            if (email.isNotEmpty() && password.isNotEmpty() && name.isNotEmpty() && surname.isNotEmpty()) {
                viewModel.register(email = email, password = password, name = name, female = surname)
                progressDialog!!.show()
                viewModel.authState.observe(viewLifecycleOwner) {
                    Toast.makeText(requireContext(), "AuthResult - ${it.auth}", Toast.LENGTH_LONG).show()
                    if (it.auth) {
                        progressDialog!!.dismiss()
                        fragmentManager?.let { it1 -> dialogEmailCheck!!.show(it1, dialogTag) }
                        findNavController().navigateUp()
                    }
                    else{
                        when(it.error) {
                            error_email_use -> Toast.makeText(requireContext(), getString(R.string.ERROR_EMAIL_ALREADY_IN_USE), Toast.LENGTH_LONG).show()
                            error_invalid_email -> Toast.makeText(requireContext(), getString(R.string.ERROR_INVALID_EMAIL), Toast.LENGTH_LONG).show()
                            error_email_not_verified -> Toast.makeText(requireContext(), getString(R.string.ERROR_EMAIL_NOT_VERIFIED), Toast.LENGTH_LONG).show()
                        }
                        Toast.makeText(requireContext(), "AuthResult - ${it.error}", Toast.LENGTH_LONG).show()
                        progressDialog!!.dismiss()
                    }
                }
            }
        }
    }

    private fun checkFields(email: String, name: String, surname: String, password: String) {
        if(email.isEmpty()) {
            binding.textFieldEmail.apply {
                error = getString(R.string.enter_email)
                requestFocus()
            }
            return
        }else {
            binding.textFieldEmail.error = null
        }

        if(name.isEmpty()) {
            binding.textFieldName.apply {
                error = getString(R.string.enter_name)
                requestFocus()
            }
            return
        }else {
            binding.textFieldName.error = null
        }
        if(surname.isEmpty()) {
            binding.textFieldFemale.apply {
                error = getString(R.string.enter_surname)
                requestFocus()
            }
            return
        }else {
            binding.textFieldFemale.error = null

        }

        if(password.isEmpty()) {
            binding.textFieldPassword.apply {
                error = getString(R.string.enter_password)
                requestFocus()
            }
            return
        }else {
            binding.textFieldPassword.error = null
        }
        if(password.length < 6) {
            binding.textFieldPassword.apply {
                error = getString(R.string.password_error)
                requestFocus()
            }
            return
        }else {
            binding.textFieldPassword.error = null
        }

    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}
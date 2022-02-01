package com.esoft.accounting.presentation.registerFragment

import android.app.ProgressDialog
import android.os.Bundle
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentManager
import androidx.navigation.fragment.findNavController
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentRegisterBinding
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.helpers.error_email_use
import com.esoft.accounting.helpers.error_invalid_email
import com.esoft.accounting.presentation.dialogFragments.EmailCheckFragment
import org.koin.androidx.viewmodel.ext.android.viewModel


class RegisterFragment : Fragment(R.layout.fragment_register) {

    private var _binding: FragmentRegisterBinding? = null
    private val binding get() = _binding!!

    private val viewModel by viewModel<RegisterViewModel>()

    private var dialogEmailCheck: EmailCheckFragment? = null
    private var progressDialog: ProgressDialog? = null

    private companion object {
        const val dialogTag = "dialogEmailCheckFragment"
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        dialogEmailCheck = EmailCheckFragment()
        initProgressDialog()

        viewModel.errorCode.observe(this, ::showErrors)
        viewModel.authState.observe(this, ::getAuthState)
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
        onClickBtn()
    }

    private fun getAuthState(authState: AuthState) {
        if (authState.auth) {
            progressDialog!!.dismiss()
            val fm: FragmentManager = requireActivity().supportFragmentManager
            val oldFragment: Fragment? = fm.findFragmentByTag(dialogTag)
            if (oldFragment != null) {
                fm.beginTransaction().remove(oldFragment).commit()
            }
            val newFragment = EmailCheckFragment()
            fm.beginTransaction().add(newFragment, dialogTag)
            dialogEmailCheck?.show(requireActivity().supportFragmentManager, dialogTag)
            findNavController().navigateUp()
        }
    }

    private fun showErrors(error: String) {
        when (error) {
            error_email_use -> {
                binding.textFieldEmail.error = getString(R.string.ERROR_EMAIL_ALREADY_IN_USE)
            }
            error_invalid_email -> {
                binding.textFieldEmail.error = getString(R.string.ERROR_INVALID_EMAIL)
            }
        }
        Toast.makeText(requireContext(), "AuthResult - $error", Toast.LENGTH_LONG).show()
        progressDialog!!.dismiss()
    }

    private fun onClickBtn() {
        binding.buttonRegister.setOnClickListener {
            val email = binding.textLoginInput.text.toString()
            val password = binding.textPasswordInput.text.toString()
            val name = binding.textNameInput.text.toString()
            val surname = binding.textFemaleInput.text.toString()
            checkFields(email = email, name = name, surname = surname, password = password)
            if (email.isNotEmpty() && password.isNotEmpty() && name.isNotEmpty() && surname.isNotEmpty()) {
                viewModel.register(email = email, password = password, name = name, surname = surname)
                progressDialog!!.show()
            }
        }
    }

    private fun checkFields(email: String, name: String, surname: String, password: String) {
        if (email.isEmpty()) {
            binding.textFieldEmail.apply {
                error = getString(R.string.enter_email)
                requestFocus()
            }
            return
        } else {
            binding.textFieldEmail.error = null
        }

        if (name.isEmpty()) {
            binding.textFieldName.apply {
                error = getString(R.string.enter_name)
                requestFocus()
            }
            return
        } else {
            binding.textFieldName.error = null
        }
        if (surname.isEmpty()) {
            binding.textFieldSurname.apply {
                error = getString(R.string.enter_surname)
                requestFocus()
            }
            return
        } else {
            binding.textFieldSurname.error = null

        }

        if (password.isEmpty()) {
            binding.textFieldPassword.apply {
                error = getString(R.string.enter_password)
                requestFocus()
            }
            return
        } else {
            binding.textFieldPassword.error = null
        }
        if (password.length < 6) {
            binding.textFieldPassword.apply {
                error = getString(R.string.password_error)
                requestFocus()
            }
            return
        } else {
            binding.textFieldPassword.error = null
        }

    }

    private fun initProgressDialog() {
        progressDialog = ProgressDialog(this.context)
        progressDialog!!.setTitle(getString(R.string.wait))
        progressDialog!!.setMessage(getString(R.string.user_registration))
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}
package com.esoft.accounting.fragments.registerFragment

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
import com.esoft.accounting.fragments.dialogFragments.EmailCheckFragment


class RegisterFragment : Fragment(R.layout.fragment_register) {

    lateinit var registerBinding: FragmentRegisterBinding
    lateinit var navController: NavController
    private lateinit var viewModel: RegisterViewModel
    private lateinit var dialogEmailCheck: EmailCheckFragment
    private lateinit var progressDialog: ProgressDialog

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        viewModel = ViewModelProvider(this, RegisterViewModelFactory(requireContext())).get(RegisterViewModel::class.java)
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

            if (email.isNotEmpty() && password.isNotEmpty()) {
                viewModel.register(email = email, password = password)
                progressDialog.show()
                viewModel.getTaskLiveData().observe(viewLifecycleOwner,
                    {
                        if (it) {
                            progressDialog.dismiss()
                            fragmentManager?.let { it1 -> dialogEmailCheck.show(it1, "dialogEmailCheck") }
                            activity?.onBackPressed()
                        }
                        progressDialog.dismiss()
                    })
            } else {
                Toast.makeText(this.context, "Заполните данные!", Toast.LENGTH_LONG).show()
            }
        }

        registerBinding.backArrow.setOnClickListener {
            activity?.onBackPressed()
        }
    }

}
package com.esoft.accounting.fragments.registerFragment

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class RegisterViewModel(private val authRepository: AuthRepository) : ViewModel() {

    val taskRegister = authRepository.getTaskRegister()

    fun register(email: String, password: String) {
        authRepository.registration(email = email, password = password)
    }


}
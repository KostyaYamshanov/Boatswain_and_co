package com.esoft.accounting.fragments.registerFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class RegisterViewModel(private val authRepository: AuthRepository) : ViewModel() {

    private val taskRegister = authRepository.userTask()

    fun register(email: String, password: String) {
        authRepository.registration(email = email, password = password)
    }

    fun getTaskLiveData(): LiveData<Boolean> {
        return taskRegister
    }


}
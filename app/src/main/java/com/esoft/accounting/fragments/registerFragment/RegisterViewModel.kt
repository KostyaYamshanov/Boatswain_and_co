package com.esoft.accounting.fragments.registerFragment

import android.app.Activity
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class RegisterViewModel(private val authRepository: AuthRepository) : ViewModel() {

    private var userLiveData = MutableLiveData<FirebaseUser>()
    private var taskRegister = MutableLiveData<Boolean>()

    init {
        userLiveData = authRepository.getUserLiveData()
        taskRegister = authRepository.getTaskRegister()
    }

    fun register(email: String, password: String) {
        authRepository.registration(email = email, password = password)
    }

    fun getUserLiveData(): MutableLiveData<FirebaseUser> {
        return userLiveData
    }

    fun getTaskRegister():MutableLiveData<Boolean> {
        return taskRegister
    }

}
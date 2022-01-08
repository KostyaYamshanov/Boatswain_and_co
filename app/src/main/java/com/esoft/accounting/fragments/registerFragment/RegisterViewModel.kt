package com.esoft.accounting.fragments.registerFragment

import android.app.Activity
import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.MutableLiveData
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class RegisterViewModel(application: Application) : AndroidViewModel(application) {

    private var authRepository: AuthRepository = AuthRepository(application)
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
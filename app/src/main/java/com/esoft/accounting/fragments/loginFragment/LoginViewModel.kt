package com.esoft.accounting.fragments.loginFragment

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class LoginViewModel(private val authRepository: AuthRepository) : ViewModel(){

    private var userLiveData = MutableLiveData<FirebaseUser>()
    private var taskLogin = MutableLiveData<Boolean>()

    init {
        userLiveData = authRepository.getUserLiveData()
        taskLogin = authRepository.getTaskLogin()
    }

    fun login(email: String, password: String) {
        authRepository.login(email = email, password = password)
    }

    fun getUserLiveData(): MutableLiveData<FirebaseUser> {
        return userLiveData
    }

    fun getTaskLogin(): MutableLiveData<Boolean> {
        return taskLogin
    }

}
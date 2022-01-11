package com.esoft.accounting.fragments.loginFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class LoginViewModel(private val authRepository: AuthRepository) : ViewModel(){

    private val userLiveData = authRepository.getUserLiveData()
    private val taskLogin = authRepository.userTask()

    fun login(email: String, password: String) {
        authRepository.login(email = email, password = password)
    }

    fun getTaskLiveData(): LiveData<Boolean> {
        return taskLogin
    }

    fun getUserLiveData(): LiveData<FirebaseUser> {
        return userLiveData
    }


}
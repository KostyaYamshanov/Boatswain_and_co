package com.esoft.accounting.fragments.loginFragment

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.MutableLiveData
import com.esoft.accounting.data.AuthRepository
import com.google.firebase.auth.FirebaseUser

class LoginViewModel(application: Application) : AndroidViewModel(application) {

    private var authRepository: AuthRepository = AuthRepository(application)
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
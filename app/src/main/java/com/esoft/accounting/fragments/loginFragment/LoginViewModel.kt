package com.esoft.accounting.fragments.loginFragment

import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository

class LoginViewModel(private val authRepository: AuthRepository) : ViewModel(){

    val userLiveData = authRepository.getUserLiveData()
    val taskLogin = authRepository.getTaskLogin()

    fun login(email: String, password: String) {
        authRepository.login(email = email, password = password)
    }


}
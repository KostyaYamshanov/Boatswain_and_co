package com.esoft.accounting.presentation.loginFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.GetUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.LoginByEmailUseCase
import com.google.firebase.auth.FirebaseUser

class LoginViewModel(
    private val loginByEmailUseCase: LoginByEmailUseCase,
    getUserLiveDataUseCase: GetUserLiveDataUseCase,
    getTaskUserLiveDataUseCase: GetTaskUserLiveDataUseCase
    ) : ViewModel(){

    private val userLiveData = getUserLiveDataUseCase.getUserLiveData()
    private val taskLogin = getTaskUserLiveDataUseCase.getTaskLiveData()

    fun login(email: String, password: String) {
        loginByEmailUseCase.login(email = email, password = password)
    }

    fun getTaskLiveData(): LiveData<Boolean> {
        return taskLogin
    }

    fun getUserLiveData(): LiveData<FirebaseUser> {
        return userLiveData
    }


}
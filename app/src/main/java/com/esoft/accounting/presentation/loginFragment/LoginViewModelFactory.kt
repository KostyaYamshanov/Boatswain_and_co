package com.esoft.accounting.presentation.loginFragment

import android.app.Application
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.app.LabBpmApp
import com.esoft.accounting.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.GetUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.LoginByEmailUseCase

class LoginViewModelFactory(application: Application): ViewModelProvider.Factory {

    private val repository = (application as LabBpmApp).authRepository

    private val getTaskUserLiveDataUseCase = GetTaskUserLiveDataUseCase(repository)
    private val getUserLiveDataUseCase = GetUserLiveDataUseCase(repository)
    private val loginByEmailUseCase = LoginByEmailUseCase(repository)

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return LoginViewModel(
            getUserLiveDataUseCase = getUserLiveDataUseCase,
            getTaskUserLiveDataUseCase = getTaskUserLiveDataUseCase,
            loginByEmailUseCase = loginByEmailUseCase
        ) as T
    }
}
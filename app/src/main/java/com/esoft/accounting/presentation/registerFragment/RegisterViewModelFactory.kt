package com.esoft.accounting.presentation.registerFragment

import android.app.Application
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.app.LabBpmApp
import com.esoft.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.domain.usecase.RegisterByEmailUseCase

class RegisterViewModelFactory(application: Application): ViewModelProvider.Factory {

    private val repository = (application as LabBpmApp).authRepository!!

    private val registerByEmailUseCase = RegisterByEmailUseCase(repository)
    private val getTaskUserLiveDataUseCase = GetTaskUserLiveDataUseCase(repository)

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return RegisterViewModel(
            registerByEmailUseCase = registerByEmailUseCase,
            getTaskUserLiveDataUseCase = getTaskUserLiveDataUseCase
        ) as T
    }
}
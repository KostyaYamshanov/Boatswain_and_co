package com.esoft.accounting.presentation.registerFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepositoryDataSourceImpl
import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.RegisterByEmailUseCase

class RegisterViewModel(
    private val registerByEmailUseCase: RegisterByEmailUseCase,
    getTaskUserLiveDataUseCase: GetTaskUserLiveDataUseCase
) : ViewModel() {

    private val taskRegister = getTaskUserLiveDataUseCase.getTaskLiveData()

    fun register(email: String, password: String) {
        registerByEmailUseCase.register(email = email, password = password)
    }

    fun getTaskLiveData(): LiveData<Boolean> {
        return taskRegister
    }


}
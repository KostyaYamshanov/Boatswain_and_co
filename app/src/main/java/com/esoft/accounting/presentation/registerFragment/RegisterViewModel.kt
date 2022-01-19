package com.esoft.accounting.presentation.registerFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.esoft.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.domain.usecase.RegisterByEmailUseCase

class RegisterViewModel(
    private val registerByEmailUseCase: RegisterByEmailUseCase,
    getTaskUserLiveDataUseCase: GetTaskUserLiveDataUseCase
) : ViewModel() {

    private val taskRegister = getTaskUserLiveDataUseCase.getTaskLiveData()

    fun register(email: String, password: String, name: String, female: String) {
        registerByEmailUseCase.register(email = email, password = password, name = name, female = female)
    }

    fun getTaskLiveData(): LiveData<Boolean> {
        return taskRegister
    }


}
package com.esoft.accounting.presentation.dialogFragments

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.ResetPasswordUseCase

class ResetPasswordDialogViewModel(
    private val resetPasswordUseCase: ResetPasswordUseCase,
    getTaskUserLiveDataUseCase: GetTaskUserLiveDataUseCase
): ViewModel() {

    private val taskResetLiveData = getTaskUserLiveDataUseCase.getTaskLiveData()

    fun resetPassword(email: String) {
        resetPasswordUseCase.resetPassword(email = email)
    }

    fun getTaskLiveData(): LiveData<Boolean> {
        return taskResetLiveData
    }

}
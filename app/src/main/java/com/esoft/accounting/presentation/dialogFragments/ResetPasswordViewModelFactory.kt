package com.esoft.accounting.presentation.dialogFragments

import android.app.Application
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.app.LabBpmApp
import com.esoft.accounting.domain.usecase.GetTaskUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.ResetPasswordUseCase

class ResetPasswordViewModelFactory(application: Application): ViewModelProvider.Factory {

    private val repository = (application as LabBpmApp).authRepository!!

    private val resetPasswordUseCase = ResetPasswordUseCase(repository)
    private val getTaskUserLiveDataUseCase = GetTaskUserLiveDataUseCase(repository)


    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return ResetPasswordDialogViewModel(
            resetPasswordUseCase = resetPasswordUseCase,
            getTaskUserLiveDataUseCase = getTaskUserLiveDataUseCase
        ) as T
    }
}
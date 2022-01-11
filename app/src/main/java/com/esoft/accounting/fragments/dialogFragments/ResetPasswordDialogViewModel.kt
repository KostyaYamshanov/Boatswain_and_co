package com.esoft.accounting.fragments.dialogFragments

import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository

class ResetPasswordDialogViewModel(private val authRepository: AuthRepository): ViewModel() {

    val taskResetLiveData = authRepository.userTask()

    fun resetPassword(email: String) {
        authRepository.resetPassword(email = email)
    }

}
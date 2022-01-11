package com.esoft.accounting.fragments.dialogFragments

import android.app.Activity
import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.data.AuthRepository

class ResetPasswordDialogViewModel(private val authRepository: AuthRepository): ViewModel() {

    fun resetPassword(email: String) {
        authRepository.resetPassword(email = email)
    }

    fun getTaskReset(): MutableLiveData<Boolean> {
      return authRepository.getResetTask()
    }

}
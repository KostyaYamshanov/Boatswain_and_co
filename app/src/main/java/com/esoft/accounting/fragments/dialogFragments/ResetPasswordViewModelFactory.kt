package com.esoft.accounting.fragments.dialogFragments

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.data.AuthRepository

class ResetPasswordViewModelFactory(val context: Context): ViewModelProvider.Factory {

    private val authRepository = AuthRepository(context = context)

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return ResetPasswordDialogViewModel(authRepository = authRepository) as T
    }
}
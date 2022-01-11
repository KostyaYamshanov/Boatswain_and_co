package com.esoft.accounting.fragments.loginFragment

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.data.AuthRepository

class LoginViewModelFactory(val context: Context): ViewModelProvider.Factory {

    private var authRepository: AuthRepository = AuthRepository(context = context)

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return LoginViewModel(authRepository = authRepository) as T
    }
}
package com.esoft.accounting.presentation.listFragment

import android.app.Application
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.app.LabBpmApp
import com.esoft.accounting.domain.usecase.GetUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.LogOutUserUseCase

class ListFragmentViewModelFactory(private val application: Application): ViewModelProvider.Factory {

    private val repository = (application as LabBpmApp).authRepository

    private val logOutUserUseCase = LogOutUserUseCase(repository)
    private val getUserLiveDataUseCase = GetUserLiveDataUseCase(repository)

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return ListFragmentViewModel(
            logOutUserUseCase = logOutUserUseCase,
            getUserLiveDataUseCase = getUserLiveDataUseCase
        ) as T
    }
}
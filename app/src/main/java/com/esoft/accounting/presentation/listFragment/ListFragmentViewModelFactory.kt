package com.esoft.accounting.presentation.listFragment

import android.app.Application
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.esoft.accounting.app.LabBpmApp
import com.esoft.domain.usecase.GetUserProfileUseCase
import com.esoft.domain.usecase.LogOutUserUseCase

class ListFragmentViewModelFactory(private val application: Application): ViewModelProvider.Factory {

    private val repository = (application as LabBpmApp).authRepository!!
    private val usersRepository = (application as LabBpmApp).usersRepository!!

    private val logOutUserUseCase = LogOutUserUseCase(repository)
    private val getUserProfileUseCase = GetUserProfileUseCase(usersRepository = usersRepository)

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return ListFragmentViewModel(
            logOutUserUseCase = logOutUserUseCase,
            getUserProfileUseCase = getUserProfileUseCase
        ) as T
    }
}
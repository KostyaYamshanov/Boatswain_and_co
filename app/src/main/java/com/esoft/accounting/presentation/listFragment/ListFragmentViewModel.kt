package com.esoft.accounting.presentation.listFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.ViewModel
import com.esoft.domain.usecase.GetUserProfileUseCase
import com.esoft.domain.usecase.LogOutUserUseCase

class ListFragmentViewModel(
    private val logOutUserUseCase: LogOutUserUseCase,
    private val getUserProfileUseCase: GetUserProfileUseCase
): ViewModel() {


    fun logOut() = logOutUserUseCase.logOut()

    fun getLoggedOutLiveData(): LiveData<Boolean> = logOutUserUseCase.getLoggedOutLiveData()

    fun getUserProfile() = getUserProfileUseCase.getUserLiveData()
}
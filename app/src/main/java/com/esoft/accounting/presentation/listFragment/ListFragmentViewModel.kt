package com.esoft.accounting.presentation.listFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.repository.User
import com.esoft.accounting.domain.usecase.GetUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.GetUserProfileUseCase
import com.esoft.accounting.domain.usecase.LogOutUserUseCase
import com.google.firebase.auth.FirebaseUser

class ListFragmentViewModel(
    private val logOutUserUseCase: LogOutUserUseCase,
    private val getUserProfileUseCase: GetUserProfileUseCase
): ViewModel() {

    fun logOut() = logOutUserUseCase.logOut()

    fun getLoggedOutLiveData(): LiveData<Boolean> = logOutUserUseCase.getLoggedOutLiveData()

    fun getUserProfile(): LiveData<User> = getUserProfileUseCase.getUserLiveData()

}
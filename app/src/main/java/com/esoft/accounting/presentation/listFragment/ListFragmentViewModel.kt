package com.esoft.accounting.presentation.listFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.usecase.GetUserLiveDataUseCase
import com.esoft.accounting.domain.usecase.LogOutUserUseCase
import com.google.firebase.auth.FirebaseUser

class ListFragmentViewModel(
    private val logOutUserUseCase: LogOutUserUseCase,
    private val getUserLiveDataUseCase: GetUserLiveDataUseCase
): ViewModel() {

    fun logOut() = logOutUserUseCase.logOut()

    fun getLoggedOutLiveData(): LiveData<Boolean> = logOutUserUseCase.getLoggedOutLiveData()

    fun getUserLiveData(): LiveData<FirebaseUser> = getUserLiveDataUseCase.getUserLiveData()

}
package com.esoft.accounting.presentation.listFragment

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.repository.UserModel
import com.esoft.accounting.domain.usecase.GetUserProfileUseCase
import com.esoft.accounting.domain.usecase.LogOutUserUseCase
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.schedulers.Schedulers

class ListFragmentViewModel(
    private val logOutUserUseCase: LogOutUserUseCase,
    private val getUserProfileUseCase: GetUserProfileUseCase
): ViewModel() {

    val userLiveData = MutableLiveData<UserModel>()
    private val compositeDisposable = CompositeDisposable()

    fun logOut() = logOutUserUseCase.logOut()
    fun getLoggedOutLiveData(): LiveData<Boolean> = logOutUserUseCase.getLoggedOutLiveData()

    fun getUserProfile() {
        val dispose = getUserProfileUseCase.getUser()
            .subscribeOn(Schedulers.newThread())
            .subscribe {
                userLiveData.value = it
            }
        compositeDisposable.add(dispose)
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }
}
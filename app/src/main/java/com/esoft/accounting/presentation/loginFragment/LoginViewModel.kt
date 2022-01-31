package com.esoft.accounting.presentation.loginFragment

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.domain.usecase.IsUserAuthenticated
import com.esoft.accounting.domain.usecase.LoginByEmailUseCase
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.schedulers.Schedulers

class LoginViewModel(
    private val loginByEmailUseCase: LoginByEmailUseCase,
    private val isUserAuthenticated: IsUserAuthenticated
) : ViewModel() {

    val authState = MutableLiveData<AuthState>()
    val userLiveData = MutableLiveData<Boolean>()
    private val compositeDisposable = CompositeDisposable()

    fun login(email: String, password: String) {
        val disposable = loginByEmailUseCase.login(email = email, password = password)
            .subscribeOn(Schedulers.newThread())
            .subscribe {
                authState.value = it
            }
        compositeDisposable.add(disposable)
    }

    fun getUser() {
        userLiveData.value = isUserAuthenticated.invoke()
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }


}
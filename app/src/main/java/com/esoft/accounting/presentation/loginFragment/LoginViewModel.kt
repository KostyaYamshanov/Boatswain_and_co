package com.esoft.accounting.presentation.loginFragment

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.domain.usecase.IsUserAuthenticated
import com.esoft.accounting.domain.usecase.LoginByEmailUseCase
import com.google.firebase.auth.FirebaseAuthException
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.rxkotlin.subscribeBy

class LoginViewModel(
    private val loginByEmailUseCase: LoginByEmailUseCase,
    private val isUserAuthenticated: IsUserAuthenticated
) : ViewModel() {

    val authState = MutableLiveData<AuthState>()
    val userLiveData = MutableLiveData<Boolean>()
    val errorCode = MutableLiveData<String>()
    private val compositeDisposable = CompositeDisposable()

    init {
        userLiveData.value = isUserAuthenticated.invoke()
    }

    fun login(email: String, password: String) {
        val disposable = loginByEmailUseCase.login(email = email, password = password)
            .observeOn(AndroidSchedulers.mainThread())
            .subscribeBy(
                onSuccess = {
                    this.authState.value = it
                },
                onError = {
                    val error = (it as FirebaseAuthException).errorCode
                    this.errorCode.value = error
                }
            )
        compositeDisposable.add(disposable)
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }
}
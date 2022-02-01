package com.esoft.accounting.presentation.registerFragment

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.domain.usecase.RegisterByEmailUseCase
import com.google.firebase.auth.FirebaseAuthException
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.rxkotlin.subscribeBy

class RegisterViewModel(
    private val registerByEmailUseCase: RegisterByEmailUseCase,
) : ViewModel() {

    val authState = MutableLiveData<AuthState>()
    val errorCode = MutableLiveData<String>()
    private val compositeDisposable = CompositeDisposable()

    fun register(email: String, password: String, name: String, surname: String) {
        val dispose = registerByEmailUseCase.registration(email = email, password = password, name = name, surname = surname)
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
        compositeDisposable.add(dispose)
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }
}
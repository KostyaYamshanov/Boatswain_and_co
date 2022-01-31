package com.esoft.accounting.presentation.registerFragment

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.domain.usecase.RegisterByEmailUseCase
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.schedulers.Schedulers

class RegisterViewModel(
    private val registerByEmailUseCase: RegisterByEmailUseCase,
) : ViewModel() {

    val authState = MutableLiveData<AuthState>()
    private val compositeDisposable = CompositeDisposable()

    fun register(email: String, password: String, name: String, female: String) {
        val dispose = registerByEmailUseCase.registration(email = email, password = password, name = name, female = female)
            .subscribeOn(Schedulers.newThread())
            .subscribe {
                authState.value = it
            }
        compositeDisposable.add(dispose)
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }
}
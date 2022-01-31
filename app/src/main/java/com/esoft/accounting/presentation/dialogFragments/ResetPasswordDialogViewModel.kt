package com.esoft.accounting.presentation.dialogFragments

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.usecase.ResetPasswordUseCase
import io.reactivex.disposables.CompositeDisposable

class ResetPasswordDialogViewModel(
    private val resetPasswordUseCase: ResetPasswordUseCase
): ViewModel() {

    val resetLiveData = MutableLiveData<Boolean>()
    private val compositeDisposable = CompositeDisposable()

    fun resetPassword(email: String) {
       val dispose =  resetPasswordUseCase.resetPassword(email = email)
           .subscribe {
               resetLiveData.value = it
           }
        compositeDisposable.add(dispose)
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }

}
package com.esoft.accounting.presentation.dialogFragments

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.usecase.ResetPasswordUseCase
import com.google.firebase.auth.FirebaseAuthException
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.rxkotlin.subscribeBy

class ResetPasswordDialogViewModel(
    private val resetPasswordUseCase: ResetPasswordUseCase
): ViewModel() {

    val resetLiveData = MutableLiveData<Boolean>()
    val errorCode = MutableLiveData<String>()
    private val compositeDisposable = CompositeDisposable()

    fun resetPassword(email: String) {
       val dispose =  resetPasswordUseCase.resetPassword(email = email)
           .observeOn(AndroidSchedulers.mainThread())
           .subscribeBy(
               onSuccess = {
                   this.resetLiveData.value = it
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
package com.esoft.accounting.presentation.newEntry

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.esoft.accounting.domain.usecase.GetAllCropsUseCase
import io.reactivex.android.schedulers.AndroidSchedulers
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.rxkotlin.subscribeBy
import io.reactivex.schedulers.Schedulers

class NewEntryViewModel(private val getAllCropsUseCase: GetAllCropsUseCase) : ViewModel() {


    val cropLiveData = MutableLiveData<List<String>>()
    val sortLiveData = MutableLiveData<List<String>>()
    private val compositeDisposable = CompositeDisposable()

    init {
        val dispose = getAllCropsUseCase.getAllCrop()
            .subscribeOn(Schedulers.io())
            .observeOn(AndroidSchedulers.mainThread())
            .subscribeBy(
                onSuccess = {
                    this.cropLiveData.value = it
                },
                onError = {

                }
            )

        compositeDisposable.add(dispose)
    }

    fun getSortByCrop(name: String) {
        val disposable = getAllCropsUseCase.getSortByCrop(name)
            .subscribeOn(Schedulers.io())
            .observeOn(AndroidSchedulers.mainThread())
            .subscribeBy(
                onSuccess = {
                    this.sortLiveData.value = it
                },
                onError = {

                }
            )
        compositeDisposable.add(disposable)
    }

    override fun onCleared() {
        super.onCleared()
        compositeDisposable.clear()
    }


}
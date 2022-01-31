package com.esoft.accounting.domain.repository

import io.reactivex.Observable

interface UsersRepository {

    fun getUserLiveData(): Observable<UserModel>

}
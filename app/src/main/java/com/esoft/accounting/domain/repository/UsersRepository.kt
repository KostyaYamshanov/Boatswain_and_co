package com.esoft.accounting.domain.repository

import io.reactivex.Observable

interface UsersRepository {

    fun getUserInfo(): Observable<UserModel>

}
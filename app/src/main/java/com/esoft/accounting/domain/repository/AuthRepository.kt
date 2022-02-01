package com.esoft.accounting.domain.repository

import io.reactivex.Observable
import io.reactivex.Single

interface AuthRepository {

    fun login(email: String, password: String): Single<AuthState>

    fun registration(email: String, password: String, name: String, surname: String): Single<AuthState>

    fun resetPassword(email: String): Single<Boolean>

    fun logOut()

    fun isUserAuthenticated(): Boolean
}
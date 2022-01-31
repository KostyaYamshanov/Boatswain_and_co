package com.esoft.accounting.domain.repository

import io.reactivex.Observable

interface AuthRepository {

    fun login(email: String, password: String): Observable<AuthState>

    fun registration(email: String, password: String, name: String, surname: String): Observable<AuthState>

    fun resetPassword(email: String): Observable<Boolean>

    fun logOut()

    fun isUserAuthenticated(): Boolean
}
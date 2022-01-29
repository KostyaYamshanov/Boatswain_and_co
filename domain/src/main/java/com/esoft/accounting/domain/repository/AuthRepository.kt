package com.esoft.accounting.domain.repository

import androidx.lifecycle.MutableLiveData
import com.google.firebase.auth.FirebaseUser

interface AuthRepository {

    fun login(email: String, password: String)

    fun registration(email: String, password: String, name: String, surname: String)

    fun resetPassword(email: String)

    fun logOut()

    fun getUserLiveData(): MutableLiveData<FirebaseUser>

    fun userTask(): MutableLiveData<Boolean>

    fun getLoggedOutLiveData(): MutableLiveData<Boolean>

}
package com.esoft.accounting.data.repository

import androidx.lifecycle.MutableLiveData
import com.esoft.accounting.data.AuthRepositoryDataSource
import com.esoft.accounting.domain.repository.AuthRepository
import com.google.firebase.auth.FirebaseUser

class AuthRepositoryImp(private val authRepositoryDataSource: AuthRepositoryDataSource): AuthRepository {

    override fun login(email: String, password: String)  =
        authRepositoryDataSource.login(email = email, password = password)

    override fun registration(email: String, password: String, name: String, female: String) =
        authRepositoryDataSource.registration(email = email, password = password, name = name, female = female)

    override fun resetPassword(email: String) =
        authRepositoryDataSource.resetPassword(email = email)

    override fun logOut()  =
        authRepositoryDataSource.logOut()

    override fun getUserLiveData(): MutableLiveData<FirebaseUser>  =
        authRepositoryDataSource.getUserLiveData()

    override fun userTask(): MutableLiveData<Boolean> =
        authRepositoryDataSource.userTask()

    override fun getLoggedOutLiveData(): MutableLiveData<Boolean> =
        authRepositoryDataSource.getLoggedOutLiveData()


}
package com.esoft.data.repository

import androidx.lifecycle.MutableLiveData
import com.esoft.data.dataSource.AuthRepositoryDataSource
import com.esoft.domain.repository.AuthRepository
import com.google.firebase.auth.FirebaseUser

class AuthRepositoryImp(private val authRepositoryDataSource: AuthRepositoryDataSource):
    AuthRepository {

    override fun login(email: String, password: String)  =
        authRepositoryDataSource.login(email = email, password = password)

    override fun registration(email: String, password: String, name: String, surname: String) =
        authRepositoryDataSource.registration(email = email, password = password, name = name, surname = surname)

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
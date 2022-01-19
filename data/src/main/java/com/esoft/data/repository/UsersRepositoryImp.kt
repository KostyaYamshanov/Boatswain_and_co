package com.esoft.data.repository

import androidx.lifecycle.MutableLiveData
import com.esoft.data.UsersRepositoryDataSource
import com.esoft.domain.repository.UserModel
import com.esoft.domain.repository.UsersRepository

class UsersRepositoryImp(private val usersRepositoryDataSource: UsersRepositoryDataSource):
    UsersRepository {


    override fun getUserProfile(): MutableLiveData<UserModel> {
        val mutableLiveData = MutableLiveData<UserModel>()
        usersRepositoryDataSource.getUserProfile().observeForever {
            val userModel = UserModel(
                email = it.email,
                name = it.name,
                surname = it.surname,
                photoUri = it.photoUri
            )
            mutableLiveData.postValue(userModel)
        }
        return mutableLiveData
    }

}
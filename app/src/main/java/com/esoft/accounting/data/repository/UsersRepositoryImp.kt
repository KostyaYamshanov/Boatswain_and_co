package com.esoft.accounting.data.repository

import androidx.lifecycle.MutableLiveData
import com.esoft.accounting.data.UsersRepositoryDataSource
import com.esoft.accounting.domain.repository.User
import com.esoft.accounting.domain.repository.UsersRepository

class UsersRepositoryImp(private val usersRepositoryDataSource: UsersRepositoryDataSource): UsersRepository {

    override fun getUserProfile(): MutableLiveData<User> =
        usersRepositoryDataSource.getUserProfile()
}
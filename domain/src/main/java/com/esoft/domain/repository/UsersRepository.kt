package com.esoft.domain.repository

import androidx.lifecycle.MutableLiveData

interface UsersRepository {

    fun getUserProfile(): MutableLiveData<UserModel>

}
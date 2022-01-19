package com.esoft.accounting.domain.repository

import androidx.lifecycle.MutableLiveData

interface UsersRepository {

    fun getUserProfile(): MutableLiveData<User>

}
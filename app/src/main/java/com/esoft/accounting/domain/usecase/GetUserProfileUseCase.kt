package com.esoft.accounting.domain.usecase

import androidx.lifecycle.MutableLiveData
import com.esoft.accounting.domain.repository.User
import com.esoft.accounting.domain.repository.UsersRepository

class GetUserProfileUseCase(private val usersRepository: UsersRepository) {

    fun getUserLiveData(): MutableLiveData<User> =
        usersRepository.getUserProfile()

}
package com.esoft.domain.usecase

import androidx.lifecycle.MutableLiveData
import com.esoft.domain.repository.UserModel
import com.esoft.domain.repository.UsersRepository

class GetUserProfileUseCase(private val usersRepository: UsersRepository) {

    fun getUserLiveData(): MutableLiveData<UserModel> =
        usersRepository.getUserProfile()

}
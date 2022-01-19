package com.esoft.domain.usecase

import com.esoft.domain.repository.AuthRepository

class LogOutUserUseCase(private val authRepository: AuthRepository) {

    fun logOut() = authRepository.logOut()

    fun getLoggedOutLiveData() = authRepository.getLoggedOutLiveData()

}
package com.esoft.domain.usecase

import com.esoft.domain.repository.AuthRepository

class GetUserLiveDataUseCase(private val authRepository: AuthRepository) {

    fun getUserLiveData() = authRepository.getUserLiveData()

}
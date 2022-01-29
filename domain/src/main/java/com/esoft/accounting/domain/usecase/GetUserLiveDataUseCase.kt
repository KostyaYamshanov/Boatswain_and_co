package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class GetUserLiveDataUseCase(private val authRepository: AuthRepository) {

    fun getUserLiveData() = authRepository.getUserLiveData()

}
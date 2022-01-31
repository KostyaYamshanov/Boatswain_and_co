package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class LogOutUserUseCase(private val authRepository: AuthRepository) {

    fun logOut() = authRepository.logOut()

}
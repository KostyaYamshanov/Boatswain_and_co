package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class LoginByEmailUseCase(private val authRepository: AuthRepository) {

    fun login(email: String, password: String) =
        authRepository.login(email = email, password = password)

}
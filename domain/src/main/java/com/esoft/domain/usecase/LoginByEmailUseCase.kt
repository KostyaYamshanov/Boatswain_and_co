package com.esoft.domain.usecase

import com.esoft.domain.repository.AuthRepository

class LoginByEmailUseCase(private val authRepository: AuthRepository) {

    fun login(email: String, password: String) = authRepository.login(email = email, password = password)

}
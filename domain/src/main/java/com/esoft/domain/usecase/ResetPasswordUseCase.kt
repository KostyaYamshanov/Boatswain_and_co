package com.esoft.domain.usecase

import com.esoft.domain.repository.AuthRepository

class ResetPasswordUseCase(private val authRepository: AuthRepository) {

    fun resetPassword(email: String) = authRepository.resetPassword(email = email)

}
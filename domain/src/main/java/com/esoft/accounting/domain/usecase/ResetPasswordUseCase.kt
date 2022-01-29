package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class ResetPasswordUseCase(private val authRepository: AuthRepository) {

    fun resetPassword(email: String) = authRepository.resetPassword(email = email)

}
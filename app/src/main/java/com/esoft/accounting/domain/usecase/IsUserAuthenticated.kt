package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class IsUserAuthenticated(private val authRepository: AuthRepository) {

    fun invoke() = authRepository.isUserAuthenticated()

}
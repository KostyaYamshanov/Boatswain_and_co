package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class RegisterByEmailUseCase(private val authRepository: AuthRepository) {

    fun registration(email: String, password: String, name: String, surname: String) =
        authRepository.registration(email = email, password = password, name = name, surname = surname)

}
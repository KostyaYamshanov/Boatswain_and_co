package com.esoft.domain.usecase

import com.esoft.domain.repository.AuthRepository

class RegisterByEmailUseCase(private val authRepository: AuthRepository) {

    fun register(email: String, password: String, name: String, female: String) =
        authRepository.registration(email = email, password = password, name = name, surname = female)

}
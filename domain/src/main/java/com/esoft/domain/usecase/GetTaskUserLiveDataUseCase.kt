package com.esoft.domain.usecase

import com.esoft.domain.repository.AuthRepository

class GetTaskUserLiveDataUseCase(private val authRepository: AuthRepository) {

    fun getTaskLiveData() = authRepository.userTask()

}
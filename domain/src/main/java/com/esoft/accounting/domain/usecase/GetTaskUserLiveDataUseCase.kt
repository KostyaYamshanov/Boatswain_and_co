package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.AuthRepository

class GetTaskUserLiveDataUseCase(private val authRepository: AuthRepository) {

    fun getTaskLiveData() = authRepository.userTask()

}
package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.UserModel
import com.esoft.accounting.domain.repository.UsersRepository
import io.reactivex.Observable

class GetUserProfileUseCase(private val usersRepository: UsersRepository) {

    fun getUser(): Observable<UserModel> =
        usersRepository.getUserInfo()

}
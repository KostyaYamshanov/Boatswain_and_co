package com.esoft.accounting.di

import com.esoft.data.repository.AuthRepositoryImp
import com.esoft.data.repository.UsersRepositoryImp
import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.repository.UsersRepository
import org.koin.dsl.module


val dataModule = module {

    single<AuthRepository> {
        AuthRepositoryImp()
    }

    single<UsersRepository> {
        UsersRepositoryImp()
    }
}
package com.esoft.accounting.di

import com.esoft.data.UsersRepositoryDataSource
import com.esoft.data.UsersRepositoryDataSourceImp
import com.esoft.data.dataSource.AuthRepositoryDataSource
import com.esoft.data.dataSource.AuthRepositoryDataSourceImpl
import com.esoft.data.repository.AuthRepositoryImp
import com.esoft.data.repository.UsersRepositoryImp
import com.esoft.domain.repository.AuthRepository
import com.esoft.domain.repository.UsersRepository
import org.koin.dsl.module


val dataModule = module {

    single<AuthRepositoryDataSource> {
        AuthRepositoryDataSourceImpl()
    }

    single<AuthRepository> {
        AuthRepositoryImp(authRepositoryDataSource = get())
    }

    single <UsersRepositoryDataSource> {
        UsersRepositoryDataSourceImp()
    }

    single<UsersRepository> {
        UsersRepositoryImp(usersRepositoryDataSource = get())
    }

}
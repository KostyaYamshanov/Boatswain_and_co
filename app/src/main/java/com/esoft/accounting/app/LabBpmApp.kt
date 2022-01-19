package com.esoft.accounting.app

import android.app.Application
import com.esoft.data.dataSource.AuthRepositoryDataSourceImpl
import com.esoft.data.UsersRepositoryDataSourceImp
import com.esoft.data.repository.AuthRepositoryImp
import com.esoft.data.repository.UsersRepositoryImp
import com.esoft.domain.repository.AuthRepository
import com.esoft.domain.repository.UsersRepository

class LabBpmApp: Application() {

    var authRepository: AuthRepository? = null
    var usersRepository: UsersRepository? = null

    override fun onCreate() {
        super.onCreate()
        authRepository = AuthRepositoryImp(AuthRepositoryDataSourceImpl())
        usersRepository = UsersRepositoryImp(UsersRepositoryDataSourceImp())

    }

}
package com.esoft.accounting.app

import android.app.Application
import com.esoft.accounting.data.AuthRepositoryDataSourceImpl
import com.esoft.accounting.data.UsersRepositoryDataSourceImp
import com.esoft.accounting.data.repository.AuthRepositoryImp
import com.esoft.accounting.data.repository.UsersRepositoryImp
import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.repository.UsersRepository

class LabBpmApp: Application() {

    var authRepository: AuthRepository? = null
    var usersRepository: UsersRepository? = null

    override fun onCreate() {
        super.onCreate()
        authRepository = AuthRepositoryImp(AuthRepositoryDataSourceImpl())
        usersRepository = UsersRepositoryImp(UsersRepositoryDataSourceImp())

    }

}
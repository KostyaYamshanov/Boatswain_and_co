package com.esoft.accounting.app

import android.app.Application
import com.esoft.accounting.data.AuthRepositoryDataSourceImpl
import com.esoft.accounting.data.repository.AuthRepositoryImp
import com.esoft.accounting.domain.repository.AuthRepository

class LabBpmApp: Application() {

    lateinit var authRepository: AuthRepository

    override fun onCreate() {
        super.onCreate()
        authRepository = AuthRepositoryImp(AuthRepositoryDataSourceImpl())
    }

}
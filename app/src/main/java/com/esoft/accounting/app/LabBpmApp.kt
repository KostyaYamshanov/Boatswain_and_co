package com.esoft.accounting.app

import android.app.Application
import com.esoft.accounting.di.appModule
import com.esoft.accounting.di.dataModule
import com.esoft.accounting.di.domainModule
import org.koin.android.ext.koin.androidLogger
import org.koin.core.context.startKoin
import org.koin.core.logger.Level

class LabBpmApp: Application() {

    override fun onCreate() {
        super.onCreate()

        startKoin {
            androidLogger(Level.DEBUG)
            modules(listOf(appModule, domainModule, dataModule))
        }

    }

}
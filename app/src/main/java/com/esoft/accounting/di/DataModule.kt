package com.esoft.accounting.di

import com.esoft.accounting.data.repository.AuthRepositoryImp
import com.esoft.accounting.data.repository.CropRepositoryImp
import com.esoft.accounting.data.repository.UsersRepositoryImp
import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.repository.CropRepository
import com.esoft.accounting.domain.repository.UsersRepository
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.FirebaseDatabase
import org.koin.dsl.module

val dataModule = module {

    single<AuthRepository> {
        AuthRepositoryImp(
            firebaseDataBase = FirebaseDatabase.getInstance(),
            auth = FirebaseAuth.getInstance()
        )
    }

    single<UsersRepository> {
        UsersRepositoryImp(
            firebaseAuth = FirebaseAuth.getInstance(),
            firebaseDatabase = FirebaseDatabase.getInstance()
        )
    }

    single<CropRepository> {
        CropRepositoryImp(
            firebaseDatabase = FirebaseDatabase.getInstance()
        )
    }

}
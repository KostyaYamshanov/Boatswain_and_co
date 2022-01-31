package com.esoft.accounting.di

import com.esoft.accounting.domain.usecase.*
import org.koin.dsl.module

val domainModule = module {

    factory<LoginByEmailUseCase> {
        LoginByEmailUseCase(authRepository = get())
    }

    factory<RegisterByEmailUseCase> {
        RegisterByEmailUseCase(authRepository = get())
    }

    factory<LogOutUserUseCase> {
        LogOutUserUseCase(authRepository = get())
    }

    factory<GetUserProfileUseCase> {
        GetUserProfileUseCase(usersRepository = get())
    }

    factory<ResetPasswordUseCase> {
        ResetPasswordUseCase(authRepository = get())
    }

    factory<IsUserAuthenticated>{
        IsUserAuthenticated(authRepository = get())
    }
}
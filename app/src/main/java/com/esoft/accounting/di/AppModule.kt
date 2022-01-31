package com.esoft.accounting.di

import com.esoft.accounting.presentation.dialogFragments.ResetPasswordDialogViewModel
import com.esoft.accounting.presentation.listFragment.ListFragmentViewModel
import com.esoft.accounting.presentation.loginFragment.LoginViewModel
import com.esoft.accounting.presentation.registerFragment.RegisterViewModel
import org.koin.androidx.viewmodel.dsl.viewModel
import org.koin.dsl.module

val appModule = module {

    viewModel<LoginViewModel> {
        LoginViewModel(
            loginByEmailUseCase = get(),
            isUserAuthenticated = get()
        )
    }

    viewModel<RegisterViewModel> {
        RegisterViewModel(
            registerByEmailUseCase = get()
        )
    }

    viewModel<ResetPasswordDialogViewModel> {
        ResetPasswordDialogViewModel(
            resetPasswordUseCase = get()
        )
    }

    viewModel<ListFragmentViewModel> {
        ListFragmentViewModel(
            getUserProfileUseCase = get(),
            logOutUserUseCase =  get()
        )
    }

}
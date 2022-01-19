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
            getUserLiveDataUseCase = get(),
            getTaskUserLiveDataUseCase = get(),
            loginByEmailUseCase = get()
        )
    }

    viewModel<RegisterViewModel> {
        RegisterViewModel(
            getTaskUserLiveDataUseCase = get(),
            registerByEmailUseCase = get()
        )
    }

    viewModel<ResetPasswordDialogViewModel> {
        ResetPasswordDialogViewModel(
            resetPasswordUseCase = get(),
            getTaskUserLiveDataUseCase = get()
        )
    }

    viewModel<ListFragmentViewModel> {
        ListFragmentViewModel(
            getUserProfileUseCase = get(),
            logOutUserUseCase =  get()
        )
    }

}
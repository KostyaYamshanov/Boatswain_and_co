package com.esoft.accounting.domain.repository

data class AuthState (
    val auth: Boolean = false,
    val error: String? = null
)
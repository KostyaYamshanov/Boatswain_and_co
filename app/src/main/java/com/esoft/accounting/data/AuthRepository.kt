package com.esoft.accounting.data

import android.annotation.SuppressLint
import android.app.Activity
import android.app.Application
import android.content.Context
import android.os.Build
import android.util.Log
import android.widget.Toast
import androidx.annotation.RequiresApi
import androidx.lifecycle.MutableLiveData
import com.google.android.gms.tasks.OnCompleteListener
import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import kotlin.properties.Delegates
import androidx.annotation.NonNull
import com.esoft.accounting.model.Users


class AuthRepository(val context: Context) {

    private var firebaseAuth: FirebaseAuth = FirebaseAuth.getInstance()
    private val userLiveData = MutableLiveData<FirebaseUser>()
    private val loggedOutLiveData = MutableLiveData<Boolean>()
    private val taskRegister = MutableLiveData<Boolean>()
    private val taskLogin = MutableLiveData<Boolean>()
    private val taskReset = MutableLiveData<Boolean>()
    private lateinit var user: Users

    init {
        if (firebaseAuth.currentUser != null) {
            userLiveData.postValue(firebaseAuth.currentUser)
            loggedOutLiveData.postValue(false)
        }
    }

    @SuppressLint("NewApi")
    fun login(email: String, password: String) {
        firebaseAuth.signInWithEmailAndPassword(email, password)
            .addOnCompleteListener( OnCompleteListener<AuthResult?> { task ->
                    if (task.isSuccessful) {
                        // Sign in success, update UI with the signed-in user's information
                        val user = firebaseAuth.currentUser
                        userLiveData.postValue(user)
                        if (user!!.isEmailVerified) {
                            taskLogin.postValue(true)
                        }else {
                            Toast.makeText(
                                context,
                                "Подтвердите почту",
                                Toast.LENGTH_SHORT
                            ).show();
                            Log.d("AuthRepository", "fun login: Пользователь не подтвердил почту")
                        }
                        Log.d("AuthRepository", "fun login: true")
                    } else {
                        // If sign in fails, display a message to the user.
                        Toast.makeText(
                            context,
                            "Ошибка входа",
                            Toast.LENGTH_SHORT
                        ).show();
                        taskLogin.postValue(false)
                        Log.d("AuthRepository", "fun login: false")
                    }

                    // ...
                })
    }

    @SuppressLint("NewApi")
    fun registration(email: String, password: String) {
        firebaseAuth!!.createUserWithEmailAndPassword(email, password)
            .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                    if (task.isSuccessful) {
                        // Sign in success, update UI with the signed-in user's information
                        val user = firebaseAuth.currentUser
                        userLiveData.postValue(user)
                        user!!.sendEmailVerification()
                            .addOnCompleteListener { task ->
                                if (task.isSuccessful) {
                                    taskRegister.postValue(true)
                                }
                            }
                        Log.d("AuthRepository", "fun register: true")
                    } else {
                        // If sign in fails, display a message to the user.
                        Toast.makeText(
                            context,
                            "Ошибка регистрации",
                            Toast.LENGTH_SHORT
                        ).show()
                        taskRegister.postValue(false)
                        Log.d("AuthRepository", "fun register: false")
                    }

                    // ...
                })

    }

    fun resetPassword(email: String) {
       if (firebaseAuth.currentUser != null && firebaseAuth.currentUser!!.email == email ) {
            firebaseAuth.sendPasswordResetEmail(email)
            taskReset.postValue(true)
        }else{
            taskReset.postValue(false)
        }
    }

    fun logOut() {
        firebaseAuth.signOut()
        loggedOutLiveData!!.postValue(true)
    }

    fun getResetTask(): MutableLiveData<Boolean>  {
        return taskReset
    }

    fun getUserLiveData(): MutableLiveData<FirebaseUser> {
        return userLiveData
    }

    fun getTaskRegister(): MutableLiveData<Boolean> {
        return taskRegister
    }

    fun getTaskLogin(): MutableLiveData<Boolean> {
        return taskLogin
    }

    fun getLoggedOutLiveData(): MutableLiveData<Boolean> {
        return loggedOutLiveData
    }
}
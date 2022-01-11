package com.esoft.accounting.data

import android.annotation.SuppressLint
import android.util.Log
import androidx.lifecycle.MutableLiveData
import com.google.android.gms.tasks.OnCompleteListener
import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser

interface AuthRepositoryDataSource {

    fun login(email: String, password: String)

    fun registration(email: String, password: String)

    fun resetPassword(email: String)

    fun logOut()

    fun getUserLiveData(): MutableLiveData<FirebaseUser>

    fun userTask(): MutableLiveData<Boolean>

}

class AuthRepositoryDataSourceImpl: AuthRepositoryDataSource {

    private var firebaseAuth: FirebaseAuth = FirebaseAuth.getInstance()
    private val userLiveData = MutableLiveData<FirebaseUser>()
    private val loggedOutLiveData = MutableLiveData<Boolean>()
    private val userTask = MutableLiveData<Boolean>()

    init {
        if (firebaseAuth.currentUser != null) {
            userLiveData.postValue(firebaseAuth.currentUser)
            loggedOutLiveData.postValue(false)
        }
    }

    @SuppressLint("NewApi")
    override fun login(email: String, password: String) {
        firebaseAuth.signInWithEmailAndPassword(email, password)
            .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                if (task.isSuccessful) {
                    // Sign in success, update UI with the signed-in user's information
                    val user = firebaseAuth.currentUser
                    userLiveData.postValue(user)
                    if (user!!.isEmailVerified) {
                        userTask.postValue(true)
                    } else {
                        Log.d("AuthRepository", "fun login: Пользователь не подтвердил почту")
                    }
                    Log.d("AuthRepository", "fun login: true")
                } else {
                    // If sign in fails, display a message to the user.
                    userTask.postValue(false)
                    Log.d("AuthRepository", "fun login: false")
                }

                // ...
            })
    }

    @SuppressLint("NewApi")
    override fun registration(email: String, password: String) {
        firebaseAuth!!.createUserWithEmailAndPassword(email, password)
            .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                if (task.isSuccessful) {
                    // Sign in success, update UI with the signed-in user's information
                    val user = firebaseAuth.currentUser
                    userLiveData.postValue(user)
                    user!!.sendEmailVerification()
                        .addOnCompleteListener { task ->
                            if (task.isSuccessful) {
                                userTask.postValue(true)
                            }
                        }
                    Log.d("AuthRepository", "fun register: true")
                } else {
                    // If sign in fails, display a message to the user.
                    userTask.postValue(false)
                    Log.d("AuthRepository", "fun register: false")
                }

                // ...
            })

    }

    override fun resetPassword(email: String) {
        if (firebaseAuth.currentUser != null && firebaseAuth.currentUser!!.email == email) {
            firebaseAuth.sendPasswordResetEmail(email)
            userTask.postValue(true)
        } else {
            userTask.postValue(false)
        }
    }

    override fun logOut() {
        firebaseAuth.signOut()
        loggedOutLiveData!!.postValue(true)
    }

    override fun userTask(): MutableLiveData<Boolean> {
        return userTask
    }

    override fun getUserLiveData(): MutableLiveData<FirebaseUser> {
        return userLiveData
    }

}
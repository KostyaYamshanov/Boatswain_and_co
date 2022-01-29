package com.esoft.data.repository

import android.util.Log
import androidx.lifecycle.MutableLiveData
import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.repository.UserModel
import com.google.android.gms.tasks.OnCompleteListener
import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseUser
import com.google.firebase.database.FirebaseDatabase

class AuthRepositoryImp: AuthRepository {

    private var firebaseAuth: FirebaseAuth = FirebaseAuth.getInstance()
    private val firebaseDataBase: FirebaseDatabase = FirebaseDatabase.getInstance()
    private val userLiveData = MutableLiveData<FirebaseUser>()
    private val loggedOutLiveData = MutableLiveData<Boolean>()
    private val userTask = MutableLiveData<Boolean>()

    init {
        if (firebaseAuth.currentUser != null) {
            userLiveData.postValue(firebaseAuth.currentUser)
            loggedOutLiveData.postValue(false)
        }
    }

    override fun login(email: String, password: String) {
        firebaseAuth.signInWithEmailAndPassword(email, password)
            .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                if (task.isSuccessful) {
                    // Sign in success, update UI with the signed-in user's information
                    val user = firebaseAuth.currentUser
                    if (user!!.isEmailVerified) {
                        userTask.postValue(true)
                        loggedOutLiveData.postValue(false)
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


    override fun registration(email: String, password: String, name: String, surname: String) {
        firebaseAuth!!.createUserWithEmailAndPassword(email, password)
            .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                if (task.isSuccessful) {
                    // Sign in success, update UI with the signed-in user's information
                    val user = firebaseAuth.currentUser
                    val userR = UserModel(email = user!!.email, name = name, surname = surname, photoUri = user.photoUrl!!)
                    firebaseDataBase.getReference("Users").child(user.uid).setValue(userR)
                    user.sendEmailVerification()
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
        loggedOutLiveData.postValue(true)
    }

    override fun getUserLiveData(): MutableLiveData<FirebaseUser> {
        return userLiveData
    }

    override fun userTask(): MutableLiveData<Boolean> {
        return userTask
    }

    override fun getLoggedOutLiveData(): MutableLiveData<Boolean> {
        return loggedOutLiveData
    }
}
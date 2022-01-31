package com.esoft.accounting.data.repository

import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.domain.repository.UserModel
import com.google.android.gms.tasks.OnCompleteListener
import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseAuthException
import com.google.firebase.database.FirebaseDatabase
import io.reactivex.Observable


class AuthRepositoryImp(
    private val auth: FirebaseAuth,
    private val firebaseDataBase: FirebaseDatabase
) : AuthRepository {

    override fun isUserAuthenticated(): Boolean =
        auth.currentUser != null && auth.currentUser!!.isEmailVerified

    override fun login(email: String, password: String): Observable<AuthState> {
        return Observable.create { subscriber ->
            auth.signInWithEmailAndPassword(email, password)
                .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                    if (task.isSuccessful) {
                        val user = auth.currentUser
                        if (user!!.isEmailVerified) {
                            val authState = AuthState(auth = true, error = null)
                            subscriber.onNext(authState)
                        }else {
                            val authState = AuthState(auth = false, error = "Email не подтвержден")
                            subscriber.onNext(authState)
                        }
                    } else {
                        val errorCode = (task.exception as FirebaseAuthException?)!!.errorCode
                        val authState = AuthState(auth = false, error = errorCode)
                        subscriber.onNext(authState)
                    }
                })
        }
    }


    override fun registration(
        email: String,
        password: String,
        name: String,
        surname: String
    ): Observable<AuthState> {
        return Observable.create { subscriber ->
            auth.createUserWithEmailAndPassword(email, password)
                .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                    if (task.isSuccessful) {
                        // Sign in success, update UI with the signed-in user's information
                        val user = auth.currentUser
                        val userR = UserModel(email = user!!.email, name = name, surname = surname)
                        firebaseDataBase.getReference("Users").child(user.uid).setValue(userR)
                        user.sendEmailVerification().addOnCompleteListener { task ->
                            if (task.isSuccessful) {
                                val authState = AuthState(auth = true, error = null)
                                subscriber.onNext(authState)
                            }
                            else {
                                val errorCode = (task.exception as FirebaseAuthException?)!!.errorCode
                                val authState = AuthState(auth = false, error = errorCode)
                                subscriber.onNext(authState)
                            }
                        }
                    } else {
                        val errorCode = (task.exception as FirebaseAuthException?)!!.errorCode
                        val authState = AuthState(auth = false, error = errorCode)
                        subscriber.onNext(authState)
                    }
                })
        }
    }

    override fun resetPassword(email: String): Observable<Boolean> {
        return Observable.create { subscriber ->
            if (auth.currentUser != null && auth.currentUser!!.email == email) {
                auth.sendPasswordResetEmail(email)
                subscriber.onNext(true)
            }
        }

    }

    override fun logOut() {
        auth.signOut()
    }

}
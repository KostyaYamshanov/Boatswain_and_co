package com.esoft.accounting.data.repository

import com.esoft.accounting.domain.repository.AuthRepository
import com.esoft.accounting.domain.repository.AuthState
import com.esoft.accounting.domain.repository.UserModel
import com.google.android.gms.tasks.OnCompleteListener
import com.google.firebase.auth.AuthResult
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.auth.FirebaseAuthException
import com.google.firebase.database.FirebaseDatabase
import io.reactivex.Single

class AuthRepositoryImp(
    private val auth: FirebaseAuth,
    private val firebaseDataBase: FirebaseDatabase
) : AuthRepository {

    override fun isUserAuthenticated(): Boolean =
        auth.currentUser != null && auth.currentUser!!.isEmailVerified

    override fun login(email: String, password: String): Single<AuthState> {
        return Single.create { subscriber ->
            auth.signInWithEmailAndPassword(email, password)
                .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                    if (task.isSuccessful) {
                        val user = auth.currentUser
                        if (user!!.isEmailVerified) {
                            val authState = AuthState(auth = true, error = null)
                            subscriber.onSuccess(authState)
                        }else {
                            val authState = AuthState(auth = false, error = null)
                            subscriber.onSuccess(authState)
                        }
                    } else {
                        subscriber.onError(task.exception as FirebaseAuthException)
                    }
                })
        }
    }


    override fun registration(email: String, password: String, name: String, surname: String): Single<AuthState> {
        return Single.create { subscriber ->
            auth.createUserWithEmailAndPassword(email, password)
                .addOnCompleteListener(OnCompleteListener<AuthResult?> { task ->
                    if (task.isSuccessful) {
                        // Sign in success, update UI with the signed-in user's information
                        val user = auth.currentUser
                        val userR = UserModel(email = user!!.email, name = name, surname = surname)
                        firebaseDataBase.getReference("Users").child(user.uid).setValue(userR)
                        user.sendEmailVerification()
                        val authState = AuthState(auth = true, error = null)
                        subscriber.onSuccess(authState)
                    } else {
                        subscriber.onError(task.exception as FirebaseAuthException)
                    }
                })
        }
    }

    override fun resetPassword(email: String): Single<Boolean> {
        return Single.create { subscriber ->
            auth.sendPasswordResetEmail(email).addOnCompleteListener { task->
                if (task.isSuccessful) {
                    subscriber.onSuccess(true)
                }
                else {
                    subscriber.onError(task.exception as FirebaseAuthException)
                }
            }
        }

    }

    override fun logOut() {
        auth.signOut()
    }

}
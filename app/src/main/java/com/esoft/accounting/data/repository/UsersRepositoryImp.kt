package com.esoft.accounting.data.repository

import com.esoft.accounting.domain.repository.UserModel
import com.esoft.accounting.domain.repository.UsersRepository
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import io.reactivex.Observable

class UsersRepositoryImp(
    private val firebaseAuth: FirebaseAuth,
    private val firebaseDatabase: FirebaseDatabase
) : UsersRepository {


    override fun getUserInfo(): Observable<UserModel> {
        return Observable.create { subscriber ->
            val user = firebaseAuth.currentUser
            if (user != null) {
                val reference = firebaseDatabase.getReference("Users")
                val userId = user.uid

                reference.child(userId).addListenerForSingleValueEvent(object : ValueEventListener {
                    override fun onDataChange(snapshot: DataSnapshot) {
                        val userProfile = snapshot.getValue(UserModel::class.java)
                        if (userProfile != null) {
                            val user = UserModel(
                                email = userProfile.email,
                                name = userProfile.name,
                                surname = userProfile.surname,
                                rootUser = userProfile.rootUser
                            )
                            subscriber.onNext(user)
                        }
                    }

                    override fun onCancelled(error: DatabaseError) {
                        TODO("Not yet implemented")
                    }

                })
            }
        }
    }

}
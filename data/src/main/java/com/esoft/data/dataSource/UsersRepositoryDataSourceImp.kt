package com.esoft.data

import androidx.lifecycle.MutableLiveData
import com.esoft.data.dataSource.model.User
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener


interface UsersRepositoryDataSource {

    fun getUserProfile(): MutableLiveData<User>

}

class UsersRepositoryDataSourceImp: UsersRepositoryDataSource {

    private var firebaseAuth: FirebaseAuth = FirebaseAuth.getInstance()
    private val firebaseDataBase: FirebaseDatabase = FirebaseDatabase.getInstance()
    private val userProfileLiveData = MutableLiveData<User>()

    override fun getUserProfile(): MutableLiveData<User> {
        val user = firebaseAuth.currentUser
        val reference = firebaseDataBase.getReference("Users")
        val userId = user!!.uid

        reference.child(userId).addListenerForSingleValueEvent(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                val userProfile = snapshot.getValue(User::class.java)
                if (userProfile != null) {
                     val user = User(
                        email = userProfile.email,
                        name = userProfile.name,
                        surname = userProfile.surname,
                        photoUri = userProfile.photoUri
                    )
                    userProfileLiveData.postValue(user)
                }
            }

            override fun onCancelled(error: DatabaseError) {
                TODO("Not yet implemented")
            }

        })

        return userProfileLiveData
    }

}


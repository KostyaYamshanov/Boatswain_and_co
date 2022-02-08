package com.esoft.accounting.data.repository

import com.esoft.accounting.domain.repository.CropRepository
import com.esoft.accounting.helpers.cropReference
import com.esoft.accounting.helpers.sortReference
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import io.reactivex.Single

class CropRepositoryImp(
    private val firebaseDatabase: FirebaseDatabase
) : CropRepository {

    override fun getAllCrop(): Single<List<String>> {
        return Single.create { subscriber ->
            firebaseDatabase.getReference(cropReference)
                .addListenerForSingleValueEvent(object : ValueEventListener {
                    override fun onDataChange(snapshot: DataSnapshot) {
                        val list = ArrayList<String>()
                        for (postSnapshot in snapshot.children) {
                            list.add(postSnapshot.value.toString())
                        }
                        subscriber.onSuccess(list)
                    }

                    override fun onCancelled(error: DatabaseError) {
                    }

                })
        }
    }

    override fun getSortByCrop(cropName: String): Single<List<String>> {
        return Single.create { subscriber ->
            firebaseDatabase.getReference(sortReference).child(cropName)
                .addListenerForSingleValueEvent(object : ValueEventListener {
                    override fun onDataChange(snapshot: DataSnapshot) {
                        val list = ArrayList<String>()
                        for (postSnapshot in snapshot.children) {
                            list.add(postSnapshot.value.toString())
                        }
                        subscriber.onSuccess(list)
                    }

                    override fun onCancelled(error: DatabaseError) {
                    }

                })
        }
    }

}
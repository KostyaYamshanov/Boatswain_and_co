package com.esoft.accounting.domain.repository

import io.reactivex.Single

interface CropRepository {

    fun getAllCrop(): Single<List<String>>

    fun getSortByCrop(cropName: String): Single<List<String>>

}
package com.esoft.accounting.domain.usecase

import com.esoft.accounting.domain.repository.CropRepository

class GetAllCropsUseCase(private val cropRepository: CropRepository) {

    fun getAllCrop() = cropRepository.getAllCrop()

    fun getSortByCrop(cropName: String) = cropRepository.getSortByCrop(cropName = cropName)

}
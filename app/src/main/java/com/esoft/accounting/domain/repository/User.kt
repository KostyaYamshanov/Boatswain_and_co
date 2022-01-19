package com.esoft.accounting.domain.repository

import android.net.Uri

class User() {

    var email: String? = null
    var name: String? = null
    var surname: String? = null
    var photoUri: Uri? = null

    constructor(email: String?, name: String?, surname: String?, photoUri: Uri?): this() {
        this.email = email
        this.name = name
        this.surname = surname
        this.photoUri = photoUri
    }

}
package com.esoft.accounting.domain.repository

class UserModel(){

    var email: String? = null
    var name: String? = null
    var surname: String? = null

    constructor(email: String?, name: String?, surname: String?): this() {
        this.email = email
        this.name = name
        this.surname = surname
    }

}






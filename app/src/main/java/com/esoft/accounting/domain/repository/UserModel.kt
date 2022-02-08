package com.esoft.accounting.domain.repository

class UserModel(){

    var email: String? = null
    var name: String? = null
    var surname: String? = null
    var rootUser: Boolean? = null

    constructor(email: String?, name: String?, surname: String?, rootUser: Boolean?): this() {
        this.email = email
        this.name = name
        this.surname = surname
        this.rootUser = rootUser
    }

}






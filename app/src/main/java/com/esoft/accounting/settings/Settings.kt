package com.esoft.accounting.settings

import android.content.Context
import android.content.SharedPreferences

const val SET_KEY = "save_key"
const val MY_PREF = "my_pref"

class Settings(val context: Context) {

    private var sharedPreferences: SharedPreferences = context.getSharedPreferences(MY_PREF, Context.MODE_PRIVATE)

    fun saveMePref(saveMe: Boolean) {
        val editor = sharedPreferences.edit()
        editor.putBoolean(SET_KEY, saveMe)
        editor.apply()
    }

    fun getSaveMePref(): Boolean {
        return sharedPreferences.getBoolean(SET_KEY, false)
    }

}
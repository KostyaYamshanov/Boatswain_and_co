package com.esoft.accounting.fragments.dialogFragments

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.DialogFragment
import com.esoft.accounting.databinding.DialogCheckEmailBinding

class EmailCheckFragment(): DialogFragment() {

    private lateinit var viewBinding: DialogCheckEmailBinding

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?): View {
        viewBinding = DialogCheckEmailBinding.inflate(inflater, container, false)
        onClick()
        return viewBinding.root
    }


    fun onClick() {
        viewBinding.btnDialogComplite.setOnClickListener {
            dismiss()
        }
    }

}
package com.esoft.accounting.presentation.listFragment

import android.os.Bundle
import android.view.View
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.NavController
import androidx.navigation.Navigation
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentListBinding

class ListFragment : Fragment(R.layout.fragment_list) {

    private var viewModel: ListFragmentViewModel? = null
    private var _binding: FragmentListBinding? = null
    private val binding get() = _binding!!

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        viewModel = ViewModelProvider(
            this,
            ListFragmentViewModelFactory(requireActivity().application)
        ).get(ListFragmentViewModel::class.java)

        viewModel!!.getUserLiveData().observe(this, {
            if (it != null) {
                binding.userInfo.userName.text = it.displayName
                binding.userInfo.userEmail.text = it.email
            }
        })

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentListBinding.bind(view)

        binding.userInfo.logOutImageBtn.setOnClickListener {
            viewModel!!.logOut()
        }


    }

    override fun onResume() {
        super.onResume()
        viewModel!!.getLoggedOutLiveData().observe(viewLifecycleOwner, {
            if (it) {
            }
        })
    }

    override fun onDestroy() {
        super.onDestroy()
        _binding = null
    }

}
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

    private lateinit var viewModel: ListFragmentViewModel
    private lateinit var binding: FragmentListBinding
    private lateinit var navController: NavController

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        navController = Navigation.findNavController(requireActivity(), R.id.nav_host_fragment)

        viewModel = ViewModelProvider(
            this,
            ListFragmentViewModelFactory(requireActivity().application)
        ).get(ListFragmentViewModel::class.java)

        viewModel.getUserLiveData().observe(this, {
            if (it != null) {
                binding.userInfo.userName.text = it.displayName
                binding.userInfo.userEmail.text = it.email
            }
        })

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding = FragmentListBinding.bind(view)

        binding.userInfo.logOutImageBtn.setOnClickListener {
            viewModel.logOut()
        }


    }

    override fun onResume() {
        super.onResume()
        viewModel.getLoggedOutLiveData().observe(viewLifecycleOwner, {
            if (it) {
                navController.navigateUp()
            }
        })
    }

}
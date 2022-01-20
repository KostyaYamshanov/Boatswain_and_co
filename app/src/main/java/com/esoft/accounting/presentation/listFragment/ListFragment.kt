package com.esoft.accounting.presentation.listFragment

import android.os.Bundle
import android.view.View
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.fragment.findNavController
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentListBinding
import com.esoft.domain.repository.UserModel
import org.koin.androidx.viewmodel.ext.android.viewModel

class ListFragment : Fragment(R.layout.fragment_list) {

    private val viewModel by viewModel<ListFragmentViewModel>()

    private var _binding: FragmentListBinding? = null
    private val binding get() = _binding!!

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        viewModel.getUserProfile().observe(this, ::bindUser)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentListBinding.bind(view)

        binding.userInfo.logOutImageBtn.setOnClickListener {
            viewModel.logOut()
        }

    }

    private fun bindUser(user: UserModel) {
        if(user != null) {
            binding.linearList.visibility = View.VISIBLE
            binding.frameLoading.visibility = View.GONE
            binding.userInfo.apply {
                userName.text = user.name + " " + user.surname
                userEmail.text = user.email
            }
        }
    }

    override fun onResume() {
        super.onResume()
        viewModel.getLoggedOutLiveData().observe(viewLifecycleOwner, {
            if (it) {
                findNavController().popBackStack()
            }
        })
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}
package com.esoft.accounting.presentation.listFragment

import android.os.Bundle
import android.view.View
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentListBinding
import com.esoft.accounting.domain.repository.UserModel
import org.koin.androidx.viewmodel.ext.android.viewModel

class ListFragment : Fragment(R.layout.fragment_list) {

    private val viewModel by viewModel<ListFragmentViewModel>()

    private var _binding: FragmentListBinding? = null
    private val binding get() = _binding!!

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentListBinding.bind(view)

        viewModel.logOutLiveData.observe(viewLifecycleOwner) {
            if (it) {
                findNavController().navigateUp()
            }
        }

        binding.userInfo.logOutImageBtn.setOnClickListener {
            viewModel.logOut()
        }

        binding.btnAddNewEntry.setOnClickListener {
            findNavController().navigate(R.id.action_listFragment_to_newRecordingFragment)
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
        viewModel.getUserProfile()
        viewModel.userLiveData.observe(this, ::bindUser)
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

}
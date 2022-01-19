package com.esoft.accounting.presentation.listFragment

import android.os.Bundle
import android.view.View
import android.widget.ProgressBar
import androidx.appcompat.app.AppCompatActivity
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.NavController
import androidx.navigation.Navigation
import androidx.navigation.fragment.findNavController
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

        viewModel!!.getUserProfile().observe(this, {
            if (it != null) {
                binding.linearList.visibility = View.VISIBLE
                binding.frameLoading.visibility = View.GONE
                binding.userInfo.apply {
                    userName.text = it.name + " " + it.surname
                    userEmail.text = it.email
                }
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
                findNavController().popBackStack()
            }
        })
    }

    override fun onDestroy() {
        super.onDestroy()
        _binding = null
    }

}
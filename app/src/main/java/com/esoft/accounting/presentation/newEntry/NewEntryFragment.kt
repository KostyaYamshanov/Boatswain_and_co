package com.esoft.accounting.presentation.newEntry

import android.os.Bundle
import android.view.View
import android.widget.AdapterView
import android.widget.ArrayAdapter
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.esoft.accounting.R
import com.esoft.accounting.databinding.FragmentNewRecordingBinding
import org.koin.androidx.viewmodel.ext.android.viewModel


class NewEntryFragment : Fragment(R.layout.fragment_new_recording) {

    private var _binding: FragmentNewRecordingBinding? = null
    private val binding get() = _binding!!

    private var toolbar: Toolbar? = null

    private val viewModel by viewModel<NewEntryViewModel>()

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        _binding = FragmentNewRecordingBinding.bind(view)

        toolbar = binding.newEntryToolbar

        if (toolbar != null) {
            (activity as AppCompatActivity).setSupportActionBar(toolbar)
            toolbar!!.title = getString(R.string.add_new_entry)
            toolbar!!.setNavigationIcon(R.drawable.ic_arrow_back_black_24dp)
            toolbar!!.setNavigationOnClickListener {
                findNavController().navigateUp()
            }
        }
    }

    override fun onResume() {
        super.onResume()
        viewModel.cropLiveData.observe(this, ::showAllCrops)
        viewModel.sortLiveData.observe(this, ::showAllSortByCrop)
    }

    private fun showAllSortByCrop(list: List<String>) {
        val adapter = ArrayAdapter<String>(requireContext(), android.R.layout.simple_spinner_item, list)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        binding.spinnerSort.adapter = adapter
    }

    private fun showAllCrops(list: List<String>) {
        val adapter = ArrayAdapter<String>(requireContext(), android.R.layout.simple_spinner_item, list)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        binding.spinnerCrop.adapter = adapter
        val itemSelectedListener: AdapterView.OnItemSelectedListener = object : AdapterView.OnItemSelectedListener {
                override fun onItemSelected(parent: AdapterView<*>, view: View, position: Int, id: Long) {
                    viewModel.getSortByCrop(name = parent.getItemAtPosition(position) as String)
                }
                override fun onNothingSelected(parent: AdapterView<*>?) {

                }
            }
        binding.spinnerCrop.onItemSelectedListener = itemSelectedListener
    }


}
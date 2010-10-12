set( BASELINE_DIR ${ITK_SPLIT_COMPONENTS_SOURCE_DIR}/Testing/Data/Baseline )
set( INPUT_DIR    ${ITK_SPLIT_COMPONENTS_SOURCE_DIR}/Testing/Data/Input )

add_executable( itkSplitComponentsImageFilterTest
  itkSplitComponentsImageFilterTest.cxx
  )
target_link_libraries( itkSplitComponentsImageFilterTest
  ITKCommon
  ITKIO
  )

add_test( itkSplitComponentsImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkSplitComponentsImageFilterTest
  --compare
    ${BASELINE_DIR}/itkSplitComponentsImageFilterTestBaseline0.mha
    itkSplitComponentsImageFilterTestOutput0.mha
  --compare
    ${BASELINE_DIR}/itkSplitComponentsImageFilterTestBaseline1.mha
    itkSplitComponentsImageFilterTestOutput1.mha
  itkSplitComponentsImageFilterTest
  itkSplitComponentsImageFilterTestOutput
  )


add_test( split_components_test
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/split-components
  ${INPUT_DIR}/testrgba.nrrd
  -o split_components_test_output_
  )


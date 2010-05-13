set( BASELINE_DIR ${ITK_TENSOR_COMPONENTS_SOURCE_DIR}/Testing/Data/Baseline )

add_executable( itkVectorToComponentsImageFilterTest
  itkVectorToComponentsImageFilterTest.cxx
  )
target_link_libraries( itkVectorToComponentsImageFilterTest
  ITKCommon
  ITKIO
  )

add_test( itkVectorToComponentsImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkVectorToComponentsImageFilterTest
  --compare
    ${BASELINE_DIR}/itkVectorToComponentsImageFilterTestBaseline0.mha
    itkVectorToComponentsImageFilterTestOutput0.mha
  --compare
    ${BASELINE_DIR}/itkVectorToComponentsImageFilterTestBaseline1.mha
    itkVectorToComponentsImageFilterTestOutput1.mha
  itkVectorToComponentsImageFilterTest
  itkVectorToComponentsImageFilterTestOutput
  )




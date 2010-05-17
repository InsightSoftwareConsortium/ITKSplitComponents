set( BASELINE_DIR ${ITK_TENSOR_COMPONENTS_SOURCE_DIR}/Testing/Data/Baseline )

add_executable( itkTensorComponentsImageFilterTest
  itkTensorComponentsImageFilterTest.cxx
  )
target_link_libraries( itkTensorComponentsImageFilterTest
  ITKCommon
  ITKIO
  )

add_test( itkTensorComponentsImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkTensorComponentsImageFilterTest
  --compare
    ${BASELINE_DIR}/itkTensorComponentsImageFilterTestBaseline0.mha
    itkTensorComponentsImageFilterTestOutput0.mha
  --compare
    ${BASELINE_DIR}/itkTensorComponentsImageFilterTestBaseline1.mha
    itkTensorComponentsImageFilterTestOutput1.mha
  itkTensorComponentsImageFilterTest
  itkTensorComponentsImageFilterTestOutput
  )


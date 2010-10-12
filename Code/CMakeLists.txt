add_executable( itk-tensor-components
  itk-tensor-components.cxx
  TensorComponentsArgs.cxx
  )
target_link_libraries( itk-tensor-components
  ITKCommon
  ITKIO
  )
install( TARGETS itk-tensor-components
  RUNTIME DESTINATION bin )

install( FILES
  itkTensorComponentsImageFilter.h
  itkTensorComponentsImageFilter.txx
  DESTINATION include/InsightToolkit/Review
  )

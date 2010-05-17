add_executable( tensor-components
  tensor-components.cxx
  TensorComponentsArgs.cxx
  )
target_link_libraries( tensor-components
  ITKCommon
  ITKIO
  )
install( TARGETS tensor-components
  RUNTIME
  DESTINATION bin
  )

install( FILES
  itkTensorComponentsImageFilter.h
  itkTensorComponentsImageFilter.txx
  DESTINATION include/InsightToolkit/Review
  )

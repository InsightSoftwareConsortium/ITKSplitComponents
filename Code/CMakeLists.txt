add_executable( split-components
  split-components.cxx
  SplitComponentsArgs.cxx
  )
target_link_libraries( split-components
  ITKCommon
  ITKIO
  )
install( TARGETS split-components
  RUNTIME DESTINATION bin )

install( FILES
  itkSplitComponentsImageFilter.h
  itkSplitComponentsImageFilter.txx
  DESTINATION include/InsightToolkit/Review
  )

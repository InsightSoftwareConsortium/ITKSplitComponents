macro( USE_COMPONENT_TYPE type default_value )
  set( USE_${type} ${default_value}
    CACHE BOOL
    "Enable support for the ${type} component type in the split-components executable."
    )
  if( ${USE_${type}} )
    add_definitions( -DUSE_${type} )
  endif()
endmacro( USE_COMPONENT_TYPE )

USE_COMPONENT_TYPE( UCHAR ON )
USE_COMPONENT_TYPE( CHAR OFF )
USE_COMPONENT_TYPE( USHORT OFF )
USE_COMPONENT_TYPE( SHORT ON )
USE_COMPONENT_TYPE( INT OFF )
USE_COMPONENT_TYPE( UINT OFF )
USE_COMPONENT_TYPE( ULONG OFF )
USE_COMPONENT_TYPE( LONG OFF )
USE_COMPONENT_TYPE( FLOAT ON )
USE_COMPONENT_TYPE( DOUBLE ON )

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

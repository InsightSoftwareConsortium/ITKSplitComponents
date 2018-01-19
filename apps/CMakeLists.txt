cmake_minimum_required(VERSION 3.9.5)
cmake_policy( VERSION 2.8 )

project( itk-split-components )

find_package( ITK REQUIRED
  COMPONENTS
  SplitComponents
  ITKIOImageBase
  ITKIOMeta
  ITKIONRRD
  )
include( ${ITK_USE_FILE} )

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

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
add_executable( split-components
  split-components.cxx
  SplitComponentsArgs.cxx
  )
target_link_libraries( split-components
  ${ITK_LIBRARIES}
  )
install( TARGETS split-components
  RUNTIME DESTINATION bin
  )

enable_testing()
add_test( split-componentsTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/split-components
  ${CMAKE_CURRENT_SOURCE_DIR}/testrgba.nrrd
  -o split_components_test_output_
  )

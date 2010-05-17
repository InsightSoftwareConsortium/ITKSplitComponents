// Simple program that breaks a vector, covariant vector, or symmetric second
// rank tensor into its component images.
//

#include "TensorComponentsArgs.h"

#include "itkTensorComponentsImageFilter.h"

int main( int argc, char* argv[] )
{
  try
    {
    Args args( argc, argv );

    }
  catch( itk::ExceptionObject & err ) 
    { 
    std::cerr << "ExceptionObject caught !" << std::endl; 
    std::cerr << err << std::endl; 
    return 1;
    } 
  catch( const Args::got_xml_flag_exception& e )
    {
    return 0;
    }
  catch( const std::exception& e )
    {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
    }

  return 0;
}


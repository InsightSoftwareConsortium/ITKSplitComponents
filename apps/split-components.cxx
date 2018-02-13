// Simple program that breaks a vector, covariant vector, or symmetric second
// rank tensor into its component images.
//

#include "SplitComponentsArgs.h"


#include "itkSplitComponentsImageFilter.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageIOBase.h"
#include "itkImageIOFactory.h"

#include <sstream>

template< class TPixel, unsigned int TDimension, unsigned int TComponents >
void ExtractComponents( const Args& args )
{
  using VectorType = itk::Vector< TPixel, TComponents >;
  using InputImageType = itk::Image< VectorType, TDimension >;
  using OutputImageType = itk::Image< TPixel, TDimension >;

  using ReaderType = itk::ImageFileReader< InputImageType >;
  typename ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( args.inputImage );

  using FilterType = itk::SplitComponentsImageFilter< InputImageType, OutputImageType,
          TComponents >;
  typename FilterType::Pointer filter = FilterType::New();
  filter->SetInput( reader->GetOutput() );

  using WriterType = itk::ImageFileWriter< OutputImageType >;
  typename WriterType::Pointer writer = WriterType::New();
  writer->SetNumberOfStreamDivisions( 10 );

  std::ostringstream ostr;
  for( unsigned int i = 0; i < TComponents; ++i )
    {
    ostr.str( "" );
    ostr << args.outputPrefix << "Component" << i << ".mha";
    writer->SetInput( filter->GetOutput( i ) );
    writer->SetFileName( ostr.str() );
    writer->Update();
    }
}


int main( int argc, char* argv[] )
{
  try
    {
    Args args( argc, argv );

    itk::ImageIOBase::Pointer imageIO =
      itk::ImageIOFactory::CreateImageIO( args.inputImage.c_str(),
                                     itk::ImageIOFactory::ReadMode );
    if ( !imageIO )
      {
      throw std::runtime_error( std::string( "No ImageIO found for " ) + args.inputImage );
      }
    imageIO->SetFileName( args.inputImage.c_str() );
    imageIO->ReadImageInformation();

    // Find out the pixel type of the image in file
    using ScalarComponentType = itk::ImageIOBase::IOComponentType;
    ScalarComponentType componentType = imageIO->GetComponentType();

    const unsigned int dimension = imageIO->GetNumberOfDimensions();
    if( !( dimension == 2 || dimension == 3 ) )
      {
      std::logic_error( "Only images of dimension 2 and 3 are supported." );
      }

    const unsigned int components = imageIO->GetNumberOfComponents();

    // So in hindsight using VectorImageToImageAdaptor would have been more
    // elegant for this case.
    switch( componentType )
      {
#ifdef USE_UCHAR
    case itk::ImageIOBase::UCHAR:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned char, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned char, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned char, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned char, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned char, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned char, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned char, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned char, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned char, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned char, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned char, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned char, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_UCHAR
#ifdef USE_CHAR
    case itk::ImageIOBase::CHAR:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< char, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< char, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< char, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< char, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< char, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< char, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< char, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< char, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< char, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< char, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< char, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< char, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_CHAR
#ifdef USE_USHORT
    case itk::ImageIOBase::USHORT:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned short, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned short, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned short, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned short, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned short, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned short, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned short, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned short, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned short, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned short, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned short, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned short, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_USHORT
#ifdef USE_SHORT
    case itk::ImageIOBase::SHORT:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< short, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< short, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< short, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< short, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< short, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< short, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< short, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< short, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< short, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< short, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< short, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< short, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_SHORT
#ifdef USE_UINT
    case itk::ImageIOBase::UINT:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned int, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned int, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned int, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned int, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned int, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned int, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned int, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned int, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned int, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned int, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned int, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned int, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_UINT
#ifdef USE_INT
    case itk::ImageIOBase::INT:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< int, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< int, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< int, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< int, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< int, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< int, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< int, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< int, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< int, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< int, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< int, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< int, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_INT
#ifdef USE_ULONG
    case itk::ImageIOBase::ULONG:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned long, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned long, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned long, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned long, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned long, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned long, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< unsigned long, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< unsigned long, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< unsigned long, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< unsigned long, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< unsigned long, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< unsigned long, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_ULONG
#ifdef USE_LONG
    case itk::ImageIOBase::LONG:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< long, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< long, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< long, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< long, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< long, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< long, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< long, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< long, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< long, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< long, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< long, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< long, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_LONG
#ifdef USE_FLOAT
    case itk::ImageIOBase::FLOAT:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< float, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< float, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< float, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< float, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< float, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< float, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< float, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< float, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< float, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< float, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< float, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< float, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_FLOAT
#ifdef USE_DOUBLE
    case itk::ImageIOBase::DOUBLE:
        {
        if( dimension == 2 )
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< double, 2, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< double, 2, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< double, 2, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< double, 2, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< double, 2, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< double, 2, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        else
          {
          switch( components )
            {
          case 1:
              {
              ExtractComponents< double, 3, 1 >( args );
              break;
              }
          case 2:
              {
              ExtractComponents< double, 3, 2 >( args );
              break;
              }
          case 3:
              {
              ExtractComponents< double, 3, 3 >( args );
              break;
              }
          case 4:
              {
              ExtractComponents< double, 3, 4 >( args );
              break;
              }
          case 5:
              {
              ExtractComponents< double, 3, 5 >( args );
              break;
              }
          case 6:
              {
              ExtractComponents< double, 3, 6 >( args );
              break;
              }
          default:
            throw std::logic_error( "Only 1-6 components supported." );
            }
          }
        break;
        }
#endif // USE_DOUBLE
    default:
        {
        itk::ExceptionObject ex;
        ex.SetDescription( "The file uses a pixel support not supported at this time." );
        throw ex;
        }
      } // end switch on pixel type

    }
  catch ( itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return 1;
    }
  catch ( const Args::got_xml_flag_exception& e )
    {
    return 0;
    }
  catch ( const std::exception& e )
    {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
    }

  return 0;
}

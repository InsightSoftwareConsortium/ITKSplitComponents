#include "itkTestMain.h"

void RegisterTests()
{
  REGISTER_TEST( itkSplitComponentsImageFilterTest );
}

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkVector.h"

// aoeusth
#include <sstream>

#include "itkSplitComponentsImageFilter.h"

int itkSplitComponentsImageFilterTest( int argc, char* argv[] )
{
  if( argc < 2 )
    {
    std::cerr << "Usage: " << argv[0];
    std::cerr << " outputImagePrefix ";
    std::cerr << std::endl;
    return EXIT_FAILURE;
    }

  const unsigned int Dimension = 2;
  typedef signed short                         PixelType;
  typedef itk::Image<  PixelType, Dimension >  OutputImageType;
  typedef itk::Vector< PixelType, Dimension >  VectorType;
  typedef itk::Image<  VectorType, Dimension > InputImageType;

  // Size in every dimension of the output image.
  const unsigned int sizes = 100;

  InputImageType::Pointer input = InputImageType::New();

  typedef InputImageType::RegionType RegionType;
  RegionType region;
  RegionType::IndexType index;
  index.Fill( 0 );
  region.SetIndex( index );
  RegionType::SizeType  size;
  for( unsigned int i = 0; i < Dimension; i++ )
    {
    size[i] = sizes;
    }
  region.SetSize( size );

  input->SetRegions( region );
  input->Allocate();

  itk::ImageRegionIteratorWithIndex< InputImageType > it( input, region );
  VectorType vector;
  for( it.GoToBegin(); !it.IsAtEnd(); ++it )
    {
    index = it.GetIndex();
    vector[0] = index[0];
    vector[1] = index[1];
    it.Set( vector );
    }

  typedef itk::SplitComponentsImageFilter< InputImageType, OutputImageType,
          Dimension >
    FilterType;
  FilterType::Pointer filter = FilterType::New();
  filter->SetInput( input );

  typedef itk::ImageFileWriter< OutputImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();

  std::ostringstream ostr;
  try
    {
    ostr << argv[1] << 0 << ".mha";
    writer->SetFileName( ostr.str() );
    writer->SetInput( filter->GetOutput() );
    writer->Update();

    ostr.str( "" );
    ostr << argv[1] << 1 << ".mha";
    writer->SetFileName( ostr.str() );
    writer->SetInput( filter->GetOutput( 1 ) );
    writer->Update();
    }
  catch (itk::ExceptionObject& ex)
    {
      std::cerr << "Exception caught!" << std::endl;
      std::cerr << ex << std::endl;
      return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}

#ifndef __itkVectorToComponentsImageFilter_txx
#define __itkVectorToComponentsImageFilter_txx

#include "itkVectorToComponentsImageFilter.h"

#include "itkImageRegionConstIterator.h"
#include "itkImageRegionIterator.h"

namespace itk
{

template< class TInputImage, class TOutputImage,
  unsigned int TComponents >
VectorToComponentsImageFilter< TInputImage, TOutputImage, TComponents >
::VectorToComponentsImageFilter()
{
  this->SetNumberOfOutputs( VectorComponents );
  // ImageSource only does this for the first output.
  for( unsigned int i = 1; i < VectorComponents; i++ )
    {
    this->SetNthOutput( i, this->MakeOutput( i ) );
    }
}

template< class TInputImage, class TOutputImage,
  unsigned int TComponents >
void
VectorToComponentsImageFilter< TInputImage, TOutputImage, TComponents >
::ThreadedGenerateData( const OutputRegionType& outputRegion, 
  int threadId )
{
  typename InputImageType::ConstPointer input = this->GetInput();

  DataObjectPointerArray outputs = this->GetOutputs();

  typedef typename itk::ImageRegionIterator< OutputImageType >
    OutputIteratorType;
  typename itk::ImageRegionConstIterator< InputImageType > 
    inIt( input, outputRegion );
  typename std::vector< OutputIteratorType > outIts;
  unsigned int i;
  for( i = 0; i < VectorComponents; i++ )
    {
    OutputIteratorType outIt( dynamic_cast< OutputImageType* >
      ( outputs[i].GetPointer() ), outputRegion );
    outIt.GoToBegin();
    outIts.push_back( outIt );
    }
  VectorType vector;
  for( inIt.GoToBegin(); ! inIt.IsAtEnd(); ++inIt )
    {
    vector = inIt.Get();
    for( i = 0; i < VectorComponents; i++ )
      {
      outIts[i].Set( static_cast< PixelType >( vector[i] ) );
      ++(outIts[i]);
      }
    }
}

} // end namespace itk

#endif

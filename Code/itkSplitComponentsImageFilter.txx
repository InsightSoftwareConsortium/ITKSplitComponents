#ifndef __itkSplitComponentsImageFilter_txx
#define __itkSplitComponentsImageFilter_txx

#include "itkSplitComponentsImageFilter.h"

#include "itkImageRegionConstIterator.h"
#include "itkImageRegionIterator.h"

namespace itk
{

template< class TInputImage, class TOutputImage,
          unsigned int TComponents >
SplitComponentsImageFilter< TInputImage, TOutputImage, TComponents >
::SplitComponentsImageFilter()
{
  this->SetNumberOfOutputs( Components );
  // ImageSource only does this for the first output.
  for ( unsigned int i = 1; i < Components; i++ )
    {
    this->SetNthOutput( i, this->MakeOutput( i ) );
    }
}

template< class TInputImage, class TOutputImage,
          unsigned int TComponents >
void
SplitComponentsImageFilter< TInputImage, TOutputImage, TComponents >
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
  for ( i = 0; i < Components; i++ )
    {
    OutputIteratorType outIt( dynamic_cast< OutputImageType* >
      ( outputs[i].GetPointer() ), outputRegion );
    outIt.GoToBegin();
    outIts.push_back( outIt );
    }
  InputPixelType inputPixel;
  for ( inIt.GoToBegin(); !inIt.IsAtEnd(); ++inIt )
    {
    inputPixel = inIt.Get();
    for ( i = 0; i < Components; i++ )
      {
      outIts[i].Set( static_cast< OutputPixelType >( inputPixel[i] ) );
      ++(outIts[i]);
      }
    }
}

} // end namespace itk

#endif

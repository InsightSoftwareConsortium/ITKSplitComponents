#ifndef __itkSplitComponentsImageFilter_h
#define __itkSplitComponentsImageFilter_h

#include "itkImageToImageFilter.h"

namespace itk
{

/** \class SplitComponentsImageFilter
 *
 * \brief Extract components of an Image with multi-component pixels.
 *
 * This class extracts components of itk::Image of itk::Vector's
 * itk::CovariantVector, itk::SymmetricSecondRankTensor, or other classes that
 * have the same interface.  The interface must implement ValueType operator[] (
 * unsigned int ).  Therefore, it does not work itk::Matrix.
 *
 * It puts an image on every output corresponding to each component.
 *
 * \sa VectorImageToImageAdaptor
 * \sa Vector
 * \sa CovariantVector
 * \sa SymmetricSecondRankTensor
 * \sa DiffusionTensor3D
 * \sa NthElementImageAdaptor
 */
template< class TInputImage, class TOutputImage,
  unsigned int TComponents = TInputImage::ImageDimension >
class ITK_EXPORT SplitComponentsImageFilter :
  public ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** ImageDimension enumeration. */
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TInputImage::ImageDimension);
  /** Components enumeration. */
  itkStaticConstMacro(Components, unsigned int,
                      TComponents);

  /** Image types. */
  typedef TInputImage                                 InputImageType;
  typedef TOutputImage                                OutputImageType;
  typedef typename InputImageType::PixelType          TensorType;
  typedef typename OutputImageType::PixelType         PixelType;
  typedef typename OutputImageType::RegionType        OutputRegionType;

  /** Standard class typedefs. */
  typedef SplitComponentsImageFilter	  Self;
  typedef ImageToImageFilter< InputImageType, OutputImageType > Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(SplitComponentsImageFilter, ImageToImageFilter);

  /** Provide ::New() */
  itkNewMacro( Self );

  /** Type of the outputs. */
  typedef itk::ProcessObject::DataObjectPointerArray  DataObjectPointerArray;

protected:
  SplitComponentsImageFilter();
  virtual ~SplitComponentsImageFilter() {};

  virtual void ThreadedGenerateData( const OutputRegionType& outputRegion,
    int threadId );

private:
  SplitComponentsImageFilter( const Self& ); // purposely not implemented
  void operator=( const Self& ); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkSplitComponentsImageFilter.txx"
#endif

#endif

#ifndef __itkTensorComponentsImageFilter_h
#define __itkTensorComponentsImageFilter_h

#include "itkImageToImageFilter.h"

namespace itk
{

/** \class TensorComponents
 *
 * \brief Extract components of an Image of itk::Vector's.
 *
 * This class extracts components of itk::Image< itk::Vector<> > or itk::Image<
 * itk::CovariantVector<> > and puts an
 * image on every output corresponding to each component.
 *
 * \sa VectorImageToImageAdaptor
 */
template< class TInputImage, class TOutputImage,
  unsigned int TComponents = TInputImage::ImageDimension >
class ITK_EXPORT TensorComponentsImageFilter :
  public ImageToImageFilter< TInputImage, TOutputImage >
{
public:
  /** ImageDimension enumeration. */
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TInputImage::ImageDimension);
  /** VectorComponents enumeration. */
  itkStaticConstMacro(VectorComponents, unsigned int,
                      TComponents);

  /** Image types. */
  typedef TInputImage                                 InputImageType;
  typedef TOutputImage                                OutputImageType;
  typedef typename InputImageType::PixelType          VectorType;
  typedef typename OutputImageType::PixelType         PixelType;
  typedef typename OutputImageType::RegionType        OutputRegionType;

  /** Standard class typedefs. */
  typedef TensorComponentsImageFilter	  Self;
  typedef ImageToImageFilter< InputImageType, OutputImageType > Superclass;
  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;
  
  /** Run-time type information (and related methods). */
  itkTypeMacro(TensorComponentsImageFilter, ImageToImageFilter);

  /** Provide ::New() */
  itkNewMacro( Self );

  /** Type of the outputs. */
  typedef itk::ProcessObject::DataObjectPointerArray  DataObjectPointerArray;

protected:
  TensorComponentsImageFilter();
  virtual ~TensorComponentsImageFilter() {};

  virtual void ThreadedGenerateData( const OutputRegionType& outputRegion,
    int threadId );

private:
  TensorComponentsImageFilter( const Self& ); // purposely not implemented
  void operator=( const Self& ); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTensorComponentsImageFilter.txx"
#endif

#endif

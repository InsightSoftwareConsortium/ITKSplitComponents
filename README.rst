ITKSplitComponents
==================

.. |CircleCI| image:: https://circleci.com/gh/InsightSoftwareConsortium/ITKSplitComponents.svg?style=shield
    :target: https://circleci.com/gh/InsightSoftwareConsortium/ITKSplitComponents

.. |TravisCI| image:: https://travis-ci.org/InsightSoftwareConsortium/ITKSplitComponents.svg?branch=master
    :target: https://travis-ci.org/InsightSoftwareConsortium/ITKSplitComponents

.. |AppVeyor| image:: https://img.shields.io/appveyor/ci/itkrobot/itksplitcomponents.svg
    :target: https://ci.appveyor.com/project/itkrobot/itksplitcomponents

=========== =========== ===========
   Linux      macOS       Windows
=========== =========== ===========
|CircleCI|  |TravisCI|  |AppVeyor|
=========== =========== ===========

Description
-----------

This module contains filter called
itk::SplitComponentsImageFilter.  This filter generates component images from an
itk::Image of, for example, itk::Vector, itk::CovariantVector, or
itk::SymmetricSecondRankTensor.tk::SymmetricSecondRankTensor.

For more information, see the Insight Journal article at::

  http://hdl.handle.net/10380/3230


Build
-----

This is an ITKv4 Module.  To build the module, clone the repository into the
directory *Modules/External* of the ITK source tree.  Also, set the CMake
configuration variable, *ExternalData_URL_TEMPLATES* to::

  http://c389985.r85.cf1.rackcdn.com/%(algo)/%(hash)

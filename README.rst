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

This ITK module contains filter called
itk::SplitComponentsImageFilter.  This filter generates component images from an
itk::Image of, for example, itk::Vector, itk::CovariantVector, or
itk::SymmetricSecondRankTensor.tk::SymmetricSecondRankTensor.

For more information, see the Insight Journal article at::

  http://hdl.handle.net/10380/3230


Installation
------------

This module is available in the ITK source tree as a Remote module. To enable it, set::

  Module_SplitComponents:BOOL=ON

in ITK's CMake build configuration.

Alternatively, build the module externally with::

  git clone https://github.com/InsightSoftwareConsortium/ITKSplitComponents.git
  mkdir ITKSplitComponents-build
  cd ITKSplitComponents-build
  cmake -DITK_DIR=/path/to/ITK-build ../ITKSplitComponents
  make

License
-------

The source code is distributed under the Apache 2.0 License. Please see LICENSE file for details.

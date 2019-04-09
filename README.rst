ITKSplitComponents
==================

.. image:: https://dev.azure.com/InsightSoftwareConsortium/ITKModules/_apis/build/status/InsightSoftwareConsortium.ITKSplitComponents?branchName=master
    :target: https://dev.azure.com/InsightSoftwareConsortium/ITKModules/_build/latest?definitionId=8&branchName=master
    :alt:    Build Status

.. image:: https://mybinder.org/badge.svg
    :target: https://mybinder.org/v2/gh/InsightSoftwareConsortium/ITKSplitComponents/master?filepath=examples%2FITKSplitComponents.ipynb

Overview
--------

This ITK module contains a filter called ``itk::SplitComponentsImageFilter``.
This filter generates component images from an ``itk::Image`` of, for example,
``itk::Vector``, ``itk::CovariantVector``, or
``itk::SymmetricSecondRankTensor``.

For more information, see the `Insight Journal article <http://hdl.handle.net/10380/3230>`_::

  McCormick M.
  An ITK Class that Splits Multi-Component Images
  The Insight Journal. January-December. 2010.
  http://hdl.handle.net/10380/3230
  http://www.insight-journal.org/browse/publication/774


.. image:: https://raw.githubusercontent.com/InsightSoftwareConsortium/ITKSplitComponents/master/images/ITKSplitComponentsAnimation.gif
  :alt: ITKSplitComponents Notebook

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

This software is distributed under the Apache 2.0 license. Please see the
*LICENSE* file for details.

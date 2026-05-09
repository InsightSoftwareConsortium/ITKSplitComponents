ITKSplitComponents
==================

.. image:: https://github.com/InsightSoftwareConsortium/ITKSplitComponents/actions/workflows/build-test-package.yml/badge.svg
    :target: https://github.com/InsightSoftwareConsortium/ITKSplitComponents/actions/workflows/build-test-package.yml
    :alt: Build, test, package

.. image:: https://img.shields.io/pypi/v/itk-splitcomponents.svg
    :target: https://pypi.python.org/pypi/itk-splitcomponents
    :alt: PyPI Version

.. image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
    :target: https://github.com/InsightSoftwareConsortium/ITKSplitComponents/blob/master/LICENSE
    :alt: License

.. image:: https://mybinder.org/badge.svg
    :target: https://mybinder.org/v2/gh/InsightSoftwareConsortium/ITKSplitComponents/master?filepath=examples%2FITKSplitComponents.ipynb

Overview
--------

This ITK module contains a filter called ``itk::SplitComponentsImageFilter``.
This filter generates component images from an ``itk::Image`` of, for example,
``itk::Vector``, ``itk::CovariantVector``, or
``itk::SymmetricSecondRankTensor``.

For more information, see the `Insight Journal article <https://hdl.handle.net/10380/3230>`_::

  McCormick M.
  An ITK Class that Splits Multi-Component Images
  The Insight Journal. January-December. 2010.
  https://hdl.handle.net/10380/3230
  https://www.insight-journal.org/browse/publication/774


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

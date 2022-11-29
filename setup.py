# -*- coding: utf-8 -*-
from __future__ import print_function
from os import sys

try:
    from skbuild import setup
except ImportError:
    print('scikit-build is required to build from source.', file=sys.stderr)
    print('Please run:', file=sys.stderr)
    print('', file=sys.stderr)
    print('  python -m pip install scikit-build')
    sys.exit(1)

setup(
    name='itk-splitcomponents',
    version='2.1.0',
    author='Matthew M. McCormick',
    author_email='matt.mccormick@kitware.com',
    packages=['itk'],
    package_dir={'itk': 'itk'},
    download_url=r'https://github.com/InsightSoftwareConsortium/ITKSplitComponents',
    description=r'ITK filters to split a multi-component pixel image into component-wise scalar images',
    long_description='itk-splitcomponents provides a class that takes an image '
                     'with multi-component pixels and outputs a scalar image '
                     'for each component. This can be useful when examining '
                     'images of vectors, tensors, etc.\n'
                     'Please refer to:\n'
                     'M. McCormick, "An ITK Class that Splits Multi-Component Images.", '
                     'Insight Journal, July-December 2010, https://hdl.handle.net/10380/3230',
    classifiers=[
        "License :: OSI Approved :: Apache Software License",
        "Programming Language :: Python",
        "Programming Language :: C++",
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "Intended Audience :: Education",
        "Intended Audience :: Healthcare Industry",
        "Intended Audience :: Science/Research",
        "Topic :: Scientific/Engineering",
        "Topic :: Scientific/Engineering :: Medical Science Apps.",
        "Topic :: Scientific/Engineering :: Information Analysis",
        "Topic :: Software Development :: Libraries",
        "Operating System :: Android",
        "Operating System :: Microsoft :: Windows",
        "Operating System :: POSIX",
        "Operating System :: Unix",
        "Operating System :: MacOS"
        ],
    license='Apache',
    keywords='ITK Higher-order Derivative Gradient',
    url=r'https://github.com/InsightSoftwareConsortium/ITKSplitComponents',
    install_requires=[
        r'itk>=5.3.0'
    ]
    )

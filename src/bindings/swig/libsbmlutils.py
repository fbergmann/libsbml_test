#!/usr/bin/env python
#
# @file   libsbmlutils.py
# @brief  Common utility code used by some of our other Python programs.
# @author Michael Hucka
# @date   Created 2014-03-26
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright (C) 2013-2014 jointly by the following organizations:
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
#     3. University of Heidelberg, Heidelberg, Germany
#
# Copyright (C) 2009-2013 jointly by the following organizations:
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
#
# Copyright (C) 2006-2008 by the California Institute of Technology,
#     Pasadena, CA, USA
#
# Copyright (C) 2002-2005 jointly by the following organizations:
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. Japan Science and Technology Agency, Japan
#
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#----------------------------------------------------------------------- -->*/

import os, re
from os.path import join

skip_names = ['is', 'endl', 'flush']

#
# find_classes(X)
#

def find_classes(arg, swig_too = False, enums_too = True):
    """List class declarations found in .h files.

    ARG can be a single directory or a list of files.  Returns a list of all
    classes found in all .h or .i files in ARG (either one if present), or if
    ARG is a directory, found recursively in .h (optionally, .i) files in ARG
    and its subdirectories.  It does this by searching for Doxygen @class
    declarations in the comments of the files and %template declarations in
    .i files.  Skips classes whose names begin with 'doc_'.  The argument
    swig_too is only necessary if ARG is a directory; if ARG is a list of
    files, then the intention is clear based on whether the list contains .h
    files or .i files.
    """

    if type(arg) is list:
        classes = [c for file in arg for c in classes_in_file(file)]
    else:
        classes = classes_in_dir(arg, swig_too)
    if not enums_too:
        classes = [item for item in classes if not item.endswith('_t')]
    return cleanup(classes)


def classes_in_dir(dir, swig_too):
    files = []
    for root, dirnames, found_files in os.walk(dir):
        # Skip legacy dirs; we want the current code only.
        if root.find('-legacy') >= 0:
            continue
        for tail in found_files:
            if (not (tail.endswith('.h') or \
                     tail.endswith('.txt') or \
                     (swig_too and tail.endswith('.i')))):
               continue
            if tail.endswith('fwd.h'): 
               continue
            if tail.endswith('ExtensionTypes.h'): 
               continue
            files.append(os.path.join(root, tail))
    return [c for file in files for c in classes_in_file(file)]


def classes_in_file(filename):
    stream = open(filename)
    classes = []
    if filename.endswith('.h') or filename.endswith('.txt'):
        classes = classes_in_header_file(stream)
    elif filename.endswith('.i'):
        classes = classes_in_swig_file(stream)
    stream.close()
    return classes


def classes_in_header_file(stream):
    classes = []
    for line in stream.readlines():
        match = re.search('(@class|@enum)\s+(\w+)', line)
        if match == None:
            continue
        name = match.group(2)
        # Ignore documentation fragments pseudoclasses.
        if not name.startswith("doc_"):
            classes.append(name)
    return classes


def classes_in_swig_file(stream):
    classes = []
    for line in stream.readlines():
        start = line.find('%template(')
        if start < 0:
            continue
        end = line.find(')')
        name = line[start + 10:end].strip()
        if name:
          classes.append(name)
    return classes


def cleanup(classes):
    return [item for item in classes if not item in skip_names]


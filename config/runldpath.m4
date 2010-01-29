dnl
dnl Filename    : runldpath.m4
dnl Description : Autoconf macro to set special variable RUN_LDPATH
dnl Author(s)   : Mike Hucka
dnl Created     : 2005-04-30
dnl Revision    : $Id$
dnl $HeadURL$
dnl
dnl <!-------------------------------------------------------------------------
dnl This file is part of libSBML.  Please visit http://sbml.org for more
dnl information about SBML, and the latest version of libSBML.
dnl
dnl Copyright 2005-2010 California Institute of Technology.
dnl Copyright 2002-2005 California Institute of Technology and
dnl                     Japan Science and Technology Corporation.
dnl 
dnl This library is free software; you can redistribute it and/or modify it
dnl under the terms of the GNU Lesser General Public License as published by
dnl the Free Software Foundation.  A copy of the license agreement is provided
dnl in the file named "LICENSE.txt" included with this software distribution
dnl and also available online as http://sbml.org/software/libsbml/license.html
dnl --------------------------------------------------------------------- -->*/

dnl CONFIG_LDPATH needs to be called from configure.ac to initialize the 
dnl internal variable.  It needs to be called fairly early.

AC_DEFUN([CONFIG_LDPATH],
[
  AC_DEFINE([RUN_LDPATH])

  dnl The initial value is the user's LD_LIBRARY_PATH or DYLD_LIBRARY_PATH

  case $host in
  *darwin*) 
    RUN_LDPATH="$DYLD_LIBRARY_PATH"
    ;;
  *)
    RUN_LDPATH="$LD_LIBRARY_PATH"
    ;;
  esac

  AC_SUBST(RUN_LDPATH)
])


dnl CONFIG_ADD_LDPATH(path) adds "path" to list of paths used to set
dnl LD_LIBRARY_PATH.

AC_DEFUN([CONFIG_ADD_LDPATH],
[
  RUN_LDPATH="$RUN_LDPATH:$1"
])


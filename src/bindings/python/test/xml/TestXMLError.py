#
# @file    TestXMLError.py
# @brief   XMLError unit tests, C++ version
#
# @author  Akiya Jouraku (Python conversion)
# @author  Michael Hucka 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestXMLError.cpp
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2009 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#--------------------------------------------------------------------------->*/
import sys
import unittest
import libsbml

class TestXMLError(unittest.TestCase):


  def test_XMLError_create(self):
    error = libsbml.XMLError()
    self.assert_( error != 0 )
    error = None
    error = libsbml.XMLError(libsbml.DuplicateXMLAttribute)
    self.assert_( error.getErrorId() == libsbml.DuplicateXMLAttribute )
    self.assert_( error.getSeverity() == libsbml.LIBSBML_SEV_ERROR )
    self.assert_( error.getSeverityAsString() ==  "Error"  )
    self.assert_( error.getCategory() == libsbml.LIBSBML_CAT_XML )
    self.assert_( error.getCategoryAsString() ==  "XML content" )
    self.assert_( error.getMessage() ==  "Duplicate attribute."  )
    error = None
    error = libsbml.XMLError(12345, "My message")
    self.assert_( error.getErrorId() == 12345 )
    self.assert_( error.getMessage() ==  "My message"  )
    self.assert_( error.getSeverity() == libsbml.LIBSBML_SEV_FATAL )
    self.assert_( error.getSeverityAsString() ==  "Fatal"  )
    self.assert_( error.getCategory() == libsbml.LIBSBML_CAT_INTERNAL )
    self.assert_( error.getCategoryAsString() ==  "Internal" )
    error = None
    error = libsbml.XMLError(12345, "My message",0,0,libsbml.LIBSBML_SEV_INFO,libsbml.LIBSBML_CAT_SYSTEM)
    self.assert_( error.getErrorId() == 12345 )
    self.assert_( error.getMessage() ==  "My message"  )
    self.assert_( error.getSeverity() == libsbml.LIBSBML_SEV_INFO )
    self.assert_( error.getSeverityAsString() ==  "Informational"  )
    self.assert_( error.getCategory() == libsbml.LIBSBML_CAT_SYSTEM )
    self.assert_( error.getCategoryAsString() ==  "Operating system" )
    self.assertEqual( True, error.isInfo() )
    self.assertEqual( True, error.isSystem() )
    error = None
    error = libsbml.XMLError(10000, "Another message",0,0,libsbml.LIBSBML_SEV_FATAL,libsbml.LIBSBML_CAT_XML)
    self.assert_( error.getErrorId() == 10000 )
    self.assert_( error.getMessage() ==  "Another message"  )
    self.assert_( error.getSeverity() == libsbml.LIBSBML_SEV_FATAL )
    self.assert_( error.getSeverityAsString() ==  "Fatal"  )
    self.assert_( error.getCategory() == libsbml.LIBSBML_CAT_XML )
    self.assert_( error.getCategoryAsString() ==  "XML content" )
    self.assertEqual( True, error.isFatal() )
    self.assertEqual( True, error.isXML() )
    error = None
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestXMLError))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

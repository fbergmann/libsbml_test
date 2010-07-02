#
# @file    TestXMLAttributes.py
# @brief   TestXMLAttributes unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Ben Bornstein 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestXMLAttributes.cpp
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2010 California Institute of Technology.
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

def util_NaN():
  z = 1e300
  z = z * z

  return z - z

def util_PosInf():
  z = 1e300
  z = z * z

  return z

def util_NegInf():
  z = 1e300
  z = z * z

  return -z 

def wrapString(s):
  return s
  pass


class TestXMLAttributes(unittest.TestCase):


  def test_XMLAttributes_add_get(self):
    attrs = libsbml.XMLAttributes()
    self.assert_( attrs.getLength() == 0 )
    self.assertEqual( True, attrs.isEmpty() )
    attrs.add("xmlns", "http://foo.org/")
    self.assert_( attrs.getLength() == 1 )
    self.assert_( attrs.isEmpty() == False )
    attrs.add("foo", "bar")
    self.assert_( attrs.getLength() == 2 )
    self.assert_( attrs.isEmpty() == False )
    self.assert_( attrs.getIndex("xmlns") == 0 )
    self.assert_( attrs.getIndex("foo"  ) == 1 )
    self.assert_( attrs.getIndex("bar"  ) == -1 )
    self.assert_( attrs.getValue("xmlns") ==  "http://foo.org/"  )
    self.assert_( attrs.getValue("foo"  ) ==  "bar"              )
    self.assert_( attrs.getValue("bar"  ) ==  ""                 )
    self.assert_( attrs.getName(0) ==  "xmlns"  )
    self.assert_( attrs.getName(1) ==  "foo"    )
    self.assert_( attrs.getName(2) ==  ""       )
    pass  

  def test_XMLAttributes_assignment(self):
    att1 = libsbml.XMLAttributes()
    att1.add("xmlns", "http://foo.org/")
    self.assert_( att1.getLength() == 1 )
    self.assert_( att1.isEmpty() == False )
    self.assert_( att1.getIndex("xmlns") == 0 )
    self.assert_( att1.getName(0) ==   "xmlns"  )
    self.assert_( att1.getValue("xmlns") ==  "http://foo.org/"  )
    att2 = libsbml.XMLAttributes()
    att2 = att1
    self.assert_( att2.getLength() == 1 )
    self.assert_( att2.isEmpty() == False )
    self.assert_( att2.getIndex("xmlns") == 0 )
    self.assert_( att2.getName(0) ==   "xmlns"  )
    self.assert_( att2.getValue("xmlns") ==  "http://foo.org/"  )
    att2 = None
    att1 = None
    pass  

  def test_XMLAttributes_clone(self):
    att1 = libsbml.XMLAttributes()
    att1.add("xmlns", "http://foo.org/")
    self.assert_( att1.getLength() == 1 )
    self.assert_( att1.isEmpty() == False )
    self.assert_( att1.getIndex("xmlns") == 0 )
    self.assert_( att1.getName(0) ==   "xmlns"  )
    self.assert_( att1.getValue("xmlns") ==  "http://foo.org/"  )
    att2 = att1.clone()
    self.assert_( att2.getLength() == 1 )
    self.assert_( att2.isEmpty() == False )
    self.assert_( att2.getIndex("xmlns") == 0 )
    self.assert_( att2.getName(0) ==   "xmlns"  )
    self.assert_( att2.getValue("xmlns") ==  "http://foo.org/"  )
    att2 = None
    att1 = None
    pass  

  def test_XMLAttributes_copy(self):
    att1 = libsbml.XMLAttributes()
    att1.add("xmlns", "http://foo.org/")
    self.assert_( att1.getLength() == 1 )
    self.assert_( att1.isEmpty() == False )
    self.assert_( att1.getIndex("xmlns") == 0 )
    self.assert_( att1.getName(0) ==   "xmlns"  )
    self.assert_( att1.getValue("xmlns") ==  "http://foo.org/"  )
    att2 = libsbml.XMLAttributes(att1)
    self.assert_( att2.getLength() == 1 )
    self.assert_( att2.isEmpty() == False )
    self.assert_( att2.getIndex("xmlns") == 0 )
    self.assert_( att2.getName(0) ==   "xmlns"  )
    self.assert_( att2.getValue("xmlns") ==  "http://foo.org/"  )
    att2 = None
    att1 = None
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestXMLAttributes))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

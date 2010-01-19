#
# @file    TestL3Unit.py
# @brief   L3 Unit unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestL3Unit.c
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

def isnan(x):
  return (x != x)
  pass
SBML_INT_MAX = 2147483647
class TestL3Unit(unittest.TestCase):

  U = None

  def setUp(self):
    self.U = libsbml.Unit(3,1)
    if (self.U == None):
      pass    
    pass  

  def tearDown(self):
    self.U = None
    pass  

  def test_L3_Unit_NS(self):
    self.assert_( self.U.getNamespaces() != None )
    self.assert_( self.U.getNamespaces().getLength() == 1 )
    self.assert_((     "http://www.sbml.org/sbml/level3/version1/core" == self.U.getNamespaces().getURI(0) ))
    pass  

  def test_L3_Unit_create(self):
    self.assert_( self.U.getTypeCode() == libsbml.SBML_UNIT )
    self.assert_( self.U.getMetaId() == "" )
    self.assert_( self.U.getNotes() == None )
    self.assert_( self.U.getAnnotation() == None )
    self.assert_( self.U.getKind() == libsbml.UNIT_KIND_INVALID )
    self.assertEqual( True, isnan(self.U.getExponentAsDouble()) )
    self.assertEqual( True, isnan(self.U.getMultiplier()) )
    self.assert_( self.U.getScale() == SBML_INT_MAX )
    self.assertEqual( False, self.U.isSetKind() )
    self.assertEqual( False, self.U.isSetExponent() )
    self.assertEqual( False, self.U.isSetMultiplier() )
    self.assertEqual( False, self.U.isSetScale() )
    pass  

  def test_L3_Unit_createWithNS(self):
    xmlns = libsbml.XMLNamespaces()
    xmlns.add( "http://www.sbml.org", "testsbml")
    sbmlns = libsbml.SBMLNamespaces(3,1)
    sbmlns.addNamespaces(xmlns)
    u = libsbml.Unit(sbmlns)
    self.assert_( u.getTypeCode() == libsbml.SBML_UNIT )
    self.assert_( u.getMetaId() == "" )
    self.assert_( u.getNotes() == None )
    self.assert_( u.getAnnotation() == None )
    self.assert_( u.getLevel() == 3 )
    self.assert_( u.getVersion() == 1 )
    self.assert_( u.getNamespaces() != None )
    self.assert_( u.getNamespaces().getLength() == 2 )
    self.assert_( u.getKind() == libsbml.UNIT_KIND_INVALID )
    self.assertEqual( True, isnan(u.getExponentAsDouble()) )
    self.assertEqual( True, isnan(u.getMultiplier()) )
    self.assertEqual( False, u.isSetKind() )
    self.assertEqual( False, u.isSetExponent() )
    self.assertEqual( False, u.isSetMultiplier() )
    self.assertEqual( False, u.isSetScale() )
    u = None
    pass  

  def test_L3_Unit_exponent(self):
    exponent = 0.2
    self.assertEqual( False, self.U.isSetExponent() )
    self.assertEqual( True, isnan(self.U.getExponentAsDouble()) )
    self.U.setExponent(exponent)
    self.assert_( self.U.getExponentAsDouble() == exponent )
    self.assertEqual( True, self.U.isSetExponent() )
    pass  

  def test_L3_Unit_free_NULL(self):
    pass  

  def test_L3_Unit_hasRequiredAttributes(self):
    u = libsbml.Unit(3,1)
    self.assertEqual( False, u.hasRequiredAttributes() )
    u.setKind(libsbml.UNIT_KIND_MOLE)
    self.assertEqual( False, u.hasRequiredAttributes() )
    u.setExponent(0)
    self.assertEqual( False, u.hasRequiredAttributes() )
    u.setMultiplier(0.45)
    self.assertEqual( False, u.hasRequiredAttributes() )
    u.setScale(2)
    self.assertEqual( True, u.hasRequiredAttributes() )
    u = None
    pass  

  def test_L3_Unit_kind(self):
    kind =  "mole";
    self.assertEqual( False, self.U.isSetKind() )
    self.U.setKind(libsbml.UnitKind_forName(kind))
    self.assert_( self.U.getKind() == libsbml.UNIT_KIND_MOLE )
    self.assertEqual( True, self.U.isSetKind() )
    pass  

  def test_L3_Unit_multiplier(self):
    multiplier = 0.2
    self.assertEqual( False, self.U.isSetMultiplier() )
    self.assertEqual( True, isnan(self.U.getMultiplier()) )
    self.U.setMultiplier(multiplier)
    self.assert_( self.U.getMultiplier() == multiplier )
    self.assertEqual( True, self.U.isSetMultiplier() )
    pass  

  def test_L3_Unit_scale(self):
    scale = 2
    self.assertEqual( False, self.U.isSetScale() )
    self.assert_( self.U.getScale() == SBML_INT_MAX )
    self.U.setScale(scale)
    self.assert_( self.U.getScale() == scale )
    self.assertEqual( True, self.U.isSetScale() )
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestL3Unit))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

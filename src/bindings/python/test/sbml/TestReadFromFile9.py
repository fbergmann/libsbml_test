#
# @file    TestReadFromFile9.py
# @brief   Reads tests/l3v1-new.xml into memory and tests it.
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestReadFromFile9.cpp
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

class TestReadFromFile9(unittest.TestCase):


  def test_read_l3v1_new(self):
    reader = libsbml.SBMLReader()
    filename = "../../sbml/test/test-data/"
    filename += "l3v1-new.xml"
    d = reader.readSBML(filename)
    if (d == None):
      pass    
    self.assert_( d.getLevel() == 3 )
    self.assert_( d.getVersion() == 1 )
    m = d.getModel()
    self.assert_( m != None )
    self.assertEqual( True, m.isSetSubstanceUnits() )
    self.assertEqual( True, m.isSetTimeUnits() )
    self.assertEqual( True, m.isSetVolumeUnits() )
    self.assertEqual( True, m.isSetLengthUnits() )
    self.assertEqual( True, m.isSetAreaUnits() )
    self.assertEqual( True, m.isSetExtentUnits() )
    self.assertEqual( True, m.isSetConversionFactor() )
    self.assert_( m.getSubstanceUnits() ==  "mole" )
    self.assert_( m.getTimeUnits() ==  "second" )
    self.assert_( m.getVolumeUnits() ==  "litre" )
    self.assert_( m.getLengthUnits() ==  "metre" )
    self.assert_( m.getAreaUnits() ==  "metre" )
    self.assert_( m.getExtentUnits() ==  "mole" )
    self.assert_( m.getConversionFactor() ==  "p" )
    self.assert_( m.getNumUnitDefinitions() == 2 )
    ud = m.getUnitDefinition(0)
    self.assert_( ud.getNumUnits() == 1 )
    u = ud.getUnit(0)
    self.assertEqual( False, u.isSetExponent() )
    self.assertEqual( False, u.isSetScale() )
    self.assertEqual( False, u.isSetMultiplier() )
    ud = m.getUnitDefinition(1)
    self.assert_( ud.getNumUnits() == 3 )
    u = ud.getUnit(0)
    self.assertEqual( True, u.isSetExponent() )
    self.assertEqual( True, u.isSetScale() )
    self.assertEqual( True, u.isSetMultiplier() )
    self.assert_( u.getExponent() == -1 )
    self.assert_( u.getScale() == 2 )
    self.assert_( u.getMultiplier() == 1.3 )
    u = ud.getUnit(1)
    self.assertEqual( True, u.isSetExponent() )
    self.assertEqual( True, u.isSetScale() )
    self.assertEqual( True, u.isSetMultiplier() )
    self.assert_( u.getScale() == 10 )
    self.assert_( u.getMultiplier() == 0.5 )
    u = ud.getUnit(2)
    self.assertEqual( True, u.isSetExponent() )
    self.assertEqual( True, u.isSetScale() )
    self.assertEqual( True, u.isSetMultiplier() )
    self.assert_( u.getExponent() == 1 )
    self.assert_( u.getScale() == 0 )
    self.assert_( u.getMultiplier() == 1 )
    self.assert_( m.getNumCompartments() == 3 )
    c = m.getCompartment(0)
    self.assertEqual( True, c.isSetSize() )
    self.assertEqual( True, c.isSetSpatialDimensions() )
    self.assertEqual( True, c.isSetConstant() )
    self.assert_( c.getId() ==  "comp" )
    self.assert_( c.getSize() == 1e-14 )
    self.assert_( c.getSpatialDimensions() == 3 )
    self.assert_( c.getUnits() ==  "litre" )
    self.assert_( c.getConstant() == True )
    c = m.getCompartment(1)
    self.assertEqual( False, c.isSetSize() )
    self.assertEqual( False, c.isSetSpatialDimensions() )
    self.assertEqual( True, c.isSetConstant() )
    self.assert_( c.getId() ==  "comp1" )
    self.assert_( c.getConstant() == False )
    c = m.getCompartment(2)
    self.assertEqual( False, c.isSetSize() )
    self.assertEqual( False, c.isSetConstant() )
    self.assert_( c.getId() ==  "comp2" )
    self.assert_( m.getNumSpecies() == 2 )
    s = m.getSpecies(0)
    self.assert_( s.getId() ==  "ES" )
    self.assert_( s.getCompartment() ==  "comp" )
    self.assertEqual( True, s.isSetConversionFactor() )
    self.assert_( s.getConversionFactor() ==  "p" )
    self.assertEqual( True, s.isSetBoundaryCondition() )
    self.assert_( s.getBoundaryCondition() == False )
    self.assertEqual( True, s.isSetHasOnlySubstanceUnits() )
    self.assert_( s.getHasOnlySubstanceUnits() == False )
    self.assertEqual( True, s.isSetSubstanceUnits() )
    self.assert_( s.getSubstanceUnits() ==  "mole" )
    self.assertEqual( True, s.isSetConstant() )
    self.assert_( s.getConstant() == False )
    s = m.getSpecies(1)
    self.assert_( s.getId() ==  "P" )
    self.assert_( s.getCompartment() ==  "comp" )
    self.assertEqual( False, s.isSetConversionFactor() )
    self.assert_( s.getConversionFactor() ==  "" )
    self.assertEqual( False, s.isSetBoundaryCondition() )
    self.assertEqual( False, s.isSetHasOnlySubstanceUnits() )
    self.assertEqual( False, s.isSetSubstanceUnits() )
    self.assert_( s.getSubstanceUnits() ==  "" )
    self.assertEqual( False, s.isSetConstant() )
    self.assert_( m.getNumParameters() == 3 )
    p = m.getParameter(0)
    self.assert_( p.getId() ==  "Keq" )
    self.assertEqual( True, p.isSetValue() )
    self.assert_( p.getValue() == 2.5 )
    self.assertEqual( True, p.isSetUnits() )
    self.assert_( p.getUnits() ==  "dimensionless" )
    self.assertEqual( True, p.isSetConstant() )
    self.assert_( p.getConstant() == True )
    p = m.getParameter(1)
    self.assert_( p.getId() ==  "Keq1" )
    self.assertEqual( False, p.isSetValue() )
    self.assertEqual( False, p.isSetUnits() )
    self.assert_( p.getUnits() ==  "" )
    self.assertEqual( True, p.isSetConstant() )
    self.assert_( p.getConstant() == False )
    p = m.getParameter(2)
    self.assert_( p.getId() ==  "Keq2" )
    self.assertEqual( False, p.isSetValue() )
    self.assertEqual( False, p.isSetUnits() )
    self.assert_( p.getUnits() ==  "" )
    self.assertEqual( False, p.isSetConstant() )
    self.assert_( m.getNumReactions() == 3 )
    r = m.getReaction(0)
    self.assertEqual( True, r.isSetFast() )
    self.assert_( r.getFast() == False )
    self.assertEqual( True, r.isSetReversible() )
    self.assert_( r.getReversible() == False )
    self.assertEqual( True, r.isSetCompartment() )
    self.assert_( r.getCompartment() ==  "comp" )
    sr = r.getReactant(0)
    self.assertEqual( True, sr.isSetConstant() )
    self.assert_( sr.getConstant() == True )
    sr = r.getProduct(0)
    self.assertEqual( True, sr.isSetConstant() )
    self.assert_( sr.getConstant() == False )
    kl = r.getKineticLaw()
    self.assert_( kl.getNumLocalParameters() == 1 )
    self.assert_( kl.getNumParameters() == 0 )
    p = kl.getParameter(0)
    self.assert_( p == None )
    lp = kl.getLocalParameter(0)
    self.assertEqual( True, lp.isSetUnits() )
    self.assert_( lp.getUnits() ==  "per_second" )
    self.assertEqual( True, lp.isSetValue() )
    self.assert_( lp.getValue() == 0.1 )
    r = m.getReaction(1)
    self.assertEqual( True, r.isSetFast() )
    self.assert_( r.getFast() == True )
    self.assertEqual( True, r.isSetReversible() )
    self.assert_( r.getReversible() == True )
    self.assertEqual( False, r.isSetCompartment() )
    self.assert_( r.getCompartment() ==  "" )
    sr = r.getReactant(0)
    self.assertEqual( False, sr.isSetConstant() )
    r = m.getReaction(2)
    self.assertEqual( False, r.isSetFast() )
    self.assertEqual( False, r.isSetReversible() )
    self.assertEqual( False, r.isSetCompartment() )
    self.assert_( r.getCompartment() ==  "" )
    d = None
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestReadFromFile9))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

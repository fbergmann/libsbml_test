#
# @file    TestCompartment.py
# @brief   Compartment unit tests
# @author  Akiya Jouraku (Python conversion)
# @author  Ben Bornstein 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestCompartment.c
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2008 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#--------------------------------------------------------------------------->*/
#
import sys
import unittest
import libsbml

class TestCompartment(unittest.TestCase):

  C = None

  def setUp(self):
    self.C = libsbml.Compartment()
    if (self.C == None):
      pass    
    pass  

  def tearDown(self):
    self.C = None
    pass  

  def test_Compartment_create(self):
    self.assert_( self.C.getTypeCode() == libsbml.SBML_COMPARTMENT )
    self.assert_( self.C.getMetaId() == "" )
    self.assert_( self.C.getNotes() == None )
    self.assert_( self.C.getAnnotation() == None )
    self.assert_( self.C.getId() == "" )
    self.assert_( self.C.getName() == "" )
    self.assert_( self.C.getUnits() == "" )
    self.assert_( self.C.getOutside() == "" )
    self.assert_( self.C.getSpatialDimensions() == 3 )
    self.assert_( self.C.getVolume() == 1.0 )
    self.assert_( self.C.getConstant() == True )
    self.assertEqual( False, self.C.isSetId() )
    self.assertEqual( False, self.C.isSetName() )
    self.assertEqual( False, self.C.isSetSize() )
    self.assertEqual( False, self.C.isSetVolume() )
    self.assertEqual( False, self.C.isSetUnits() )
    self.assertEqual( False, self.C.isSetOutside() )
    pass  

  def test_Compartment_createWith(self):
    c = libsbml.Compartment("A", "")
    self.assert_( c.getTypeCode() == libsbml.SBML_COMPARTMENT )
    self.assert_( c.getMetaId() == "" )
    self.assert_( c.getNotes() == None )
    self.assert_( c.getAnnotation() == None )
    self.assert_( c.getName() == "" )
    self.assert_( c.getSpatialDimensions() == 3 )
    self.assert_((  "A"      == c.getId() ))
    self.assert_( c.getConstant() == True )
    self.assertEqual( True, c.isSetId() )
    self.assertEqual( False, c.isSetName() )
    c = None
    pass  

  def test_Compartment_free_NULL(self):
    
    pass  

  def test_Compartment_getSpatialDimensions(self):
    self.C.setSpatialDimensions(1)
    self.assert_( self.C.getSpatialDimensions() == 1 )
    pass  

  def test_Compartment_getsetConstant(self):
    self.C.setConstant(1)
    self.assert_( self.C.getConstant() == True )
    pass  

  def test_Compartment_getsetType(self):
    self.C.setCompartmentType( "cell")
    self.assert_((  "cell"  == self.C.getCompartmentType() ))
    self.assertEqual( True, self.C.isSetCompartmentType() )
    self.C.unsetCompartmentType()
    self.assertEqual( False, self.C.isSetCompartmentType() )
    pass  

  def test_Compartment_initDefaults(self):
    c = libsbml.Compartment("A", "")
    c.initDefaults()
    self.assert_((  "A" == c.getId() ))
    self.assert_( c.getName() == "" )
    self.assert_( c.getUnits() == "" )
    self.assert_( c.getOutside() == "" )
    self.assert_( c.getSpatialDimensions() == 3 )
    self.assert_( c.getVolume() == 1.0 )
    self.assert_( c.getConstant() == True )
    self.assertEqual( True, c.isSetId() )
    self.assertEqual( False, c.isSetName() )
    self.assertEqual( False, c.isSetSize() )
    self.assertEqual( False, c.isSetVolume() )
    self.assertEqual( False, c.isSetUnits() )
    self.assertEqual( False, c.isSetOutside() )
    c = None
    pass  

  def test_Compartment_setId(self):
    id = "mitochondria"
    self.C.setId(id)
    self.assert_(( id == self.C.getId() ))
    self.assertEqual( True, self.C.isSetId() )
    if (self.C.getId() == id):
      pass    
    self.C.setId(self.C.getId())
    self.assert_(( id == self.C.getId() ))
    self.C.setId("")
    self.assertEqual( False, self.C.isSetId() )
    if (self.C.getId() != None):
      pass    
    pass  

  def test_Compartment_setName(self):
    name = "My Favorite Factory"
    self.C.setName(name)
    self.assert_(( name == self.C.getName() ))
    self.assertEqual( True, self.C.isSetName() )
    if (self.C.getName() == name):
      pass    
    self.C.setName(self.C.getName())
    self.assert_(( name == self.C.getName() ))
    self.C.setName("")
    self.assertEqual( False, self.C.isSetName() )
    if (self.C.getName() != None):
      pass    
    pass  

  def test_Compartment_setOutside(self):
    outside = "cell"
    self.C.setOutside(outside)
    self.assert_(( outside == self.C.getOutside() ))
    self.assertEqual( True, self.C.isSetOutside() )
    if (self.C.getOutside() == outside):
      pass    
    self.C.setOutside(self.C.getOutside())
    self.assert_(( outside == self.C.getOutside() ))
    self.C.setOutside("")
    self.assertEqual( False, self.C.isSetOutside() )
    if (self.C.getOutside() != None):
      pass    
    pass  

  def test_Compartment_setUnits(self):
    units = "volume"
    self.C.setUnits(units)
    self.assert_(( units == self.C.getUnits() ))
    self.assertEqual( True, self.C.isSetUnits() )
    if (self.C.getUnits() == units):
      pass    
    self.C.setUnits(self.C.getUnits())
    self.assert_(( units == self.C.getUnits() ))
    self.C.setUnits("")
    self.assertEqual( False, self.C.isSetUnits() )
    if (self.C.getUnits() != None):
      pass    
    pass  

  def test_Compartment_unsetSize(self):
    self.C.setSize(0.2)
    self.assert_( self.C.getSize() == 0.2 )
    self.assertEqual( True, self.C.isSetSize() )
    self.C.unsetSize()
    self.assertEqual( False, self.C.isSetSize() )
    pass  

  def test_Compartment_unsetVolume(self):
    self.C.setVolume(1.0)
    self.assert_( self.C.getVolume() == 1.0 )
    self.assertEqual( True, self.C.isSetVolume() )
    self.C.unsetVolume()
    self.assertEqual( False, self.C.isSetVolume() )
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestCompartment))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

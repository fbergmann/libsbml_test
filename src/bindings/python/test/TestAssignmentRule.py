#
# @file    TestAssignmentRule.py
# @brief   AssignmentRule unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Ben Bornstein 
#
# $Id:$
# $HeadURL:$
#
# This test file was converted from src/sbml/test/TestAssignmentRule.c
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
import sys
import unittest
import libsbml

class TestAssignmentRule(unittest.TestCase):

  AR = None

  def setUp(self):
    self.AR = libsbml.AssignmentRule()
    if (self.AR == None):
      pass    
    pass  

  def tearDown(self):
    self.AR = None
    pass  

  def test_AssignmentRule_L2_create(self):
    self.assert_( self.AR.getTypeCode() == libsbml.SBML_ASSIGNMENT_RULE )
    self.assert_( self.AR.getMetaId() == "" )
    self.assert_( self.AR.getNotes() == None )
    self.assert_( self.AR.getAnnotation() == None )
    self.assert_( self.AR.getFormula() == "" )
    self.assert_( self.AR.getMath() == None )
    self.assert_( self.AR.getVariable() == "" )
    self.assert_( self.AR.getType() == libsbml.RULE_TYPE_SCALAR )
    pass  

  def test_AssignmentRule_createWithFormula(self):
    ar = libsbml.AssignmentRule("s", "1 + 1")
    self.assert_( ar.getTypeCode() == libsbml.SBML_ASSIGNMENT_RULE )
    self.assert_( ar.getMetaId() == "" )
    self.assert_((  "s" == ar.getVariable() ))
    math = ar.getMath()
    self.assert_( math != None )
    formula = libsbml.formulaToString(math)
    self.assert_( formula != None )
    self.assert_((  "1 + 1" == formula ))
    self.assert_(( formula == ar.getFormula() ))
    ar = None
    pass  

  def test_AssignmentRule_createWithMath(self):
    math = libsbml.parseFormula("1 + 1")
    ar = libsbml.AssignmentRule("s",math)
    self.assert_( ar.getTypeCode() == libsbml.SBML_ASSIGNMENT_RULE )
    self.assert_( ar.getMetaId() == "" )
    self.assert_((  "s" == ar.getVariable() ))
    self.assert_((  "1 + 1" == ar.getFormula() ))
    self.assert_( ar.getMath() != math )
    ar = None
    pass  

  def test_AssignmentRule_free_NULL(self):
    pass  

  def test_AssignmentRule_setVariable(self):
    variable = "x"
    self.AR.setVariable(variable)
    self.assert_(( variable == self.AR.getVariable() ))
    self.assertEqual( True, self.AR.isSetVariable() )
    if (self.AR.getVariable() == variable):
      pass    
    self.AR.setVariable(self.AR.getVariable())
    self.assert_(( variable == self.AR.getVariable() ))
    self.AR.setVariable("")
    self.assertEqual( False, self.AR.isSetVariable() )
    if (self.AR.getVariable() != None):
      pass    
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestAssignmentRule))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

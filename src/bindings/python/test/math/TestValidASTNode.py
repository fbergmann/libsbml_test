#
# @file    TestValidASTNode.py
# @brief   Test the isWellFormedASTNode function
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestValidASTNode.cpp
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


class TestValidASTNode(unittest.TestCase):


  def test_ValidASTNode_Name(self):
    n = libsbml.parseFormula("c")
    self.assertEqual( True, n.isWellFormedASTNode() )
    d = libsbml.parseFormula("d")
    n.addChild(d)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    n = None
    pass  

  def test_ValidASTNode_Number(self):
    n = libsbml.parseFormula("1.2")
    self.assertEqual( True, n.isWellFormedASTNode() )
    d = libsbml.parseFormula("d")
    n.addChild(d)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    n = None
    pass  

  def test_ValidASTNode_binary(self):
    n = libsbml.ASTNode(libsbml.AST_DIVIDE)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    c = libsbml.parseFormula("c")
    n.addChild(c)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    d = libsbml.parseFormula("d")
    n.addChild(d)
    self.assertEqual( True, n.isWellFormedASTNode() )
    n = None
    pass  

  def test_ValidASTNode_lambda(self):
    n = libsbml.ASTNode(libsbml.AST_LAMBDA)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    c = libsbml.parseFormula("c")
    n.addChild(c)
    self.assertEqual( True, n.isWellFormedASTNode() )
    d = libsbml.parseFormula("d")
    n.addChild(d)
    self.assertEqual( True, n.isWellFormedASTNode() )
    e = libsbml.parseFormula("e")
    n.addChild(e)
    self.assertEqual( True, n.isWellFormedASTNode() )
    n = None
    pass  

  def test_ValidASTNode_nary(self):
    n = libsbml.ASTNode(libsbml.AST_TIMES)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    c = libsbml.parseFormula("c")
    n.addChild(c)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    d = libsbml.parseFormula("d")
    n.addChild(d)
    self.assertEqual( True, n.isWellFormedASTNode() )
    e = libsbml.parseFormula("e")
    n.addChild(e)
    self.assertEqual( True, n.isWellFormedASTNode() )
    n = None
    pass  

  def test_ValidASTNode_root(self):
    n = libsbml.ASTNode(libsbml.AST_FUNCTION_ROOT)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    c = libsbml.parseFormula("c")
    n.addChild(c)
    self.assertEqual( True, n.isWellFormedASTNode() )
    d = libsbml.parseFormula("3")
    n.addChild(d)
    self.assertEqual( True, n.isWellFormedASTNode() )
    e = libsbml.parseFormula("3")
    n.addChild(e)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    n = None
    pass  

  def test_ValidASTNode_setType(self):
    n = libsbml.ASTNode()
    i = n.setType(libsbml.AST_REAL)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( n.getType() == libsbml.AST_REAL )
    i = n.setType(libsbml.AST_PLUS)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( n.getType() == libsbml.AST_PLUS )
    c = n.getCharacter()
    self.assert_( c ==  '+'  )
    i = n.setType(libsbml.AST_FUNCTION_ARCCOSH)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCOSH )
    i = n.setType(libsbml.AST_UNKNOWN)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( n.getType() == libsbml.AST_UNKNOWN )
    n = None
    pass  

  def test_ValidASTNode_unary(self):
    n = libsbml.ASTNode(libsbml.AST_FUNCTION_ABS)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    c = libsbml.parseFormula("c")
    n.addChild(c)
    self.assertEqual( True, n.isWellFormedASTNode() )
    d = libsbml.parseFormula("d")
    n.addChild(d)
    self.assertEqual( False, (n.isWellFormedASTNode()) )
    n = None
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestValidASTNode))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

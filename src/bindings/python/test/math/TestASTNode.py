#
# @file    TestASTNode.py
# @brief   ASTNode unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Ben Bornstein 
#
# $Id:$
# $HeadURL:$
#
# This test file was converted from src/sbml/test/TestASTNode.c
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

DBL_EPSILON =  2.2204460492503131e-16

class TestASTNode(unittest.TestCase):


  def test_ASTNode_canonicalizeConstants(self):
    n = libsbml.ASTNode()
    n.setName( "ExponentialE")
    self.assertEqual( True, n.isName() )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_CONSTANT_E )
    n.setType(libsbml.AST_NAME)
    n.setName( "False")
    self.assertEqual( True, n.isName() )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_CONSTANT_FALSE )
    n.setType(libsbml.AST_NAME)
    n.setName( "Pi")
    self.assertEqual( True, n.isName() )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_CONSTANT_PI )
    n.setType(libsbml.AST_NAME)
    n.setName( "True")
    self.assertEqual( True, n.isName() )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_CONSTANT_TRUE )
    n.setType(libsbml.AST_NAME)
    n.setName( "Foo")
    self.assertEqual( True, n.isName() )
    n.canonicalize()
    self.assertEqual( True, n.isName() )
    n = None
    pass  

  def test_ASTNode_canonicalizeFunctions(self):
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "abs")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ABS )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arccos")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCOS )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arccosh")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCOSH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arccot")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCOT )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arccoth")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCOTH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arccsc")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCSC )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arccsch")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCSCH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arcsec")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCSEC )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arcsech")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCSECH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arcsin")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCSIN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arcsinh")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCSINH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arctan")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCTAN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "arctanh")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCTANH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "ceiling")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_CEILING )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "cos")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_COS )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "cosh")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_COSH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "cot")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_COT )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "coth")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_COTH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "csc")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_CSC )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "csch")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_CSCH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "exp")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_EXP )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "factorial")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_FACTORIAL )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "floor")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_FLOOR )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "lambda")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_LAMBDA )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "ln")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_LN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "log")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_LOG )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "piecewise")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_PIECEWISE )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "power")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_POWER )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "root")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ROOT )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "sec")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_SEC )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "sech")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_SECH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "sin")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_SIN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "sinh")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_SINH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "tan")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_TAN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "tanh")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_TANH )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "Foo")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n = None
    pass  

  def test_ASTNode_canonicalizeFunctionsL1(self):
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "acos")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCCOS )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "asin")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCSIN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "atan")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ARCTAN )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "ceil")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_CEILING )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "pow")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_POWER )
    n = None
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "log")
    c = libsbml.ASTNode()
    c.setName( "x")
    n.addChild(c)
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    self.assert_( n.getNumChildren() == 1 )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_LN )
    self.assert_( n.getNumChildren() == 1 )
    n.setType(libsbml.AST_FUNCTION)
    c = libsbml.ASTNode()
    c.setName( "y")
    n.addChild(c)
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    self.assert_( n.getNumChildren() == 2 )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_LOG )
    n = None
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "log10")
    c = libsbml.ASTNode()
    c.setName( "x")
    n.addChild(c)
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    self.assert_( n.getNumChildren() == 1 )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_LOG )
    self.assert_( n.getNumChildren() == 2 )
    c = n.getLeftChild()
    self.assert_( c.getType() == libsbml.AST_INTEGER )
    self.assert_( c.getInteger() == 10 )
    c = n.getRightChild()
    self.assert_( c.getType() == libsbml.AST_NAME )
    self.assert_((  "x" == c.getName() ))
    n = None
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "sqr")
    c = libsbml.ASTNode()
    c.setName( "x")
    n.addChild(c)
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    self.assert_( n.getNumChildren() == 1 )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_POWER )
    self.assert_( n.getNumChildren() == 2 )
    c = n.getLeftChild()
    self.assert_( c.getType() == libsbml.AST_NAME )
    self.assert_((  "x" == c.getName() ))
    c = n.getRightChild()
    self.assert_( c.getType() == libsbml.AST_INTEGER )
    self.assert_( c.getInteger() == 2 )
    n = None
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "sqrt")
    c = libsbml.ASTNode()
    c.setName( "x")
    n.addChild(c)
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    self.assert_( n.getNumChildren() == 1 )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_FUNCTION_ROOT )
    self.assert_( n.getNumChildren() == 2 )
    c = n.getLeftChild()
    self.assert_( c.getType() == libsbml.AST_INTEGER )
    self.assert_( c.getInteger() == 2 )
    c = n.getRightChild()
    self.assert_( c.getType() == libsbml.AST_NAME )
    self.assert_((  "x" == c.getName() ))
    n = None
    pass  

  def test_ASTNode_canonicalizeLogical(self):
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "and")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_LOGICAL_AND )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "not")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_LOGICAL_NOT )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "or")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_LOGICAL_OR )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "xor")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_LOGICAL_XOR )
    n.setType(libsbml.AST_FUNCTION)
    n = None
    pass  

  def test_ASTNode_canonicalizeRelational(self):
    n = libsbml.ASTNode(libsbml.AST_FUNCTION)
    n.setName( "eq")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_RELATIONAL_EQ )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "geq")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_RELATIONAL_GEQ )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "gt")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_RELATIONAL_GT )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "leq")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_RELATIONAL_LEQ )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "lt")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_RELATIONAL_LT )
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "neq")
    self.assert_( n.getType() == libsbml.AST_FUNCTION )
    n.canonicalize()
    self.assert_( n.getType() == libsbml.AST_RELATIONAL_NEQ )
    n.setType(libsbml.AST_FUNCTION)
    n = None
    pass  

  def test_ASTNode_children(self):
    parent = libsbml.ASTNode()
    left = libsbml.ASTNode()
    right = libsbml.ASTNode()
    right2 = libsbml.ASTNode()
    parent.setType(libsbml.AST_PLUS)
    left.setValue(1)
    right.setValue(2)
    right2.setValue(3)
    parent.addChild(left)
    parent.addChild(right)
    self.assert_( parent.getNumChildren() == 2 )
    self.assert_( left.getNumChildren() == 0 )
    self.assert_( right.getNumChildren() == 0 )
    self.assert_( parent.getLeftChild() == left )
    self.assert_( parent.getRightChild() == right )
    self.assert_( parent.getChild(0) == left )
    self.assert_( parent.getChild(1) == right )
    self.assert_( parent.getChild(2) == None )
    parent.addChild(right2)
    self.assert_( parent.getNumChildren() == 3 )
    self.assert_( left.getNumChildren() == 0 )
    self.assert_( right.getNumChildren() == 0 )
    self.assert_( right2.getNumChildren() == 0 )
    self.assert_( parent.getLeftChild() == left )
    self.assert_( parent.getRightChild() == right2 )
    self.assert_( parent.getChild(0) == left )
    self.assert_( parent.getChild(1) == right )
    self.assert_( parent.getChild(2) == right2 )
    self.assert_( parent.getChild(3) == None )
    parent = None
    pass  

  def test_ASTNode_create(self):
    n = libsbml.ASTNode()
    ea = libsbml.EventAssignment()
    self.assert_( n.getType() == libsbml.AST_UNKNOWN )
    self.assert_( n.getCharacter() ==  '\0'  )
    self.assert_( n.getName() == None )
    self.assert_( n.getInteger() == 0 )
    self.assert_( n.getExponent() == 0 )
    self.assert_( n.getNumChildren() == 0 )
    self.assert_( n.getParentSBMLObject() == None )
    ea = None
    n = None
    pass  

  def test_ASTNode_deepCopy_1(self):
    node = libsbml.ASTNode()
    node.setCharacter( '+')
    node.addChild(libsbml.ASTNode())
    node.addChild(libsbml.ASTNode())
    node.getLeftChild().setValue(1)
    node.getRightChild().setValue(2)
    self.assert_( node.getType() == libsbml.AST_PLUS )
    self.assert_( node.getCharacter() ==  '+'       )
    self.assert_( node.getNumChildren() == 2 )
    child = node.getLeftChild()
    self.assert_( child.getType() == libsbml.AST_INTEGER )
    self.assert_( child.getInteger() == 1 )
    self.assert_( child.getNumChildren() == 0 )
    child = node.getRightChild()
    self.assert_( child.getType() == libsbml.AST_INTEGER )
    self.assert_( child.getInteger() == 2 )
    self.assert_( child.getNumChildren() == 0 )
    copy = node.deepCopy()
    self.assert_( copy != node )
    self.assert_( copy.getType() == libsbml.AST_PLUS )
    self.assert_( copy.getCharacter() ==  '+'       )
    self.assert_( copy.getNumChildren() == 2 )
    child = copy.getLeftChild()
    self.assert_( child != node.getLeftChild() )
    self.assert_( child.getType() == libsbml.AST_INTEGER )
    self.assert_( child.getInteger() == 1 )
    self.assert_( child.getNumChildren() == 0 )
    child = copy.getRightChild()
    self.assert_( child != node.getRightChild() )
    self.assert_( child.getType() == libsbml.AST_INTEGER )
    self.assert_( child.getInteger() == 2 )
    self.assert_( child.getNumChildren() == 0 )
    node = None
    copy = None
    pass  

  def test_ASTNode_deepCopy_2(self):
    node = libsbml.ASTNode()
    node.setName( "Foo")
    self.assert_( node.getType() == libsbml.AST_NAME )
    self.assert_((  "Foo" == node.getName() ))
    self.assert_( node.getNumChildren() == 0 )
    copy = node.deepCopy()
    self.assert_( copy != node )
    self.assert_( copy.getType() == libsbml.AST_NAME )
    self.assert_((  "Foo" == copy.getName() ))
    self.assert_( copy.getNumChildren() == 0 )
    node = None
    copy = None
    pass  

  def test_ASTNode_deepCopy_3(self):
    node = libsbml.ASTNode(libsbml.AST_FUNCTION)
    node.setName( "Foo")
    self.assert_( node.getType() == libsbml.AST_FUNCTION )
    self.assert_((  "Foo" == node.getName() ))
    self.assert_( node.getNumChildren() == 0 )
    copy = node.deepCopy()
    self.assert_( copy != node )
    self.assert_( copy.getType() == libsbml.AST_FUNCTION )
    self.assert_((  "Foo" == copy.getName() ))
    self.assert_( copy.getNumChildren() == 0 )
    node = None
    copy = None
    pass  

  def test_ASTNode_deepCopy_4(self):
    node = libsbml.ASTNode(libsbml.AST_FUNCTION_ABS)
    node.setName( "ABS")
    self.assert_( node.getType() == libsbml.AST_FUNCTION_ABS )
    self.assert_((  "ABS" == node.getName() ))
    self.assert_( node.getNumChildren() == 0 )
    copy = node.deepCopy()
    self.assert_( copy != node )
    self.assert_( copy.getType() == libsbml.AST_FUNCTION_ABS )
    self.assert_((  "ABS" == copy.getName() ))
    self.assert_( copy.getNumChildren() == 0 )
    node = None
    copy = None
    pass  

  def test_ASTNode_free_NULL(self):
    pass  

  def test_ASTNode_getName(self):
    n = libsbml.ASTNode()
    n.setName( "foo")
    self.assert_((  "foo" == n.getName() ))
    n.setType(libsbml.AST_NAME_TIME)
    self.assert_((  "foo" == n.getName() ))
    n.setName(None)
    self.assert_( n.getName() == None )
    n.setType(libsbml.AST_CONSTANT_E)
    self.assert_((  "exponentiale" == n.getName() ))
    n.setType(libsbml.AST_CONSTANT_FALSE)
    self.assert_((  "false" == n.getName() ))
    n.setType(libsbml.AST_CONSTANT_PI)
    self.assert_((  "pi" == n.getName() ))
    n.setType(libsbml.AST_CONSTANT_TRUE)
    self.assert_((  "true" == n.getName() ))
    n.setType(libsbml.AST_LAMBDA)
    self.assert_((  "lambda" == n.getName() ))
    n.setType(libsbml.AST_FUNCTION)
    n.setName( "f")
    self.assert_((  "f" == n.getName() ))
    n.setType(libsbml.AST_FUNCTION_DELAY)
    self.assert_((  "f" == n.getName() ))
    n.setName(None)
    self.assert_((  "delay" == n.getName() ))
    n.setType(libsbml.AST_FUNCTION)
    self.assert_( n.getName() == None )
    n.setType(libsbml.AST_FUNCTION_ABS)
    self.assert_((  "abs" == n.getName() ))
    n.setType(libsbml.AST_FUNCTION_ARCCOS)
    self.assert_((  "arccos" == n.getName() ))
    n.setType(libsbml.AST_FUNCTION_TAN)
    self.assert_((  "tan" == n.getName() ))
    n.setType(libsbml.AST_FUNCTION_TANH)
    self.assert_((  "tanh" == n.getName() ))
    n.setType(libsbml.AST_LOGICAL_AND)
    self.assert_((  "and" == n.getName() ))
    n.setType(libsbml.AST_LOGICAL_NOT)
    self.assert_((  "not" == n.getName() ))
    n.setType(libsbml.AST_LOGICAL_OR)
    self.assert_((  "or" == n.getName() ))
    n.setType(libsbml.AST_LOGICAL_XOR)
    self.assert_((  "xor" == n.getName() ))
    n.setType(libsbml.AST_RELATIONAL_EQ)
    self.assert_((  "eq" == n.getName() ))
    n.setType(libsbml.AST_RELATIONAL_GEQ)
    self.assert_((  "geq" == n.getName() ))
    n.setType(libsbml.AST_RELATIONAL_LT)
    self.assert_((  "lt" == n.getName() ))
    n.setType(libsbml.AST_RELATIONAL_NEQ)
    self.assert_((  "neq" == n.getName() ))
    n = None
    pass  

  def test_ASTNode_getPrecedence(self):
    n = libsbml.ASTNode()
    n.setType(libsbml.AST_PLUS)
    self.assert_( n.getPrecedence() == 2 )
    n.setType(libsbml.AST_MINUS)
    self.assert_( n.getPrecedence() == 2 )
    n.setType(libsbml.AST_TIMES)
    self.assert_( n.getPrecedence() == 3 )
    n.setType(libsbml.AST_DIVIDE)
    self.assert_( n.getPrecedence() == 3 )
    n.setType(libsbml.AST_POWER)
    self.assert_( n.getPrecedence() == 4 )
    n.setType(libsbml.AST_MINUS)
    n.addChild(libsbml.ASTNode(libsbml.AST_NAME))
    self.assert_( n.isUMinus() == True )
    self.assert_( n.getPrecedence() == 5 )
    n.setType(libsbml.AST_NAME)
    self.assert_( n.getPrecedence() == 6 )
    n.setType(libsbml.AST_FUNCTION)
    self.assert_( n.getPrecedence() == 6 )
    n = None
    pass  

  def test_ASTNode_getReal(self):
    n = libsbml.ASTNode()
    n.setType(libsbml.AST_REAL)
    n.setValue(1.6)
    self.assert_( n.getReal() == 1.6 )
    n.setType(libsbml.AST_REAL_E)
    n.setValue(12.3,3)
    self.assert_( abs(n.getReal() - 12300.0) < DBL_EPSILON )
    n.setType(libsbml.AST_RATIONAL)
    n.setValue(1,2)
    self.assert_( n.getReal() == 0.5 )
    n = None
    pass  

  def test_ASTNode_insertChild(self):
    node = libsbml.ASTNode()
    c1 = libsbml.ASTNode()
    c2 = libsbml.ASTNode()
    c3 = libsbml.ASTNode()
    newc = libsbml.ASTNode()
    newc1 = libsbml.ASTNode()
    i = 0
    node.setType(libsbml.AST_LOGICAL_AND)
    c1.setName( "a")
    c2.setName( "b")
    c3.setName( "c")
    node.addChild(c1)
    node.addChild(c2)
    node.addChild(c3)
    self.assert_( node.getNumChildren() == 3 )
    self.assert_((  "and(a, b, c)" == libsbml.formulaToString(node) ))
    newc.setName( "d")
    newc1.setName( "e")
    i = node.insertChild(1,newc)
    self.assert_( i == 0 )
    self.assert_( node.getNumChildren() == 4 )
    self.assert_((  "and(a, d, b, c)" == libsbml.formulaToString(node) ))
    i = node.insertChild(5,newc)
    self.assert_( i ==  - 1 )
    self.assert_( node.getNumChildren() == 4 )
    self.assert_((  "and(a, d, b, c)" == libsbml.formulaToString(node) ))
    i = node.insertChild(2,newc1)
    self.assert_( i == 0 )
    self.assert_( node.getNumChildren() == 5 )
    self.assert_((  "and(a, d, e, b, c)" == libsbml.formulaToString(node) ))
    node = None
    pass  

  def test_ASTNode_isLog10(self):
    n = libsbml.ASTNode()
    n.setType(libsbml.AST_FUNCTION)
    self.assert_( n.isLog10() == False )
    n.setType(libsbml.AST_FUNCTION_LOG)
    self.assert_( n.isLog10() == False )
    c = libsbml.ASTNode()
    n.addChild(c)
    c.setValue(10)
    self.assert_( n.isLog10() == False )
    n.addChild(libsbml.ASTNode())
    self.assert_( n.isLog10() == True )
    c.setValue(2)
    self.assert_( n.isLog10() == False )
    n = None
    pass  

  def test_ASTNode_isSqrt(self):
    n = libsbml.ASTNode()
    n.setType(libsbml.AST_FUNCTION)
    self.assert_( n.isSqrt() == False )
    n.setType(libsbml.AST_FUNCTION_ROOT)
    self.assert_( n.isSqrt() == False )
    c = libsbml.ASTNode()
    n.addChild(c)
    c.setValue(2)
    self.assert_( n.isSqrt() == False )
    n.addChild(libsbml.ASTNode())
    self.assert_( n.isSqrt() == True )
    c.setValue(3)
    self.assert_( n.isSqrt() == False )
    n = None
    pass  

  def test_ASTNode_isUMinus(self):
    n = libsbml.ASTNode()
    n.setType(libsbml.AST_MINUS)
    self.assert_( n.isUMinus() == False )
    n.addChild(libsbml.ASTNode(libsbml.AST_NAME))
    self.assert_( n.isUMinus() == True )
    n = None
    pass  

  def test_ASTNode_no_children(self):
    node = libsbml.ASTNode()
    self.assert_( node.getNumChildren() == 0 )
    self.assert_( node.getLeftChild() == None )
    self.assert_( node.getRightChild() == None )
    self.assert_( node.getChild(0) == None )
    node = None
    pass  

  def test_ASTNode_one_child(self):
    node = libsbml.ASTNode()
    child = libsbml.ASTNode()
    node.addChild(child)
    self.assert_( node.getNumChildren() == 1 )
    self.assert_( node.getLeftChild() == child )
    self.assert_( node.getRightChild() == None )
    self.assert_( node.getChild(0) == child )
    self.assert_( node.getChild(1) == None )
    node = None
    pass  

  def test_ASTNode_removeChild(self):
    node = libsbml.ASTNode()
    c1 = libsbml.ASTNode()
    c2 = libsbml.ASTNode()
    i = 0
    node.setType(libsbml.AST_PLUS)
    c1.setName( "foo")
    c2.setName( "foo2")
    node.addChild(c1)
    node.addChild(c2)
    self.assert_( node.getNumChildren() == 2 )
    i = node.removeChild(0)
    self.assert_( i == 0 )
    self.assert_( node.getNumChildren() == 1 )
    i = node.removeChild(1)
    self.assert_( i ==  - 1 )
    self.assert_( node.getNumChildren() == 1 )
    i = node.removeChild(0)
    self.assert_( i == 0 )
    self.assert_( node.getNumChildren() == 0 )
    node = None
    pass  

  def test_ASTNode_replaceChild(self):
    node = libsbml.ASTNode()
    c1 = libsbml.ASTNode()
    c2 = libsbml.ASTNode()
    c3 = libsbml.ASTNode()
    newc = libsbml.ASTNode()
    i = 0
    node.setType(libsbml.AST_LOGICAL_AND)
    c1.setName( "a")
    c2.setName( "b")
    c3.setName( "c")
    node.addChild(c1)
    node.addChild(c2)
    node.addChild(c3)
    self.assert_( node.getNumChildren() == 3 )
    self.assert_((  "and(a, b, c)" == libsbml.formulaToString(node) ))
    newc.setName( "d")
    i = node.replaceChild(0,newc)
    self.assert_( i == 0 )
    self.assert_( node.getNumChildren() == 3 )
    self.assert_((  "and(d, b, c)" == libsbml.formulaToString(node) ))
    i = node.replaceChild(3,newc)
    self.assert_( i ==  - 1 )
    self.assert_( node.getNumChildren() == 3 )
    self.assert_((  "and(d, b, c)" == libsbml.formulaToString(node) ))
    i = node.replaceChild(1,c1)
    self.assert_( i == 0 )
    self.assert_( node.getNumChildren() == 3 )
    self.assert_((  "and(d, a, c)" == libsbml.formulaToString(node) ))
    node = None
    pass  

  def test_ASTNode_setCharacter(self):
    node = libsbml.ASTNode()
    node.setName( "foo")
    self.assert_( node.getType() == libsbml.AST_NAME )
    self.assert_( node.getCharacter() == '\0' )
    self.assert_((  "foo" == node.getName() ))
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setCharacter( '+')
    self.assert_( node.getType() == libsbml.AST_PLUS )
    self.assert_( node.getCharacter() ==  '+'       )
    self.assert_( node.getName() == None )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setCharacter( '-')
    self.assert_( node.getType() == libsbml.AST_MINUS )
    self.assert_( node.getCharacter() ==  '-'        )
    self.assert_( node.getName() == None )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setCharacter( '*')
    self.assert_( node.getType() == libsbml.AST_TIMES )
    self.assert_( node.getCharacter() ==  '*'        )
    self.assert_( node.getName() == None )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setCharacter( '/')
    self.assert_( node.getType() == libsbml.AST_DIVIDE )
    self.assert_( node.getCharacter() ==  '/'         )
    self.assert_( node.getName() == None )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setCharacter( '^')
    self.assert_( node.getType() == libsbml.AST_POWER )
    self.assert_( node.getCharacter() ==  '^'        )
    self.assert_( node.getName() == None )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setCharacter( '$')
    self.assert_( node.getType() == libsbml.AST_UNKNOWN )
    self.assert_( node.getCharacter() ==  '$'          )
    self.assert_( node.getName() == None )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node = None
    pass  

  def test_ASTNode_setInteger(self):
    node = libsbml.ASTNode()
    node.setName( "foo")
    self.assert_( node.getType() == libsbml.AST_NAME )
    self.assert_((  "foo" == node.getName() ))
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setValue(3.2)
    self.assert_( node.getType() == libsbml.AST_REAL )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getName() == None )
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getReal() == 3.2 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setValue(321)
    self.assert_( node.getType() == libsbml.AST_INTEGER )
    self.assert_( node.getInteger() == 321 )
    self.assert_( node.getName() == None )
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node = None
    pass  

  def test_ASTNode_setName(self):
    name =  "foo";
    node = libsbml.ASTNode()
    self.assert_( node.getType() == libsbml.AST_UNKNOWN )
    node.setName(name)
    self.assert_( node.getType() == libsbml.AST_NAME )
    self.assert_(( name == node.getName() ))
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    if (node.getName() == name):
      pass    
    node.setName(None)
    self.assert_( node.getType() == libsbml.AST_NAME )
    if (node.getName() != None):
      pass    
    node.setType(libsbml.AST_FUNCTION_COS)
    self.assert_( node.getType() == libsbml.AST_FUNCTION_COS )
    self.assert_((  "cos" == node.getName() ))
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node.setType(libsbml.AST_PLUS)
    node.setName(name)
    self.assert_( node.getType() == libsbml.AST_NAME )
    self.assert_(( name == node.getName() ))
    self.assert_( node.getCharacter() ==  '+'         )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getReal() == 0 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    node = None
    pass  

  def test_ASTNode_setName_override(self):
    node = libsbml.ASTNode(libsbml.AST_FUNCTION_SIN)
    self.assert_((  "sin" == node.getName() ))
    self.assert_( node.getType() == libsbml.AST_FUNCTION_SIN )
    node.setName( "MySinFunc")
    self.assert_((  "MySinFunc" == node.getName() ))
    self.assert_( node.getType() == libsbml.AST_FUNCTION_SIN )
    node.setName(None)
    self.assert_((  "sin" == node.getName() ))
    self.assert_( node.getType() == libsbml.AST_FUNCTION_SIN )
    node = None
    pass  

  def test_ASTNode_setReal(self):
    node = libsbml.ASTNode()
    node.setName( "foo")
    self.assert_( node.getType() == libsbml.AST_NAME )
    node.setValue(32.1)
    self.assert_( node.getType() == libsbml.AST_REAL )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getName() == None )
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getReal() == 32.1 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 1 )
    self.assert_( node.getMantissa() == 32.1 )
    node.setValue(45,90)
    self.assert_( node.getType() == libsbml.AST_RATIONAL )
    self.assert_( node.getInteger() == 45 )
    self.assert_( node.getName() == None )
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getReal() == 0.5 )
    self.assert_( node.getExponent() == 0 )
    self.assert_( node.getDenominator() == 90 )
    self.assert_( node.getMantissa() == 0 )
    node.setValue(32.0,4)
    self.assert_( node.getType() == libsbml.AST_REAL_E )
    self.assert_( node.getInteger() == 0 )
    self.assert_( node.getName() == None )
    self.assert_( node.getCharacter() == '\0' )
    self.assert_( node.getReal() == 320000 )
    self.assert_( node.getExponent() == 4 )
    self.assert_( node.getDenominator() == 1 )
    self.assert_( node.getMantissa() == 32 )
    node = None
    pass  

  def test_ASTNode_setType(self):
    node = libsbml.ASTNode()
    node.setName( "foo")
    self.assert_( node.getType() == libsbml.AST_NAME )
    node.setType(libsbml.AST_FUNCTION)
    self.assert_( node.getType() == libsbml.AST_FUNCTION )
    self.assert_((  "foo" == node.getName() ))
    node.setType(libsbml.AST_NAME)
    self.assert_( node.getType() == libsbml.AST_NAME )
    self.assert_((  "foo" == node.getName() ))
    node.setType(libsbml.AST_INTEGER)
    self.assert_( node.getType() == libsbml.AST_INTEGER )
    node.setType(libsbml.AST_REAL)
    self.assert_( node.getType() == libsbml.AST_REAL )
    node.setType(libsbml.AST_UNKNOWN)
    self.assert_( node.getType() == libsbml.AST_UNKNOWN )
    node.setType(libsbml.AST_PLUS)
    self.assert_( node.getType() == libsbml.AST_PLUS )
    self.assert_( node.getCharacter() ==  '+'       )
    node.setType(libsbml.AST_MINUS)
    self.assert_( node.getType() == libsbml.AST_MINUS )
    self.assert_( node.getCharacter() ==  '-'        )
    node.setType(libsbml.AST_TIMES)
    self.assert_( node.getType() == libsbml.AST_TIMES )
    self.assert_( node.getCharacter() ==  '*'        )
    node.setType(libsbml.AST_DIVIDE)
    self.assert_( node.getType() == libsbml.AST_DIVIDE )
    self.assert_( node.getCharacter() ==  '/'         )
    node.setType(libsbml.AST_POWER)
    self.assert_( node.getType() == libsbml.AST_POWER )
    self.assert_( node.getCharacter() ==  '^'        )
    node = None
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestASTNode))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

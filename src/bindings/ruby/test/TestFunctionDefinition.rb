#
# @file    TestFunctionDefinition.rb
# @brief   SBML FunctionDefinition unit tests
# @author  Akiya Jouraku (Ruby conversion)
# @author  Ben Bornstein 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestFunctionDefinition.c
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
require 'test/unit'
require 'libSBML'

class TestFunctionDefinition < Test::Unit::TestCase

  def setup
    @@fd = LibSBML::FunctionDefinition.new
    if (@@fd == nil)
    end
  end

  def teardown
    @@fd = nil
  end

  def test_FunctionDefinition_create
    assert( @@fd.getTypeCode == LibSBML::SBML_FUNCTION_DEFINITION )
    assert( @@fd.getMetaId == "" )
    assert( @@fd.getNotes == nil )
    assert( @@fd.getAnnotation == nil )
    assert( @@fd.getId == "" )
    assert( @@fd.getName == "" )
    assert( @@fd.getMath == nil )
  end

  def test_FunctionDefinition_createWith
    math = LibSBML::parseFormula("lambda(x, x^3)")
    fd = LibSBML::FunctionDefinition.new("pow3",math)
    assert( fd.getTypeCode == LibSBML::SBML_FUNCTION_DEFINITION )
    assert( fd.getMetaId == "" )
    assert( fd.getNotes == nil )
    assert( fd.getAnnotation == nil )
    assert( fd.getName == "" )
    math1 = fd.getMath
    assert( math1 != nil )
    formula = LibSBML::formulaToString(math1)
    assert( formula != nil )
    assert ((  "lambda(x, x^3)" == formula ))
    assert( fd.getMath != math )
    assert_equal true, fd.isSetMath
    assert ((  "pow3" == fd.getId ))
    assert_equal true, fd.isSetId
    math = nil
    fd = nil
  end

  def test_FunctionDefinition_free_NULL
    
  end

  def test_FunctionDefinition_getArguments
    @@fd.setMath(LibSBML::parseFormula("lambda(x, y, x^y)"))
    assert( @@fd.getNumArguments == 2 )
    math = @@fd.getArgument(0)
    assert( math != nil )
    assert_equal true, math.isName
    assert ((  "x" == math.getName ))
    assert( math.getNumChildren == 0 )
    math = @@fd.getArgument(1)
    assert( math != nil )
    assert_equal true, math.isName
    assert ((  "y" == math.getName ))
    assert( math.getNumChildren == 0 )
    assert( @@fd.getArgument(0) == @@fd.getArgument( "x") )
    assert( @@fd.getArgument(1) == @@fd.getArgument( "y") )
  end

  def test_FunctionDefinition_getBody
    math1 = LibSBML::parseFormula("lambda(x, x)")
    @@fd.setMath(math1)
    math = @@fd.getBody
    assert( math != nil )
    assert_equal true, math.isName
    assert ((  "x" == math.getName ))
    assert( math.getNumChildren == 0 )
    math1 = nil
  end

  def test_FunctionDefinition_setId
    id = "pow3"
    @@fd.setId(id)
    assert (( id == @@fd.getId ))
    assert_equal true, @@fd.isSetId
    if (@@fd.getId == id)
    end
    @@fd.setId(@@fd.getId)
    assert (( id == @@fd.getId ))
    @@fd.setId("")
    assert_equal false, @@fd.isSetId
    if (@@fd.getId != nil)
    end
  end

  def test_FunctionDefinition_setMath
    math = LibSBML::parseFormula("lambda(x, x^3)")
    @@fd.setMath(math)
    math1 = @@fd.getMath
    assert( math1 != nil )
    formula = LibSBML::formulaToString(math1)
    assert( formula != nil )
    assert ((  "lambda(x, x^3)" == formula ))
    assert( @@fd.getMath != math )
    assert_equal true, @@fd.isSetMath
    @@fd.setMath(@@fd.getMath)
    math1 = @@fd.getMath
    assert( math1 != nil )
    formula = LibSBML::formulaToString(math1)
    assert( formula != nil )
    assert ((  "lambda(x, x^3)" == formula ))
    assert( @@fd.getMath != math )
    @@fd.setMath(nil)
    assert_equal false, @@fd.isSetMath
    if (@@fd.getMath != nil)
    end
  end

  def test_FunctionDefinition_setName
    name = "Cube Me"
    @@fd.setName(name)
    assert (( name == @@fd.getName ))
    assert_equal true, @@fd.isSetName
    if (@@fd.getName == name)
    end
    @@fd.setName(@@fd.getName)
    assert (( name == @@fd.getName ))
    @@fd.setName("")
    assert_equal false, @@fd.isSetName
    if (@@fd.getName != nil)
    end
  end

end

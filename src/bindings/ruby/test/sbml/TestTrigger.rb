#
# @file    TestTrigger.rb
# @brief   SBML Trigger unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Sarah Keating 
#
# $Id:$
# $HeadURL:$
#
# This test file was converted from src/sbml/test/TestTrigger.c
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
require 'test/unit'
require 'libSBML'

class TestTrigger < Test::Unit::TestCase

  def setup
    @@d = LibSBML::Trigger.new()
    if (@@d == nil)
    end
  end

  def teardown
    @@d = nil
  end

  def test_Trigger_create
    assert( @@d.getTypeCode() == LibSBML::SBML_TRIGGER )
    assert( @@d.getMetaId() == "" )
    assert( @@d.getNotes() == nil )
    assert( @@d.getAnnotation() == nil )
    assert( @@d.getMath() == nil )
  end

  def test_Trigger_createWithLevelVersionAndNamespace
    xmlns = LibSBML::XMLNamespaces.new()
    xmlns.add( "http://www.sbml.org", "sbml")
    object = LibSBML::Trigger.new(2,1,xmlns)
    assert( object.getTypeCode() == LibSBML::SBML_TRIGGER )
    assert( object.getMetaId() == "" )
    assert( object.getNotes() == nil )
    assert( object.getAnnotation() == nil )
    assert( object.getLevel() == 2 )
    assert( object.getVersion() == 1 )
    assert( object.getNamespaces() != "" )
    assert( object.getNamespaces().getLength() == 1 )
    object = nil
  end

  def test_Trigger_createWithMath
    math = LibSBML::parseFormula("x^3")
    fd = LibSBML::Trigger.new(math)
    assert( fd.getTypeCode() == LibSBML::SBML_TRIGGER )
    assert( fd.getMetaId() == "" )
    assert( fd.getNotes() == nil )
    assert( fd.getAnnotation() == nil )
    math1 = fd.getMath()
    assert( math1 != nil )
    formula = LibSBML::formulaToString(math1)
    assert( formula != nil )
    assert ((  "x^3" == formula ))
    assert( fd.getMath() != math )
    assert_equal true, fd.isSetMath()
    fd = nil
  end

  def test_Trigger_free_NULL
  end

  def test_Trigger_setMath
    math = LibSBML::parseFormula("lambda(x, x^3)")
    @@d.setMath(math)
    math1 = @@d.getMath()
    assert( math1 != nil )
    formula = LibSBML::formulaToString(math1)
    assert( formula != nil )
    assert ((  "lambda(x, x^3)" == formula ))
    assert( @@d.getMath() != math )
    assert_equal true, @@d.isSetMath()
    @@d.setMath(@@d.getMath())
    math1 = @@d.getMath()
    assert( math1 != nil )
    formula = LibSBML::formulaToString(math1)
    assert( formula != nil )
    assert ((  "lambda(x, x^3)" == formula ))
    @@d.setMath(nil)
    assert_equal false, @@d.isSetMath()
    if (@@d.getMath() != nil)
    end
  end

end

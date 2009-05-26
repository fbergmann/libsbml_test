#
# @file    TestSBMLNamespaces.rb
# @brief   SBMLNamespaces unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestSBMLNamespaces.cpp
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
require 'test/unit'
require 'libSBML'

class TestSBMLNamespaces < Test::Unit::TestCase

  def test_SBMLNamespaces_L1V1
    sbml = LibSBML::SBMLNamespaces.new(1,1)
    assert( sbml.getLevel() == 1 )
    assert( sbml.getVersion() == 1 )
    ns = sbml.getNamespaces()
    assert( ns.getLength() == 1 )
    assert( ns.getURI(0) ==  "http://www.sbml.org/sbml/level1" )
    assert( ns.getPrefix(0) ==  "sbml" )
    sbml = nil
  end

  def test_SBMLNamespaces_L1V2
    sbml = LibSBML::SBMLNamespaces.new(1,2)
    assert( sbml.getLevel() == 1 )
    assert( sbml.getVersion() == 2 )
    ns = sbml.getNamespaces()
    assert( ns.getLength() == 1 )
    assert( ns.getURI(0) ==  "http://www.sbml.org/sbml/level1" )
    assert( ns.getPrefix(0) ==  "sbml" )
    sbml = nil
  end

  def test_SBMLNamespaces_L2V1
    sbml = LibSBML::SBMLNamespaces.new(2,1)
    assert( sbml.getLevel() == 2 )
    assert( sbml.getVersion() == 1 )
    ns = sbml.getNamespaces()
    assert( ns.getLength() == 1 )
    assert( ns.getURI(0) ==  "http://www.sbml.org/sbml/level2" )
    assert( ns.getPrefix(0) ==  "sbml" )
    sbml = nil
  end

  def test_SBMLNamespaces_L2V2
    sbml = LibSBML::SBMLNamespaces.new(2,2)
    assert( sbml.getLevel() == 2 )
    assert( sbml.getVersion() == 2 )
    ns = sbml.getNamespaces()
    assert( ns.getLength() == 1 )
    assert( ns.getURI(0) ==  "http://www.sbml.org/sbml/level2/version2" )
    assert( ns.getPrefix(0) ==  "sbml" )
    sbml = nil
  end

  def test_SBMLNamespaces_L2V3
    sbml = LibSBML::SBMLNamespaces.new(2,3)
    assert( sbml.getLevel() == 2 )
    assert( sbml.getVersion() == 3 )
    ns = sbml.getNamespaces()
    assert( ns.getLength() == 1 )
    assert( ns.getURI(0) ==  "http://www.sbml.org/sbml/level2/version3" )
    assert( ns.getPrefix(0) ==  "sbml" )
    sbml = nil
  end

  def test_SBMLNamespaces_L2V4
    sbml = LibSBML::SBMLNamespaces.new(2,4)
    assert( sbml.getLevel() == 2 )
    assert( sbml.getVersion() == 4 )
    ns = sbml.getNamespaces()
    assert( ns.getLength() == 1 )
    assert( ns.getURI(0) ==  "http://www.sbml.org/sbml/level2/version4" )
    assert( ns.getPrefix(0) ==  "sbml" )
    sbml = nil
  end

  def test_SBMLNamespaces_getURI
    assert( LibSBML::SBMLNamespaces.getSBMLNamespaceURI(1,1) ==                              "http://www.sbml.org/sbml/level1" )
    assert( LibSBML::SBMLNamespaces.getSBMLNamespaceURI(1,2) ==                              "http://www.sbml.org/sbml/level1" )
    assert( LibSBML::SBMLNamespaces.getSBMLNamespaceURI(2,1) ==                              "http://www.sbml.org/sbml/level2" )
    assert( LibSBML::SBMLNamespaces.getSBMLNamespaceURI(2,2) ==                              "http://www.sbml.org/sbml/level2/version2" )
    assert( LibSBML::SBMLNamespaces.getSBMLNamespaceURI(2,3) ==                              "http://www.sbml.org/sbml/level2/version3" )
    assert( LibSBML::SBMLNamespaces.getSBMLNamespaceURI(2,4) ==                              "http://www.sbml.org/sbml/level2/version4" )
  end

end

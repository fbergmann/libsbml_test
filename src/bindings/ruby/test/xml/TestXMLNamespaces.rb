#
# @file    TestXMLNamespaces.rb
# @brief   XMLNamespaces unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Michael Hucka <mhucka@caltech.edu> 
#
# $Id:$
# $HeadURL:$
#
# This test file was converted from src/sbml/test/TestXMLNamespaces.c
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

class TestXMLNamespaces < Test::Unit::TestCase

  def setup
    @@ns = LibSBML::XMLNamespaces.new()
    if (@@ns == nil)
    end
  end

  def teardown
    @@ns = nil
  end

  def test_XMLNamespaces_add
    assert( @@ns.getLength() == 0 )
    assert( @@ns.isEmpty() == true )
    @@ns.add( "http://test1.org/", "test1")
    assert( @@ns.getLength() == 1 )
    assert( @@ns.isEmpty() == false )
    @@ns.add( "http://test2.org/", "test2")
    assert( @@ns.getLength() == 2 )
    assert( @@ns.isEmpty() == false )
    @@ns.add( "http://test1.org/", "test1a")
    assert( @@ns.getLength() == 3 )
    assert( @@ns.isEmpty() == false )
    @@ns.add( "http://test1.org/", "test1a")
    assert( @@ns.getLength() == 3 )
    assert( @@ns.isEmpty() == false )
    assert( !( @@ns.getIndex( "http://test1.org/") == -1) )
  end

  def test_XMLNamespaces_baseline
    assert( @@ns.getLength() == 0 )
    assert( @@ns.isEmpty() == true )
  end

  def test_XMLNamespaces_get
    @@ns.add( "http://test1.org/", "test1")
    @@ns.add( "http://test2.org/", "test2")
    @@ns.add( "http://test3.org/", "test3")
    @@ns.add( "http://test4.org/", "test4")
    @@ns.add( "http://test5.org/", "test5")
    @@ns.add( "http://test6.org/", "test6")
    @@ns.add( "http://test7.org/", "test7")
    @@ns.add( "http://test8.org/", "test8")
    @@ns.add( "http://test9.org/", "test9")
    assert( @@ns.getLength() == 9 )
    assert( @@ns.getIndex( "http://test1.org/") == 0 )
    assert( (  "test2" != @@ns.getPrefix(1) ) == false )
    assert( ( 		      "test1" != @@ns.getPrefix( "http://test1.org/") ) == false )
    assert( (  "http://test2.org/" != @@ns.getURI(1) ) == false )
    assert( ( 		      "http://test2.org/" != @@ns.getURI( "test2") ) == false )
    assert( @@ns.getIndex( "http://test1.org/") == 0 )
    assert( @@ns.getIndex( "http://test2.org/") == 1 )
    assert( @@ns.getIndex( "http://test5.org/") == 4 )
    assert( @@ns.getIndex( "http://test9.org/") == 8 )
    assert( @@ns.getIndex( "http://testX.org/") == -1 )
    assert( @@ns.hasURI( "http://test1.org/") != false )
    assert( @@ns.hasURI( "http://test2.org/") != false )
    assert( @@ns.hasURI( "http://test5.org/") != false )
    assert( @@ns.hasURI( "http://test9.org/") != false )
    assert( @@ns.hasURI( "http://testX.org/") == false )
    assert( @@ns.getIndexByPrefix( "test1") == 0 )
    assert( @@ns.getIndexByPrefix( "test5") == 4 )
    assert( @@ns.getIndexByPrefix( "test9") == 8 )
    assert( @@ns.getIndexByPrefix( "testX") == -1 )
    assert( @@ns.hasPrefix( "test1") != false )
    assert( @@ns.hasPrefix( "test5") != false )
    assert( @@ns.hasPrefix( "test9") != false )
    assert( @@ns.hasPrefix( "testX") == false )
    assert( @@ns.hasNS( "http://test1.org/", "test1") != false )
    assert( @@ns.hasNS( "http://test5.org/", "test5") != false )
    assert( @@ns.hasNS( "http://test9.org/", "test9") != false )
    assert( @@ns.hasNS( "http://testX.org/", "testX") == false )
  end

  def test_XMLNamespaces_remove
    @@ns.add( "http://test1.org/", "test1")
    @@ns.add( "http://test2.org/", "test2")
    @@ns.add( "http://test3.org/", "test3")
    @@ns.add( "http://test4.org/", "test4")
    @@ns.add( "http://test5.org/", "test5")
    assert( @@ns.getLength() == 5 )
    @@ns.remove(4)
    assert( @@ns.getLength() == 4 )
    @@ns.remove(3)
    assert( @@ns.getLength() == 3 )
    @@ns.remove(2)
    assert( @@ns.getLength() == 2 )
    @@ns.remove(1)
    assert( @@ns.getLength() == 1 )
    @@ns.remove(0)
    assert( @@ns.getLength() == 0 )
    @@ns.add( "http://test1.org/", "test1")
    @@ns.add( "http://test2.org/", "test2")
    @@ns.add( "http://test3.org/", "test3")
    @@ns.add( "http://test4.org/", "test4")
    @@ns.add( "http://test5.org/", "test5")
    assert( @@ns.getLength() == 5 )
    @@ns.remove(0)
    assert( @@ns.getLength() == 4 )
    @@ns.remove(0)
    assert( @@ns.getLength() == 3 )
    @@ns.remove(0)
    assert( @@ns.getLength() == 2 )
    @@ns.remove(0)
    assert( @@ns.getLength() == 1 )
    @@ns.remove(0)
    assert( @@ns.getLength() == 0 )
  end

  def test_XMLNamespaces_remove_by_prefix
    @@ns.add( "http://test1.org/", "test1")
    @@ns.add( "http://test2.org/", "test2")
    @@ns.add( "http://test3.org/", "test3")
    @@ns.add( "http://test4.org/", "test4")
    @@ns.add( "http://test5.org/", "test5")
    assert( @@ns.getLength() == 5 )
    @@ns.remove( "test1")
    assert( @@ns.getLength() == 4 )
    @@ns.remove( "test2")
    assert( @@ns.getLength() == 3 )
    @@ns.remove( "test3")
    assert( @@ns.getLength() == 2 )
    @@ns.remove( "test4")
    assert( @@ns.getLength() == 1 )
    @@ns.remove( "test5")
    assert( @@ns.getLength() == 0 )
    @@ns.add( "http://test1.org/", "test1")
    @@ns.add( "http://test2.org/", "test2")
    @@ns.add( "http://test3.org/", "test3")
    @@ns.add( "http://test4.org/", "test4")
    @@ns.add( "http://test5.org/", "test5")
    assert( @@ns.getLength() == 5 )
    @@ns.remove( "test5")
    assert( @@ns.getLength() == 4 )
    @@ns.remove( "test4")
    assert( @@ns.getLength() == 3 )
    @@ns.remove( "test3")
    assert( @@ns.getLength() == 2 )
    @@ns.remove( "test2")
    assert( @@ns.getLength() == 1 )
    @@ns.remove( "test1")
    assert( @@ns.getLength() == 0 )
    @@ns.add( "http://test1.org/", "test1")
    @@ns.add( "http://test2.org/", "test2")
    @@ns.add( "http://test3.org/", "test3")
    @@ns.add( "http://test4.org/", "test4")
    @@ns.add( "http://test5.org/", "test5")
    assert( @@ns.getLength() == 5 )
    @@ns.remove( "test3")
    assert( @@ns.getLength() == 4 )
    @@ns.remove( "test1")
    assert( @@ns.getLength() == 3 )
    @@ns.remove( "test4")
    assert( @@ns.getLength() == 2 )
    @@ns.remove( "test5")
    assert( @@ns.getLength() == 1 )
    @@ns.remove( "test2")
    assert( @@ns.getLength() == 0 )
  end

end

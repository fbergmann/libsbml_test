#
# @file    TestXMLNode_newSetters.py
# @brief   XMLNode unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestXMLNode_newSetters.c
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


class TestXMLNode_newSetters(unittest.TestCase):


  def test_XMLNode_addChild1(self):
    node = libsbml.XMLNode()
    node2 = libsbml.XMLNode()
    i = node.addChild(node2)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getNumChildren() == 1 )
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node2 ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_addChild2(self):
    triple = libsbml.XMLTriple("test","","")
    attr = libsbml.XMLAttributes()
    node = libsbml.XMLNode(triple,attr)
    node2 = libsbml.XMLNode()
    i = node.addChild(node2)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getNumChildren() == 1 )
    _dummyList = [ triple ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ attr ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node2 ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_addChild3(self):
    triple = libsbml.XMLTriple("test","","")
    node = libsbml.XMLNode(triple)
    node2 = libsbml.XMLNode()
    i = node.addChild(node2)
    self.assert_( i == libsbml.LIBSBML_INVALID_XML_OPERATION )
    self.assert_( node.getNumChildren() == 0 )
    _dummyList = [ triple ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node2 ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_clearAttributes(self):
    triple = libsbml.XMLTriple("test","","")
    attr = libsbml.XMLAttributes()
    node = libsbml.XMLNode(triple,attr)
    xt2 = libsbml.XMLTriple("name3", "http://name3.org/", "p3")
    xt1 = libsbml.XMLTriple("name5", "http://name5.org/", "p5")
    i = node.addAttr( "name1", "val1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 1 )
    i = node.addAttr( "name2", "val2", "http://name1.org/", "p1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 2 )
    i = node.addAttr(xt2, "val2")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 3 )
    i = node.addAttr( "name4", "val4")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 4 )
    i = node.clearAttributes()
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 0 )
    _dummyList = [ xt1 ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ xt2 ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ triple ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ attr ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_clearNamespaces(self):
    triple = libsbml.XMLTriple("test","","")
    attr = libsbml.XMLAttributes()
    node = libsbml.XMLNode(triple,attr)
    i = node.addNamespace( "http://test1.org/", "test1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 1 )
    i = node.addNamespace( "http://test2.org/", "test2")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 2 )
    i = node.clearNamespaces()
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 0 )
    _dummyList = [ triple ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ attr ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_removeAttributes(self):
    triple = libsbml.XMLTriple("test","","")
    attr = libsbml.XMLAttributes()
    node = libsbml.XMLNode(triple,attr)
    xt2 = libsbml.XMLTriple("name3", "http://name3.org/", "p3")
    xt1 = libsbml.XMLTriple("name5", "http://name5.org/", "p5")
    i = node.addAttr( "name1", "val1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 1 )
    i = node.addAttr( "name2", "val2", "http://name1.org/", "p1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 2 )
    i = node.addAttr(xt2, "val2")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 3 )
    i = node.addAttr( "name4", "val4")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 4 )
    i = node.removeAttr(7)
    self.assert_( i == libsbml.LIBSBML_INDEX_EXCEEDS_SIZE )
    i = node.removeAttr( "name7")
    self.assert_( i == libsbml.LIBSBML_INDEX_EXCEEDS_SIZE )
    i = node.removeAttr( "name7", "namespaces7")
    self.assert_( i == libsbml.LIBSBML_INDEX_EXCEEDS_SIZE )
    i = node.removeAttr(xt1)
    self.assert_( i == libsbml.LIBSBML_INDEX_EXCEEDS_SIZE )
    self.assert_( node.getAttributes().getLength() == 4 )
    i = node.removeAttr(3)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 3 )
    i = node.removeAttr( "name1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 2 )
    i = node.removeAttr( "name2", "http://name1.org/")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 1 )
    i = node.removeAttr(xt2)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getAttributes().getLength() == 0 )
    _dummyList = [ xt1 ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ xt2 ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ triple ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ attr ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_removeChildren(self):
    node = libsbml.XMLNode()
    node2 = libsbml.XMLNode()
    node3 = libsbml.XMLNode()
    node.addChild(node2)
    node.addChild(node3)
    self.assert_( node.getNumChildren() == 2 )
    i = node.removeChildren()
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( node.getNumChildren() == 0 )
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node2 ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node3 ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_XMLNode_removeNamespaces(self):
    triple = libsbml.XMLTriple("test","","")
    attr = libsbml.XMLAttributes()
    node = libsbml.XMLNode(triple,attr)
    i = node.addNamespace( "http://test1.org/", "test1")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 1 )
    i = node.addNamespace( "http://test2.org/", "test2")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 2 )
    i = node.removeNamespace(7)
    self.assert_( i == libsbml.LIBSBML_INDEX_EXCEEDS_SIZE )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 2 )
    i = node.removeNamespace( "name7")
    self.assert_( i == libsbml.LIBSBML_INDEX_EXCEEDS_SIZE )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 2 )
    i = node.removeNamespace(0)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 1 )
    i = node.removeNamespace( "test2")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    nms = node.getNamespaces()
    self.assert_( nms.getLength() == 0 )
    _dummyList = [ triple ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ attr ]; _dummyList[:] = []; del _dummyList
    _dummyList = [ node ]; _dummyList[:] = []; del _dummyList
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestXMLNode_newSetters))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

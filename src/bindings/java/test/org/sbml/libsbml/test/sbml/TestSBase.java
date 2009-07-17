/*
 *
 * @file    TestSBase.java
 * @brief   SBase unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Ben Bornstein 
 *
 * $Id$
 * $HeadURL$
 *
 * This test file was converted from src/sbml/test/TestSBase.cpp
 * with the help of conversion sciprt (ctest_converter.pl).
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2009 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *--------------------------------------------------------------------------->*/


package org.sbml.libsbml.test.sbml;

import org.sbml.libsbml.*;

import java.io.File;
import java.lang.AssertionError;

public class TestSBase {

  static void assertTrue(boolean condition) throws AssertionError
  {
    if (condition == true)
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      return;
    }
    else if (a.equals(b))
    {
      return;
    }

    throw new AssertionError();
  }

  static void assertNotEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      throw new AssertionError();
    }
    else if (a.equals(b))
    {
      throw new AssertionError();
    }
  }

  static void assertEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(int a, int b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(int a, int b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }
  private SBase S;

  protected void setUp() throws Exception
  {
    S = new Model();
    if (S == null);
    {
    }
  }

  protected void tearDown() throws Exception
  {
  }

  public void test_SBase_CVTerms()
  {
    CVTerm cv = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    assertTrue( S.getNumCVTerms() == 0 );
    assertTrue( S.getCVTerms() == null );
    S.setMetaId( "sbase1");
    S.addCVTerm(cv);
    assertTrue( S.getNumCVTerms() == 1 );
    assertTrue( S.getCVTerms() != null );
    assertTrue( !S.getCVTerm(0).equals(cv) );
    cv = null;
  }

  public void test_SBase_addCVTerms()
  {
    CVTerm cv = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv.setBiologicalQualifierType(libsbml.BQB_ENCODES);
    cv.addResource( "foo");
    S.setMetaId( "sbase1");
    S.addCVTerm(cv);
    assertTrue( S.getNumCVTerms() == 1 );
    assertTrue( S.getCVTerms() != null );
    XMLAttributes res = S.getCVTerm(0).getResources();
    assertTrue(res.getValue(0).equals( "foo"));
    CVTerm cv1 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv1.setBiologicalQualifierType(libsbml.BQB_IS);
    cv1.addResource( "bar");
    S.addCVTerm(cv1);
    assertTrue( S.getNumCVTerms() == 2 );
    CVTerm cv2 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv2.setBiologicalQualifierType(libsbml.BQB_IS);
    cv2.addResource( "bar1");
    S.addCVTerm(cv2);
    assertTrue( S.getNumCVTerms() == 2 );
    res = S.getCVTerm(1).getResources();
    assertTrue( res.getLength() == 2 );
    assertTrue(res.getValue(0).equals( "bar"));
    assertTrue(res.getValue(1).equals( "bar1"));
    CVTerm cv4 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv4.setBiologicalQualifierType(libsbml.BQB_IS);
    cv4.addResource( "bar1");
    S.addCVTerm(cv4);
    assertTrue( S.getNumCVTerms() == 2 );
    res = S.getCVTerm(1).getResources();
    assertTrue( res.getLength() == 2 );
    assertTrue(res.getValue(0).equals( "bar"));
    assertTrue(res.getValue(1).equals( "bar1"));
    CVTerm cv5 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv5.setBiologicalQualifierType(libsbml.BQB_HAS_PART);
    cv5.addResource( "bar1");
    S.addCVTerm(cv5);
    assertTrue( S.getNumCVTerms() == 2 );
    res = S.getCVTerm(1).getResources();
    assertTrue( res.getLength() == 2 );
    assertTrue(res.getValue(0).equals( "bar"));
    assertTrue(res.getValue(1).equals( "bar1"));
    cv = null;
    cv2 = null;
    cv1 = null;
    cv4 = null;
  }

  public void test_SBase_appendNotes()
  {
    XMLToken token;
    XMLNode node;
    XMLToken token1;
    XMLNode node1;
    XMLNode node2;
    XMLTriple triple = new  XMLTriple("p", "", "");
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLToken token4 = new  XMLToken("This is my text");
    XMLNode node4 = new XMLNode(token4);
    XMLToken token5 = new  XMLToken("This is additional text");
    XMLNode node5 = new XMLNode(token5);
    token = new  XMLToken(triple,att,ns);
    node = new XMLNode(token);
    node.addChild(node4);
    S.setNotes(node);
    assertTrue( S.isSetNotes() == true );
    token1 = new  XMLToken(triple,att,ns);
    node1 = new XMLNode(token1);
    node1.addChild(node5);
    S.appendNotes(node1);
    assertTrue( S.isSetNotes() == true );
    node2 = S.getNotes();
    assertTrue( node2.getNumChildren() == 2 );
    assertTrue(node2.getChild(0).getName().equals( "p"));
    assertTrue( node2.getChild(0).getNumChildren() == 1 );
    assertTrue(node2.getChild(1).getName().equals( "p"));
    assertTrue( node2.getChild(1).getNumChildren() == 1 );
    String chars1 = node2.getChild(0).getChild(0).getCharacters();
    String chars2 = node2.getChild(1).getChild(0).getCharacters();
    assertTrue(chars1.equals( "This is my text"));
    assertTrue(chars2.equals( "This is additional text"));
    node = null;
    node1 = null;
  }

  public void test_SBase_appendNotes1()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple html_triple = new  XMLTriple("html", "", "");
    XMLTriple head_triple = new  XMLTriple("head", "", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken html_token = new  XMLToken(html_triple,att,ns);
    XMLToken head_token = new  XMLToken(head_triple,att);
    XMLToken body_token = new  XMLToken(body_triple,att);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode html_node = new XMLNode(html_token);
    XMLNode head_node = new XMLNode(head_token);
    XMLNode body_node = new XMLNode(body_token);
    XMLNode p_node = new XMLNode(p_token);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode html_node1 = new XMLNode(html_token);
    XMLNode head_node1 = new XMLNode(head_token);
    XMLNode body_node1 = new XMLNode(body_token);
    XMLNode p_node1 = new XMLNode(p_token);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    body_node.addChild(p_node);
    html_node.addChild(head_node);
    html_node.addChild(body_node);
    p_node1.addChild(text_node1);
    body_node1.addChild(p_node1);
    html_node1.addChild(head_node1);
    html_node1.addChild(body_node1);
    S.setNotes(html_node);
    S.appendNotes(html_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "html"));
    assertTrue( child.getNumChildren() == 2 );
    child = child.getChild(1);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    html_triple = null;
    head_triple = null;
    body_triple = null;
    p_triple = null;
    html_token = null;
    head_token = null;
    body_token = null;
    p_token = null;
    text_token = null;
    text_token1 = null;
    html_node = null;
    head_node = null;
    body_node = null;
    p_node = null;
    text_node = null;
    html_node1 = null;
    head_node1 = null;
    body_node1 = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes2()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple html_triple = new  XMLTriple("html", "", "");
    XMLTriple head_triple = new  XMLTriple("head", "", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken html_token = new  XMLToken(html_triple,att,ns);
    XMLToken head_token = new  XMLToken(head_triple,att);
    XMLToken body_token = new  XMLToken(body_triple,att);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode html_node = new XMLNode(html_token);
    XMLNode head_node = new XMLNode(head_token);
    XMLNode body_node = new XMLNode(body_token);
    XMLNode p_node = new XMLNode(p_token);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken body_token1 = new  XMLToken(body_triple,att,ns);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode body_node1 = new XMLNode(body_token1);
    XMLNode p_node1 = new XMLNode(p_token);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    body_node.addChild(p_node);
    html_node.addChild(head_node);
    html_node.addChild(body_node);
    p_node1.addChild(text_node1);
    body_node1.addChild(p_node1);
    S.setNotes(html_node);
    S.appendNotes(body_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "html"));
    assertTrue( child.getNumChildren() == 2 );
    child = child.getChild(1);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    html_triple = null;
    head_triple = null;
    body_triple = null;
    p_triple = null;
    html_token = null;
    head_token = null;
    body_token = null;
    p_token = null;
    text_token = null;
    text_token1 = null;
    body_token1 = null;
    html_node = null;
    head_node = null;
    body_node = null;
    p_node = null;
    text_node = null;
    body_node1 = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes3()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple html_triple = new  XMLTriple("html", "", "");
    XMLTriple head_triple = new  XMLTriple("head", "", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken html_token = new  XMLToken(html_triple,att,ns);
    XMLToken head_token = new  XMLToken(head_triple,att);
    XMLToken body_token = new  XMLToken(body_triple,att);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode html_node = new XMLNode(html_token);
    XMLNode head_node = new XMLNode(head_token);
    XMLNode body_node = new XMLNode(body_token);
    XMLNode p_node = new XMLNode(p_token);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken p_token1 = new  XMLToken(p_triple,att,ns);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode p_node1 = new XMLNode(p_token1);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    body_node.addChild(p_node);
    html_node.addChild(head_node);
    html_node.addChild(body_node);
    p_node1.addChild(text_node1);
    S.setNotes(html_node);
    S.appendNotes(p_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "html"));
    assertTrue( child.getNumChildren() == 2 );
    child = child.getChild(1);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    html_triple = null;
    head_triple = null;
    body_triple = null;
    p_triple = null;
    html_token = null;
    head_token = null;
    body_token = null;
    p_token = null;
    text_token = null;
    text_token1 = null;
    p_token1 = null;
    html_node = null;
    head_node = null;
    body_node = null;
    p_node = null;
    text_node = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes4()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple html_triple = new  XMLTriple("html", "", "");
    XMLTriple head_triple = new  XMLTriple("head", "", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken html_token = new  XMLToken(html_triple,att,ns);
    XMLToken head_token = new  XMLToken(head_triple,att);
    XMLToken body_token = new  XMLToken(body_triple,att);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken body_token1 = new  XMLToken(body_triple,att,ns);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode body_node = new XMLNode(body_token1);
    XMLNode p_node = new XMLNode(p_token);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode html_node1 = new XMLNode(html_token);
    XMLNode head_node1 = new XMLNode(head_token);
    XMLNode body_node1 = new XMLNode(body_token);
    XMLNode p_node1 = new XMLNode(p_token);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    body_node.addChild(p_node);
    p_node1.addChild(text_node1);
    body_node1.addChild(p_node1);
    html_node1.addChild(head_node1);
    html_node1.addChild(body_node1);
    S.setNotes(body_node);
    S.appendNotes(html_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "html"));
    assertTrue( child.getNumChildren() == 2 );
    child = child.getChild(1);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    html_triple = null;
    head_triple = null;
    body_triple = null;
    p_triple = null;
    body_token = null;
    p_token = null;
    text_token = null;
    text_token1 = null;
    body_token1 = null;
    body_node = null;
    p_node = null;
    text_node = null;
    html_node1 = null;
    head_node1 = null;
    body_node1 = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes5()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple html_triple = new  XMLTriple("html", "", "");
    XMLTriple head_triple = new  XMLTriple("head", "", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken html_token = new  XMLToken(html_triple,att,ns);
    XMLToken head_token = new  XMLToken(head_triple,att);
    XMLToken body_token = new  XMLToken(body_triple,att);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken p_token1 = new  XMLToken(p_triple,att,ns);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode p_node = new XMLNode(p_token1);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode html_node1 = new XMLNode(html_token);
    XMLNode head_node1 = new XMLNode(head_token);
    XMLNode body_node1 = new XMLNode(body_token);
    XMLNode p_node1 = new XMLNode(p_token);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    p_node1.addChild(text_node1);
    body_node1.addChild(p_node1);
    html_node1.addChild(head_node1);
    html_node1.addChild(body_node1);
    S.setNotes(p_node);
    S.appendNotes(html_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "html"));
    assertTrue( child.getNumChildren() == 2 );
    child = child.getChild(1);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    html_triple = null;
    head_triple = null;
    body_triple = null;
    p_triple = null;
    body_token = null;
    p_token = null;
    p_token1 = null;
    text_token = null;
    text_token1 = null;
    p_node = null;
    text_node = null;
    html_node1 = null;
    head_node1 = null;
    body_node1 = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes6()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken body_token = new  XMLToken(body_triple,att,ns);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode body_node = new XMLNode(body_token);
    XMLNode p_node = new XMLNode(p_token);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode body_node1 = new XMLNode(body_token);
    XMLNode p_node1 = new XMLNode(p_token);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    body_node.addChild(p_node);
    p_node1.addChild(text_node1);
    body_node1.addChild(p_node1);
    S.setNotes(body_node);
    S.appendNotes(body_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    body_triple = null;
    p_triple = null;
    body_token = null;
    p_token = null;
    text_token = null;
    text_token1 = null;
    body_node = null;
    p_node = null;
    text_node = null;
    body_node1 = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes7()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken body_token = new  XMLToken(body_triple,att,ns);
    XMLToken p_token1 = new  XMLToken(p_triple,att,ns);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLNode p_node = new XMLNode(p_token1);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode body_node1 = new XMLNode(body_token);
    XMLNode p_node1 = new XMLNode(p_token);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    p_node1.addChild(text_node1);
    body_node1.addChild(p_node1);
    S.setNotes(p_node);
    S.appendNotes(body_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    body_triple = null;
    p_triple = null;
    body_token = null;
    p_token = null;
    p_token1 = null;
    text_token = null;
    text_token1 = null;
    p_node = null;
    text_node = null;
    body_node1 = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotes8()
  {
    XMLAttributes att = new  XMLAttributes();
    XMLNamespaces ns = new  XMLNamespaces();
    ns.add( "http://www.w3.org/1999/xhtml", "");
    XMLTriple body_triple = new  XMLTriple("body", "", "");
    XMLTriple p_triple = new  XMLTriple("p", "", "");
    XMLToken body_token = new  XMLToken(body_triple,att,ns);
    XMLToken p_token = new  XMLToken(p_triple,att);
    XMLToken text_token = new  XMLToken("This is my text");
    XMLNode body_node = new XMLNode(body_token);
    XMLNode p_node = new XMLNode(p_token);
    XMLNode text_node = new XMLNode(text_token);
    XMLToken p_token1 = new  XMLToken(p_triple,att,ns);
    XMLToken text_token1 = new  XMLToken("This is more text");
    XMLNode p_node1 = new XMLNode(p_token1);
    XMLNode text_node1 = new XMLNode(text_token1);
    XMLNode notes;
    XMLNode child,child1;
    p_node.addChild(text_node);
    body_node.addChild(p_node);
    p_node1.addChild(text_node1);
    S.setNotes(body_node);
    S.appendNotes(p_node1);
    notes = S.getNotes();
    assertTrue(notes.getName().equals( "notes"));
    assertTrue( notes.getNumChildren() == 1 );
    child = notes.getChild(0);
    assertTrue(child.getName().equals( "body"));
    assertTrue( child.getNumChildren() == 2 );
    child1 = child.getChild(0);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is my text"));
    assertTrue( child1.getNumChildren() == 0 );
    child1 = child.getChild(1);
    assertTrue(child1.getName().equals( "p"));
    assertTrue( child1.getNumChildren() == 1 );
    child1 = child1.getChild(0);
    assertTrue(child1.getCharacters().equals( "This is more text"));
    assertTrue( child1.getNumChildren() == 0 );
    att = null;
    ns = null;
    body_triple = null;
    p_triple = null;
    body_token = null;
    p_token = null;
    text_token = null;
    text_token1 = null;
    p_token1 = null;
    body_node = null;
    p_node = null;
    text_node = null;
    p_node1 = null;
    text_node1 = null;
  }

  public void test_SBase_appendNotesString()
  {
    String notes =  "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>";;
    String taggednewnotes = "<notes>\n" + "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n" + 
    "</notes>";
    String taggednewnotes2 = "<notes>\n" + "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>\n" + 
    "</notes>";
    String newnotes =  "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>";;
    String newnotes2 = "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>" + "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>";;
    String newnotes3 = "<notes>\n" + "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n" + "</notes>";;
    String newnotes4 = "<notes>\n" + "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>\n" + 
    "</notes>";
    S.setNotes(notes);
    assertTrue( S.isSetNotes() == true );
    S.appendNotes(newnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(newnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes2.equals(notes2));
    S.setNotes(notes);
    S.appendNotes(newnotes3);
    String notes3 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes3));
    S.setNotes(notes);
    S.appendNotes(newnotes4);
    String notes4 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes2.equals(notes4));
  }

  public void test_SBase_appendNotesString1()
  {
    String notes = "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <head>\n" + 
    "    <title/>\n" + 
    "  </head>\n" + 
    "  <body>\n" + 
    "    <p>This is a test note </p>\n" + 
    "  </body>\n" + 
    "</html>";
    String taggednewnotes = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is a test note </p>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    String addnotes = "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <head>\n" + 
    "    <title/>\n" + 
    "  </head>\n" + 
    "  <body>\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</html>";
    String addnotes2 = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes2));
  }

  public void test_SBase_appendNotesString2()
  {
    String notes = "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <head>\n" + 
    "    <title/>\n" + 
    "  </head>\n" + 
    "  <body>\n" + 
    "    <p>This is a test note </p>\n" + 
    "  </body>\n" + 
    "</html>";
    String taggednewnotes = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is a test note </p>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    String addnotes = "<body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <p>This is more test notes </p>\n" + "</body>\n";;
    String addnotes2 = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes2));
  }

  public void test_SBase_appendNotesString3()
  {
    String notes = "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <head>\n" + 
    "    <title/>\n" + 
    "  </head>\n" + 
    "  <body>\n" + 
    "    <p>This is a test note </p>\n" + 
    "  </body>\n" + 
    "</html>";
    String taggednewnotes = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is a test note </p>\n" + 
    "      <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    String taggednewnotes2 = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is a test note </p>\n" + 
    "      <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + 
    "      <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    String addnotes =  "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n";;
    String addnotes2 = "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>";;
    String addnotes3 = "<notes>\n" + "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n" + "</notes>";;
    String addnotes4 = "<notes>\n" + "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes2.equals(notes2));
    S.setNotes(notes);
    S.appendNotes(addnotes3);
    String notes3 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes3));
    S.setNotes(notes);
    S.appendNotes(addnotes4);
    String notes4 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes2.equals(notes4));
  }

  public void test_SBase_appendNotesString4()
  {
    String notes = "<body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <p>This is a test note </p>\n" + "</body>";;
    String taggednewnotes = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is a test note </p>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    String addnotes = "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <head>\n" + 
    "    <title/>\n" + 
    "  </head>\n" + 
    "  <body>\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</html>";
    String addnotes2 = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes2));
  }

  public void test_SBase_appendNotesString5()
  {
    String notes =  "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>";;
    String taggednewnotes = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    String addnotes = "<html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <head>\n" + 
    "    <title/>\n" + 
    "  </head>\n" + 
    "  <body>\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</html>";
    String addnotes2 = "<notes>\n" + 
    "  <html xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <head>\n" + 
    "      <title/>\n" + 
    "    </head>\n" + 
    "    <body>\n" + 
    "      <p>This is more test notes </p>\n" + 
    "    </body>\n" + 
    "  </html>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes2));
  }

  public void test_SBase_appendNotesString6()
  {
    String notes = "<body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <p>This is a test note </p>\n" + "</body>";;
    String taggednewnotes = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p>This is a test note </p>\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</notes>";
    String addnotes = "<body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <p>This is more test notes </p>\n" + "</body>";;
    String addnotes2 = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes2));
  }

  public void test_SBase_appendNotesString7()
  {
    String notes =  "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>";;
    String taggednewnotes = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p xmlns=\"http://www.w3.org/1999/xhtml\">This is a test note </p>\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</notes>";
    String addnotes = "<body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <p>This is more test notes </p>\n" + "</body>";;
    String addnotes2 = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p>This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes2));
  }

  public void test_SBase_appendNotesString8()
  {
    String notes = "<body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + "  <p>This is a test note </p>\n" + "</body>";;
    String taggednewnotes = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p>This is a test note </p>\n" + 
    "    <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n" + 
    "  </body>\n" + 
    "</notes>";
    String taggednewnotes2 = "<notes>\n" + 
    "  <body xmlns=\"http://www.w3.org/1999/xhtml\">\n" + 
    "    <p>This is a test note </p>\n" + 
    "    <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + 
    "    <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>\n" + 
    "  </body>\n" + 
    "</notes>";
    String addnotes =  "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>";;
    String addnotes2 = "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + "<p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>";;
    String addnotes3 = "<notes>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes </p>\n" + 
    "</notes>";
    String addnotes4 = "<notes>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 1</p>\n" + 
    "  <p xmlns=\"http://www.w3.org/1999/xhtml\">This is more test notes 2</p>\n" + 
    "</notes>";
    S.setNotes(notes);
    S.appendNotes(addnotes);
    String notes1 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes1));
    S.setNotes(notes);
    S.appendNotes(addnotes2);
    String notes2 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes2.equals(notes2));
    S.setNotes(notes);
    S.appendNotes(addnotes3);
    String notes3 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes.equals(notes3));
    S.setNotes(notes);
    S.appendNotes(addnotes4);
    String notes4 = S.getNotesString();
    assertTrue( S.isSetNotes() == true );
    assertTrue(taggednewnotes2.equals(notes4));
  }

  public void test_SBase_getQualifiersFromResources()
  {
    CVTerm cv = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv.setBiologicalQualifierType(libsbml.BQB_ENCODES);
    cv.addResource( "foo");
    S.setMetaId( "sbase1");
    S.addCVTerm(cv);
    assertTrue( S.getResourceBiologicalQualifier( "foo") == libsbml.BQB_ENCODES );
    CVTerm cv1 = new  CVTerm(libsbml.MODEL_QUALIFIER);
    cv1.setModelQualifierType(libsbml.BQM_IS);
    cv1.addResource( "bar");
    S.addCVTerm(cv1);
    assertTrue( S.getResourceModelQualifier( "bar") == libsbml.BQM_IS );
    cv = null;
    cv1 = null;
  }

  public void test_SBase_setAnnotation()
  {
    XMLToken token;
    XMLNode node;
    XMLTriple triple;
    XMLNode node2;
    Species sp;
    String taggedannt =  "<annotation>This is a test note</annotation>";;
    token = new  XMLToken("This is a test note");
    node = new XMLNode(token);
    S.setAnnotation(node);
    assertTrue( S.isSetAnnotation() == true );
    XMLNode t1 = S.getAnnotation();
    assertTrue( t1.getNumChildren() == 1 );
    assertTrue(t1.getChild(0).getCharacters().equals( "This is a test note"));
    if (S.getAnnotation() == node);
    {
    }
    S.setAnnotation(S.getAnnotation());
    assertTrue(S.getAnnotation().getChild(0).getCharacters().equals( "This is a test note"));
    S.setAnnotation((XMLNode)null);
    assertTrue( S.isSetAnnotation() == false );
    if (S.getAnnotation() != null);
    {
    }
    S.setAnnotation(node);
    assertTrue( S.isSetAnnotation() == true );
    S.unsetAnnotation();
    assertTrue( S.isSetAnnotation() == false );
    triple = new  XMLTriple("annotation", "", "");
    node2 = new XMLNode(triple);
    node2.addChild(node);
    sp = ((Model)S).createSpecies();
    sp.setAnnotation(node2);
    assertTrue( sp.isSetAnnotation() == true );
    assertTrue(sp.getAnnotationString().equals(taggedannt));
    sp.unsetAnnotation();
    assertTrue( sp.isSetAnnotation() == false );
    S.setAnnotation(node2);
    assertTrue( S.isSetAnnotation() == true );
    assertTrue(S.getAnnotationString().equals(taggedannt));
    S.unsetAnnotation();
    assertTrue( S.isSetAnnotation() == false );
    token = new  XMLToken("(CR) &#0168; &#x00a8; &#x00A8; (NOT CR) &#; &#x; &#00a8; &#0168 &#x00a8");
    node = new XMLNode(token);
    S.setAnnotation(node);
    t1 = S.getAnnotation();
    assertTrue( t1.getNumChildren() == 1 );
    String s = t1.getChild(0).toXMLString();
    String expected =  "(CR) &#0168; &#x00a8; &#x00A8; (NOT CR) &amp;#; &amp;#x; &amp;#00a8; &amp;#0168 &amp;#x00a8";;
    assertTrue(s.equals(expected));
    token = new  XMLToken("& ' > < \" &amp; &apos; &gt; &lt; &quot;");
    node = new XMLNode(token);
    S.setAnnotation(node);
    t1 = S.getAnnotation();
    assertTrue( t1.getNumChildren() == 1 );
    String s2 = t1.getChild(0).toXMLString();
    String expected2 =  "&amp; &apos; &gt; &lt; &quot; &amp; &apos; &gt; &lt; &quot;";;
    assertTrue(s2.equals(expected2));
    token = null;
    node = null;
    node2 = null;
    triple = null;
  }

  public void test_SBase_setAnnotationString()
  {
    String annotation =  "This is a test note";;
    String taggedannotation =  "<annotation>This is a test note</annotation>";;
    S.setAnnotation(annotation);
    assertTrue( S.isSetAnnotation() == true );
    if (!S.getAnnotationString().equals(taggedannotation));
    {
    }
    XMLNode t1 = S.getAnnotation();
    assertTrue( t1.getNumChildren() == 1 );
    assertTrue(t1.getChild(0).getCharacters().equals( "This is a test note"));
    S.setAnnotation(S.getAnnotationString());
    t1 = S.getAnnotation();
    assertTrue( t1.getNumChildren() == 1 );
    String chars = S.getAnnotationString();
    assertTrue(chars.equals(taggedannotation));
    S.setAnnotation( "");
    assertTrue( S.isSetAnnotation() == false );
    if (S.getAnnotationString() != null);
    {
    }
    S.setAnnotation(taggedannotation);
    assertTrue( S.isSetAnnotation() == true );
    if (!S.getAnnotationString().equals(taggedannotation));
    {
    }
    t1 = S.getAnnotation();
    assertTrue( t1.getNumChildren() == 1 );
    XMLNode t2 = t1.getChild(0);
    assertTrue(t2.getCharacters().equals( "This is a test note"));
  }

  public void test_SBase_setMetaId()
  {
    String metaid =  "x12345";;
    S.setMetaId(metaid);
    assertTrue(S.getMetaId().equals(metaid));
    assertEquals( true, S.isSetMetaId() );
    if (S.getMetaId() == metaid);
    {
    }
    S.setMetaId(S.getMetaId());
    assertTrue(S.getMetaId().equals(metaid));
    S.setMetaId("");
    assertEquals( false, S.isSetMetaId() );
    if (S.getMetaId() != null);
    {
    }
  }

  public void test_SBase_setNotes()
  {
    XMLToken token;
    XMLNode node;
    token = new  XMLToken("This is a test note");
    node = new XMLNode(token);
    S.setNotes(node);
    assertTrue( S.isSetNotes() == true );
    if (S.getNotes() == node);
    {
    }
    XMLNode t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    assertTrue(t1.getChild(0).getCharacters().equals( "This is a test note"));
    S.setNotes(S.getNotes());
    t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    String chars = t1.getChild(0).getCharacters();
    assertTrue(chars.equals( "This is a test note"));
    S.setNotes((XMLNode)null);
    assertTrue( S.isSetNotes() == false );
    if (S.getNotes() != null);
    {
    }
    S.setNotes(node);
    assertTrue( S.isSetNotes() == true );
    token = null;
    node = null;
    token = new  XMLToken("(CR) &#0168; &#x00a8; &#x00A8; (NOT CR) &#; &#x; &#00a8; &#0168 &#x00a8");
    node = new XMLNode(token);
    S.setNotes(node);
    t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    String s = t1.getChild(0).toXMLString();
    String expected =  "(CR) &#0168; &#x00a8; &#x00A8; (NOT CR) &amp;#; &amp;#x; &amp;#00a8; &amp;#0168 &amp;#x00a8";;
    assertTrue(s.equals(expected));
    token = new  XMLToken("& ' > < \" &amp; &apos; &gt; &lt; &quot;");
    node = new XMLNode(token);
    S.setNotes(node);
    t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    String s2 = t1.getChild(0).toXMLString();
    String expected2 =  "&amp; &apos; &gt; &lt; &quot; &amp; &apos; &gt; &lt; &quot;";;
    assertTrue(s2.equals(expected2));
    token = null;
    node = null;
  }

  public void test_SBase_setNotesString()
  {
    String notes =  "This is a test note";;
    String taggednotes =  "<notes>This is a test note</notes>";;
    S.setNotes(notes);
    assertTrue( S.isSetNotes() == true );
    if (!S.getNotesString().equals(taggednotes));
    {
    }
    XMLNode t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    assertTrue(t1.getChild(0).getCharacters().equals( "This is a test note"));
    S.setNotes(S.getNotesString());
    t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    String chars = S.getNotesString();
    assertTrue(chars.equals(taggednotes));
    S.setNotes( "");
    assertTrue( S.isSetNotes() == false );
    if (S.getNotesString() != null);
    {
    }
    S.setNotes(taggednotes);
    assertTrue( S.isSetNotes() == true );
    if (!S.getNotesString().equals(taggednotes));
    {
    }
    t1 = S.getNotes();
    assertTrue( t1.getNumChildren() == 1 );
    XMLNode t2 = t1.getChild(0);
    assertTrue(t2.getCharacters().equals( "This is a test note"));
  }

  public void test_SBase_unsetAnnotationWithCVTerms()
  {
    CVTerm cv;
    String annt = "<annotation>\n" + 
    "  <test:test xmlns:test=\"http://test.org/test\">this is a test node</test:test>\n" + 
    "</annotation>";
    String annt_with_cvterm = "<annotation>\n" + 
    "  <test:test xmlns:test=\"http://test.org/test\">this is a test node</test:test>\n" + 
    "  <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" " + 
    "xmlns:dc=\"http://purl.org/dc/elements/1.1/\" " + 
    "xmlns:dcterms=\"http://purl.org/dc/terms/\" " + 
    "xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" " + 
    "xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" " + 
    "xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n" + 
    "    <rdf:Description rdf:about=\"#_000001\">\n" + 
    "      <bqbiol:is>\n" + 
    "        <rdf:Bag>\n" + 
    "          <rdf:li rdf:resource=\"http://www.geneontology.org/#GO:0005895\"/>\n" + 
    "        </rdf:Bag>\n" + 
    "      </bqbiol:is>\n" + 
    "    </rdf:Description>\n" + 
    "  </rdf:RDF>\n" + 
    "</annotation>";
    S.setAnnotation(annt);
    assertTrue( S.isSetAnnotation() == true );
    assertTrue(S.getAnnotationString().equals(annt));
    S.unsetAnnotation();
    assertTrue( S.isSetAnnotation() == false );
    assertTrue( S.getAnnotation() == null );
    S.setAnnotation(annt);
    S.setMetaId( "_000001");
    cv = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv.setBiologicalQualifierType(libsbml.BQB_IS);
    cv.addResource( "http://www.geneontology.org/#GO:0005895");
    S.addCVTerm(cv);
    assertTrue( S.isSetAnnotation() == true );
    assertTrue(S.getAnnotationString().equals(annt_with_cvterm));
    S.unsetAnnotation();
    assertTrue( S.isSetAnnotation() == false );
    assertTrue( S.getAnnotation() == null );
    cv = null;
  }

  public void test_SBase_unsetAnnotationWithModelHistory()
  {
    ModelHistory h = new  ModelHistory();
    ModelCreator c = new  ModelCreator();
    String annt = "<annotation>\n" + 
    "  <test:test xmlns:test=\"http://test.org/test\">this is a test node</test:test>\n" + 
    "</annotation>";
    String annt_with_modelhistory = "<annotation>\n" + 
    "  <test:test xmlns:test=\"http://test.org/test\">this is a test node</test:test>\n" + 
    "  <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" " + 
    "xmlns:dc=\"http://purl.org/dc/elements/1.1/\" " + 
    "xmlns:dcterms=\"http://purl.org/dc/terms/\" " + 
    "xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" " + 
    "xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" " + 
    "xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n" + 
    "    <rdf:Description rdf:about=\"#_000001\">\n" + 
    "      <dc:creator>\n" + 
    "        <rdf:Bag>\n" + 
    "          <rdf:li rdf:parseType=\"Resource\">\n" + 
    "            <vCard:N rdf:parseType=\"Resource\">\n" + 
    "              <vCard:Family>Keating</vCard:Family>\n" + 
    "              <vCard:Given>Sarah</vCard:Given>\n" + 
    "            </vCard:N>\n" + 
    "            <vCard:EMAIL>sbml-team@caltech.edu</vCard:EMAIL>\n" + 
    "          </rdf:li>\n" + 
    "        </rdf:Bag>\n" + 
    "      </dc:creator>\n" + 
    "    </rdf:Description>\n" + 
    "  </rdf:RDF>\n" + 
    "</annotation>";
    S.setAnnotation(annt);
    assertTrue( S.isSetAnnotation() == true );
    assertTrue(S.getAnnotationString().equals(annt));
    S.unsetAnnotation();
    assertTrue( S.isSetAnnotation() == false );
    assertTrue( S.getAnnotation() == null );
    S.setAnnotation(annt);
    S.setMetaId( "_000001");
    c.setFamilyName("Keating");
    c.setGivenName("Sarah");
    c.setEmail("sbml-team@caltech.edu");
    h.addCreator(c);
    ((Model)S).setModelHistory(h);
    assertTrue( S.isSetAnnotation() == true );
    assertTrue(S.getAnnotationString().equals(annt_with_modelhistory));
    S.unsetAnnotation();
    assertTrue( S.isSetAnnotation() == false );
    assertTrue( S.getAnnotation() == null );
    c = null;
    h = null;
  }

  public void test_SBase_unsetCVTerms()
  {
    CVTerm cv = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv.setBiologicalQualifierType(libsbml.BQB_ENCODES);
    cv.addResource( "foo");
    S.setMetaId( "sbase1");
    S.addCVTerm(cv);
    CVTerm cv1 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv1.setBiologicalQualifierType(libsbml.BQB_IS);
    cv1.addResource( "bar");
    S.addCVTerm(cv1);
    CVTerm cv2 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv2.setBiologicalQualifierType(libsbml.BQB_IS);
    cv2.addResource( "bar1");
    S.addCVTerm(cv2);
    CVTerm cv4 = new  CVTerm(libsbml.BIOLOGICAL_QUALIFIER);
    cv4.setBiologicalQualifierType(libsbml.BQB_IS);
    cv4.addResource( "bar1");
    S.addCVTerm(cv4);
    assertTrue( S.getNumCVTerms() == 2 );
    S.unsetCVTerms();
    assertTrue( S.getNumCVTerms() == 0 );
    assertTrue( S.getCVTerms() == null );
    cv = null;
    cv2 = null;
    cv1 = null;
    cv4 = null;
  }

  /**
   * Loads the SWIG-generated libSBML Java module when this class is
   * loaded, or reports a sensible diagnostic message about why it failed.
   */
  static
  {
    String varname;
    String shlibname;

    if (System.getProperty("mrj.version") != null)
    {
      varname = "DYLD_LIBRARY_PATH";    // We're on a Mac.
      shlibname = "libsbmlj.jnilib and/or libsbml.dylib";
    }
    else
    {
      varname = "LD_LIBRARY_PATH";      // We're not on a Mac.
      shlibname = "libsbmlj.so and/or libsbml.so";
    }

    try
    {
      System.loadLibrary("sbmlj");
      // For extra safety, check that the jar file is in the classpath.
      Class.forName("org.sbml.libsbml.libsbml");
    }
    catch (SecurityException e)
    {
      e.printStackTrace();
      System.err.println("Could not load the libSBML library files due to a"+
                         " security exception.\n");
      System.exit(1);
    }
    catch (UnsatisfiedLinkError e)
    {
      e.printStackTrace();
      System.err.println("Error: could not link with the libSBML library files."+
                         " It is likely\nyour " + varname +
                         " environment variable does not include the directories\n"+
                         "containing the " + shlibname + " library files.\n");
      System.exit(1);
    }
    catch (ClassNotFoundException e)
    {
      e.printStackTrace();
      System.err.println("Error: unable to load the file libsbmlj.jar."+
                         " It is likely\nyour -classpath option and CLASSPATH" +
                         " environment variable\n"+
                         "do not include the path to libsbmlj.jar.\n");
      System.exit(1);
    }
  }
}

/*
 *
 * @file    TestL3Parameter.java
 * @brief   L3 Parameter unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Sarah Keating 
 *
 * $Id$
 * $HeadURL$
 *
 * This test file was converted from src/sbml/test/TestL3Parameter.c
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

public class TestL3Parameter {

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
    else if ( (a == null) || (b == null) )
    {
      throw new AssertionError();
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
    else if ( (a == null) || (b == null) )
    {
      return;
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
  private Parameter P;

  public boolean isnan(double x)
  {
    return (x != x);
  }

  protected void setUp() throws Exception
  {
    P = new  Parameter(3,1);
    if (P == null);
    {
    }
  }

  protected void tearDown() throws Exception
  {
    P = null;
  }

  public void test_L3_Parameter_NS()
  {
    assertTrue( P.getNamespaces() != null );
    assertTrue( P.getNamespaces().getLength() == 1 );
    assertTrue(P.getNamespaces().getURI(0).equals(    "http://www.sbml.org/sbml/level3/version1/core"));
  }

  public void test_L3_Parameter_constant()
  {
    assertTrue( P.isSetConstant() == false );
    P.setConstant(true);
    assertTrue( P.getConstant() == true );
    assertTrue( P.isSetConstant() == true );
    P.setConstant(false);
    assertTrue( P.getConstant() == false );
    assertTrue( P.isSetConstant() == true );
  }

  public void test_L3_Parameter_create()
  {
    assertTrue( P.getTypeCode() == libsbml.SBML_PARAMETER );
    assertTrue( P.getMetaId().equals("") == true );
    assertTrue( P.getNotes() == null );
    assertTrue( P.getAnnotation() == null );
    assertTrue( P.getId().equals("") == true );
    assertTrue( P.getName().equals("") == true );
    assertTrue( P.getUnits().equals("") == true );
    assertEquals( true, isnan(P.getValue()) );
    assertTrue( P.getConstant() == true );
    assertEquals( false, P.isSetId() );
    assertEquals( false, P.isSetName() );
    assertEquals( false, P.isSetValue() );
    assertEquals( false, P.isSetUnits() );
    assertEquals( false, P.isSetConstant() );
  }

  public void test_L3_Parameter_createWithNS()
  {
    XMLNamespaces xmlns = new  XMLNamespaces();
    xmlns.add( "http://www.sbml.org", "testsbml");
    SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
    sbmlns.addNamespaces(xmlns);
    Parameter p = new  Parameter(sbmlns);
    assertTrue( p.getTypeCode() == libsbml.SBML_PARAMETER );
    assertTrue( p.getMetaId().equals("") == true );
    assertTrue( p.getNotes() == null );
    assertTrue( p.getAnnotation() == null );
    assertTrue( p.getLevel() == 3 );
    assertTrue( p.getVersion() == 1 );
    assertTrue( p.getNamespaces() != null );
    assertTrue( p.getNamespaces().getLength() == 2 );
    assertTrue( p.getId().equals("") == true );
    assertTrue( p.getName().equals("") == true );
    assertTrue( p.getUnits().equals("") == true );
    assertEquals( true, isnan(p.getValue()) );
    assertTrue( p.getConstant() == true );
    assertEquals( false, p.isSetId() );
    assertEquals( false, p.isSetName() );
    assertEquals( false, p.isSetValue() );
    assertEquals( false, p.isSetUnits() );
    assertEquals( false, p.isSetConstant() );
    p = null;
  }

  public void test_L3_Parameter_free_NULL()
  {
  }

  public void test_L3_Parameter_hasRequiredAttributes()
  {
    Parameter p = new  Parameter(3,1);
    assertEquals( false, p.hasRequiredAttributes() );
    p.setId( "id");
    assertEquals( false, p.hasRequiredAttributes() );
    p.setConstant(false);
    assertEquals( true, p.hasRequiredAttributes() );
    p = null;
  }

  public void test_L3_Parameter_id()
  {
    String id =  "mitochondria";;
    assertEquals( false, P.isSetId() );
    P.setId(id);
    assertTrue(P.getId().equals(id));
    assertEquals( true, P.isSetId() );
    if (P.getId() == id);
    {
    }
  }

  public void test_L3_Parameter_name()
  {
    String name =  "My_Favorite_Factory";;
    assertEquals( false, P.isSetName() );
    P.setName(name);
    assertTrue(P.getName().equals(name));
    assertEquals( true, P.isSetName() );
    if (P.getName() == name);
    {
    }
    P.unsetName();
    assertEquals( false, P.isSetName() );
    if (P.getName() != null);
    {
    }
  }

  public void test_L3_Parameter_units()
  {
    String units =  "volume";;
    assertEquals( false, P.isSetUnits() );
    P.setUnits(units);
    assertTrue(P.getUnits().equals(units));
    assertEquals( true, P.isSetUnits() );
    if (P.getUnits() == units);
    {
    }
    P.unsetUnits();
    assertEquals( false, P.isSetUnits() );
    if (P.getUnits() != null);
    {
    }
  }

  public void test_L3_Parameter_value()
  {
    assertEquals( false, P.isSetValue() );
    assertEquals( true, isnan(P.getValue()) );
    P.setValue(1.5);
    assertEquals( true, P.isSetValue() );
    assertTrue( P.getValue() == 1.5 );
    P.unsetValue();
    assertEquals( false, P.isSetValue() );
    assertEquals( true, isnan(P.getValue()) );
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

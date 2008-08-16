/*
 *
 * @file    TestFunctionDefinition.java
 * @brief   SBML FunctionDefinition unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Ben Bornstein 
 *
 * $Id:$
 * $HeadURL:$
 *
 * This test file was converted from src/sbml/test/TestFunctionDefinition.c
 * with the help of conversion sciprt (ctest_converter.pl).
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2008 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *--------------------------------------------------------------------------->*/


package org.sbml.libsbml.test;

import org.sbml.libsbml.*;

import java.io.File;
import java.lang.AssertionError;

public class TestFunctionDefinition {

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
  private FunctionDefinition FD;

  protected void setUp() throws Exception
  {
    FD = new  FunctionDefinition();
    if (FD == null);
    {
    }
  }

  protected void tearDown() throws Exception
  {
    FD = null;
  }

  public void test_FunctionDefinition_create()
  {
    assertTrue( FD.getTypeCode() == libsbml.SBML_FUNCTION_DEFINITION );
    assertTrue( FD.getMetaId().equals("") == true );
    assertTrue( FD.getNotes() == null );
    assertTrue( FD.getAnnotation() == null );
    assertTrue( FD.getId().equals("") == true );
    assertTrue( FD.getName().equals("") == true );
    assertTrue( FD.getMath() == null );
  }

  public void test_FunctionDefinition_createWith()
  {
    ASTNode math = libsbml.parseFormula("lambda(x, x^3)");
    FunctionDefinition fd = new  FunctionDefinition("pow3",math);
    ASTNode math1;
    String formula;
    assertTrue( fd.getTypeCode() == libsbml.SBML_FUNCTION_DEFINITION );
    assertTrue( fd.getMetaId().equals("") == true );
    assertTrue( fd.getNotes() == null );
    assertTrue( fd.getAnnotation() == null );
    assertTrue( fd.getName().equals("") == true );
    math1 = fd.getMath();
    assertTrue( math1 != null );
    formula = libsbml.formulaToString(math1);
    assertTrue( formula != null );
    assertTrue(formula.equals( "lambda(x, x^3)"));
    assertTrue( fd.getMath() != math );
    assertEquals( true, fd.isSetMath() );
    assertTrue(fd.getId().equals( "pow3"));
    assertEquals( true, fd.isSetId() );
    math = null;
    fd = null;
  }

  public void test_FunctionDefinition_free_NULL()
  {
  }

  public void test_FunctionDefinition_getArguments()
  {
    ASTNode math;
    FD.setMath(libsbml.parseFormula("lambda(x, y, x^y)"));
    assertTrue( FD.getNumArguments() == 2 );
    math = FD.getArgument(0);
    assertTrue( math != null );
    assertEquals( true, math.isName() );
    assertTrue(math.getName().equals( "x"));
    assertTrue( math.getNumChildren() == 0 );
    math = FD.getArgument(1);
    assertTrue( math != null );
    assertEquals( true, math.isName() );
    assertTrue(math.getName().equals( "y"));
    assertTrue( math.getNumChildren() == 0 );
    assertEquals( FD.getArgument(0) , FD.getArgument( "x") );
    assertEquals( FD.getArgument(1) , FD.getArgument( "y") );
  }

  public void test_FunctionDefinition_getBody()
  {
    ASTNode math;
    ASTNode math1 = libsbml.parseFormula("lambda(x, x)");
    FD.setMath(math1);
    math = FD.getBody();
    assertTrue( math != null );
    assertEquals( true, math.isName() );
    assertTrue(math.getName().equals( "x"));
    assertTrue( math.getNumChildren() == 0 );
    math1 = null;
  }

  public void test_FunctionDefinition_setId()
  {
    String id = "pow3";
    FD.setId(id);
    assertTrue(FD.getId().equals(id));
    assertEquals( true, FD.isSetId() );
    if (FD.getId() == id);
    {
    }
    FD.setId(FD.getId());
    assertTrue(FD.getId().equals(id));
    FD.setId("");
    assertEquals( false, FD.isSetId() );
    if (FD.getId() != null);
    {
    }
  }

  public void test_FunctionDefinition_setMath()
  {
    ASTNode math = libsbml.parseFormula("lambda(x, x^3)");
    ASTNode math1;
    String formula;
    FD.setMath(math);
    math1 = FD.getMath();
    assertTrue( math1 != null );
    formula = libsbml.formulaToString(math1);
    assertTrue( formula != null );
    assertTrue(formula.equals( "lambda(x, x^3)"));
    assertTrue( FD.getMath() != math );
    assertEquals( true, FD.isSetMath() );
    FD.setMath(FD.getMath());
    math1 = FD.getMath();
    assertTrue( math1 != null );
    formula = libsbml.formulaToString(math1);
    assertTrue( formula != null );
    assertTrue(formula.equals( "lambda(x, x^3)"));
    assertTrue( FD.getMath() != math );
    FD.setMath(null);
    assertEquals( false, FD.isSetMath() );
    if (FD.getMath() != null);
    {
    }
  }

  public void test_FunctionDefinition_setName()
  {
    String name = "Cube Me";
    FD.setName(name);
    assertTrue(FD.getName().equals(name));
    assertEquals( true, FD.isSetName() );
    if (FD.getName() == name);
    {
    }
    FD.setName(FD.getName());
    assertTrue(FD.getName().equals(name));
    FD.setName("");
    assertEquals( false, FD.isSetName() );
    if (FD.getName() != null);
    {
    }
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

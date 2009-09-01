/*
 *
 * @file    TestReadFromFile9.java
 * @brief   Reads tests/l3v1-new.xml into memory and tests it.
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Sarah Keating 
 *
 * $Id$
 * $HeadURL$
 *
 * This test file was converted from src/sbml/test/TestReadFromFile9.cpp
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

public class TestReadFromFile9 {

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

  public void test_read_l3v1_new()
  {
    SBMLReader reader = new SBMLReader();
    SBMLDocument d;
    Model m;
    UnitDefinition ud;
    Unit u;
    Compartment c;
    Species s;
    Parameter p;
    Reaction r;
    SpeciesReference sr;
    KineticLaw kl;
    LocalParameter lp;
    String filename = new String( "../../sbml/test/test-data/" );
    filename += "l3v1-new.xml";
    d = reader.readSBML(filename);
    if (d == null);
    {
    }
    assertTrue( d.getLevel() == 3 );
    assertTrue( d.getVersion() == 1 );
    m = d.getModel();
    assertTrue( m != null );
    assertEquals( true, m.isSetSubstanceUnits() );
    assertEquals( true, m.isSetTimeUnits() );
    assertEquals( true, m.isSetVolumeUnits() );
    assertEquals( true, m.isSetLengthUnits() );
    assertEquals( true, m.isSetAreaUnits() );
    assertEquals( true, m.isSetExtentUnits() );
    assertEquals( true, m.isSetConversionFactor() );
    assertTrue( m.getSubstanceUnits().equals( "mole") );
    assertTrue( m.getTimeUnits().equals( "second") );
    assertTrue( m.getVolumeUnits().equals( "litre") );
    assertTrue( m.getLengthUnits().equals( "metre") );
    assertTrue( m.getAreaUnits().equals( "metre") );
    assertTrue( m.getExtentUnits().equals( "mole") );
    assertTrue( m.getConversionFactor().equals( "p") );
    assertTrue( m.getNumUnitDefinitions() == 2 );
    ud = m.getUnitDefinition(0);
    assertTrue( ud.getNumUnits() == 1 );
    u = ud.getUnit(0);
    assertEquals( false, u.isSetExponent() );
    assertEquals( false, u.isSetScale() );
    assertEquals( false, u.isSetMultiplier() );
    ud = m.getUnitDefinition(1);
    assertTrue( ud.getNumUnits() == 3 );
    u = ud.getUnit(0);
    assertEquals( true, u.isSetExponent() );
    assertEquals( true, u.isSetScale() );
    assertEquals( true, u.isSetMultiplier() );
    assertTrue( u.getExponent() == -1 );
    assertTrue( u.getScale() == 2 );
    assertTrue( u.getMultiplier() == 1.3 );
    u = ud.getUnit(1);
    assertEquals( true, u.isSetExponent() );
    assertEquals( true, u.isSetScale() );
    assertEquals( true, u.isSetMultiplier() );
    assertTrue( u.getScale() == 10 );
    assertTrue( u.getMultiplier() == 0.5 );
    u = ud.getUnit(2);
    assertEquals( true, u.isSetExponent() );
    assertEquals( true, u.isSetScale() );
    assertEquals( true, u.isSetMultiplier() );
    assertTrue( u.getExponent() == 1 );
    assertTrue( u.getScale() == 0 );
    assertTrue( u.getMultiplier() == 1 );
    assertTrue( m.getNumCompartments() == 3 );
    c = m.getCompartment(0);
    assertEquals( true, c.isSetSize() );
    assertEquals( true, c.isSetSpatialDimensions() );
    assertEquals( true, c.isSetConstant() );
    assertTrue( c.getId().equals( "comp") );
    assertTrue( c.getSize() == 1e-14 );
    assertTrue( c.getSpatialDimensions() == 3 );
    assertTrue( c.getUnits().equals( "litre") );
    assertTrue( c.getConstant() == true );
    c = m.getCompartment(1);
    assertEquals( false, c.isSetSize() );
    assertEquals( false, c.isSetSpatialDimensions() );
    assertEquals( true, c.isSetConstant() );
    assertTrue( c.getId().equals( "comp1") );
    assertTrue( c.getConstant() == false );
    c = m.getCompartment(2);
    assertEquals( false, c.isSetSize() );
    assertEquals( false, c.isSetConstant() );
    assertTrue( c.getId().equals( "comp2") );
    assertTrue( m.getNumSpecies() == 2 );
    s = m.getSpecies(0);
    assertTrue( s.getId().equals( "ES") );
    assertTrue( s.getCompartment().equals( "comp") );
    assertEquals( true, s.isSetConversionFactor() );
    assertTrue( s.getConversionFactor().equals( "p") );
    assertEquals( true, s.isSetBoundaryCondition() );
    assertTrue( s.getBoundaryCondition() == false );
    assertEquals( true, s.isSetHasOnlySubstanceUnits() );
    assertTrue( s.getHasOnlySubstanceUnits() == false );
    assertEquals( true, s.isSetSubstanceUnits() );
    assertTrue( s.getSubstanceUnits().equals( "mole") );
    assertEquals( true, s.isSetConstant() );
    assertTrue( s.getConstant() == false );
    s = m.getSpecies(1);
    assertTrue( s.getId().equals( "P") );
    assertTrue( s.getCompartment().equals( "comp") );
    assertEquals( false, s.isSetConversionFactor() );
    assertTrue( s.getConversionFactor().equals( "") );
    assertEquals( false, s.isSetBoundaryCondition() );
    assertEquals( false, s.isSetHasOnlySubstanceUnits() );
    assertEquals( false, s.isSetSubstanceUnits() );
    assertTrue( s.getSubstanceUnits().equals( "") );
    assertEquals( false, s.isSetConstant() );
    assertTrue( m.getNumParameters() == 3 );
    p = m.getParameter(0);
    assertTrue( p.getId().equals( "Keq") );
    assertEquals( true, p.isSetValue() );
    assertTrue( p.getValue() == 2.5 );
    assertEquals( true, p.isSetUnits() );
    assertTrue( p.getUnits().equals( "dimensionless") );
    assertEquals( true, p.isSetConstant() );
    assertTrue( p.getConstant() == true );
    p = m.getParameter(1);
    assertTrue( p.getId().equals( "Keq1") );
    assertEquals( false, p.isSetValue() );
    assertEquals( false, p.isSetUnits() );
    assertTrue( p.getUnits().equals( "") );
    assertEquals( true, p.isSetConstant() );
    assertTrue( p.getConstant() == false );
    p = m.getParameter(2);
    assertTrue( p.getId().equals( "Keq2") );
    assertEquals( false, p.isSetValue() );
    assertEquals( false, p.isSetUnits() );
    assertTrue( p.getUnits().equals( "") );
    assertEquals( false, p.isSetConstant() );
    assertTrue( m.getNumReactions() == 3 );
    r = m.getReaction(0);
    assertEquals( true, r.isSetFast() );
    assertTrue( r.getFast() == false );
    assertEquals( true, r.isSetReversible() );
    assertTrue( r.getReversible() == false );
    assertEquals( true, r.isSetCompartment() );
    assertTrue( r.getCompartment().equals( "comp") );
    sr = r.getReactant(0);
    assertEquals( true, sr.isSetConstant() );
    assertTrue( sr.getConstant() == true );
    sr = r.getProduct(0);
    assertEquals( true, sr.isSetConstant() );
    assertTrue( sr.getConstant() == false );
    kl = r.getKineticLaw();
    assertTrue( kl.getNumLocalParameters() == 1 );
    assertTrue( kl.getNumParameters() == 0 );
    p = kl.getParameter(0);
    assertTrue( p == null );
    lp = kl.getLocalParameter(0);
    assertEquals( true, lp.isSetUnits() );
    assertTrue( lp.getUnits().equals( "per_second") );
    assertEquals( true, lp.isSetValue() );
    assertTrue( lp.getValue() == 0.1 );
    r = m.getReaction(1);
    assertEquals( true, r.isSetFast() );
    assertTrue( r.getFast() == true );
    assertEquals( true, r.isSetReversible() );
    assertTrue( r.getReversible() == true );
    assertEquals( false, r.isSetCompartment() );
    assertTrue( r.getCompartment().equals( "") );
    sr = r.getReactant(0);
    assertEquals( false, sr.isSetConstant() );
    r = m.getReaction(2);
    assertEquals( false, r.isSetFast() );
    assertEquals( false, r.isSetReversible() );
    assertEquals( false, r.isSetCompartment() );
    assertTrue( r.getCompartment().equals( "") );
    d = null;
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

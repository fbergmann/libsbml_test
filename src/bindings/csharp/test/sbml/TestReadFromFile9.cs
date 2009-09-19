/// 
///  @file    TestReadFromFile9.cs
///  @brief   Reads tests/l3v1-new.xml into memory and tests it.
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id$
///  $HeadURL$
/// 
///  This test file was converted from src/sbml/test/TestReadFromFile9.cpp
///  with the help of conversion sciprt (ctest_converter.pl).
/// 
/// <!---------------------------------------------------------------------------
///  This file is part of libSBML.  Please visit http://sbml.org for more
///  information about SBML, and the latest version of libSBML.
/// 
///  Copyright 2005-2009 California Institute of Technology.
///  Copyright 2002-2005 California Institute of Technology and
///                      Japan Science and Technology Corporation.
///  
///  This library is free software; you can redistribute it and/or modify it
///  under the terms of the GNU Lesser General Public License as published by
///  the Free Software Foundation.  A copy of the license agreement is provided
///  in the file named "LICENSE.txt" included with this software distribution
///  and also available online as http://sbml.org/software/libsbml/license.html
/// --------------------------------------------------------------------------->*/


namespace LibSBMLCSTest {

  using libsbml;

  using  System.IO;

  public class TestReadFromFile9 {
    public class AssertionError : System.Exception 
    {
      public AssertionError() : base()
      {
        
      }
    }


    static void assertTrue(bool condition)
    {
      if (condition == true)
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertEquals(object a, object b)
    {
      if ( (a == null) && (b == null) )
      {
        return;
      }
      else if ( (a == null) || (b == null) )
      {
        throw new AssertionError();
      }
      else if (a.Equals(b))
      {
        return;
      }
  
      throw new AssertionError();
    }

    static void assertNotEquals(object a, object b)
    {
      if ( (a == null) && (b == null) )
      {
        throw new AssertionError();
      }
      else if ( (a == null) || (b == null) )
      {
        return;
      }
      else if (a.Equals(b))
      {
        throw new AssertionError();
      }
    }

    static void assertEquals(bool a, bool b)
    {
      if ( a == b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertNotEquals(bool a, bool b)
    {
      if ( a != b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertEquals(int a, int b)
    {
      if ( a == b )
      {
        return;
      }
      throw new AssertionError();
    }

    static void assertNotEquals(int a, int b)
    {
      if ( a != b )
      {
        return;
      }
      throw new AssertionError();
    }


    public bool isnan(double x)
    {
      return (x != x);
    }

  private const int SBML_INT_MAX = 2147483647;
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
      string filename =  "../../sbml/test/test-data/";
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
      assertTrue( m.getSubstanceUnits() ==  "mole" );
      assertTrue( m.getTimeUnits() ==  "second" );
      assertTrue( m.getVolumeUnits() ==  "litre" );
      assertTrue( m.getLengthUnits() ==  "metre" );
      assertTrue( m.getAreaUnits() ==  "metre" );
      assertTrue( m.getExtentUnits() ==  "mole" );
      assertTrue( m.getConversionFactor() ==  "p" );
      assertTrue( m.getNumUnitDefinitions() == 2 );
      ud = m.getUnitDefinition(0);
      assertTrue( ud.getNumUnits() == 1 );
      u = ud.getUnit(0);
      assertEquals( false, u.isSetExponent() );
      assertEquals( false, u.isSetScale() );
      assertEquals( false, u.isSetMultiplier() );
      assertEquals( true, isnan(u.getExponentAsDouble()) );
      assertTrue( u.getScale() == SBML_INT_MAX );
      assertEquals( true, isnan(u.getMultiplier()) );
      ud = m.getUnitDefinition(1);
      assertTrue( ud.getNumUnits() == 3 );
      u = ud.getUnit(0);
      assertEquals( true, u.isSetExponent() );
      assertEquals( true, u.isSetScale() );
      assertEquals( true, u.isSetMultiplier() );
      assertTrue( u.getExponent() == -1 );
      assertTrue( u.getExponentAsDouble() == -1 );
      assertTrue( u.getScale() == 2 );
      assertTrue( u.getMultiplier() == 1.3 );
      u = ud.getUnit(1);
      assertEquals( true, u.isSetExponent() );
      assertEquals( true, u.isSetScale() );
      assertEquals( true, u.isSetMultiplier() );
      assertTrue( u.getExponentAsDouble() == 1.5 );
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
      assertTrue( c.getId() ==  "comp" );
      assertTrue( c.getSize() == 1e-14 );
      assertTrue( c.getSpatialDimensions() == 3 );
      assertTrue( c.getSpatialDimensionsAsDouble() == 3 );
      assertTrue( c.getUnits() ==  "litre" );
      assertTrue( c.getConstant() == true );
      c = m.getCompartment(1);
      assertEquals( false, c.isSetSize() );
      assertEquals( false, c.isSetSpatialDimensions() );
      assertEquals( true, c.isSetConstant() );
      assertTrue( c.getId() ==  "comp1" );
      assertEquals( true, isnan(c.getSize()) );
      assertEquals( true, isnan(c.getSpatialDimensionsAsDouble()) );
      assertTrue( c.getConstant() == false );
      c = m.getCompartment(2);
      assertEquals( false, c.isSetSize() );
      assertEquals( true, c.isSetSpatialDimensions() );
      assertEquals( false, c.isSetConstant() );
      assertTrue( c.getId() ==  "comp2" );
      assertTrue( c.getSpatialDimensionsAsDouble() == 4.6 );
      assertTrue( m.getNumSpecies() == 2 );
      s = m.getSpecies(0);
      assertTrue( s.getId() ==  "ES" );
      assertTrue( s.getCompartment() ==  "comp" );
      assertEquals( true, s.isSetConversionFactor() );
      assertTrue( s.getConversionFactor() ==  "p" );
      assertEquals( true, s.isSetBoundaryCondition() );
      assertTrue( s.getBoundaryCondition() == false );
      assertEquals( true, s.isSetHasOnlySubstanceUnits() );
      assertTrue( s.getHasOnlySubstanceUnits() == false );
      assertEquals( true, s.isSetSubstanceUnits() );
      assertTrue( s.getSubstanceUnits() ==  "mole" );
      assertEquals( true, s.isSetConstant() );
      assertTrue( s.getConstant() == false );
      assertEquals( true, s.isSetInitialAmount() );
      assertTrue( s.getInitialAmount() == 0 );
      assertEquals( false, s.isSetInitialConcentration() );
      assertEquals( true, isnan(s.getInitialConcentration()) );
      s = m.getSpecies(1);
      assertTrue( s.getId() ==  "P" );
      assertTrue( s.getCompartment() ==  "comp" );
      assertEquals( false, s.isSetConversionFactor() );
      assertTrue( s.getConversionFactor() ==  "" );
      assertEquals( false, s.isSetBoundaryCondition() );
      assertEquals( false, s.isSetHasOnlySubstanceUnits() );
      assertEquals( false, s.isSetSubstanceUnits() );
      assertTrue( s.getSubstanceUnits() ==  "" );
      assertEquals( false, s.isSetConstant() );
      assertEquals( false, s.isSetInitialAmount() );
      assertEquals( true, isnan(s.getInitialAmount()) );
      assertEquals( false, s.isSetInitialConcentration() );
      assertEquals( true, isnan(s.getInitialConcentration()) );
      assertTrue( m.getNumParameters() == 3 );
      p = m.getParameter(0);
      assertTrue( p.getId() ==  "Keq" );
      assertEquals( true, p.isSetValue() );
      assertTrue( p.getValue() == 2.5 );
      assertEquals( true, p.isSetUnits() );
      assertTrue( p.getUnits() ==  "dimensionless" );
      assertEquals( true, p.isSetConstant() );
      assertTrue( p.getConstant() == true );
      p = m.getParameter(1);
      assertTrue( p.getId() ==  "Keq1" );
      assertEquals( false, p.isSetValue() );
      assertEquals( true, isnan(p.getValue()) );
      assertEquals( false, p.isSetUnits() );
      assertTrue( p.getUnits() ==  "" );
      assertEquals( true, p.isSetConstant() );
      assertTrue( p.getConstant() == false );
      p = m.getParameter(2);
      assertTrue( p.getId() ==  "Keq2" );
      assertEquals( false, p.isSetValue() );
      assertEquals( true, isnan(p.getValue()) );
      assertEquals( false, p.isSetUnits() );
      assertTrue( p.getUnits() ==  "" );
      assertEquals( false, p.isSetConstant() );
      assertTrue( m.getNumReactions() == 3 );
      r = m.getReaction(0);
      assertEquals( true, r.isSetFast() );
      assertTrue( r.getFast() == false );
      assertEquals( true, r.isSetReversible() );
      assertTrue( r.getReversible() == false );
      assertEquals( true, r.isSetCompartment() );
      assertTrue( r.getCompartment() ==  "comp" );
      sr = r.getReactant(0);
      assertEquals( true, sr.isSetConstant() );
      assertTrue( sr.getConstant() == true );
      assertEquals( true, sr.isSetStoichiometry() );
      assertTrue( sr.getStoichiometry() == 1 );
      sr = r.getProduct(0);
      assertEquals( true, sr.isSetConstant() );
      assertTrue( sr.getConstant() == false );
      assertEquals( false, sr.isSetStoichiometry() );
      assertEquals( true, isnan(sr.getStoichiometry()) );
      kl = r.getKineticLaw();
      assertTrue( kl.getNumLocalParameters() == 2 );
      assertTrue( kl.getNumParameters() == 0 );
      p = kl.getParameter(0);
      assertTrue( p == null );
      lp = kl.getLocalParameter(0);
      assertEquals( true, lp.isSetUnits() );
      assertTrue( lp.getUnits() ==  "per_second" );
      assertEquals( true, lp.isSetValue() );
      assertTrue( lp.getValue() == 0.1 );
      lp = kl.getLocalParameter(1);
      assertEquals( false, lp.isSetUnits() );
      assertTrue( lp.getUnits() ==  "" );
      assertEquals( false, lp.isSetValue() );
      assertEquals( true, isnan(lp.getValue()) );
      r = m.getReaction(1);
      assertEquals( true, r.isSetFast() );
      assertTrue( r.getFast() == true );
      assertEquals( true, r.isSetReversible() );
      assertTrue( r.getReversible() == true );
      assertEquals( false, r.isSetCompartment() );
      assertTrue( r.getCompartment() ==  "" );
      sr = r.getReactant(0);
      assertEquals( false, sr.isSetConstant() );
      r = m.getReaction(2);
      assertEquals( false, r.isSetFast() );
      assertEquals( false, r.isSetReversible() );
      assertEquals( false, r.isSetCompartment() );
      assertTrue( r.getCompartment() ==  "" );
      d = null;
    }

  }
}

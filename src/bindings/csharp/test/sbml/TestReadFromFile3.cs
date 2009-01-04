/// 
///  @file    TestReadFromFile3.cs
///  @brief   Reads tests/l1v1-rules.xml into memory and tests it.
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Ben Bornstein 
/// 
///  $Id:$
///  $HeadURL:$
/// 
///  This test file was converted from src/sbml/test/TestReadFromFile3.c
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

  public class TestReadFromFile3 {
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


    public void test_read_l1v1_rules()
    {
      SBMLDocument d;
      Model m;
      Compartment c;
      KineticLaw kl;
      Parameter p;
      Rule pr;
      Reaction r;
      Species s;
      Rule scr;
      SpeciesReference sr;
      UnitDefinition ud;
      string filename = "../../sbml/test/test-data/l1v1-rules.xml";
      d = libsbml.readSBML(filename);
      if (d == null);
      {
      }
      assertTrue( d.getLevel() == 1 );
      assertTrue( d.getVersion() == 1 );
      m = d.getModel();
      assertTrue( m.getNumCompartments() == 1 );
      c = m.getCompartment(0);
      assertTrue((  "cell" == c.getName() ));
      assertTrue( c.getVolume() == 1 );
      assertTrue( m.getNumSpecies() == 6 );
      s = m.getSpecies(0);
      assertTrue((  "s1"    == s.getName() ));
      assertTrue((  "cell"  == s.getCompartment() ));
      assertTrue( s.getInitialAmount() == 4 );
      assertTrue( s.getBoundaryCondition() == false );
      s = m.getSpecies(1);
      assertTrue((  "s2"    == s.getName() ));
      assertTrue((  "cell"  == s.getCompartment() ));
      assertTrue( s.getInitialAmount() == 2 );
      assertTrue( s.getBoundaryCondition() == false );
      s = m.getSpecies(2);
      assertTrue((  "x0"    == s.getName() ));
      assertTrue((  "cell"  == s.getCompartment() ));
      assertTrue( s.getInitialAmount() == 1 );
      assertTrue( s.getBoundaryCondition() == false );
      s = m.getSpecies(3);
      assertTrue((  "x1"    == s.getName() ));
      assertTrue((  "cell"  == s.getCompartment() ));
      assertTrue( s.getInitialAmount() == 0 );
      assertTrue( s.getBoundaryCondition() == false );
      s = m.getSpecies(4);
      assertTrue((  "x2"    == s.getName() ));
      assertTrue((  "cell"  == s.getCompartment() ));
      assertTrue( s.getInitialAmount() == 1 );
      assertTrue( s.getBoundaryCondition() == false );
      s = m.getSpecies(5);
      assertTrue((  "x3"    == s.getName() ));
      assertTrue((  "cell"  == s.getCompartment() ));
      assertTrue( s.getInitialAmount() == 0 );
      assertTrue( s.getBoundaryCondition() == false );
      assertTrue( m.getNumParameters() == 7 );
      p = m.getParameter(0);
      assertTrue((  "k1" == p.getName() ));
      assertTrue( p.getValue() == 1.2 );
      p = m.getParameter(1);
      assertTrue((  "k2" == p.getName() ));
      assertTrue( p.getValue() == 1000 );
      p = m.getParameter(2);
      assertTrue((  "k3" == p.getName() ));
      assertTrue( p.getValue() == 3000 );
      p = m.getParameter(3);
      assertTrue((  "k4" == p.getName() ));
      assertTrue( p.getValue() == 4.5 );
      assertTrue( m.getNumRules() == 4 );
      pr = m.getRule(0);
      assertTrue((  "t" == pr.getVariable() ));
      assertTrue((  "s1 + s2" == pr.getFormula() ));
      ud = pr.getDerivedUnitDefinition();
      assertTrue( ud.getNumUnits() == 2 );
      assertTrue( ud.getUnit(0).getKind() == libsbml.UNIT_KIND_MOLE );
      assertTrue( ud.getUnit(0).getExponent() == 1 );
      assertTrue( ud.getUnit(1).getKind() == libsbml.UNIT_KIND_LITRE );
      assertTrue( ud.getUnit(1).getExponent() == -1 );
      assertTrue( pr.containsUndeclaredUnits() == false );
      pr = m.getRule(1);
      assertTrue((  "k" == pr.getVariable() ));
      assertTrue((  "k3/k2" == pr.getFormula() ));
      ud = pr.getDerivedUnitDefinition();
      assertTrue( ud.getNumUnits() == 0 );
      assertTrue( pr.containsUndeclaredUnits() == true );
      scr = m.getRule(2);
      assertTrue((  "x2" == scr.getVariable() ));
      assertTrue((  "k * (s1+s2)/(1 + k)" == scr.getFormula() ));
      scr = m.getRule(3);
      assertTrue((  "x3" == scr.getVariable() ));
      assertTrue((  "p*(t - s2)" == scr.getFormula() ));
      assertTrue( m.getNumReactions() == 2 );
      r = m.getReaction(0);
      assertTrue((  "j1" == r.getName() ));
      assertTrue( r.getReversible() != false );
      assertTrue( r.getFast() == false );
      r = m.getReaction(1);
      assertTrue((  "j3" == r.getName() ));
      assertTrue( r.getReversible() != false );
      assertTrue( r.getFast() == false );
      r = m.getReaction(0);
      assertTrue( r.getNumReactants() == 1 );
      assertTrue( r.getNumProducts() == 1 );
      sr = r.getReactant(0);
      assertTrue((  "x0" == sr.getSpecies() ));
      assertTrue( sr.getStoichiometry() == 1 );
      assertTrue( sr.getDenominator() == 1 );
      sr = r.getProduct(0);
      assertTrue((  "s1" == sr.getSpecies() ));
      assertTrue( sr.getStoichiometry() == 1 );
      assertTrue( sr.getDenominator() == 1 );
      kl = r.getKineticLaw();
      assertTrue((  "k1 * x0" == kl.getFormula() ));
      r = m.getReaction(1);
      assertTrue( r.getNumReactants() == 1 );
      assertTrue( r.getNumProducts() == 1 );
      sr = r.getReactant(0);
      assertTrue((  "s2" == sr.getSpecies() ));
      assertTrue( sr.getStoichiometry() == 1 );
      assertTrue( sr.getDenominator() == 1 );
      sr = r.getProduct(0);
      assertTrue((  "x1" == sr.getSpecies() ));
      assertTrue( sr.getStoichiometry() == 1 );
      assertTrue( sr.getDenominator() == 1 );
      kl = r.getKineticLaw();
      assertTrue((  "k4 * s2" == kl.getFormula() ));
      d = null;
    }

  }
}

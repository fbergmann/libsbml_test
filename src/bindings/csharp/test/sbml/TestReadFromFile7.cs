/// 
///  @file    TestReadFromFile7.cs
///  @brief   Reads test-data/l2v3-all.xml into memory and tests it.
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id:$
///  $HeadURL:$
/// 
///  This test file was converted from src/sbml/test/TestReadFromFile7.cpp
///  with the help of conversion sciprt (ctest_converter.pl).
/// 
/// <!---------------------------------------------------------------------------
///  This file is part of libSBML.  Please visit http://sbml.org for more
///  information about SBML, and the latest version of libSBML.
/// 
///  Copyright 2005-2008 California Institute of Technology.
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

  public class TestReadFromFile7 {
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


    public void test_read_l2v3_all()
    {
      SBMLReader reader = new SBMLReader();
      SBMLDocument d = new SBMLDocument();
      Model m = new Model();
      Compartment c = new Compartment();
      CompartmentType ct = new CompartmentType();
      Species s = new Species();
      Parameter p = new Parameter();
      AssignmentRule ar = new AssignmentRule();
      Reaction r = new Reaction();
      SpeciesReference sr = new SpeciesReference();
      KineticLaw kl = new KineticLaw();
      UnitDefinition ud = new UnitDefinition();
      Constraint con = new Constraint();
      Event e = new Event();
      Delay delay = new Delay();
      Trigger trigger = new Trigger();
      EventAssignment ea = new EventAssignment();
      FunctionDefinition fd = new FunctionDefinition();
      InitialAssignment ia = new InitialAssignment();
      AlgebraicRule alg = new AlgebraicRule();
      RateRule rr = new RateRule();
      SpeciesType st = new SpeciesType();
      StoichiometryMath stoich = new StoichiometryMath();
      Unit u = new Unit();
      ListOfEvents loe = new ListOfEvents();
      Event e1 = new Event();
      ListOfEventAssignments loea = new ListOfEventAssignments();
      EventAssignment ea1 = new EventAssignment();
      ListOfFunctionDefinitions lofd = new ListOfFunctionDefinitions();
      FunctionDefinition fd1 = new FunctionDefinition();
      ListOfParameters lop = new ListOfParameters();
      Parameter p1 = new Parameter();
      ListOfSpeciesTypes lost = new ListOfSpeciesTypes();
      SpeciesType st1 = new SpeciesType();
      ListOfUnitDefinitions loud = new ListOfUnitDefinitions();
      UnitDefinition ud1 = new UnitDefinition();
      ListOfUnits lou = new ListOfUnits();
      Unit u1 = new Unit();
      ASTNode ast = new ASTNode();
      string filename =  "../../sbml/test/test-data/";
      filename += "l2v3-all.xml";
      d = reader.readSBML(filename);
      if (d == null);
      {
      }
      assertTrue( d.getLevel() == 2 );
      assertTrue( d.getVersion() == 3 );
      m = d.getModel();
      assertTrue( m != null );
      assertTrue( m.getId() ==  "l2v3_all" );
      assertTrue( m.getNumCompartments() == 1 );
      c = m.getCompartment(0);
      assertTrue( c != null );
      assertTrue( c.getId() ==  "a" );
      assertEquals(c.getCompartmentType(), "hh");
      assertTrue( c.getSBOTerm() == 236 );
      assertTrue( c.getSBOTermID() ==  "SBO:0000236" );
      assertTrue( c.getSize() == 2.3 );
      assertTrue( m.getNumCompartmentTypes() == 1 );
      ct = m.getCompartmentType(0);
      assertTrue( ct != null );
      assertTrue( ct.getId() ==  "hh" );
      assertTrue( ct.getSBOTerm() == 236 );
      assertTrue( ct.getSBOTermID() ==  "SBO:0000236" );
      assertTrue( m.getNumSpeciesTypes() == 1 );
      st = m.getSpeciesType(0);
      assertTrue( st != null );
      assertTrue( st.getId() ==  "gg" );
      assertTrue( st.getName() ==  "dd" );
      assertTrue( st.getSBOTerm() == 236 );
      assertTrue( st.getSBOTermID() ==  "SBO:0000236" );
      lost = m.getListOfSpeciesTypes();
      st1 = lost.get(0);
      assertTrue( st1 == st );
      st1 = lost.get("gg");
      assertTrue( st1 == st );
      assertTrue( m.getNumConstraints() == 1 );
      con = m.getConstraint(0);
      assertTrue( con != null );
      ast = con.getMath();
      assertTrue((  "lt(x, 3)" == libsbml.formulaToString(ast) ));
      assertTrue( m.getNumEvents() == 1 );
      e = m.getEvent(0);
      assertTrue( e != null );
      assertTrue( e.getId() ==  "e1" );
      assertTrue( e.getSBOTerm() == 231 );
      assertTrue( e.getSBOTermID() ==  "SBO:0000231" );
      assertEquals( true, e.isSetDelay() );
      delay = e.getDelay();
      assertTrue( delay != null );
      assertTrue( delay.getSBOTerm() == 64 );
      assertTrue( delay.getSBOTermID() ==  "SBO:0000064" );
      ast = delay.getMath();
      assertTrue((  "p + 3" == libsbml.formulaToString(ast) ));
      assertEquals( true, e.isSetTrigger() );
      trigger = e.getTrigger();
      assertTrue( trigger != null );
      assertTrue( trigger.getSBOTerm() == 64 );
      assertTrue( trigger.getSBOTermID() ==  "SBO:0000064" );
      ast = trigger.getMath();
      assertTrue((  "lt(x, 3)" == libsbml.formulaToString(ast) ));
      loe = m.getListOfEvents();
      e1 = loe.get(0);
      assertTrue( e1 == e );
      e1 = loe.get("e1");
      assertTrue( e1 == e );
      assertTrue( e.getNumEventAssignments() == 1 );
      ea = e.getEventAssignment(0);
      assertTrue( ea != null );
      assertTrue( ea.getVariable() ==  "a" );
      assertTrue( ea.getSBOTerm() == 64 );
      assertTrue( ea.getSBOTermID() ==  "SBO:0000064" );
      ast = ea.getMath();
      assertTrue((  "x * p3" == libsbml.formulaToString(ast) ));
      loea = e.getListOfEventAssignments();
      ea1 = loea.get(0);
      assertTrue( ea1 == ea );
      ea1 = loea.get("a");
      assertTrue( ea1 == ea );
      assertTrue( m.getNumFunctionDefinitions() == 1 );
      fd = m.getFunctionDefinition(0);
      assertTrue( fd != null );
      assertTrue( fd.getId() ==  "fd" );
      assertTrue( fd.getSBOTerm() == 64 );
      assertTrue( fd.getSBOTermID() ==  "SBO:0000064" );
      ast = fd.getMath();
      assertTrue((  "lambda(x, pow(x, 3))" == libsbml.formulaToString(ast) ));
      lofd = m.getListOfFunctionDefinitions();
      fd1 = lofd.get(0);
      assertTrue( fd1 == fd );
      fd1 = lofd.get("fd");
      assertTrue( fd1 == fd );
      assertTrue( m.getNumInitialAssignments() == 1 );
      ia = m.getInitialAssignment(0);
      assertTrue( ia != null );
      assertTrue( ia.getSymbol() ==  "p1" );
      ast = ia.getMath();
      assertTrue((  "x * p3" == libsbml.formulaToString(ast) ));
      assertTrue( m.getNumRules() == 3 );
      alg = ((AlgebraicRule)  m.getRule(0));
      assertTrue( alg != null );
      assertTrue( alg.getSBOTerm() == 64 );
      assertTrue( alg.getSBOTermID() ==  "SBO:0000064" );
      ast = alg.getMath();
      assertTrue((  "pow(x, 3)" == libsbml.formulaToString(ast) ));
      ar = ((AssignmentRule) m.getRule(1));
      assertTrue( ar != null );
      assertTrue( ar.getVariable() ==  "p2" );
      assertTrue( ar.getSBOTerm() == 64 );
      assertTrue( ar.getSBOTermID() ==  "SBO:0000064" );
      ast = ar.getMath();
      assertTrue((  "x * p3" == libsbml.formulaToString(ast) ));
      rr = ((RateRule) m.getRule(2));
      assertTrue( rr != null );
      assertTrue( rr.getVariable() ==  "p3" );
      assertTrue( rr.getSBOTerm() == 64 );
      assertTrue( rr.getSBOTermID() ==  "SBO:0000064" );
      ast = rr.getMath();
      assertTrue((  "p1 / p" == libsbml.formulaToString(ast) ));
      assertTrue( m.getNumSpecies() == 1 );
      s = m.getSpecies(0);
      assertTrue( s != null );
      assertTrue( s.getId() ==  "s" );
      assertEquals(s.getSpeciesType(), "gg");
      assertTrue( s.getCompartment() ==  "a" );
      assertTrue( s.getSBOTerm() == 236 );
      assertTrue( s.getSBOTermID() ==  "SBO:0000236" );
      assertEquals( true, s.isSetInitialAmount() );
      assertEquals( false, s.isSetInitialConcentration() );
      assertTrue( s.getInitialAmount() == 0 );
      assertTrue( m.getNumReactions() == 1 );
      r = m.getReaction(0);
      assertTrue( r != null );
      assertTrue( r.getId() ==  "r" );
      assertEquals( false, r.getReversible() );
      assertEquals( true, r.getFast() );
      assertEquals( true, r.isSetKineticLaw() );
      kl = r.getKineticLaw();
      assertTrue( kl != null );
      assertEquals( true, kl.isSetMath() );
      ast = kl.getMath();
      assertTrue((  "s * k / p" == libsbml.formulaToString(ast) ));
      assertTrue( kl.getNumParameters() == 2 );
      p = kl.getParameter(0);
      assertTrue( p != null );
      assertTrue( p.getId() ==  "k" );
      assertTrue( p.getUnits() ==  "litre" );
      assertTrue( p.getValue() == 9 );
      ud = p.getDerivedUnitDefinition();
      assertTrue( ud.getNumUnits() == 1 );
      assertTrue( ud.getUnit(0).getKind() == libsbml.UNIT_KIND_LITRE );
      assertTrue( ud.getUnit(0).getExponent() == 1 );
      lop = kl.getListOfParameters();
      p1 = lop.get(0);
      assertTrue( p1 == p );
      p1 = lop.get("k");
      assertTrue( p1 == p );
      p = kl.getParameter(1);
      assertTrue( p != null );
      assertTrue( p.getId() ==  "k1" );
      assertTrue( p.getUnits() ==  "ud1" );
      assertTrue( p.getValue() == 9 );
      ud = p.getDerivedUnitDefinition();
      assertTrue( ud.getNumUnits() == 1 );
      assertTrue( ud.getUnit(0).getKind() == libsbml.UNIT_KIND_MOLE );
      assertTrue( ud.getUnit(0).getExponent() == 1 );
      assertTrue( r.getNumReactants() == 1 );
      assertTrue( r.getNumProducts() == 0 );
      assertTrue( r.getNumModifiers() == 0 );
      sr = r.getReactant(0);
      assertTrue( sr != null );
      assertTrue( sr.getSpecies() ==  "s" );
      assertTrue( sr.getSBOTerm() == 11 );
      assertTrue( sr.getSBOTermID() ==  "SBO:0000011" );
      stoich = sr.getStoichiometryMath();
      assertTrue( stoich != null );
      assertTrue( stoich.getSBOTerm() == 64 );
      assertTrue( stoich.getSBOTermID() ==  "SBO:0000064" );
      ast = stoich.getMath();
      assertTrue((  "s * p" == libsbml.formulaToString(ast) ));
      assertTrue( m.getNumUnitDefinitions() == 1 );
      ud = m.getUnitDefinition(0);
      assertTrue( ud != null );
      assertTrue( ud.getId() ==  "ud1" );
      loud = m.getListOfUnitDefinitions();
      ud1 = loud.get(0);
      assertTrue( ud1 == ud );
      ud1 = loud.get("ud1");
      assertTrue( ud1 == ud );
      assertTrue( ud.getNumUnits() == 1 );
      u = ud.getUnit(0);
      assertTrue( u != null );
      assertTrue( u.getKind() == libsbml.UNIT_KIND_MOLE );
      lou = ud.getListOfUnits();
      u1 = lou.get(0);
      assertTrue( u1 == u );
      d = null;
    }

  }
}

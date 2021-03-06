///  @file    TestWriteL3SBML.cs
///  @brief   Write SBML unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
/// 
///  ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
/// 
///  DO NOT EDIT THIS FILE.
/// 
///  This file was generated automatically by converting the file located at
///  src/sbml/test/TestWriteL3SBML.cpp
///  using the conversion program dev/utilities/translateTests/translateTests.pl.
///  Any changes made here will be lost the next time the file is regenerated.
/// 
///  -----------------------------------------------------------------------------
///  This file is part of libSBML.  Please visit http://sbml.org for more
///  information about SBML, and the latest version of libSBML.
/// 
///  Copyright 2005-2010 California Institute of Technology.
///  Copyright 2002-2005 California Institute of Technology and
///                      Japan Science and Technology Corporation.
///  
///  This library is free software; you can redistribute it and/or modify it
///  under the terms of the GNU Lesser General Public License as published by
///  the Free Software Foundation.  A copy of the license agreement is provided
///  in the file named "LICENSE.txt" included with this software distribution
///  and also available online as http://sbml.org/software/libsbml/license.html
///  -----------------------------------------------------------------------------


namespace LibSBMLCSTest.sbml {

  using libsbmlcs;

  using System;

  using System.IO;

  public class TestWriteL3SBML {
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

    private SBMLDocument D;
    private string S;

    public string LV_L3v1()
    {
      return "level=\"3\" version=\"1\">\n";
    }

    public string NS_L3v1()
    {
      return "xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" ";
    }

    public string SBML_END()
    {
      return "</sbml>\n";
    }

    public string SBML_START()
    {
      return "<sbml ";
    }

    public string XML_START()
    {
      return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    }

    public string wrapSBML_L3v1(string s)
    {
      string r = XML_START();
      r += SBML_START();
      r += NS_L3v1();
      r += LV_L3v1();
      r += s;
      r += SBML_END();
      return r;
    }

    public string wrapXML(string s)
    {
      string r = XML_START();
      r += s;
      return r;
    }


  public double util_NaN()
  {
    double z = 0.0;
    return 0.0/z;
  }

  public double util_PosInf()
  {
    double z = 0.0;
    return 1.0/z;
  }

  public double util_NegInf()
  {
    double z = 0.0;
    return -1.0/z;
  }

//  public bool equals(string s)
//  {
//    return s == OSS.str();
//  }

  public bool equals(string s1, string s2)
  {
    return (s1 ==s2);
  }

    public void setUp()
    {
      D = new SBMLDocument();
      D.setLevelAndVersion(3,1,false);
      S = null;
    }

    public void tearDown()
    {
      S = null;
    }

    public void test_SBMLWriter_L3_create()
    {
      SBMLWriter w = new  SBMLWriter();
      assertTrue( w != null );
      w = null;
    }

    public void test_SBMLWriter_L3_setProgramName()
    {
      SBMLWriter w = new  SBMLWriter();
      assertTrue( w != null );
      int i = w.setProgramName( "sss");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      i = w.setProgramName("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      w = null;
    }

    public void test_SBMLWriter_L3_setProgramVersion()
    {
      SBMLWriter w = new  SBMLWriter();
      assertTrue( w != null );
      int i = w.setProgramVersion( "sss");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      i = w.setProgramVersion("");
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      w = null;
    }

    public void test_WriteL3SBML_Compartment()
    {
      string expected =  "<compartment id=\"A\" constant=\"true\"/>";
      Compartment c = D.createModel().createCompartment();
      c.setId("A");
      c.setConstant(true);
      assertEquals( true, equals(expected,c.toSBML()) );
    }

    public void test_WriteL3SBML_Compartment_spatialDimensions()
    {
      string expected = "<compartment id=\"A\" spatialDimensions=\"2.1\" " + "constant=\"false\"/>";
      string expected1 =  "<compartment id=\"A\" constant=\"false\"/>";
      Compartment c = D.createModel().createCompartment();
      c.setId("A");
      c.setConstant(false);
      c.setSpatialDimensions(2.1);
      assertEquals( true, equals(expected,c.toSBML()) );
      c.unsetSpatialDimensions();
      assertEquals( true, equals(expected1,c.toSBML()) );
    }

    public void test_WriteL3SBML_Event()
    {
      string expected =  "<event id=\"e\" useValuesFromTriggerTime=\"true\"/>";
      Event e = D.createModel().createEvent();
      e.setId("e");
      e.setUseValuesFromTriggerTime(true);
      assertEquals( true, equals(expected,e.toSBML()) );
    }

    public void test_WriteL3SBML_Event_full()
    {
      string expected = "<event useValuesFromTriggerTime=\"true\">\n" + 
    "  <trigger initialValue=\"true\" persistent=\"false\">\n" + 
    "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\">\n" + 
    "      <true/>\n" + 
    "    </math>\n" + 
    "  </trigger>\n" + 
    "  <priority>\n" + 
    "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\">\n" + 
    "      <cn type=\"integer\"> 2 </cn>\n" + 
    "    </math>\n" + 
    "  </priority>\n" + 
    "</event>";
      Event e = D.createModel().createEvent();
      e.setUseValuesFromTriggerTime(true);
      Trigger t = e.createTrigger();
      t.setInitialValue(true);
      t.setPersistent(false);
      ASTNode math1 = libsbml.parseFormula("true");
      t.setMath(math1);
      Priority p = e.createPriority();
      ASTNode math2 = libsbml.parseFormula("2");
      p.setMath(math2);
      assertEquals( true, equals(expected,e.toSBML()) );
    }

    public void test_WriteL3SBML_Event_useValues()
    {
      string expected = "<event id=\"e\" useValuesFromTriggerTime=\"false\">\n" + 
    "  <delay/>\n" + 
    "</event>";
      Event e = D.createModel().createEvent();
      e.setId("e");
      e.setUseValuesFromTriggerTime(false);
      e.createDelay();
      assertEquals( true, equals(expected,e.toSBML()) );
    }

    public void test_WriteL3SBML_INF()
    {
      string expected = "<parameter id=\"p\" value=\"INF\"" + " constant=\"true\"/>";
      Parameter p = D.createModel().createParameter();
      p.setId("p");
      p.setValue(util_PosInf());
      p.setConstant(true);
      assertEquals( true, equals(expected,p.toSBML()) );
    }

    public void test_WriteL3SBML_KineticLaw_ListOfParameters()
    {
      string expected = "<kineticLaw>\n" + 
    "  <listOfLocalParameters>\n" + 
    "    <localParameter id=\"n\" value=\"1.2\"/>\n" + 
    "  </listOfLocalParameters>\n" + 
    "</kineticLaw>";
      KineticLaw kl = D.createModel().createReaction().createKineticLaw();
      LocalParameter p = kl.createLocalParameter();
      p.setId("n");
      p.setValue(1.2);
      assertEquals( true, equals(expected,kl.toSBML()) );
    }

    public void test_WriteL3SBML_Model()
    {
      string expected = wrapSBML_L3v1("  <model/>\n"  
    );
      Model m = D.createModel("");
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_Model_conversionFactor()
    {
      string expected = wrapSBML_L3v1("  <model conversionFactor=\"p\"/>\n"  
    );
      Model m = D.createModel("");
      m.setConversionFactor("p");
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_Model_otherUnits()
    {
      string expected = wrapSBML_L3v1("  <model volumeUnits=\"litre\" areaUnits=\"area\" lengthUnits=\"metre\"/>\n"  
    );
      Model m = D.createModel("");
      m.setVolumeUnits("litre");
      m.setAreaUnits("area");
      m.setLengthUnits("metre");
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_Model_substanceUnits()
    {
      string expected = wrapSBML_L3v1("  <model substanceUnits=\"mole\"/>\n"  
    );
      Model m = D.createModel("");
      m.setSubstanceUnits("mole");
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_Model_timeUnits()
    {
      string expected = wrapSBML_L3v1("  <model timeUnits=\"second\"/>\n"  
    );
      Model m = D.createModel("");
      m.setTimeUnits("second");
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_NaN()
    {
      string expected = "<parameter id=\"p\" value=\"NaN\"" + " constant=\"true\"/>";
      Parameter p = D.createModel().createParameter();
      p.setId("p");
      p.setValue(util_NaN());
      p.setConstant(true);
      assertEquals( true, equals(expected,p.toSBML()) );
    }

    public void test_WriteL3SBML_NegINF()
    {
      string expected = "<parameter id=\"p\" value=\"-INF\"" + " constant=\"true\"/>";
      Parameter p = D.createModel().createParameter();
      p.setId("p");
      p.setValue(util_NegInf());
      p.setConstant(true);
      assertEquals( true, equals(expected,p.toSBML()) );
    }

    public void test_WriteL3SBML_Parameter()
    {
      string expected = "<parameter id=\"Km1\" value=\"2.3\"" + " units=\"second\" constant=\"true\"/>";
      Parameter p = D.createModel().createParameter();
      p.setId("Km1");
      p.setValue(2.3);
      p.setUnits("second");
      p.setConstant(true);
      assertEquals( true, equals(expected,p.toSBML()) );
    }

    public void test_WriteL3SBML_Priority()
    {
      string expected =  "<priority/>";
      Priority p = D.createModel().createEvent().createPriority();
      assertEquals( true, equals(expected,p.toSBML()) );
    }

    public void test_WriteL3SBML_Reaction()
    {
      string expected = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\"/>";
      Reaction r = D.createModel().createReaction();
      r.setId("r");
      r.setReversible(false);
      r.setFast(true);
      assertEquals( true, equals(expected,r.toSBML()) );
    }

    public void test_WriteL3SBML_Reaction_compartment()
    {
      string expected = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\" compartment=\"c\"/>";
      string expected1 = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\"/>";
      Reaction r = D.createModel().createReaction();
      r.setId("r");
      r.setReversible(false);
      r.setFast(true);
      r.setCompartment("c");
      assertEquals( true, equals(expected,r.toSBML()) );
      r.unsetCompartment();
      assertEquals( true, equals(expected1,r.toSBML()) );
    }

    public void test_WriteL3SBML_Reaction_full()
    {
      string expected = "<reaction id=\"v1\" reversible=\"true\" fast=\"false\">\n" + 
    "  <listOfReactants>\n" + 
    "    <speciesReference species=\"x0\"/>\n" + 
    "  </listOfReactants>\n" + 
    "  <listOfProducts>\n" + 
    "    <speciesReference species=\"s1\"/>\n" + 
    "  </listOfProducts>\n" + 
    "  <listOfModifiers>\n" + 
    "    <modifierSpeciesReference species=\"m1\"/>\n" + 
    "  </listOfModifiers>\n" + 
    "  <kineticLaw>\n" + 
    "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\">\n" + 
    "      <apply>\n" + 
    "        <divide/>\n" + 
    "        <apply>\n" + 
    "          <times/>\n" + 
    "          <ci> vm </ci>\n" + 
    "          <ci> s1 </ci>\n" + 
    "        </apply>\n" + 
    "        <apply>\n" + 
    "          <plus/>\n" + 
    "          <ci> km </ci>\n" + 
    "          <ci> s1 </ci>\n" + 
    "        </apply>\n" + 
    "      </apply>\n" + 
    "    </math>\n" + 
    "  </kineticLaw>\n" + 
    "</reaction>";
      D.createModel();
      Reaction r = D.getModel().createReaction();
      r.setId("v1");
      r.setReversible(true);
      r.setFast(false);
      r.createReactant().setSpecies("x0");
      r.createProduct().setSpecies("s1");
      r.createModifier().setSpecies("m1");
      r.createKineticLaw().setFormula("(vm * s1)/(km + s1)");
      assertEquals( true, equals(expected,r.toSBML()) );
    }

    public void test_WriteL3SBML_SBMLDocument_L3v1()
    {
      string expected = wrapXML("<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" " + "level=\"3\" version=\"1\"/>\n");
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_Species()
    {
      string expected = "<species id=\"Ca2\" compartment=\"cell\" initialAmount=\"0.7\"" + 
    " substanceUnits=\"mole\" hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"/>";
      Species s = D.createModel().createSpecies();
      s.setId("Ca2");
      s.setCompartment("cell");
      s.setInitialAmount(0.7);
      s.setUnits("mole");
      s.setBoundaryCondition(true);
      s.setHasOnlySubstanceUnits(false);
      s.setConstant(true);
      assertEquals( true, equals(expected,s.toSBML()) );
    }

    public void test_WriteL3SBML_SpeciesReference()
    {
      string expected = "<speciesReference species=\"s\"" + " stoichiometry=\"3\" constant=\"true\"/>";
      SpeciesReference sr = D.createModel().createReaction().createReactant();
      sr.setSpecies("s");
      sr.setStoichiometry(3);
      sr.setConstant(true);
      assertEquals( true, equals(expected,sr.toSBML()) );
    }

    public void test_WriteL3SBML_Species_conversionFactor()
    {
      string expected = "<species id=\"Ca2\" compartment=\"cell\"" + 
    " hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"" + 
    " conversionFactor=\"p\"/>";
      string expected1 = "<species id=\"Ca2\" compartment=\"cell\"" + 
    " hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"/>";
      Species s = D.createModel().createSpecies();
      s.setId("Ca2");
      s.setCompartment("cell");
      s.setBoundaryCondition(true);
      s.setHasOnlySubstanceUnits(false);
      s.setConstant(true);
      s.setConversionFactor("p");
      assertEquals( true, equals(expected,s.toSBML()) );
      s.unsetConversionFactor();
      assertEquals( true, equals(expected1,s.toSBML()) );
    }

    public void test_WriteL3SBML_Trigger()
    {
      string expected =  "<trigger/>";
      Trigger t = D.createModel().createEvent().createTrigger();
      assertEquals( true, equals(expected,t.toSBML()) );
    }

    public void test_WriteL3SBML_Trigger_initialValue()
    {
      string expected =  "<trigger initialValue=\"false\" persistent=\"true\"/>";
      Trigger t = D.createModel().createEvent().createTrigger();
      t.setInitialValue(false);
      t.setPersistent(true);
      assertEquals( true, equals(expected,t.toSBML()) );
    }

    public void test_WriteL3SBML_Trigger_persistent()
    {
      string expected =  "<trigger initialValue=\"true\" persistent=\"false\"/>";
      Trigger t = D.createModel().createEvent().createTrigger();
      t.setPersistent(false);
      t.setInitialValue(true);
      assertEquals( true, equals(expected,t.toSBML()) );
    }

    public void test_WriteL3SBML_Unit()
    {
      string expected = "<unit kind=\"kilogram\" exponent=\"0.2\"" + " scale=\"-3\" multiplier=\"3.2\"/>";
      Unit u = D.createModel().createUnitDefinition().createUnit();
      u.setKind(libsbml.UNIT_KIND_KILOGRAM);
      double exp = 0.2;
      u.setExponent(exp);
      u.setScale(-3);
      u.setMultiplier(3.2);
      assertEquals( true, equals(expected,u.toSBML()) );
    }

    public void test_WriteL3SBML_UnitDefinition()
    {
      string expected = "<unitDefinition id=\"myUnit\">\n" + 
    "  <listOfUnits>\n" + 
    "    <unit kind=\"mole\" exponent=\"1\" scale=\"0\" multiplier=\"1.8\"/>\n" + 
    "  </listOfUnits>\n" + 
    "</unitDefinition>";
      UnitDefinition ud = D.createModel().createUnitDefinition();
      ud.setId("myUnit");
      Unit u1 = ud.createUnit();
      u1.setKind(libsbml.UnitKind_forName("mole"));
      u1.setMultiplier(1.8);
      u1.setScale(0);
      u1.setExponent(1);
      assertEquals( true, equals(expected,ud.toSBML()) );
    }

    public void test_WriteL3SBML_Unit_noValues()
    {
      string expected =  "<unit/>";
      Unit u = D.createModel().createUnitDefinition().createUnit();
      assertEquals( true, equals(expected,u.toSBML()) );
    }

    public void test_WriteL3SBML_elements()
    {
      string expected = wrapSBML_L3v1("  <model>\n" + 
    "    <listOfFunctionDefinitions>\n" + 
    "      <functionDefinition/>\n" + 
    "    </listOfFunctionDefinitions>\n" + 
    "    <listOfUnitDefinitions>\n" + 
    "      <unitDefinition/>\n" + 
    "    </listOfUnitDefinitions>\n" + 
    "    <listOfCompartments>\n" + 
    "      <compartment/>\n" + 
    "    </listOfCompartments>\n" + 
    "    <listOfSpecies>\n" + 
    "      <species/>\n" +
    "    </listOfSpecies>\n" + 
    "    <listOfParameters>\n" + 
    "      <parameter/>\n" + 
    "    </listOfParameters>\n" + 
    "    <listOfInitialAssignments>\n" + 
    "      <initialAssignment/>\n" + 
    "    </listOfInitialAssignments>\n" + 
    "    <listOfRules>\n" + 
    "      <algebraicRule/>\n" + 
    "    </listOfRules>\n" + 
    "    <listOfConstraints>\n" + 
    "      <constraint/>\n" + 
    "    </listOfConstraints>\n" + 
    "    <listOfReactions>\n" + 
    "      <reaction/>\n" + 
    "    </listOfReactions>\n" + 
    "    <listOfEvents>\n" + 
    "      <event/>\n" + 
    "    </listOfEvents>\n" + 
    "  </model>\n");
      Model m = D.createModel();
      m.createUnitDefinition();
      m.createFunctionDefinition();
      m.createCompartment();
      m.createEvent();
      m.createParameter();
      m.createAlgebraicRule();
      m.createInitialAssignment();
      m.createConstraint();
      m.createReaction();
      m.createSpecies();
      S = libsbml.writeSBMLToString(D);
      assertEquals( true, equals(expected,S) );
    }

    public void test_WriteL3SBML_error()
    {
      SBMLDocument d = new SBMLDocument();
      SBMLWriter w = new SBMLWriter();
      assertEquals( false, w.writeSBML(d, "/tmp/impossible/path/should/fail") );
      assertTrue( d.getNumErrors() == 1 );
      assertTrue( d.getError(0).getErrorId() == libsbml.XMLFileUnwritable );
      d = null;
      w = null;
    }

    public void test_WriteL3SBML_locale()
    {
      string expected = "<parameter id=\"p\" value=\"3.31\"" + " constant=\"true\"/>";
      Parameter p = D.createModel().createParameter();
      p.setId("p");
      p.setValue(3.31);
      p.setConstant(true);
      assertEquals( true, equals(expected,p.toSBML()) );
    }

  }
}


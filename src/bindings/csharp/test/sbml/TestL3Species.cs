/// 
///  @file    TestL3Species.cs
///  @brief   L3 Species unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id$
///  $HeadURL$
/// 
///  This test file was converted from src/sbml/test/TestL3Species.c
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

  public class TestL3Species {
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

    private Species S;

    public bool isnan(double x)
    {
      return (x != x);
    }

    public void setUp()
    {
      S = new  Species(3,1);
      if (S == null);
      {
      }
    }

    public void tearDown()
    {
      S = null;
    }

    public void test_L3_Species_ModelHistory()
    {
      ModelHistory history = new  ModelHistory();
      long i = S.setModelHistory(history);
      assertTrue( i == libsbml.LIBSBML_INVALID_OBJECT );
      assertEquals( false, S.isSetModelHistory() );
      ModelCreator mc = new  ModelCreator();
      Date date = new  Date(2005,12,30,12,15,45,1,2,0);
      mc.setFamilyName( "Keating");
      mc.setGivenName( "Sarah");
      mc.setEmail( "sbml-team@caltech.edu");
      mc.setOrganisation( "UH");
      history.addCreator(mc);
      history.setCreatedDate(date);
      history.setModifiedDate(date);
      i = S.setModelHistory(history);
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( true, S.isSetModelHistory() );
      i = S.unsetModelHistory();
      assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
      assertEquals( false, S.isSetModelHistory() );
      assertTrue( S.getModelHistory() == null );
      history = null;
    }

    public void test_L3_Species_NS()
    {
      assertTrue( S.getNamespaces() != null );
      assertTrue( S.getNamespaces().getLength() == 1 );
      assertTrue((     "http://www.sbml.org/sbml/level3/version1/core" == S.getNamespaces().getURI(0) ));
    }

    public void test_L3_Species_boundaryCondition()
    {
      assertTrue( S.isSetBoundaryCondition() == false );
      S.setBoundaryCondition(true);
      assertTrue( S.getBoundaryCondition() == true );
      assertTrue( S.isSetBoundaryCondition() == true );
      S.setBoundaryCondition(false);
      assertTrue( S.getBoundaryCondition() == false );
      assertTrue( S.isSetBoundaryCondition() == true );
    }

    public void test_L3_Species_compartment()
    {
      string compartment =  "cell";;
      assertEquals( false, S.isSetCompartment() );
      S.setCompartment(compartment);
      assertTrue(( compartment == S.getCompartment() ));
      assertEquals( true, S.isSetCompartment() );
      if (S.getCompartment() == compartment);
      {
      }
    }

    public void test_L3_Species_constant()
    {
      assertTrue( S.isSetConstant() == false );
      S.setConstant(true);
      assertTrue( S.getConstant() == true );
      assertTrue( S.isSetConstant() == true );
      S.setConstant(false);
      assertTrue( S.getConstant() == false );
      assertTrue( S.isSetConstant() == true );
    }

    public void test_L3_Species_conversionFactor()
    {
      string units =  "volume";;
      assertEquals( false, S.isSetConversionFactor() );
      S.setConversionFactor(units);
      assertTrue(( units == S.getConversionFactor() ));
      assertEquals( true, S.isSetConversionFactor() );
      if (S.getConversionFactor() == units);
      {
      }
      S.unsetConversionFactor();
      assertEquals( false, S.isSetConversionFactor() );
      if (S.getConversionFactor() != null);
      {
      }
    }

    public void test_L3_Species_create()
    {
      assertTrue( S.getTypeCode() == libsbml.SBML_SPECIES );
      assertTrue( S.getMetaId() == "" );
      assertTrue( S.getNotes() == null );
      assertTrue( S.getAnnotation() == null );
      assertTrue( S.getId() == "" );
      assertTrue( S.getName() == "" );
      assertTrue( S.getCompartment() == "" );
      assertEquals( true, isnan(S.getInitialAmount()) );
      assertEquals( true, isnan(S.getInitialConcentration()) );
      assertTrue( S.getSubstanceUnits() == "" );
      assertTrue( S.getHasOnlySubstanceUnits() == false );
      assertTrue( S.getBoundaryCondition() == false );
      assertTrue( S.getConstant() == false );
      assertTrue( S.getConversionFactor() == "" );
      assertEquals( false, S.isSetId() );
      assertEquals( false, S.isSetName() );
      assertEquals( false, S.isSetCompartment() );
      assertEquals( false, S.isSetInitialAmount() );
      assertEquals( false, S.isSetInitialConcentration() );
      assertEquals( false, S.isSetSubstanceUnits() );
      assertEquals( false, S.isSetHasOnlySubstanceUnits() );
      assertEquals( false, S.isSetBoundaryCondition() );
      assertEquals( false, S.isSetConstant() );
      assertEquals( false, S.isSetConversionFactor() );
    }

    public void test_L3_Species_createWithNS()
    {
      XMLNamespaces xmlns = new  XMLNamespaces();
      xmlns.add( "http://www.sbml.org", "testsbml");
      SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
      sbmlns.addNamespaces(xmlns);
      Species s = new  Species(sbmlns);
      assertTrue( s.getTypeCode() == libsbml.SBML_SPECIES );
      assertTrue( s.getMetaId() == "" );
      assertTrue( s.getNotes() == null );
      assertTrue( s.getAnnotation() == null );
      assertTrue( s.getLevel() == 3 );
      assertTrue( s.getVersion() == 1 );
      assertTrue( s.getNamespaces() != null );
      assertTrue( s.getNamespaces().getLength() == 2 );
      assertTrue( s.getId() == "" );
      assertTrue( s.getName() == "" );
      assertTrue( s.getCompartment() == "" );
      assertEquals( true, isnan(s.getInitialAmount()) );
      assertEquals( true, isnan(s.getInitialConcentration()) );
      assertTrue( s.getSubstanceUnits() == "" );
      assertTrue( s.getHasOnlySubstanceUnits() == false );
      assertTrue( s.getBoundaryCondition() == false );
      assertTrue( s.getConstant() == false );
      assertTrue( s.getConversionFactor() == "" );
      assertEquals( false, s.isSetId() );
      assertEquals( false, s.isSetName() );
      assertEquals( false, s.isSetCompartment() );
      assertEquals( false, s.isSetInitialAmount() );
      assertEquals( false, s.isSetInitialConcentration() );
      assertEquals( false, s.isSetSubstanceUnits() );
      assertEquals( false, s.isSetHasOnlySubstanceUnits() );
      assertEquals( false, s.isSetBoundaryCondition() );
      assertEquals( false, s.isSetConstant() );
      assertEquals( false, s.isSetConversionFactor() );
      s = null;
    }

    public void test_L3_Species_free_NULL()
    {
    }

    public void test_L3_Species_hasOnlySubstanceUnits()
    {
      assertTrue( S.isSetHasOnlySubstanceUnits() == false );
      S.setHasOnlySubstanceUnits(true);
      assertTrue( S.getHasOnlySubstanceUnits() == true );
      assertTrue( S.isSetHasOnlySubstanceUnits() == true );
      S.setHasOnlySubstanceUnits(false);
      assertTrue( S.getHasOnlySubstanceUnits() == false );
      assertTrue( S.isSetHasOnlySubstanceUnits() == true );
    }

    public void test_L3_Species_hasRequiredAttributes()
    {
      Species s = new  Species(3,1);
      assertEquals( false, s.hasRequiredAttributes() );
      s.setId( "id");
      assertEquals( false, s.hasRequiredAttributes() );
      s.setCompartment( "cell");
      assertEquals( false, s.hasRequiredAttributes() );
      s.setHasOnlySubstanceUnits(false);
      assertEquals( false, s.hasRequiredAttributes() );
      s.setBoundaryCondition(false);
      assertEquals( false, s.hasRequiredAttributes() );
      s.setConstant(false);
      assertEquals( true, s.hasRequiredAttributes() );
      s = null;
    }

    public void test_L3_Species_id()
    {
      string id =  "mitochondria";;
      assertEquals( false, S.isSetId() );
      S.setId(id);
      assertTrue(( id == S.getId() ));
      assertEquals( true, S.isSetId() );
      if (S.getId() == id);
      {
      }
    }

    public void test_L3_Species_initialAmount()
    {
      double initialAmount = 0.2;
      assertEquals( false, S.isSetInitialAmount() );
      assertEquals( true, isnan(S.getInitialAmount()) );
      S.setInitialAmount(initialAmount);
      assertTrue( S.getInitialAmount() == initialAmount );
      assertEquals( true, S.isSetInitialAmount() );
      S.unsetInitialAmount();
      assertEquals( false, S.isSetInitialAmount() );
      assertEquals( true, isnan(S.getInitialAmount()) );
    }

    public void test_L3_Species_initialConcentration()
    {
      double initialConcentration = 0.2;
      assertEquals( false, S.isSetInitialConcentration() );
      assertEquals( true, isnan(S.getInitialConcentration()) );
      S.setInitialConcentration(initialConcentration);
      assertTrue( S.getInitialConcentration() == initialConcentration );
      assertEquals( true, S.isSetInitialConcentration() );
      S.unsetInitialConcentration();
      assertEquals( false, S.isSetInitialConcentration() );
      assertEquals( true, isnan(S.getInitialConcentration()) );
    }

    public void test_L3_Species_name()
    {
      string name =  "My_Favorite_Factory";;
      assertEquals( false, S.isSetName() );
      S.setName(name);
      assertTrue(( name == S.getName() ));
      assertEquals( true, S.isSetName() );
      if (S.getName() == name);
      {
      }
      S.unsetName();
      assertEquals( false, S.isSetName() );
      if (S.getName() != null);
      {
      }
    }

    public void test_L3_Species_substanceUnits()
    {
      string units =  "volume";;
      assertEquals( false, S.isSetSubstanceUnits() );
      S.setSubstanceUnits(units);
      assertTrue(( units == S.getSubstanceUnits() ));
      assertEquals( true, S.isSetSubstanceUnits() );
      if (S.getSubstanceUnits() == units);
      {
      }
      S.unsetSubstanceUnits();
      assertEquals( false, S.isSetSubstanceUnits() );
      if (S.getSubstanceUnits() != null);
      {
      }
    }

  }
}

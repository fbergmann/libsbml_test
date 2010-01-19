/// 
///  @file    TestL3SpeciesReference.cs
///  @brief   L3 SpeciesReference unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id$
///  $HeadURL$
/// 
///  This test file was converted from src/sbml/test/TestL3SpeciesReference.c
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

  public class TestL3SpeciesReference {
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

    private SpeciesReference SR;

    public bool isnan(double x)
    {
      return (x != x);
    }

    public void setUp()
    {
      SR = new  SpeciesReference(3,1);
      if (SR == null);
      {
      }
    }

    public void tearDown()
    {
      SR = null;
    }

    public void test_L3_SpeciesReference_NS()
    {
      assertTrue( SR.getNamespaces() != null );
      assertTrue( SR.getNamespaces().getLength() == 1 );
      assertTrue((     "http://www.sbml.org/sbml/level3/version1/core" == SR.getNamespaces().getURI(0) ));
    }

    public void test_L3_SpeciesReference_constant()
    {
      assertTrue( SR.isSetConstant() == false );
      SR.setConstant(true);
      assertTrue( SR.getConstant() == true );
      assertTrue( SR.isSetConstant() == true );
      SR.setConstant(false);
      assertTrue( SR.getConstant() == false );
      assertTrue( SR.isSetConstant() == true );
    }

    public void test_L3_SpeciesReference_create()
    {
      assertTrue( SR.getTypeCode() == libsbml.SBML_SPECIES_REFERENCE );
      assertTrue( SR.getMetaId() == "" );
      assertTrue( SR.getNotes() == null );
      assertTrue( SR.getAnnotation() == null );
      assertTrue( SR.getId() == "" );
      assertTrue( SR.getName() == "" );
      assertTrue( SR.getSpecies() == "" );
      assertEquals( true, isnan(SR.getStoichiometry()) );
      assertTrue( SR.getConstant() == false );
      assertEquals( false, SR.isSetId() );
      assertEquals( false, SR.isSetName() );
      assertEquals( false, SR.isSetSpecies() );
      assertEquals( false, SR.isSetStoichiometry() );
      assertEquals( false, SR.isSetConstant() );
    }

    public void test_L3_SpeciesReference_createWithNS()
    {
      XMLNamespaces xmlns = new  XMLNamespaces();
      xmlns.add( "http://www.sbml.org", "testsbml");
      SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
      sbmlns.addNamespaces(xmlns);
      SpeciesReference sr = new  SpeciesReference(sbmlns);
      assertTrue( sr.getTypeCode() == libsbml.SBML_SPECIES_REFERENCE );
      assertTrue( sr.getMetaId() == "" );
      assertTrue( sr.getNotes() == null );
      assertTrue( sr.getAnnotation() == null );
      assertTrue( sr.getLevel() == 3 );
      assertTrue( sr.getVersion() == 1 );
      assertTrue( sr.getNamespaces() != null );
      assertTrue( sr.getNamespaces().getLength() == 2 );
      assertTrue( sr.getId() == "" );
      assertTrue( sr.getName() == "" );
      assertTrue( sr.getSpecies() == "" );
      assertEquals( true, isnan(sr.getStoichiometry()) );
      assertTrue( sr.getConstant() == false );
      assertEquals( false, sr.isSetId() );
      assertEquals( false, sr.isSetName() );
      assertEquals( false, sr.isSetSpecies() );
      assertEquals( false, sr.isSetStoichiometry() );
      assertEquals( false, sr.isSetConstant() );
      sr = null;
    }

    public void test_L3_SpeciesReference_free_NULL()
    {
    }

    public void test_L3_SpeciesReference_hasRequiredAttributes()
    {
      SpeciesReference sr = new  SpeciesReference(3,1);
      assertEquals( false, sr.hasRequiredAttributes() );
      sr.setSpecies( "id");
      assertEquals( false, sr.hasRequiredAttributes() );
      sr.setConstant(false);
      assertEquals( true, sr.hasRequiredAttributes() );
      sr = null;
    }

    public void test_L3_SpeciesReference_id()
    {
      string id =  "mitochondria";;
      assertEquals( false, SR.isSetId() );
      SR.setId(id);
      assertTrue(( id == SR.getId() ));
      assertEquals( true, SR.isSetId() );
      if (SR.getId() == id);
      {
      }
    }

    public void test_L3_SpeciesReference_name()
    {
      string name =  "My_Favorite_Factory";;
      assertEquals( false, SR.isSetName() );
      SR.setName(name);
      assertTrue(( name == SR.getName() ));
      assertEquals( true, SR.isSetName() );
      if (SR.getName() == name);
      {
      }
      SR.unsetName();
      assertEquals( false, SR.isSetName() );
      if (SR.getName() != null);
      {
      }
    }

    public void test_L3_SpeciesReference_species()
    {
      string species =  "cell";;
      assertEquals( false, SR.isSetSpecies() );
      SR.setSpecies(species);
      assertTrue(( species == SR.getSpecies() ));
      assertEquals( true, SR.isSetSpecies() );
      if (SR.getSpecies() == species);
      {
      }
    }

    public void test_L3_SpeciesReference_stoichiometry()
    {
      double stoichiometry = 0.2;
      assertEquals( false, SR.isSetStoichiometry() );
      assertEquals( true, isnan(SR.getStoichiometry()) );
      SR.setStoichiometry(stoichiometry);
      assertTrue( SR.getStoichiometry() == stoichiometry );
      assertEquals( true, SR.isSetStoichiometry() );
      SR.unsetStoichiometry();
      assertEquals( false, SR.isSetStoichiometry() );
      assertEquals( true, isnan(SR.getStoichiometry()) );
    }

  }
}

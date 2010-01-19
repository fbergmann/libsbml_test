/// 
///  @file    TestL3Compartment.cs
///  @brief   L3 Compartment unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id$
///  $HeadURL$
/// 
///  This test file was converted from src/sbml/test/TestL3Compartment.c
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

  public class TestL3Compartment {
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

    private Compartment C;

    public bool isnan(double x)
    {
      return (x != x);
    }

    public void setUp()
    {
      C = new  Compartment(3,1);
      if (C == null);
      {
      }
    }

    public void tearDown()
    {
      C = null;
    }

    public void test_L3_Compartment_NS()
    {
      assertTrue( C.getNamespaces() != null );
      assertTrue( C.getNamespaces().getLength() == 1 );
      assertTrue((     "http://www.sbml.org/sbml/level3/version1/core" == C.getNamespaces().getURI(0) ));
    }

    public void test_L3_Compartment_constant()
    {
      assertTrue( C.isSetConstant() == false );
      C.setConstant(true);
      assertTrue( C.getConstant() == true );
      assertTrue( C.isSetConstant() == true );
      C.setConstant(false);
      assertTrue( C.getConstant() == false );
      assertTrue( C.isSetConstant() == true );
    }

    public void test_L3_Compartment_create()
    {
      assertTrue( C.getTypeCode() == libsbml.SBML_COMPARTMENT );
      assertTrue( C.getMetaId() == "" );
      assertTrue( C.getNotes() == null );
      assertTrue( C.getAnnotation() == null );
      assertTrue( C.getId() == "" );
      assertTrue( C.getName() == "" );
      assertTrue( C.getUnits() == "" );
      assertTrue( C.getOutside() == "" );
      assertEquals( true, isnan(C.getSpatialDimensionsAsDouble()) );
      assertEquals( true, isnan(C.getVolume()) );
      assertTrue( C.getConstant() == true );
      assertEquals( false, C.isSetId() );
      assertEquals( false, C.isSetSpatialDimensions() );
      assertEquals( false, C.isSetName() );
      assertEquals( false, C.isSetSize() );
      assertEquals( false, C.isSetVolume() );
      assertEquals( false, C.isSetUnits() );
      assertEquals( false, C.isSetOutside() );
      assertEquals( false, C.isSetConstant() );
    }

    public void test_L3_Compartment_createWithNS()
    {
      XMLNamespaces xmlns = new  XMLNamespaces();
      xmlns.add( "http://www.sbml.org", "testsbml");
      SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
      sbmlns.addNamespaces(xmlns);
      Compartment c = new  Compartment(sbmlns);
      assertTrue( c.getTypeCode() == libsbml.SBML_COMPARTMENT );
      assertTrue( c.getMetaId() == "" );
      assertTrue( c.getNotes() == null );
      assertTrue( c.getAnnotation() == null );
      assertTrue( c.getLevel() == 3 );
      assertTrue( c.getVersion() == 1 );
      assertTrue( c.getNamespaces() != null );
      assertTrue( c.getNamespaces().getLength() == 2 );
      assertTrue( c.getId() == "" );
      assertTrue( c.getName() == "" );
      assertTrue( c.getUnits() == "" );
      assertTrue( c.getOutside() == "" );
      assertEquals( true, isnan(c.getSpatialDimensionsAsDouble()) );
      assertEquals( true, isnan(c.getVolume()) );
      assertTrue( c.getConstant() == true );
      assertEquals( false, c.isSetId() );
      assertEquals( false, c.isSetSpatialDimensions() );
      assertEquals( false, c.isSetName() );
      assertEquals( false, c.isSetSize() );
      assertEquals( false, c.isSetVolume() );
      assertEquals( false, c.isSetUnits() );
      assertEquals( false, c.isSetOutside() );
      assertEquals( false, c.isSetConstant() );
      c = null;
    }

    public void test_L3_Compartment_free_NULL()
    {
    }

    public void test_L3_Compartment_hasRequiredAttributes()
    {
      Compartment c = new  Compartment(3,1);
      assertEquals( false, c.hasRequiredAttributes() );
      c.setId( "id");
      assertEquals( false, c.hasRequiredAttributes() );
      c.setConstant(false);
      assertEquals( true, c.hasRequiredAttributes() );
      c = null;
    }

    public void test_L3_Compartment_id()
    {
      string id =  "mitochondria";;
      assertEquals( false, C.isSetId() );
      C.setId(id);
      assertTrue(( id == C.getId() ));
      assertEquals( true, C.isSetId() );
      if (C.getId() == id);
      {
      }
    }

    public void test_L3_Compartment_name()
    {
      string name =  "My_Favorite_Factory";;
      assertEquals( false, C.isSetName() );
      C.setName(name);
      assertTrue(( name == C.getName() ));
      assertEquals( true, C.isSetName() );
      if (C.getName() == name);
      {
      }
      C.unsetName();
      assertEquals( false, C.isSetName() );
      if (C.getName() != null);
      {
      }
    }

    public void test_L3_Compartment_size()
    {
      double size = 0.2;
      assertEquals( false, C.isSetSize() );
      assertEquals( true, isnan(C.getSize()) );
      C.setSize(size);
      assertTrue( C.getSize() == size );
      assertEquals( true, C.isSetSize() );
      C.unsetSize();
      assertEquals( false, C.isSetSize() );
      assertEquals( true, isnan(C.getSize()) );
    }

    public void test_L3_Compartment_spatialDimensions()
    {
      assertEquals( false, C.isSetSpatialDimensions() );
      assertEquals( true, isnan(C.getSpatialDimensionsAsDouble()) );
      C.setSpatialDimensions(1.5);
      assertEquals( true, C.isSetSpatialDimensions() );
      assertTrue( C.getSpatialDimensionsAsDouble() == 1.5 );
      C.unsetSpatialDimensions();
      assertEquals( false, C.isSetSpatialDimensions() );
      assertEquals( true, isnan(C.getSpatialDimensionsAsDouble()) );
    }

    public void test_L3_Compartment_units()
    {
      string units =  "volume";;
      assertEquals( false, C.isSetUnits() );
      C.setUnits(units);
      assertTrue(( units == C.getUnits() ));
      assertEquals( true, C.isSetUnits() );
      if (C.getUnits() == units);
      {
      }
      C.unsetUnits();
      assertEquals( false, C.isSetUnits() );
      if (C.getUnits() != null);
      {
      }
    }

  }
}

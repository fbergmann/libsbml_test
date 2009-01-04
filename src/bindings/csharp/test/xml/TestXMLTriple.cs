/// 
///  @file    TestXMLTriple.cs
///  @brief   XMLTriple unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Michael Hucka <mhucka@caltech.edu> 
/// 
///  $Id:$
///  $HeadURL:$
/// 
///  This test file was converted from src/sbml/test/TestXMLTriple.c
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

  public class TestXMLTriple {
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


    public void test_XMLTriple_create()
    {
      XMLTriple t = new  XMLTriple();
      assertTrue( t != null );
      assertTrue( t.isEmpty() != false );
      t = null;
      t = new  XMLTriple("attr", "uri", "prefix");
      assertTrue( (  "attr" != t.getName() ) == false );
      assertTrue( (  "uri" != t.getURI() ) == false );
      assertTrue( (  "prefix" != t.getPrefix() ) == false );
      assertTrue( (  "prefix:attr" != t.getPrefixedName() ) == false );
      assertTrue( t.isEmpty() == false );
      t = null;
      t = new  XMLTriple("attr", "uri", "");
      assertTrue( (  "attr" != t.getName() ) == false );
      assertTrue( (  "uri" != t.getURI() ) == false );
      assertTrue( t.getPrefix() == "" );
      assertTrue( (  "attr" != t.getPrefixedName() ) == false );
      assertTrue( t.isEmpty() == false );
      t = null;
    }

  }
}

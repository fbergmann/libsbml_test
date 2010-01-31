/// 
///  @file    TestSBMLTransforms.cs
///  @brief   SBMLTransforms unit tests
///  @author  Frank Bergmann (Csharp conversion)
///  @author  Akiya Jouraku (Csharp conversion)
///  @author  Sarah Keating 
/// 
///  $Id$
///  $HeadURL$
/// 
///  This test file was converted from src/sbml/test/TestSBMLTransforms.cpp
///  with the help of conversion sciprt (ctest_converter.pl).
/// 
/// <!---------------------------------------------------------------------------
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
/// --------------------------------------------------------------------------->*/


namespace LibSBMLCSTest {

  using libsbml;

  using  System.IO;

  public class TestSBMLTransforms {

    private const double DBL_EPSILON =  2.2204460492503131e-016;

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

    bool equalDouble(double a, double b)
    {
      return (System.Math.Abs(a - b) < System.Math.Sqrt(DBL_EPSILON));
    }


    public void test_SBMLTransforms_evaluateAST()
    {
      double temp;
      ASTNode node = new ASTNode();
      node.setValue((2));
      assertTrue( SBMLTransforms.evaluateASTNode(node) == 2 );
      node.setValue((double) (3.2));
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),3.2) );
      node.setValue((1),(4));
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.25) );
      node.setValue((double) (4.234), (2));
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),423.4) );
      node.setType(libsbml.AST_NAME_AVOGADRO);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),6.02214179e23) );
      node.setType(libsbml.AST_NAME_TIME);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node.setType(libsbml.AST_NAME);
      assertEquals( true, isnan(SBMLTransforms.evaluateASTNode(node)) );
      node.setType(libsbml.AST_CONSTANT_E);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),System.Math.Exp(1.0)) );
      node.setType(libsbml.AST_CONSTANT_FALSE);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node.setType(libsbml.AST_CONSTANT_PI);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node), 4 * System.Math.Atan(1.0)) );
      node.setType(libsbml.AST_CONSTANT_TRUE);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("2.5 + 6.1");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),8.6) );
      node = libsbml.parseFormula("-4.3");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node), - 4.3) );
      node = libsbml.parseFormula("9.2-4.3");
      temp = 9.2 - 4.3;
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("2*3");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),6) );
      node = libsbml.parseFormula("1/5");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.2) );
      node = libsbml.parseFormula("pow(2, 3)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),8) );
      node = libsbml.parseFormula("3^3");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),27) );
      node = libsbml.parseFormula("abs(-9.456)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),9.456) );
      node = libsbml.parseFormula("ceil(9.456)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),10) );
      node = libsbml.parseFormula("exp(2.0)");
      temp = System.Math.Exp(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("floor(2.04567)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),2) );
      node = libsbml.parseFormula("ln(2.0)");
      temp = System.Math.Log(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("log10(100.0)");
      temp = System.Math.Log10(100.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("sin(2.0)");
      temp = System.Math.Sin(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("cos(4.1)");
      temp = System.Math.Cos(4.1);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("tan(0.345)");
      temp = System.Math.Tan(0.345);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arcsin(0.456)");
      temp = System.Math.Asin(0.456);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arccos(0.41)");
      temp = System.Math.Acos(0.41);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arctan(0.345)");
      temp = System.Math.Atan(0.345);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("sinh(2.0)");
      temp = System.Math.Sinh(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("cosh(4.1)");
      temp = System.Math.Cosh(4.1);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("tanh(0.345)");
      temp = System.Math.Tanh(0.345);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("and(1, 0)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("or(1, 0)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("not(1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("xor(1, 0)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("xor(1, 1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("eq(1, 2)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("eq(1, 1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("geq(2,1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("geq(2,4)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("geq(2,2)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("gt(2,1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("gt(2,4)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("leq(2,1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("leq(2,4)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("leq(2,2)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("lt(2,1)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("lt(2,4)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("neq(2,2)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),0.0) );
      node = libsbml.parseFormula("neq(3,2)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),1.0) );
      node = libsbml.parseFormula("cot(2.0)");
      temp = 1.0 / System.Math.Tan(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("csc(4.1)");
      temp = 1.0 / System.Math.Sin(4.1);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("sec(0.345)");
      temp = 1.0 / System.Math.Cos(0.345);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("coth(2.0)");
      temp = System.Math.Cosh(2.0) / System.Math.Sinh(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("sech(2.0)");
      temp = 1.0 / System.Math.Cosh(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("csch(2.0)");
      temp = 1.0 / System.Math.Sinh(2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arccot(2.0)");
      temp = System.Math.Atan(1 / 2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arccsc(2.0)");
      temp = System.Math.Asin(1 / 2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arcsec(2.0)");
      temp = System.Math.Acos(1 / 2.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arccosh(2.0)");
      temp = System.Math.Log(2.0 + System.Math.Pow(3.0,0.5));
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arccoth(2.0)");
      temp = 0.5 * System.Math.Log(3.0);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arcsech(0.2)");
      temp = System.Math.Log(2 * System.Math.Pow(6,0.5) + 5);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arccsch(0.2)");
      temp = 2.312438341272753;
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arcsinh(3.0)");
      temp = System.Math.Log(3.0 + System.Math.Pow(10.0,0.5));
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node = libsbml.parseFormula("arctanh(0.2)");
      temp = 0.5 * System.Math.Log(1.5);
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),temp) );
      node.setType(libsbml.AST_FUNCTION_DELAY);
      assertEquals( true, isnan(SBMLTransforms.evaluateASTNode(node)) );
      node = libsbml.parseFormula("factorial(3)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),6) );
      node.setType(libsbml.AST_FUNCTION_PIECEWISE);
      assertEquals( true, isnan(SBMLTransforms.evaluateASTNode(node)) );
      node = libsbml.parseFormula("root(2, 4)");
      assertEquals( true, equalDouble(SBMLTransforms.evaluateASTNode(node),2) );
    }

    public void test_SBMLTransforms_replaceFD()
    {
      SBMLReader reader = new SBMLReader();
      SBMLDocument d;
      Model m;
      ASTNode ast;
      FunctionDefinition fd;
      ListOfFunctionDefinitions lofd;
      string filename =  "../../sbml/test/test-data/";
      filename += "multiple-functions.xml";
      d = reader.readSBML(filename);
      if (d == null);
      {
      }
      m = d.getModel();
      assertTrue( m.getNumFunctionDefinitions() == 2 );
      ast = m.getReaction(2).getKineticLaw().getMath();
      assertTrue((  "f(S1, p) * compartmentOne / t" == libsbml.formulaToString(ast) ));
      fd = m.getFunctionDefinition(0);
      SBMLTransforms.replaceFD(((ASTNode) ast),fd);
      assertTrue((  "S1 * p * compartmentOne / t" == libsbml.formulaToString(ast) ));
      ast = m.getReaction(1).getKineticLaw().getMath();
      assertTrue((  "f(f(S1, p), compartmentOne) / t" == libsbml.formulaToString(ast) ));
      SBMLTransforms.replaceFD(((ASTNode) ast),fd);
      assertTrue((  "S1 * p * compartmentOne / t" == libsbml.formulaToString(ast) ));
      ast = m.getReaction(0).getKineticLaw().getMath();
      assertTrue((  "g(f(S1, p), compartmentOne) / t" == libsbml.formulaToString(ast) ));
      SBMLTransforms.replaceFD(((ASTNode) ast),fd);
      assertTrue((  "g(S1 * p, compartmentOne) / t" == libsbml.formulaToString(ast) ));
      fd = m.getFunctionDefinition(1);
      SBMLTransforms.replaceFD(((ASTNode) ast),fd);
      assertTrue((  "f(S1 * p, compartmentOne) / t" == libsbml.formulaToString(ast) ));
      ast = m.getReaction(0).getKineticLaw().getMath();
      lofd = m.getListOfFunctionDefinitions();
      SBMLTransforms.replaceFD(((ASTNode) ast),lofd);
      assertTrue((  "S1 * p * compartmentOne / t" == libsbml.formulaToString(ast) ));
      d.expandFunctionDefinitions();
      assertTrue( d.getModel().getNumFunctionDefinitions() == 0 );
      ast = d.getModel().getReaction(0).getKineticLaw().getMath();
      assertTrue((  "S1 * p * compartmentOne / t" == libsbml.formulaToString(ast) ));
      ast = d.getModel().getReaction(1).getKineticLaw().getMath();
      assertTrue((  "S1 * p * compartmentOne / t" == libsbml.formulaToString(ast) ));
      ast = d.getModel().getReaction(2).getKineticLaw().getMath();
      assertTrue((  "S1 * p * compartmentOne / t" == libsbml.formulaToString(ast) ));
    }

    public void test_SBMLTransforms_replaceIA()
    {
      SBMLReader reader = new SBMLReader();
      SBMLDocument d;
      Model m;
      ASTNode ast;
      FunctionDefinition fd;
      ListOfFunctionDefinitions lofd;
      string filename =  "../../sbml/test/test-data/";
      filename += "initialAssignments.xml";
      d = reader.readSBML(filename);
      if (d == null);
      {
      }
      m = d.getModel();
      assertTrue( m.getNumInitialAssignments() == 2 );
      assertEquals( false, (m.getCompartment(0).isSetSize()) );
      assertTrue( m.getParameter(1).getValue() == 2 );
      d.expandInitialAssignments();
      assertTrue( d.getModel().getNumInitialAssignments() == 0 );
      assertEquals( true, d.getModel().getCompartment(0).isSetSize() );
      assertTrue( d.getModel().getCompartment(0).getSize() == 25.0 );
      assertTrue( m.getParameter(1).getValue() == 50 );
    }

    public void test_SBMLTransforms_replaceIA_species()
    {
      SBMLReader reader = new SBMLReader();
      SBMLDocument d;
      Model m;
      ASTNode ast;
      FunctionDefinition fd;
      ListOfFunctionDefinitions lofd;
      string filename =  "../../sbml/test/test-data/";
      filename += "initialAssignments_species.xml";
      d = reader.readSBML(filename);
      if (d == null);
      {
      }
      m = d.getModel();
      assertTrue( m.getNumInitialAssignments() == 3 );
      assertTrue( m.getParameter(1).getValue() == 0.75 );
      assertEquals( false, (m.getParameter(2).isSetValue()) );
      assertEquals( true, m.getSpecies(2).isSetInitialAmount() );
      assertTrue( m.getSpecies(2).getInitialAmount() == 2 );
      d.expandInitialAssignments();
      assertTrue( d.getModel().getNumInitialAssignments() == 0 );
      assertTrue( m.getParameter(1).getValue() == 3 );
      assertEquals( true, m.getParameter(2).isSetValue() );
      assertTrue( m.getParameter(2).getValue() == 0.75 );
      assertEquals( false, (m.getSpecies(2).isSetInitialAmount()) );
      assertTrue( m.getSpecies(2).getInitialConcentration() == 2 );
    }

  }
}

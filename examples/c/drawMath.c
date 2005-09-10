/**
 * \file    drawMath.c
 * \brief   outputs the math of a model as a dot graph
 * \author  Sarah Keating
 *
 * $Id$
 * $Source$
 */
/* Copyright 2003 California Institute of Technology and
 * Japan Science and Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
 * documentation provided hereunder is on an "as is" basis, and the
 * California Institute of Technology and Japan Science and Technology
 * Corporation have no obligations to provide maintenance, support,
 * updates, enhancements or modifications.  In no event shall the
 * California Institute of Technology or the Japan Science and Technology
 * Corporation be liable to any party for direct, indirect, special,
 * incidental or consequential damages, including lost profits, arising
 * out of the use of this software and its documentation, even if the
 * California Institute of Technology and/or Japan Science and Technology
 * Corporation have been advised of the possibility of such damage.  See
 * the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * The original code contained here was initially developed by:
 *
 *     Sarah Keating
 *
 *     The SBML Team
 *     STRI
 *     University of Hertfordshire
 *     Hatfield, UK
 *
 *     http://sbml.org
 *     mailto:sbml-team@caltech.edu
 *
 * Contributor(s):
 */

#include "sbml/common/common.h"
#include "sbml/util/util.h"

#include "sbml/SBMLReader.h"
#include "sbml/SBMLWriter.h"
#include "sbml/SBMLTypes.h"

#include "FormulaGraphvizFormatter.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _MSC_VER
#  define isnan _isnan
#endif

static int noClusters = 0;

FILE * fout;

/**
 * @return the given formula AST as a directed graph.  The caller
 * owns the returned string and is responsible for freeing it.
 */
char *
SBML_formulaToDot (const ASTNode_t *tree)
{
  StringBuffer_t *sb = StringBuffer_create(128);
  char           *name;
  char           *s;

  if (FormulaGraphvizFormatter_isFunction(tree)
    || ASTNode_isOperator(tree)) 
  {
    FormulaGraphvizFormatter_visit(NULL, tree, sb);
  }
  else
  {
    name = FormulaGraphvizFormatter_format(tree);
    StringBuffer_append(sb, name);
  }
  
  StringBuffer_append(sb, "}\n");

  s = StringBuffer_getBuffer(sb);
  safe_free(sb);

  return s;
}


/**
 * @return true (non-zero) if the given ASTNode is to formatted as a
 * function.
 */
int
FormulaGraphvizFormatter_isFunction (const ASTNode_t *node)
{
  return
    ASTNode_isFunction  (node) ||
    ASTNode_isLambda    (node) ||
    ASTNode_isLogical   (node) ||
    ASTNode_isRelational(node);
}


/**
 * Formats the given ASTNode as a directed graph token and returns the result as
 * a string.
 */
char *
FormulaGraphvizFormatter_format (const ASTNode_t *node)
{
  StringBuffer_t *p = StringBuffer_create(128);
  char           *s;
 
  if (ASTNode_isOperator(node))
  {
    s = FormulaGraphvizFormatter_formatOperator(node);
  }
  else if (ASTNode_isFunction(node))
  {
    s = FormulaGraphvizFormatter_formatFunction(node);
  }
  else if (ASTNode_isInteger(node))
  {
    StringBuffer_appendInt(p, ASTNode_getInteger(node));
    s = StringBuffer_toString(p);
  }
  else if (ASTNode_isRational(node))
  {
    s = FormulaGraphvizFormatter_formatRational(node);
  }
  else if (ASTNode_isReal(node))
  {
    s = FormulaGraphvizFormatter_formatReal(node);
  }
  else if ( !ASTNode_isUnknown(node) )
  {
    if (ASTNode_getName(node) == NULL)
    {
      StringBuffer_append(p, "unknown");
    }
    else
    {
      StringBuffer_append(p, ASTNode_getName(node));
    }
    
    s = StringBuffer_toString(p);
  }
  
  safe_free(p);

  return s;
}


/**
 * Since graphviz will interpret identical names as referring to
 * the same node presentation-wise it is better if each function node
 * has a unique name.
 * 
 * Returns the name with the name of the first child
 * prepended
 *
 * THIS COULD BE DONE BETTER
 */
char *
FormulaGraphvizFormatter_getUniqueName (const ASTNode_t *node)
{
  StringBuffer_t *p = StringBuffer_create(128);
  char           *s;
  
  if (ASTNode_isOperator(node))
  {
    s = FormulaGraphvizFormatter_OperatorGetUniqueName(node);
  }
  else if (ASTNode_isFunction(node))
  {
    s = FormulaGraphvizFormatter_FunctionGetUniqueName(node);
  }
  else if (ASTNode_isInteger(node))
  {
    StringBuffer_appendInt(p, ASTNode_getInteger(node));
    s = StringBuffer_toString(p);
  }
  else if (ASTNode_isRational(node))
  {
    s = FormulaGraphvizFormatter_formatRational(node);
  }
  else if (ASTNode_isReal(node))
  {
    s = FormulaGraphvizFormatter_formatReal(node);
  }
  else if ( !ASTNode_isUnknown(node) )
  {
    StringBuffer_append(p, ASTNode_getName(node));
    s = StringBuffer_toString(p);
  }

  safe_free(p);

  return s;
}

/**
 * Formats the given ASTNode as a directed graph function name and returns the
 * result as a string.
 */
char *
FormulaGraphvizFormatter_formatFunction (const ASTNode_t *node)
{
  char           *s;
  StringBuffer_t *p   = StringBuffer_create(128);
  ASTNodeType_t  type = ASTNode_getType(node);

  switch (type)
  {
    case AST_FUNCTION_ARCCOS:
      s =  "acos";
      break;

    case AST_FUNCTION_ARCSIN:
      s =  "asin";
      break;

    case AST_FUNCTION_ARCTAN:
      s =  "atan";
      break;

    case AST_FUNCTION_CEILING:
      s =  "ceil";
      break;

    case AST_FUNCTION_LN:
      s =  "log";
      break;

    case AST_FUNCTION_POWER:
      s =  "pow";
      break;

    default:
      if (ASTNode_getName(node) == NULL)
      {
        StringBuffer_append(p, "unknown");
      }
      else
      {
        StringBuffer_append(p, ASTNode_getName(node));
      }
      s = StringBuffer_toString(p);
      break;
  }

  safe_free(p);

  return s;
}


/**
 * Since graphviz will interpret identical names as referring to
 * the same node presentation-wise it is better if each function node
 * has a unique name.
 * 
 * Returns the name of the function with the name of the first child
 * prepended
 *
 * THIS COULD BE DONE BETTER
 */
char *
FormulaGraphvizFormatter_FunctionGetUniqueName (const ASTNode_t *node)
{
  char           *s;
  StringBuffer_t *p   = StringBuffer_create(128);
  ASTNodeType_t  type = ASTNode_getType(node);
 
  if (ASTNode_getNumChildren(node) != 0)
  {
    StringBuffer_append(p, ASTNode_getName(ASTNode_getChild(node,0)));
  }
  else
  {
    StringBuffer_append(p, "unknown");
  }

  switch (type)
  {
    case AST_FUNCTION_ARCCOS:
      StringBuffer_append(p, "acos");
      break;

    case AST_FUNCTION_ARCSIN:
      StringBuffer_append(p, "asin");
      break;

    case AST_FUNCTION_ARCTAN:
      StringBuffer_append(p, "atan");
      break;

    case AST_FUNCTION_CEILING:
      StringBuffer_append(p, "ceil");
      break;

    case AST_FUNCTION_LN:
      StringBuffer_append(p, "log");
      break;

    case AST_FUNCTION_POWER:
      StringBuffer_append(p, "pow");
      break;

    default:
      if (ASTNode_getName(node) != NULL)
      {
        StringBuffer_append(p, ASTNode_getName(node));
      }
      break;
  }
  
  s = StringBuffer_toString(p);

  safe_free(p);

  return s;
}


/**
 * Formats the given ASTNode as a directed graph operator and returns the result
 * as a string.
 */
char *
FormulaGraphvizFormatter_formatOperator (const ASTNode_t *node)
{
  char           *s;
  ASTNodeType_t  type = ASTNode_getType(node);
  StringBuffer_t *p   = StringBuffer_create(128);

  switch (type)
  {
    case AST_TIMES:
      s =  "times";
      break;

    case AST_DIVIDE:
      s =  "divide";
      break;

    case AST_PLUS:
      s =  "plus";
      break;

    case AST_MINUS:
      s =  "minus";
      break;

    case AST_POWER:
      s =  "power";
      break;

    default:
      StringBuffer_appendChar(p, ASTNode_getCharacter(node));
      s = StringBuffer_toString(p);
      break;
  }

  safe_free(p);

  return s;
}

/**
 * Since graphviz will interpret identical names as referring to
 * the same node presentation-wise it is better if each function node
 * has a unique name.
 * 
 * Returns the name of the operator with the name of the first child
 * prepended
 *
 * THIS COULD BE DONE BETTER
 */
char *
FormulaGraphvizFormatter_OperatorGetUniqueName (const ASTNode_t *node)
{
  char           *s;
  StringBuffer_t *p   = StringBuffer_create(128);
  ASTNodeType_t  type = ASTNode_getType(node);
  
  if (FormulaGraphvizFormatter_isFunction(ASTNode_getChild(node,0))
    || ASTNode_isOperator(ASTNode_getChild(node,0))) 
  {
    StringBuffer_append(p, "func");
  }
  else
  {
    StringBuffer_append(p, ASTNode_getName(ASTNode_getChild(node,0)));
  }

  switch (type)
  {
    case AST_TIMES:
      StringBuffer_append(p,  "times");
      break;

    case AST_DIVIDE:
      StringBuffer_append(p,  "divide");
      break;

    case AST_PLUS:
      StringBuffer_append(p,  "plus");
      break;

    case AST_MINUS:
      StringBuffer_append(p,  "minus");
      break;

    case AST_POWER:
      StringBuffer_append(p,  "power");
      break;

    default:
      StringBuffer_appendChar(p, ASTNode_getCharacter(node));
      break;
  }
  
  s = StringBuffer_toString(p);

  safe_free(p);

  return s;
}


/**
 * Formats the given ASTNode as a rational number and returns the result as
 * a string.  This amounts to:
 *
 *   "(numerator/denominator)"
 */
char *
FormulaGraphvizFormatter_formatRational (const ASTNode_t *node)
{
  char           *s;
  StringBuffer_t *p = StringBuffer_create(128);

  StringBuffer_appendChar( p, '(');
  StringBuffer_appendInt ( p, ASTNode_getNumerator(node)   );
  StringBuffer_appendChar( p, '/');
  StringBuffer_appendInt ( p, ASTNode_getDenominator(node) );
  StringBuffer_appendChar( p, ')');

  s = StringBuffer_toString(p);

  safe_free(p);

  return s;
}


/**
 * Formats the given ASTNode as a real number and returns the result as
 * a string.
 */
char *
FormulaGraphvizFormatter_formatReal (const ASTNode_t *node)
{
  StringBuffer_t *p    = StringBuffer_create(128);
  double         value = ASTNode_getReal(node);
  int            sign;
  char           *s;

  if (isnan(value))
  {
    s =  "NaN";
  }
  else if ((sign = util_isInf(value)) != 0)
  {
    if (sign == -1)
    {
      s = "-INF";
    }
    else
    {
      s =  "INF";
    }
  }
  else if (util_isNegZero(value))
  {
    s =  "-0";
  }
  else
  {
    StringBuffer_appendReal(p, value);
    s = StringBuffer_toString(p);
  }

  safe_free(p);

  return s;
}


/**
 * Visits the given ASTNode node.  This function is really just a
 * dispatcher to either FormulaGraphvizFormatter_visitFunction() or
 * FormulaGraphvizFormatter_visitOther().
 */
void
FormulaGraphvizFormatter_visit ( const ASTNode_t *parent,
                         const ASTNode_t *node,
                         StringBuffer_t  *sb )
{
  if (ASTNode_isLog10(node))
  {
    FormulaGraphvizFormatter_visitLog10(parent, node, sb);
  }
  else if (ASTNode_isSqrt(node))
  {
    FormulaGraphvizFormatter_visitSqrt(parent, node, sb);
  }
  else if (FormulaGraphvizFormatter_isFunction(node))
  {
    FormulaGraphvizFormatter_visitFunction(parent, node, sb);
  }
  else if (ASTNode_isUMinus(node))
  {
    FormulaGraphvizFormatter_visitUMinus(parent, node, sb);
  }
  else
  {
    FormulaGraphvizFormatter_visitOther(parent, node, sb);
  }
}


/**
 * Visits the given ASTNode as a function.  For this node only the
 * traversal is preorder.
 * Writes the function as a directed graph and appends the result
 * to the StringBuffer.
 */
void
FormulaGraphvizFormatter_visitFunction ( const ASTNode_t *parent,
                                 const ASTNode_t *node,
                                 StringBuffer_t  *sb )
{
  unsigned int numChildren = ASTNode_getNumChildren(node);
  unsigned int n;
  char         *name;
  char         *uniqueName;
  
  uniqueName = FormulaGraphvizFormatter_getUniqueName(node);
  name       = FormulaGraphvizFormatter_format(node);
  
  StringBuffer_append(sb, uniqueName);
  StringBuffer_append(sb, " [shape=box, label=");
  StringBuffer_append(sb, name);
  StringBuffer_append(sb, "];\n");

  if (parent != NULL) 
  {
    name = FormulaGraphvizFormatter_getUniqueName(node);
    uniqueName = FormulaGraphvizFormatter_getUniqueName(parent);
    
    if(strcmp(name, uniqueName)) 
    {
      StringBuffer_append(sb, uniqueName);
      StringBuffer_append(sb, " -> ");
      StringBuffer_append(sb, name);
      StringBuffer_append(sb, ";\n");
    }
  }

  if (numChildren > 0)
  {
    FormulaGraphvizFormatter_visit( node, ASTNode_getChild(node, 0), sb );
  }

  for (n = 1; n < numChildren; n++)
  {
    FormulaGraphvizFormatter_visit( node, ASTNode_getChild(node, n), sb );
  }

}


/**
 * Visits the given ASTNode as the function "log(10, x)" and in doing so,
 * formats it as "log10(x)" (where x is any subexpression).
 * Writes the function as a directed graph and appends the result
 * to the StringBuffer.
 * 
 * A seperate function may not be strictly speaking necessary for graphs
 */
void
FormulaGraphvizFormatter_visitLog10 ( const ASTNode_t *parent,
                              const ASTNode_t *node,
                              StringBuffer_t  *sb )
{
  char *uniqueName = FormulaGraphvizFormatter_getUniqueName(node);
  char *name       = FormulaGraphvizFormatter_format(node);

  StringBuffer_append(sb, uniqueName);
  StringBuffer_append(sb, " [shape=box, label=");
  StringBuffer_append(sb, name);
  StringBuffer_append(sb, "];\n");

  FormulaGraphvizFormatter_visit(node, ASTNode_getChild(node, 1), sb);
}


/**
 * Visits the given ASTNode as the function "root(2, x)" and in doing so,
 * formats it as "sqrt(x)" (where x is any subexpression).
 * Writes the function as a directed graph and appends the result
 * to the StringBuffer.
 * 
 * A seperate function may not be strictly speaking necessary for graphs
 */
void
FormulaGraphvizFormatter_visitSqrt ( const ASTNode_t *parent,
                             const ASTNode_t *node,
                             StringBuffer_t  *sb )
{
  char *uniqueName = FormulaGraphvizFormatter_getUniqueName(node);
  char *name       = FormulaGraphvizFormatter_format(node);

  StringBuffer_append(sb, uniqueName);
  StringBuffer_append(sb, " [shape=box, label=");
  StringBuffer_append(sb, name);
  StringBuffer_append(sb, "];\n");

  FormulaGraphvizFormatter_visit(node, ASTNode_getChild(node, 1), sb);
}


/**
 * Visits the given ASTNode as a unary minus.  For this node only the
 * traversal is preorder.
 * Writes the function as a directed graph and appends the result
 * to the StringBuffer.
 */
void
FormulaGraphvizFormatter_visitUMinus ( const ASTNode_t *parent,
                               const ASTNode_t *node,
                               StringBuffer_t  *sb )
{
  char *uniqueName = FormulaGraphvizFormatter_getUniqueName(node);
  char *name       = FormulaGraphvizFormatter_format(node);

  StringBuffer_append(sb, uniqueName);
  StringBuffer_append(sb, " [shape=box, label=");
  StringBuffer_append(sb, name);
  StringBuffer_append(sb, "];\n");

  if (parent != NULL) 
  {
    uniqueName = FormulaGraphvizFormatter_getUniqueName(parent);
    name       = FormulaGraphvizFormatter_getUniqueName(node);

    if(strcmp(name, uniqueName)) 
    {
      StringBuffer_append(sb, uniqueName);
      StringBuffer_append(sb, " -> ");
      StringBuffer_append(sb, name);
      StringBuffer_append(sb, ";\n");
    }
  }
  
  FormulaGraphvizFormatter_visit ( node, ASTNode_getLeftChild(node), sb );
}


/**
 * Visits the given ASTNode and continues the inorder traversal.
 * Writes the function as a directed graph and appends the result
 * to the StringBuffer.
 */
void
FormulaGraphvizFormatter_visitOther ( const ASTNode_t *parent,
                              const ASTNode_t *node,
                              StringBuffer_t  *sb )
{
  unsigned int numChildren = ASTNode_getNumChildren(node);
  char         *name;
  char         *uniqueName;

  if (numChildren > 0)
  {
    uniqueName = FormulaGraphvizFormatter_getUniqueName(node);
    name       = FormulaGraphvizFormatter_format(node);
    
    StringBuffer_append(sb, uniqueName);
    StringBuffer_append(sb, " [shape=box, label=");
    StringBuffer_append(sb, name);
    StringBuffer_append(sb, "];\n");
    
    FormulaGraphvizFormatter_visit( node, ASTNode_getLeftChild(node), sb );
  }

  if (parent != NULL) 
  {
    name       = FormulaGraphvizFormatter_getUniqueName(node);
    uniqueName = FormulaGraphvizFormatter_getUniqueName(parent);
    
    if(strcmp(name, uniqueName)) 
    {
      StringBuffer_append(sb, uniqueName);
      StringBuffer_append(sb, " -> ");
      StringBuffer_append(sb, name);
      StringBuffer_append(sb, ";\n");
    }
  }

  if (numChildren > 1)
  {
    FormulaGraphvizFormatter_visit( node, ASTNode_getRightChild(node), sb );
  }
}


void
printFunctionDefinition (unsigned int n, const FunctionDefinition_t *fd)
{
  const ASTNode_t *math;
  char *formula;


  if ( FunctionDefinition_isSetMath(fd) )
  {
    math = FunctionDefinition_getMath(fd);

    /* Print function body. */
    if (ASTNode_getNumChildren(math) == 0)
    {
      printf("(no body defined)");
    }
    else
    {
      math    = ASTNode_getChild(math, ASTNode_getNumChildren(math) - 1);
      formula = SBML_formulaToDot(math);
      fprintf(fout, "subgraph cluster%u {\n", noClusters);
      fprintf(fout, "label=\"FunctionDefinition: %s\";\n%s\n", FunctionDefinition_getId(fd), formula);
      free(formula);
      noClusters++;
    }
  }
}


void
printRuleMath (unsigned int n, const Rule_t *r)
{
  char *formula;

  if ( Rule_isSetMath(r) )
  {
    formula = SBML_formulaToDot( Rule_getMath(r));
    fprintf(fout, "subgraph cluster%u {\n", noClusters);
    fprintf(fout, "label=\"Rule: %u\";\n%s\n", n, formula);
    free(formula);
    noClusters++;
  }
}


void
printReactionMath (unsigned int n, const Reaction_t *r)
{
  char         *formula;
  KineticLaw_t *kl;


  if (Reaction_isSetKineticLaw(r))
  {
    kl = Reaction_getKineticLaw(r);

    if ( KineticLaw_isSetMath(kl) )
    {
      formula = SBML_formulaToDot( KineticLaw_getMath(kl) );
      fprintf(fout, "subgraph cluster%u {\n", noClusters);
      fprintf(fout, "label=\"Reaction: %s\";\n%s\n", Reaction_getId(r), formula);
      free(formula);
      noClusters++;
    }
  }
}


void
printEventAssignmentMath (unsigned int n, const EventAssignment_t *ea)
{
  const char *variable;
  char       *formula;


  if ( EventAssignment_isSetMath(ea) )
  {
    variable = EventAssignment_getVariable(ea);
    formula  = SBML_formulaToDot( EventAssignment_getMath(ea) );
    fprintf(fout, "subgraph cluster%u {\n", noClusters);
    fprintf(fout, "label=\"EventAssignment: %u\";\n", n);
    fprintf(fout, "%s [shape=box];\n%s -> %s\n", variable, variable, formula);
    noClusters++;
    free(formula);
  }
}


void
printEventMath (unsigned int n, const Event_t *e)
{
  char         *formula;
  unsigned int i;


  if ( Event_isSetDelay(e) )
  {
    formula = SBML_formulaToDot( Event_getDelay(e) );
    fprintf(fout, "subgraph cluster%u {\n", noClusters);
    fprintf(fout, "label=\"Event %s delay:\";\n%s\n", Event_getId(e), formula);
    free(formula);
    noClusters++;
  }

  if ( Event_isSetTrigger(e) )
  {
    formula = SBML_formulaToDot( Event_getTrigger(e) );
    fprintf(fout, "subgraph cluster%u {\n", noClusters);
    fprintf(fout, "label=\"Event %s trigger:\";\n%s\n", Event_getId(e), formula);
    noClusters++;
    free(formula);
  }

  for (i = 0; i < Event_getNumEventAssignments(e); ++i)
  {
    printEventAssignmentMath(i + 1, Event_getEventAssignment(e, i));
  }
}


void
printMath (const Model_t *m)
{
  unsigned int  n;
  fprintf(fout, "digraph %s {\n", Model_getId(m));
  fprintf(fout, "compound=true;\n");

  for (n = 0; n < Model_getNumFunctionDefinitions(m); ++n)
  {
    printFunctionDefinition(n + 1, Model_getFunctionDefinition(m, n));
  }

  for (n = 0; n < Model_getNumRules(m); ++n)
  {
    printRuleMath(n + 1, Model_getRule(m, n));
  }

  printf("\n");

  for (n = 0; n < Model_getNumReactions(m); ++n)
  {
    printReactionMath(n + 1, Model_getReaction(m, n));
  }

  printf("\n");

  for (n = 0; n < Model_getNumEvents(m); ++n)
  {
    printEventMath(n + 1, Model_getEvent(m, n));
  }

  fprintf(fout, "}\n");
}


int
main (int argc, char *argv[])
{
  SBMLDocument_t *d;
  Model_t        *m;

  argc = 3;
  argv[1] = "C:\\libsbml\\src\\validator\\test\\test-data\\1801-pass-00-03.xml";
  argv[2] = "C:\\out.dot";
  if (argc != 3)
  {
    printf("\n  usage: drawMath <filename>\n\n");
    return 1;
  }
  
  d = readSBML(argv[1]);
  m = SBMLDocument_getModel(d);

  SBMLDocument_printWarnings(d, stdout);
  SBMLDocument_printErrors  (d, stdout);
  SBMLDocument_printFatals  (d, stdout);

  if ((fout  = fopen( argv[2], "w" )) == NULL )
  {
    printf( "The output file was not opened\n" );
  }
  else
  {
    printMath(m);
    fclose(fout);
  }

  SBMLDocument_free(d);
   
  return 0;
}

/**
 * Filename    : TestFunctionDefinition.c
 * Description : SBML FunctionDefinition unit tests
 * Author(s)   : SBML Development Group <sysbio-team@caltech.edu>
 * Organization: JST ERATO Kitano Symbiotic Systems Project
 * Created     : 2003-05-03
 * Revision    : $Id$
 * Source      : $Source$
 *
 * Copyright 2003 California Institute of Technology and
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
 *     Ben Bornstein
 *     The Systems Biology Markup Language Development Group
 *     ERATO Kitano Symbiotic Systems Project
 *     Control and Dynamical Systems, MC 107-81
 *     California Institute of Technology
 *     Pasadena, CA, 91125, USA
 *
 *     http://www.cds.caltech.edu/erato
 *     mailto:sysbio-team@caltech.edu
 *
 * Contributor(s):
 */


#include "sbml/common.h"
#include "sbml/FormulaParser.h"
#include "sbml/FunctionDefinition.h"


static FunctionDefinition_t *FD;


void
FunctionDefinitionTest_setup (void)
{
  FD = FunctionDefinition_create();

  if (FD == NULL)
  {
    fail("FunctionDefinition_create() returned a NULL pointer.");
  }
}


void
FunctionDefinitionTest_teardown (void)
{
  FunctionDefinition_free(FD);
}


START_TEST (test_FunctionDefinition_create)
{
  fail_unless( FD->typecode   == SBML_FUNCTION_DEFINITION, NULL );
  fail_unless( FD->metaid     == NULL, NULL );
  fail_unless( FD->notes      == NULL, NULL );
  fail_unless( FD->annotation == NULL, NULL );
  fail_unless( FD->id         == NULL, NULL );
  fail_unless( FD->name       == NULL, NULL );
  fail_unless( FD->math       == NULL, NULL );
}
END_TEST


START_TEST (test_FunctionDefinition_createWith)
{
  ASTNode_t            *math = SBML_parseFormula("lambda(x, x^3)");
  FunctionDefinition_t *fd   = FunctionDefinition_createWith("pow3", math);


  fail_unless( fd->typecode   == SBML_FUNCTION_DEFINITION, NULL );
  fail_unless( fd->metaid     == NULL, NULL );
  fail_unless( fd->notes      == NULL, NULL );
  fail_unless( fd->annotation == NULL, NULL );
  fail_unless( fd->name       == NULL, NULL );

  fail_unless( fd->math == math, NULL );
  fail_unless( FunctionDefinition_isSetMath(fd), NULL );

  fail_unless( !strcmp(fd->id, "pow3"), NULL );
  fail_unless( FunctionDefinition_isSetId(fd), NULL );

  FunctionDefinition_free(fd);
}
END_TEST


START_TEST (test_FunctionDefinition_free_NULL)
{
  FunctionDefinition_free(NULL);
}
END_TEST


START_TEST (test_FunctionDefinition_setId)
{
  char *id = "pow3";


  FunctionDefinition_setId(FD, id);

  fail_unless( !strcmp(FD->id, id), NULL );
  fail_unless( FunctionDefinition_isSetId(FD), NULL );

  if (FD->id == id)
  {
    fail("FunctionDefinition_setId(...) did not make a copy of string.");
  }

  /* Reflexive case (pathological) */
  FunctionDefinition_setId(FD, FD->id);
  fail_unless( !strcmp(FD->id, id), NULL );

  FunctionDefinition_setId(FD, NULL);
  fail_unless( !FunctionDefinition_isSetId(FD), NULL );

  if (FD->id != NULL)
  {
    fail("FunctionDefinition_setId(FD, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_FunctionDefinition_setName)
{
  char *name = "Cube Me";


  FunctionDefinition_setName(FD, name);

  fail_unless( !strcmp(FD->name, name), NULL );
  fail_unless( FunctionDefinition_isSetName(FD), NULL );

  if (FD->name == name)
  {
    fail("FunctionDefinition_setName(...) did not make a copy of string.");
  }

  /* Reflexive case (pathological) */
  FunctionDefinition_setName(FD, FD->name);
  fail_unless( !strcmp(FD->name, name), NULL );

  FunctionDefinition_setName(FD, NULL);
  fail_unless( !FunctionDefinition_isSetName(FD), NULL );

  if (FD->name != NULL)
  {
    fail("FunctionDefinition_setName(FD, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_FunctionDefinition_setMath)
{
  ASTNode_t *math = SBML_parseFormula("lambda(x, x^3)");


  FunctionDefinition_setMath(FD, math);

  fail_unless( FD->math == math, NULL );
  fail_unless( FunctionDefinition_isSetMath(FD), NULL );

  /* Reflexive case (pathological) */
  FunctionDefinition_setMath(FD, FD->math);
  fail_unless( FD->math == math, NULL );

  FunctionDefinition_setMath(FD, NULL);
  fail_unless( !FunctionDefinition_isSetMath(FD), NULL );

  if (FD->math != NULL)
  {
    fail("FunctionDefinition_setMath(FD, NULL) did not clear ASTNode.");
  }
}
END_TEST


Suite *
create_suite_FunctionDefinition (void)
{
  Suite *suite = suite_create("FunctionDefinition");
  TCase *tcase = tcase_create("FunctionDefinition");


  tcase_add_checked_fixture( tcase,
                             FunctionDefinitionTest_setup,
                             FunctionDefinitionTest_teardown );

  tcase_add_test( tcase, test_FunctionDefinition_create     );
  tcase_add_test( tcase, test_FunctionDefinition_createWith );
  tcase_add_test( tcase, test_FunctionDefinition_free_NULL  );
  tcase_add_test( tcase, test_FunctionDefinition_setId      );
  tcase_add_test( tcase, test_FunctionDefinition_setName    );
  tcase_add_test( tcase, test_FunctionDefinition_setMath    );

  suite_add_tcase(suite, tcase);

  return suite;
}

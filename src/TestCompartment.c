/**
 * Filename    : TestCompartment.c
 * Description : Compartment unit tests
 * Author(s)   : SBW Development Group <sysbio-team@caltech.edu>
 * Organization: Caltech ERATO Kitano Systems Biology Project
 * Created     : 2002-10-18
 * Revision    : $Id$
 * Source      : $Source$
 *
 * Copyright 2002 California Institute of Technology and
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
 *     The Systems Biology Workbench Development Group
 *     ERATO Kitano Systems Biology Project
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
#include "sbml/Compartment.h"


Compartment_t *C;


void
CompartmentTest_setup (void)
{
  C = Compartment_create();

  if (C == NULL)
  {
    fail("Compartment_create() returned a NULL pointer.");
  }
}


void
CompartmentTest_teardown (void)
{
  Compartment_free(C);
}


START_TEST (test_Compartment_create)
{
  fail_unless( C->typecode   == SBML_COMPARTMENT, NULL );
  fail_unless( C->notes      == NULL, NULL );
  fail_unless( C->annotation == NULL, NULL );

  fail_unless( C->name    == NULL, NULL );
  fail_unless( C->units   == NULL, NULL );
  fail_unless( C->outside == NULL, NULL );

  fail_unless( C->volume == 1.0, NULL );
}
END_TEST


START_TEST (test_Compartment_createWith)
{
  Compartment_t *c = Compartment_createWith("A", 3.6, "liter", "B");


  fail_unless( c->typecode   == SBML_COMPARTMENT, NULL );
  fail_unless( c->notes      == NULL, NULL );
  fail_unless( c->annotation == NULL, NULL );

  fail_unless( !strcmp( c->name   , "A"     ), NULL );
  fail_unless( !strcmp( c->units  , "liter" ), NULL );
  fail_unless( !strcmp( c->outside, "B"     ), NULL );

  fail_unless( c->volume == 3.6, NULL );

  Compartment_free(c);
}
END_TEST


START_TEST (test_Compartment_free_NULL)
{
  Compartment_free(NULL);
}
END_TEST


START_TEST (test_Compartment_setName)
{
  char *name = "mitochondria";


  Compartment_setName(C, name);

  fail_unless( !strcmp(C->name, name), NULL );

  if (C->name == name)
  {
    fail("Compartment_setName(...) did not make a copy of string.");
  }

  Compartment_setName(C, NULL);

  if (C->name != NULL)
  {
    fail("Compartment_setName(C, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_Compartment_setUnits)
{
  char *units = "volume";


  Compartment_setUnits(C, units);

  fail_unless( !strcmp(C->units, units), NULL );

  if (C->units == units)
  {
    fail("Compartment_setUnits(...) did not make a copy of string.");
  }

  Compartment_setUnits(C, NULL);

  if (C->units != NULL)
  {
    fail("Compartment_setUnits(C, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_Compartment_setOutside)
{
  char *outside = "cell";


  Compartment_setOutside(C, outside);

  fail_unless( !strcmp(C->outside, outside), NULL );

  if (C->outside == outside)
  {
    fail("Compartment_setOutside(...) did not make a copy of string.");
  }

  Compartment_setOutside(C, NULL);

  if (C->outside != NULL)
  {
    fail("Compartment_setOutside(C, NULL) did not clear string.");
  }
}
END_TEST


Suite *
create_suite_Compartment (void)
{
  Suite *suite = suite_create("Compartment");
  TCase *tcase = tcase_create("Compartment");


  tcase_add_checked_fixture( tcase,
                             CompartmentTest_setup,
                             CompartmentTest_teardown );

  tcase_add_test( tcase, test_Compartment_create     );
  tcase_add_test( tcase, test_Compartment_createWith );
  tcase_add_test( tcase, test_Compartment_free_NULL  );
  tcase_add_test( tcase, test_Compartment_setName    );
  tcase_add_test( tcase, test_Compartment_setUnits   );
  tcase_add_test( tcase, test_Compartment_setOutside );

  suite_add_tcase(suite, tcase);

  return suite;
}

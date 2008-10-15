/**
 * \file    TestReaction.c
 * \brief   SBML Reaction unit tests
 * \author  Ben Bornstein
 *
 * $Id$
 * $HeadURL$
 */
/* Copyright 2002 California Institute of Technology and
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
 *     mailto:sbml-team@caltech.edu
 *
 * Contributor(s):
 */


#include <sbml/common/common.h>
#include <sbml/SBMLTypes.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/SBMLDocument.h>

#include <check.h>


static Reaction_t *R;


void
ReactionTest_setup (void)
{
  R = Reaction_create();

  if (R == NULL)
  {
    fail("Reaction_create() returned a NULL pointer.");
  }
}


void
ReactionTest_teardown (void)
{
  Reaction_free(R);
}


START_TEST (test_Reaction_create)
{
  fail_unless( SBase_getTypeCode  ((SBase_t *) R) == SBML_REACTION );
  fail_unless( SBase_getMetaId    ((SBase_t *) R) == NULL );
  fail_unless( SBase_getNotes     ((SBase_t *) R) == NULL );
  fail_unless( SBase_getAnnotation((SBase_t *) R) == NULL );

  fail_unless( Reaction_getId        (R) == NULL );
  fail_unless( Reaction_getName      (R) == NULL );
  fail_unless( Reaction_getKineticLaw(R) == NULL );
  fail_unless( Reaction_getReversible(R) != 0    );
  fail_unless( Reaction_getFast      (R) == 0    );

  fail_unless( !Reaction_isSetId        (R) );
  fail_unless( !Reaction_isSetName      (R) );
  fail_unless( !Reaction_isSetKineticLaw(R) );

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );
}
END_TEST


START_TEST (test_Reaction_createWith)
{
  KineticLaw_t *kl = KineticLaw_create();
  Reaction_t   *r  = Reaction_createWithKineticLaw("r1", "", kl, 0, 1);


  fail_unless( SBase_getTypeCode  ((SBase_t *) r) == SBML_REACTION );
  fail_unless( SBase_getMetaId    ((SBase_t *) r) == NULL );
  fail_unless( SBase_getNotes     ((SBase_t *) r) == NULL );
  fail_unless( SBase_getAnnotation((SBase_t *) r) == NULL );

  fail_unless( Reaction_getName(r) == NULL );

  fail_unless( !strcmp(Reaction_getId(r), "r1") );

  //fail_unless( Reaction_getKineticLaw(r) == kl );
  fail_unless( Reaction_getReversible(r) ==  0 );
  fail_unless( Reaction_getFast      (r) ==  1 );

  fail_unless( Reaction_isSetId        (r) );
  fail_unless( !Reaction_isSetName     (r) );
  fail_unless( Reaction_isSetKineticLaw(r) );

  fail_unless( Reaction_getNumReactants(r) == 0 );
  fail_unless( Reaction_getNumProducts (r) == 0 );
  fail_unless( Reaction_getNumModifiers(r) == 0 );

  KineticLaw_free(kl);
  Reaction_free(r);
}
END_TEST


START_TEST (test_Reaction_free_NULL)
{
  Reaction_free(NULL);
}
END_TEST


START_TEST (test_Reaction_setId)
{
  char *id = "J1";


  Reaction_setId(R, id);

  fail_unless( !strcmp(Reaction_getId(R), id) );
  fail_unless( Reaction_isSetId(R) );

  if (Reaction_getId(R) == id)
  {
    fail("Reaction_setId(...) did not make a copy of string.");
  }

  /* Reflexive case (pathological) */
  Reaction_setId(R, Reaction_getId(R));
  fail_unless( !strcmp(Reaction_getId(R), id) );

  Reaction_setId(R, NULL);
  fail_unless( !Reaction_isSetId(R) );

  if (Reaction_getId(R) != NULL)
  {
    fail("Reaction_setId(R, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_Reaction_setName)
{
  char *name = "MapK Cascade";


  Reaction_setName(R, name);

  fail_unless( !strcmp(Reaction_getName(R), name) );
  fail_unless( Reaction_isSetName(R) );

  if (Reaction_getName(R) == name)
  {
    fail("Reaction_setName(...) did not make a copy of string.");
  }

  /* Reflexive case (pathological) */
  Reaction_setName(R, Reaction_getName(R));
  fail_unless( !strcmp(Reaction_getName(R), name) );

  Reaction_setName(R, NULL);
  fail_unless( !Reaction_isSetName(R) );

  if (Reaction_getName(R) != NULL)
  {
    fail("Reaction_setName(R, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_Reaction_addReactant)
{
  SpeciesReference_t *sr = SpeciesReference_create();
  Reaction_addReactant(R, sr);

  fail_unless( Reaction_getNumReactants(R) == 1 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );

  SpeciesReference_free(sr);
}
END_TEST


START_TEST (test_Reaction_addProduct)
{
  SpeciesReference_t *sr = SpeciesReference_create();
  Reaction_addProduct(R, sr);

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 1 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );

  SpeciesReference_free(sr);
}
END_TEST


START_TEST (test_Reaction_addModifier)
{
  Reaction_addModifier(R, SpeciesReference_createModifier());

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 1 );
}
END_TEST


START_TEST (test_Reaction_getReactant)
{
  SpeciesReference_t *sr1 = SpeciesReference_create();
  SpeciesReference_t *sr2 = SpeciesReference_create();


  SpeciesReference_setSpecies(sr1, "R1");
  SpeciesReference_setSpecies(sr2, "R2");

  Reaction_addReactant(R, sr1);
  Reaction_addReactant(R, sr2);

  SpeciesReference_free(sr1);
  SpeciesReference_free(sr2);

  fail_unless( Reaction_getNumReactants(R) == 2 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );

  sr1 = Reaction_getReactant(R, 0);
  sr2 = Reaction_getReactant(R, 1);

  fail_unless( !strcmp(SpeciesReference_getSpecies(sr1), "R1") );
  fail_unless( !strcmp(SpeciesReference_getSpecies(sr2), "R2") );


}
END_TEST


START_TEST (test_Reaction_getReactantById)
{
  SpeciesReference_t *sr1 = SpeciesReference_createWithSpeciesAndStoichiometry("R1", 1, 1);
  SpeciesReference_t *sr2 = SpeciesReference_createWithSpeciesAndStoichiometry("R2", 1, 1);


  Reaction_addReactant(R, sr1);
  Reaction_addReactant(R, sr2);

  fail_unless( Reaction_getNumReactants(R) == 2 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );

  fail_unless( Reaction_getReactantBySpecies(R, "R1") != sr1  );
  fail_unless( Reaction_getReactantBySpecies(R, "R2") != sr2  );
  fail_unless( Reaction_getReactantBySpecies(R, "R3") == NULL );

  SpeciesReference_free(sr1);
  SpeciesReference_free(sr2);
}
END_TEST


START_TEST (test_Reaction_getProduct)
{
  SpeciesReference_t *sr1 = SpeciesReference_create();
  SpeciesReference_t *sr2 = SpeciesReference_create();


  SpeciesReference_setSpecies(sr1, "P1");
  SpeciesReference_setSpecies(sr2, "P2");

  Reaction_addProduct(R, sr1);
  Reaction_addProduct(R, sr2);

  SpeciesReference_free(sr1);
  SpeciesReference_free(sr2);

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 2 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );

  sr1 = Reaction_getProduct(R, 0);
  sr2 = Reaction_getProduct(R, 1);

  fail_unless( !strcmp(SpeciesReference_getSpecies(sr1), "P1") );
  fail_unless( !strcmp(SpeciesReference_getSpecies(sr2), "P2") );

}
END_TEST


START_TEST (test_Reaction_getProductById)
{
  SpeciesReference_t *sr1 = SpeciesReference_createWithSpeciesAndStoichiometry("P1", 1, 1);
  SpeciesReference_t *sr2 = SpeciesReference_createWithSpeciesAndStoichiometry("P2", 1, 1);


  Reaction_addProduct(R, sr1);
  Reaction_addProduct(R, sr2);

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 2 );
  fail_unless( Reaction_getNumModifiers(R) == 0 );

  fail_unless( Reaction_getProductBySpecies(R, "P1") != sr1  );
  fail_unless( Reaction_getProductBySpecies(R, "P2") != sr2  );
  fail_unless( Reaction_getProductBySpecies(R, "P3") == NULL );

  SpeciesReference_free(sr1);
  SpeciesReference_free(sr2);
}
END_TEST


START_TEST (test_Reaction_getModifier)
{
  SpeciesReference_t *msr1 = SpeciesReference_createModifier();
  SpeciesReference_t *msr2 = SpeciesReference_createModifier();


  SpeciesReference_setSpecies(msr1, "M1");
  SpeciesReference_setSpecies(msr2, "M2");

  Reaction_addModifier(R, msr1);
  Reaction_addModifier(R, msr2);

  SpeciesReference_free(msr1);
  SpeciesReference_free(msr2);

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 2 );

  msr1 = Reaction_getModifier(R, 0);
  msr2 = Reaction_getModifier(R, 1);

  fail_unless(!strcmp(SpeciesReference_getSpecies(msr1), "M1"));
  fail_unless(!strcmp(SpeciesReference_getSpecies(msr2), "M2"));
}
END_TEST


START_TEST (test_Reaction_getModifierById)
{
  SpeciesReference_t *msr1 = SpeciesReference_createModifier();
  SpeciesReference_t *msr2 = SpeciesReference_createModifier();


  SpeciesReference_setSpecies(msr1, "M1");
  SpeciesReference_setSpecies(msr2, "M2");


  Reaction_addModifier(R, msr1);
  Reaction_addModifier(R, msr2);

  fail_unless( Reaction_getNumReactants(R) == 0 );
  fail_unless( Reaction_getNumProducts (R) == 0 );
  fail_unless( Reaction_getNumModifiers(R) == 2 );

  fail_unless( Reaction_getModifierBySpecies(R, "M1") != msr1 );
  fail_unless( Reaction_getModifierBySpecies(R, "M2") != msr2 );
  fail_unless( Reaction_getModifierBySpecies(R, "M3") == NULL );
  
  SpeciesReference_free(msr1);
  SpeciesReference_free(msr2);
}
END_TEST


START_TEST (test_Reaction_createWithLevelVersionAndNamespace)
{
  XMLNamespaces_t *xmlns = XMLNamespaces_create();
  XMLNamespaces_add(xmlns, "http://www.sbml.org", "sbml");

  Reaction_t *object = 
    Reaction_createWithLevelVersionAndNamespaces(2, 1, xmlns);


  fail_unless( SBase_getTypeCode  ((SBase_t *) object) == SBML_REACTION );
  fail_unless( SBase_getMetaId    ((SBase_t *) object) == NULL );
  fail_unless( SBase_getNotes     ((SBase_t *) object) == NULL );
  fail_unless( SBase_getAnnotation((SBase_t *) object) == NULL );

  fail_unless( SBase_getLevel       ((SBase_t *) object) == 2 );
  fail_unless( SBase_getVersion     ((SBase_t *) object) == 1 );

  fail_unless( Reaction_getNamespaces     (object) != NULL );
  fail_unless( XMLNamespaces_getLength(Reaction_getNamespaces(object)) == 1 );

  Reaction_free(object);
}
END_TEST


START_TEST (test_Reaction_createWithDocument)
{
  SBMLDocument_t *d = SBMLDocument_createWithLevelAndVersion(2, 3);

  Reaction_t *object = 
    Reaction_createWithDocument(d);


  fail_unless( SBase_getTypeCode  ((SBase_t *) object) == SBML_REACTION );
  fail_unless( SBase_getMetaId    ((SBase_t *) object) == NULL );
  fail_unless( SBase_getNotes     ((SBase_t *) object) == NULL );
  fail_unless( SBase_getAnnotation((SBase_t *) object) == NULL );

  fail_unless( SBase_getLevel       ((SBase_t *) object) == 2 );
  fail_unless( SBase_getVersion     ((SBase_t *) object) == 3 );
  fail_unless( SBase_getSBMLDocument((SBase_t *) object) != NULL);

  Reaction_free(object);
}
END_TEST


Suite *
create_suite_Reaction (void)
{
  Suite *suite = suite_create("Reaction");
  TCase *tcase = tcase_create("Reaction");


  tcase_add_checked_fixture(tcase, ReactionTest_setup, ReactionTest_teardown);

  tcase_add_test( tcase, test_Reaction_create          );
  tcase_add_test( tcase, test_Reaction_createWith      );
  tcase_add_test( tcase, test_Reaction_free_NULL       );
  tcase_add_test( tcase, test_Reaction_setId           );
  tcase_add_test( tcase, test_Reaction_setName         );
  tcase_add_test( tcase, test_Reaction_addReactant     );
  tcase_add_test( tcase, test_Reaction_addProduct      );
  tcase_add_test( tcase, test_Reaction_addModifier     );
  tcase_add_test( tcase, test_Reaction_getReactant     );
  tcase_add_test( tcase, test_Reaction_getReactantById );
  tcase_add_test( tcase, test_Reaction_getProduct      );
  tcase_add_test( tcase, test_Reaction_getProductById  );
  tcase_add_test( tcase, test_Reaction_getModifier     );
  tcase_add_test( tcase, test_Reaction_getModifierById );
  tcase_add_test( tcase, test_Reaction_createWithLevelVersionAndNamespace        );
  tcase_add_test( tcase, test_Reaction_createWithDocument  );

  suite_add_tcase(suite, tcase);

  return suite;
}

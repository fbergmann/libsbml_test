/**
 * Filename    : ValidationRules.c
 * Description : The default set of rules for validating an SBML document
 * Author(s)   : SBML Development Group <sysbio-team@caltech.edu>
 * Organization: JST ERATO Kitano Symbiotic Systems Project
 * Created     : 2004-03-25
 * Revision    : $Id$
 * Source      : $Source$
 *
 * Copyright 2004 California Institute of Technology and
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
#include "sbml/Validator.h"
#include "sbml/Model.h"
#include "sbml/UnitKind.h"


/**
 * This convenience macro is a quick and easy way to declare a new
 * validation rule.
 */
#define RULE(name) \
  static           \
  unsigned int     \
  name (const SBase_t *obj, const SBMLDocument_t *d, List_t *messages)


/**
 * This convenience macro, when coupled with the RULE macro, makes it easy
 * to log a validation error message.
 */
#define LOG_MESSAGE(msg)                                           \
  if (messages != NULL)                                            \
  {                                                                \
    unsigned int line = SBase_getLine(obj);                        \
    unsigned int col  = SBase_getColumn(obj);                      \
    List_add( messages, ParseMessage_createWith(msg, line, col) ); \
  }


typedef struct {
  int passed;
  const char *msg;
} RuleResult_t;


/******************** utility subroutines begin here ********************/

static
void
initializeRuleResult(RuleResult_t *result)
{
  result->passed = 1;
  result->msg = NULL;
}

typedef int (*PFI)();


static
int
isMeter(UnitKind_t uk)
{
  return uk == UNIT_KIND_METRE || uk == UNIT_KIND_METER;
}


static
int
isLiter(UnitKind_t uk)
{
  return uk == UNIT_KIND_LITRE || uk == UNIT_KIND_LITER;
}


static
int
isSubstanceKind(UnitKind_t uk)
{
  return uk == UNIT_KIND_MOLE || uk == UNIT_KIND_ITEM;
}


static
int
isSecond(UnitKind_t uk)
{
  return uk == UNIT_KIND_SECOND;
}


static
unsigned int
_hasSingleKind(UnitDefinition_t *ud)
{
  ListOf_t *kinds = UnitDefinition_getListOfUnits(ud);
  return ListOf_getNumItems(kinds) == 1;
}


static
unsigned int
_hasExponent(UnitDefinition_t *ud, int requiredExponent)
{
  ListOf_t *kinds = UnitDefinition_getListOfUnits(ud);
  Unit_t *u = (Unit_t *) ListOf_get(kinds, 0);

  return requiredExponent == Unit_getExponent(u);
}


static
unsigned int
isOneOfTheseKinds(UnitDefinition_t *ud, const PFI *kindTests)
{
  ListOf_t *kinds = UnitDefinition_getListOfUnits(ud);
  Unit_t *u = (Unit_t *) ListOf_get(kinds, 0);
  UnitKind_t unitKind = Unit_getKind(u);
  const PFI *kindTest;

  for (kindTest = kindTests; *kindTest; kindTest++)
  {
    if ((*kindTest)(unitKind))
    {
      return 1;
    }
  }

  return 0;
}


static
unsigned int
isKindOfLength(const char *unitsName)
{
  return
    unitsName != NULL
    &&
    (
      streq(unitsName, "length")
      ||
      streq(unitsName, "meter")
      ||
      streq(unitsName, "metre")
    );
}


static
unsigned int
isKindOfArea(const char *unitsName)
{
  return
    unitsName != NULL
    &&
    streq(unitsName, "area");
}


static
unsigned int
isKindOfVolume(const char *unitsName)
{
  return
    unitsName != NULL
    && (
      streq(unitsName, "volume")
      ||
      streq(unitsName, "litre")
      ||
      streq(unitsName, "liter")
    );
}


static
unsigned int
isKindOfSubstance(const char *unitsName)
{
  return
    unitsName != NULL
    && (
      streq(unitsName, "substance")
      ||
      streq(unitsName, "item")
      ||
      streq(unitsName, "mole")
    );
}


static
unsigned int
unitDefinitionIsVariantOf(
  UnitDefinition_t *ud,
  PFI isKindPFI,
  int requiredExponent)
{
  PFI acceptableKinds[] = { NULL, NULL };


  if (ud == NULL)
    return 0;

  acceptableKinds[0] = isKindPFI;
  return
    _hasSingleKind(ud)
    &&
    isOneOfTheseKinds(ud, acceptableKinds)
    &&
    _hasExponent(ud, requiredExponent);
}


static
unsigned int
isCubicMeters(UnitDefinition_t *ud)
{
  return unitDefinitionIsVariantOf(ud, isMeter, 3);
}


static
unsigned int
isLiters(UnitDefinition_t *ud)
{
  return unitDefinitionIsVariantOf(ud, isLiter, 1);
}


static
unsigned int
unitDefinitionIsKindOfLength(
  const Model_t *m,
  const char *spatialSizeUnits)
{
  UnitDefinition_t *ud = Model_getUnitDefinitionById(m, spatialSizeUnits);


  return unitDefinitionIsVariantOf(ud, isMeter, 1);
}
  

static
unsigned int
unitDefinitionIsKindOfArea(
  const Model_t *m,
  const char *spatialSizeUnits)
{
  UnitDefinition_t *ud = Model_getUnitDefinitionById(m, spatialSizeUnits);


  return unitDefinitionIsVariantOf(ud, isMeter, 2);
}



static
unsigned int
unitDefinitionIsKindOfVolume(
  const Model_t *m,
  const char *spatialSizeUnits)
{
  static const PFI literKinds[] = { isLiter, NULL };

  UnitDefinition_t *ud = Model_getUnitDefinitionById(m, spatialSizeUnits);


  return isCubicMeters(ud) || isLiters(ud);
}


/* TODO: move this to Model_t? */
static
BOOLEAN
speciesExists(Model_t *m, const char *speciesName)
{
  return Model_getSpeciesById(m, speciesName) != NULL;
}


static
void
hasSingleKind(RuleResult_t *result, UnitDefinition_t *ud)
{
  ListOf_t *kinds;
  if (!result->passed) return;

  kinds = UnitDefinition_getListOfUnits(ud);
  if (ListOf_getNumItems(kinds) != 1)
  {
    result->passed = 0;
    result->msg = "must have exactly one unit kind.";
  }
}


static
void
hasAcceptableKinds(
  RuleResult_t *result,
  UnitDefinition_t *ud,
  PFI *acceptableKinds,
  const char *acceptableKindsMsg)
{
  if (!result->passed) return;

  {
    if (!isOneOfTheseKinds(ud, acceptableKinds))
    {
      result->passed = 0;
      result->msg = acceptableKindsMsg;
      return;
    }
  }
}


static
void
hasExponent(RuleResult_t *result, UnitDefinition_t *ud, int requiredExponent)
{
  if (!result->passed) return;

  {
    ListOf_t *kinds = UnitDefinition_getListOfUnits(ud);
    Unit_t *u = (Unit_t *) ListOf_get(kinds, 0);

    int exponent = Unit_getExponent(u);
    if (exponent != requiredExponent)
    {
      char buf[256];

      sprintf(buf, "must have exponent %d.");
      result->passed = 0;
      result->msg = safe_strdup(buf);
    }
  }
}


static
BOOLEAN
isOneDimensional(const Model_t *m, const char *spatialSizeUnits)
{
  return
    isKindOfLength(spatialSizeUnits)
    ||
    unitDefinitionIsKindOfLength(m, spatialSizeUnits);
}


static
BOOLEAN
isTwoDimensional(const Model_t *m, const char *spatialSizeUnits)
{
  return 
    isKindOfArea(spatialSizeUnits)
    ||
    unitDefinitionIsKindOfArea(m, spatialSizeUnits);
}


static
BOOLEAN
isThreeDimensional(const Model_t *m, const char *spatialSizeUnits)
{
  return
    isKindOfVolume(spatialSizeUnits)
    ||
    unitDefinitionIsKindOfVolume(m, spatialSizeUnits);
}


/*
 * Caller owns result.
 */
/* TODO: move this to Reaction_t. */
static
List_t *
allSpeciesReferenceIdsIn(Reaction_t *r)
{
  List_t *result = List_create();
  unsigned int j;

  { /* collect reactant species */
    int numReactants = Reaction_getNumReactants(r);
    for (j = 0; j < numReactants; j++)
    {
      SpeciesReference_t *sr = Reaction_getReactant(r, j);
      List_add(result, SpeciesReference_getSpecies(sr));
    }
  }

  { /* collect product species */
    int numProducts = Reaction_getNumProducts(r);
    for (j = 0; j < numProducts; j++)
    {
      SpeciesReference_t *sr = Reaction_getProduct(r, j);
      List_add(result, SpeciesReference_getSpecies(sr));
    }
  }


  { /* collect modifier species */
    int numModifiers = Reaction_getNumModifiers(r);
    for (j = 0; j < numModifiers; j++)
    {
      ModifierSpeciesReference_t *msr = Reaction_getModifier(r, j);
      List_add(result, ModifierSpeciesReference_getSpecies(msr));
    }
  }

  return result;
}


static
BOOLEAN
anySpeciesReferenceIsTo(const Model_t *m, const char *speciesId)
{
  unsigned int result = FALSE;
  int numReactions = Model_getNumReactions(m);
  int i, j;


  for (i = 0; i < numReactions; i++)
  {
    Reaction_t *r = Model_getReaction(m, i);

    List_t *speciesReferenceIds = allSpeciesReferenceIdsIn(r);
    unsigned int numReferences = List_size(speciesReferenceIds);
    unsigned int j;

    for (j = 0; j < numReferences; j++)
    {
      const char *referenceId = (const char *)List_get(speciesReferenceIds, j);

      if (streq(speciesId, referenceId))
      {
        result = TRUE;
        break;
      }
    }

    List_free(speciesReferenceIds);

    if (result)
      break;
  }

  return result;
}


static
BOOLEAN
anyRuleVariableIs(const Model_t *m, const char *variableName)
{
  int numRules = Model_getNumRules(m);
  int i;


  for (i = 0; i < numRules; i++)
  {
    Rule_t *rule = Model_getRule(m, i);
    AssignmentRule_t *ar = (AssignmentRule_t *) rule;
    RateRule_t *rr = (RateRule_t *) rule;

    switch (rule->typecode)
    {
    case SBML_ASSIGNMENT_RULE:
      if (streq(AssignmentRule_getVariable(ar), variableName))
      {
        return TRUE;
      }
      break;

    case SBML_RATE_RULE:
      if (streq(RateRule_getVariable(rr), variableName))
      {
        return TRUE;
      }
      break;

    default:
      break;
    }
  }

  return FALSE;
}


/* TODO: what class does this function belong under? */
static
BOOLEAN
isBuiltInUnit(const char *unit)
{
  const char *builtInUnits[] = {
    "substance",
    "volume",
    "area",
    "length",
    "time",
    NULL
  };
  const char **p;

  for (p = builtInUnits; *p; p++)
  {
    if (streq(unit, *p))
    {
      return TRUE;
    }
  }

  return FALSE;
}


static
void
logFullMessage(
  const char *baseMsg,
  RuleResult_t *result,
  const SBase_t *obj,
  List_t *messages)
{
    char *message = safe_strcat(baseMsg, result->msg);
    LOG_MESSAGE(message);
    safe_free(message);
}


/*************************** RULEs begin here *****************************/


RULE (compartment_spatialDimensions1)
{
  static const char msg[] =
    "A compartment with spatialDimensions=1 must have units of 'length', "
    "'metre', or the id of a unitDefinition that defines a variant of "
    "'metre' with exponent=1.";

  Compartment_t *c = (Compartment_t *) obj;
  unsigned int passed = TRUE;


  if (Compartment_getSpatialDimensions(c) == 1)
  {
    const char *units = Compartment_getUnits(c);
    if (units && !isOneDimensional(d->model, units))
    {
      LOG_MESSAGE(msg);
      passed = FALSE;
    }
  }

  return passed;
}


RULE (compartment_spatialDimensions2)
{
  static const char msg[] =
    "A compartment with spatialDimensions=2 must have units of 'area' "
    "or the id of a unitDefinition that defines a variant of 'metre' "
    "with exponent=2.";

  Compartment_t *c = (Compartment_t *) obj;
  unsigned int passed = TRUE;


  if (Compartment_getSpatialDimensions(c) == 2)
  {
    const char *units = Compartment_getUnits(c);
    if (units && !isTwoDimensional(d->model, units))
    {
      LOG_MESSAGE(msg);
      passed = FALSE;
    }
  }

  return passed;
}


RULE (compartment_spatialDimensions3)
{
  static const char msg[] =
    "A compartment with spatialDimensions=3 must have units of 'volume', "
    "'litre', or the id of a unitDefinition that defines a variant of "
    "'metre' with exponent=3.";

  Compartment_t *c = (Compartment_t *) obj;
  unsigned int passed = TRUE;


  if (Compartment_getSpatialDimensions(c) == 3)
  {
    const char *units = Compartment_getUnits(c);
    if (units && !isThreeDimensional(d->model, units))
    {
      LOG_MESSAGE(msg);
      passed = FALSE;
    }
  }

  return passed;
}


RULE (compartment_spatialDimensions0)
{
  static const char msg[] =
    "A compartment with spatialDimensions=0 must have units of "
    "'dimensionless'.";

  Compartment_t *c = (Compartment_t *) obj;
  unsigned int passed = TRUE;


  if (Compartment_getSpatialDimensions(c) == 0)
  {
    const char *units = Compartment_getUnits(c);
    if (units && !streq(units, "dimensionless"))
    {
      LOG_MESSAGE(msg);
      passed = FALSE;
    }
  }

  return passed;
}


/**
 * The size attribute must not be set if spatialDimensions is zero.
 */
RULE (compartment_size_dimensions)
{
  unsigned int passed = 1;
  Compartment_t *c = (Compartment_t *) obj;

  static const char msg[] =
    "Compartment size must not be set if spatialDimensions is zero.";


  if (Compartment_getSpatialDimensions(c) == 0)
  {
    if (Compartment_isSetSize(c))
    {
      passed = 0;
      LOG_MESSAGE(msg);
    }
  }

  return passed;
}


/**
 * The value of the outside attribute of a compartment element must contain
 * the value of a id field of another compartment.
 */
RULE (compartment_outsideIsDefined)
{
  static const char msg[] =
    "A compartment's 'outside' must be the id of another compartment.";

  unsigned int passed = TRUE;

  Compartment_t *c = (Compartment_t *) obj;
  const char *outside = Compartment_getOutside(c);


  if (outside && Model_getCompartmentById(d->model, outside) == NULL)
  {
    LOG_MESSAGE(msg);
    passed = FALSE;
  }

  return passed;
}


/**
 * The graph of links between compartments implied by the outside attributes
 * must not be cyclic.
 */
RULE (compartment_outsideCyclic)
{
  unsigned int passed = TRUE;

  Compartment_t *c = (Compartment_t *) obj;
  const char *startCompartment = Compartment_getId(c);
  List_t *chain = List_create();


  for ( ; ; )
  {
    const char *outside = Compartment_getOutside(c);

    if (!outside)
    {
      break;
    }

    if (streq(startCompartment, outside)) /* if found a cycle */
    {
      char buf[512];

      sprintf(buf, "Compartment '%s' encloses itself", startCompartment);

      if (List_size(chain) == 0)
      {
        strcat(buf, ".");
      }
      else
      {
        int numInChain = List_size(chain);
        int i;
        BOOLEAN firstTime = TRUE;

        for (i = 0; i < numInChain; i++)
        {
          const char *name = (const char *) List_get(chain, i);

          if (streq(startCompartment, name))
          {
            break;
          }

          if (firstTime)
          {
            strcat(buf, " via ");
          }
          else
          {
            strcat(buf, ", ");
          }

          strcat(buf, "'");
          strcat(buf, name);
          strcat(buf, "'");

          firstTime = FALSE;
        }

        strcat(buf, ".");
      }

      LOG_MESSAGE(buf);
      passed = FALSE;
      break;
    }

    List_add(chain, (void *) outside);

    c = Model_getCompartmentById(d->model, outside);
    if (!c)
    {
      break;
    }
  }

  List_free(chain);
  return passed;
}


RULE (kineticLaw_substanceUnits)
{
  const char *units;

  Reaction_t   *r      = (Reaction_t *) obj;
  KineticLaw_t *kl     = Reaction_getKineticLaw(r);
  unsigned int  passed = 1;

  const char *msg =
    "substanceUnits must be 'substance', 'items', or 'mole' or the "
    "values of id attributes of unitDefinition elements that define "
    "variants (i.e. have only arbitrary scale, multiplier and "
    "offset values) of 'items' or 'mole'.";


  if (kl != NULL)
  {
    units = KineticLaw_getSubstanceUnits(kl);

    if (units != NULL)
    {
      if (! ( !strcmp(units, "substance") ||
              !strcmp(units, "item")     ||
              !strcmp(units, "mole") ) )
      {
        passed = 0;
        LOG_MESSAGE(msg);
      }
    }
  }

  return passed;
}


RULE (unitDefinition_idsMustBeUnique)
{
  static const char msg[] =
    "No two unitDefinitions may have the same id.";

  unsigned int passed = 1;

  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  const char *id = UnitDefinition_getId(ud);

  UnitDefinition_t *got = Model_getUnitDefinitionById(d->model, id);


  if (got != ud)
  {
    passed = 0;
    LOG_MESSAGE(msg);
  }

  return passed;
}


RULE (unitDefinition_idCantBePredefinedUnit)
{
  static const char msg[] =
    "The id of a unitDefinition must not be a predefined kind of unit.";

  unsigned int passed = 1;

  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  const char *id = UnitDefinition_getId(ud);


  if (UnitKind_isValidUnitKindString(id))
  {
    passed = 0;
    LOG_MESSAGE(msg);
  }

  return passed;
}


RULE (unitDefinition_volumeKinds)
{
  RuleResult_t result;
  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  PFI acceptableKinds[] = { isMeter, isLiter, NULL };
  PFI kindsThatNeedExponent3[] = { isMeter, NULL };
  static const char baseMsg[] = "A 'volume' unitDefinition ";
  static const char acceptableKindsMsg[] =
    "may only have units of kind 'liter' or 'metre'.";


  initializeRuleResult(&result);

  if (!strcmp("volume", UnitDefinition_getId(ud)))
  {
    hasSingleKind(&result, ud);
    hasAcceptableKinds(&result, ud, acceptableKinds, acceptableKindsMsg);
    if (isOneOfTheseKinds(ud, kindsThatNeedExponent3))
    {
      hasExponent(&result, ud, 3);
    }
  }

  if (!result.passed)
  {
    logFullMessage(baseMsg, &result, obj, messages);
  }
  return result.passed;
}


RULE (unitDefinition_substanceKinds)
{
  RuleResult_t result;
  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  PFI acceptableKinds[] = { isSubstanceKind, NULL };
  static const char baseMsg[] = "A 'substance' unitDefinition ";
  static const char acceptableKindsMsg[] =
    "may only have units of kind 'mole' or 'item'.";


  initializeRuleResult(&result);

  if (!strcmp("substance", UnitDefinition_getId(ud)))
  {
    hasSingleKind(&result, ud);
    hasAcceptableKinds(&result, ud, acceptableKinds, acceptableKindsMsg);
    hasExponent(&result, ud, 1);
  }

  if (!result.passed)
  {
    logFullMessage(baseMsg, &result, obj, messages);
  }
  return result.passed;
}


RULE (unitDefinition_areaKinds)
{
  RuleResult_t result;
  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  PFI acceptableKinds[] = { isMeter, NULL };
  static const char baseMsg[] = "An 'area' unitDefinition ";
  static const char acceptableKindsMsg[] =
    "may only have units of kind 'metre'.";


  initializeRuleResult(&result);

  if (!strcmp("area", UnitDefinition_getId(ud)))
  {
    hasSingleKind(&result, ud);
    hasAcceptableKinds(&result, ud, acceptableKinds, acceptableKindsMsg);
    hasExponent(&result, ud, 2);
  }

  if (!result.passed)
  {
    logFullMessage(baseMsg, &result, obj, messages);
  }
  return result.passed;
}


RULE (unitDefinition_lengthKinds)
{
  RuleResult_t result;
  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  PFI acceptableKinds[] = { isMeter, NULL };
  static const char baseMsg[] = "A 'length' unitDefinition ";
  static const char acceptableKindsMsg[] =
    "may only have units of kind 'metre'.";


  initializeRuleResult(&result);

  if (!strcmp("length", UnitDefinition_getId(ud)))
  {
    hasSingleKind(&result, ud);
    hasAcceptableKinds(&result, ud, acceptableKinds, acceptableKindsMsg);
    hasExponent(&result, ud, 1);
  }

  if (!result.passed)
  {
    logFullMessage(baseMsg, &result, obj, messages);
  }
  return result.passed;
}


RULE (unitDefinition_timeKinds)
{
  RuleResult_t result;
  UnitDefinition_t *ud = (UnitDefinition_t *) obj;
  PFI acceptableKinds[] = { isSecond, NULL };
  static const char baseMsg[] = "A 'time' unitDefinition ";
  static const char acceptableKindsMsg[] =
    "may only have units of kind 'second'.";


  initializeRuleResult(&result);

  if (!strcmp("time", UnitDefinition_getId(ud)))
  {
    hasSingleKind(&result, ud);
    hasAcceptableKinds(&result, ud, acceptableKinds, acceptableKindsMsg);
    hasExponent(&result, ud, 1);
  }

  if (!result.passed)
  {
    logFullMessage(baseMsg, &result, obj, messages);
  }
  return result.passed;
}


/**
 * The compartment attribute on a species element must contain the value of an
 * id attribute on a compartment element. 
 */
RULE (species_compartmentIsDefined)
{
  static const char msg[] =
    "Compartment '%s' is undefined.";

  const char* compartmentId;
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  compartmentId = Species_getCompartment(s);
  if (compartmentId
      &&
      Model_getCompartmentById(d->model, compartmentId) == NULL
  ) {
    char buf[512];

    sprintf(buf, msg, compartmentId);
    LOG_MESSAGE(buf);
    passed = 0;
  }

  return passed;
}

/**
 * The spatialSizeUnits attribute must not be present if the
 * hasOnlySubstanceUnits attribute is true.
 */
RULE (species_hasOnlySubstanceUnits)
{
  static const char msg[] =
    "A species with hasOnlySubstanceUnits=true must not have spatialSizeUnits.";
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  if (Species_getHasOnlySubstanceUnits(s))
  {
    if (Species_isSetSpatialSizeUnits(s))
    {
      LOG_MESSAGE(msg);
      passed = 0;
    }
  }

  return passed;
}

/**
 * The spatialSizeUnits attribute must not be present if the spatial
 * dimensions is zero.
 */
RULE (species_zeroSpatialDimensions)
{
  static const char msg[] =
    "A species must not have spatialSizeUnits if its compartment has "
    "spatialDimensions=0.";
  const char *compartmentId;
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  compartmentId = Species_getCompartment(s);
  if (compartmentId)
  {
    Compartment_t *c = Model_getCompartmentById(d->model, compartmentId);
    if (
      c
      &&
      Compartment_getSpatialDimensions(c) == 0
      &&
      Species_isSetSpatialSizeUnits(s)
    ) {
      LOG_MESSAGE(msg);
      passed = 0;
    }
  }

  return passed;
}

/**
 * spatialSizeUnits for spatialDimensions of 1.
 */
RULE (species_spatialDimensions1)
{
  static const char msg[] =
    "A species whose compartment has spatialDimensions=1 must have "
    "spatialSizeUnits of 'length', 'metre', or the id of a unitDefinition "
    "that defines a variant of 'metre' with exponent=1.";
  const char *compartmentId;
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  compartmentId = Species_getCompartment(s);
  if (compartmentId && Species_isSetSpatialSizeUnits(s))
  {
    Compartment_t *c = Model_getCompartmentById(d->model, compartmentId);
    if (c && Compartment_getSpatialDimensions(c) == 1)
    {
      if (!isOneDimensional(d->model, Species_getSpatialSizeUnits(s)))
      {
        LOG_MESSAGE(msg);
        passed = 0;
      }
    }
  }

  return passed;
}


/**
 * spatialSizeUnits for spatialDimensions of 2.
 */
RULE (species_spatialDimensions2)
{
  static const char msg[] =
    "A species whose compartment has spatialDimensions=2 must have "
    "spatialSizeUnits of 'area' or the id of a unitDefinition "
    "that defines a variant of 'metre' with exponent=2.";
  const char *compartmentId;
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  compartmentId = Species_getCompartment(s);
  if (compartmentId && Species_isSetSpatialSizeUnits(s))
  {
    Compartment_t *c = Model_getCompartmentById(d->model, compartmentId);
    if (c && Compartment_getSpatialDimensions(c) == 2)
    {
      if (!isTwoDimensional(d->model, Species_getSpatialSizeUnits(s)))
      {
        LOG_MESSAGE(msg);
        passed = 0;
      }
    }
  }

  return passed;
}


/**
 * spatialSizeUnits for spatialDimensions of 3.
 */
RULE (species_spatialDimensions3)
{
  static const char msg[] =
    "A species whose compartment has spatialDimensions=3 must have "
    "spatialSizeUnits of 'volume' or 'litre' or the id of a unitDefinition "
    "that defines a variant of 'metre' with exponent=3 or a variant of "
    "'litre'.";
  const char *compartmentId;
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  compartmentId = Species_getCompartment(s);
  if (compartmentId && Species_isSetSpatialSizeUnits(s))
  {
    Compartment_t *c = Model_getCompartmentById(d->model, compartmentId);
    if (c && Compartment_getSpatialDimensions(c) == 3)
    {
      if (!isThreeDimensional(d->model, Species_getSpatialSizeUnits(s)))
      {
        LOG_MESSAGE(msg);
        passed = 0;
      }
    }
  }

  return passed;
}

/**
 * The substanceUnits attribute must contain either substance, item, mole or
 * the values of id attributes of unitDefinition elements that define variants
 * (i.e. have only arbitrary scale, multiplier and offset values) of item or
 * mole.
 */
RULE (species_substanceUnits)
{
  static const char msg[] =
    "A species' substanceUnits must be 'substance', 'item', 'mole', or the "
    "id of a unitDefinition that defines a variant of 'item' or 'mole'.";
  unsigned int passed = 1;


  Species_t *s = (Species_t *) obj;
  if (Species_isSetSubstanceUnits(s))
  {
    const char* substanceUnits = Species_getSubstanceUnits(s);
    UnitDefinition_t *ud =
      Model_getUnitDefinitionById(d->model, substanceUnits);

    if (
      !isKindOfSubstance(substanceUnits)
      &&
      !unitDefinitionIsVariantOf(ud, isSubstanceKind, 1)
    ) {
      LOG_MESSAGE(msg);
      passed = 0;
    }
  }

  return passed;
}


/**
 * The initialConcentration attribute must not be present if the
 * hasOnlySubstanceUnits attribute is true.
 */
RULE (species_initialConcentrationSubstanceUnits)
{
  static const char msg[] =
    "A species with hasOnlySubstanceUnits='true' must not have an "
    "initialConcentration.";
  unsigned int passed = 1;

  Species_t *s = (Species_t *) obj;


  if (
    Species_getHasOnlySubstanceUnits(s)
    &&
    Species_isSetInitialConcentration(s)
  ) {
    LOG_MESSAGE(msg);
    passed = 0;
  }

  return passed;
}


/* TODO: shouldn't this be a member function of Species_t? */
unsigned int
getSpatialDimensions(Model_t *m, Species_t *s)
{
  const char *compartmentId = Species_getCompartment(s);


  if (compartmentId)
  {
    Compartment_t *c = Model_getCompartmentById(m, compartmentId);
    if (c)
    {
      return Compartment_getSpatialDimensions(c);
    }
  }

  return 0;
}


/**
 * The initialConcentration attribute must not be present if the spatial
 * dimensions is zero.
 */
RULE (species_initialConcentrationZeroSpatialDimensions)
{
  static const char msg[] =
    "A species whose compartment has spatialDimensions='0' must not have "
    "an initialConcentration.";
  unsigned int passed = 1;

  Species_t *s = (Species_t *) obj;
  unsigned int spatialDimensions = getSpatialDimensions(d->model, s);


  if (
    spatialDimensions == 0
    &&
    Species_isSetInitialConcentration(s)
  ) {
    LOG_MESSAGE(msg);
    passed = 0;
  }
    
  return passed;
}


/**
 * The initialConcentration and initialAmount attributes must not be present
 * on the same element at the same time.
 */
/* TODO: access this info directly from parser; as of 15-Apr-2004, can't
 * access it from libsbml object model.
 * Test case for partialModels:
# A species may not have both an initialConcentration and an initialAmount.
   <compartment id="c"/>
   <species id="someId" compartment="c" initialAmount="5.8" initialConcentration="2.4"/>
 */
RULE (species_initialConcentrationInitialAmount)
{
  static const char msg[] =
    "A species may not have both an initialConcentration and an initialAmount.";
  unsigned int passed = 1;

  Species_t *s = (Species_t *) obj;


  if (
    Species_isSetInitialConcentration(s)
    &&
    Species_isSetInitialAmount(s)
  ) {
    LOG_MESSAGE(msg);
    passed = 0;
  }

  return passed;
}

/**
 * When a species element has a constant attribute value of true and a
 * boundaryCondition attribute of false then there must be no speciesReference
 * element's species attribute that contains the value of the species
 * element's id attribute.
 */
RULE (species_speciesReference)
{
  static const char msg[] =
    "A speciesReference may not refer to a species with constant='true' "
    "and boundaryCondition='false'.";
  unsigned int passed = 1;

  Species_t *s = (Species_t *) obj;
  const char *speciesId = Species_getId(s);


  if (
    Species_getConstant(s)
    &&
    !Species_getBoundaryCondition(s)
  )
  {
    if (anySpeciesReferenceIsTo(d->model, speciesId))
    {
      LOG_MESSAGE(msg);
      passed = 0;
    }
  }

  return passed;
}


/**
 * Consider a species element that has a boundaryCondition attribute of false
 * and there exists a species attribute on a speciesReference element which
 * contains the value of the species element's id attribute. (The species
 * concentration is determined by a reaction.) In this case there must not
 * exist a variable attribute of a rule element that contains the id attribute
 * value on the species element. (A species can't be determined by rules and
 * reactions at the same time).
 */
/* TODO: add a test case for AlgebraicRule */
RULE (species_ruleAndReaction)
{
  static const char msg[] =
    "A species may not participate in both a rule and a reaction.";
  BOOLEAN passed = TRUE;

  Species_t *s = (Species_t *) obj;
  const char *speciesId = Species_getId(s);
  
  
  if (
    !Species_getConstant(s)
    &&
    !Species_getBoundaryCondition(s)
  )
  {
    if (
      anySpeciesReferenceIsTo(d->model, speciesId)
      &&
      anyRuleVariableIs(d->model, speciesId)
    )
    {
      LOG_MESSAGE(msg);
      passed = FALSE;
    }
  }

  return passed;
}


/**
 * The units field must contain one of the following: a value from the unit
 * kind enumeration (eg 'metre'), a value from the built-in units table e.g.
 * 'substance' or the value of a id attribute of a unitDefinition element.
 */
RULE (parameter_units)
{
  static const char msg[] =
    "A parameter's 'units' must be a base unit (e.g. 'litre'), a built-in "
    "unit (e.g. 'volume'), or the id of a unitDefinition.";
  BOOLEAN passed = TRUE;

  Parameter_t *p = (Parameter_t *) obj;
  const char *units = Parameter_getUnits(p);


  if (units)
  {
    if (
      !UnitKind_isValidUnitKindString(units)
      &&
      Model_getUnitDefinitionById(d->model, units) == NULL
      &&
      !isBuiltInUnit(units)
    )
    {
      LOG_MESSAGE(msg);
      passed = FALSE;
    }
  }

  return passed;
}


/**
 * A reaction must contain one "speciesReference" element (either in the
 * products or reactants lists).
 */
RULE (reaction_speciesReference)
{
  static const char msg[] =
    "A reaction must contain one speciesReference, in its products, "
    "reactants, or modifiers.";

  Reaction_t *r = (Reaction_t *) obj;
  BOOLEAN passed = TRUE;


  if (
    Reaction_getNumReactants(r) == 0
    &&
    Reaction_getNumProducts(r) == 0
    &&
    Reaction_getNumModifiers(r) == 0
  )
  {
    LOG_MESSAGE(msg);
    passed = FALSE;
  }
  
  return passed;
}


/**
 * The value of a species attribute of a speciesReference and
 * modifierSpeciesReference element must contain the value of a id attribute
 * of a species element.
 */
RULE (reaction_speciesReferenceExists)
{
  static const char baseMsg[] =
    "Species '%s' is not defined.";

  Reaction_t *r = (Reaction_t *) obj;
  BOOLEAN passed = TRUE;

  List_t *speciesReferenceIds = allSpeciesReferenceIdsIn(r);
  unsigned int numReferences = List_size(speciesReferenceIds);
  unsigned int i;


  for (i = 0; i < numReferences; i++)
  {
    const char *species = (const char *)List_get(speciesReferenceIds, i);

    if (!speciesExists(d->model, species))
    {
      char buf[512];

      sprintf(buf, baseMsg, species);
      LOG_MESSAGE(buf)
      passed = FALSE;
    }
  }

  List_free(speciesReferenceIds);
  return passed;
}


/**
 * Adds the default ValidationRule set to this Validator.
 */
void
Validator_addDefaultRules (Validator_t *v)
{
  Validator_addRule( v, compartment_spatialDimensions1, SBML_COMPARTMENT     );
  Validator_addRule( v, compartment_spatialDimensions2, SBML_COMPARTMENT     );
  Validator_addRule( v, compartment_spatialDimensions3, SBML_COMPARTMENT     );
  Validator_addRule( v, compartment_spatialDimensions0, SBML_COMPARTMENT     );
  Validator_addRule( v, compartment_size_dimensions,    SBML_COMPARTMENT     );
  Validator_addRule( v, compartment_outsideIsDefined,   SBML_COMPARTMENT     );
  Validator_addRule( v, compartment_outsideCyclic,      SBML_COMPARTMENT     );
  Validator_addRule( v, kineticLaw_substanceUnits  ,    SBML_REACTION        );
  Validator_addRule( v, unitDefinition_idsMustBeUnique,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, unitDefinition_idCantBePredefinedUnit,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, unitDefinition_substanceKinds,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, unitDefinition_volumeKinds,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, unitDefinition_areaKinds,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, unitDefinition_lengthKinds,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, unitDefinition_timeKinds,
                                                        SBML_UNIT_DEFINITION );
  Validator_addRule( v, species_compartmentIsDefined,   SBML_SPECIES         );
  Validator_addRule( v, species_hasOnlySubstanceUnits,  SBML_SPECIES         );
  Validator_addRule( v, species_zeroSpatialDimensions,  SBML_SPECIES         );
  Validator_addRule( v, species_spatialDimensions1,     SBML_SPECIES         );
  Validator_addRule( v, species_spatialDimensions2,     SBML_SPECIES         );
  Validator_addRule( v, species_spatialDimensions3,     SBML_SPECIES         );
  Validator_addRule( v, species_substanceUnits,         SBML_SPECIES         );
  Validator_addRule( v, species_initialConcentrationSubstanceUnits,
                                                        SBML_SPECIES         );
  Validator_addRule( v, species_initialConcentrationZeroSpatialDimensions,
                                                        SBML_SPECIES         );
  /*
  Validator_addRule( v, species_initialConcentrationInitialAmount,
                                                        SBML_SPECIES         );
  */
  Validator_addRule( v, species_speciesReference,       SBML_SPECIES         );
  Validator_addRule( v, species_ruleAndReaction,        SBML_SPECIES         );
  Validator_addRule( v, parameter_units,                SBML_PARAMETER       );
  Validator_addRule( v, reaction_speciesReference,      SBML_REACTION        );
  Validator_addRule( v, reaction_speciesReferenceExists, SBML_REACTION       );
}


/**
* @file    SBMLLevelVersionConverter.cpp
* @brief   Implementation of SBMLFunctionDefinitionConverter, a converter replacing function definitions
* @author  Frank Bergmann 
* 
* <!--------------------------------------------------------------------------
* This file is part of libSBML.  Please visit http://sbml.org for more
* information about SBML, and the latest version of libSBML.
*
* Copyright (C) 2009-2013 jointly by the following organizations: 
*     1. California Institute of Technology, Pasadena, CA, USA
*     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
*  
* Copyright (C) 2006-2008 by the California Institute of Technology,
*     Pasadena, CA, USA 
*  
* Copyright (C) 2002-2005 jointly by the following organizations: 
*     1. California Institute of Technology, Pasadena, CA, USA
*     2. Japan Science and Technology Agency, Japan
* 
* This library is free software; you can redistribute it and/or modify it
* under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation.  A copy of the license agreement is provided
* in the file named "LICENSE.txt" included with this software distribution
* and also available online as http://sbml.org/software/libsbml/license.html
* ------------------------------------------------------------------------ -->
*/


#include <sbml/conversion/SBMLFunctionDefinitionConverter.h>
#include <sbml/conversion/SBMLConverterRegistry.h>
#include <sbml/conversion/SBMLConverterRegister.h>
#include <sbml/validator/constraints/IdList.h>
#include <sbml/SBMLDocument.h>
#include <sbml/Model.h>

#ifdef __cplusplus

#include <algorithm>
#include <string>
#include <iterator>

using namespace std;
LIBSBML_CPP_NAMESPACE_BEGIN


/** @cond doxygen-libsbml-internal */
void SBMLFunctionDefinitionConverter::init()
{
  SBMLFunctionDefinitionConverter converter;
  SBMLConverterRegistry::getInstance().addConverter(&converter);
}
/** @endcond */


SBMLFunctionDefinitionConverter::SBMLFunctionDefinitionConverter() : SBMLConverter()
{

}


SBMLFunctionDefinitionConverter::SBMLFunctionDefinitionConverter(const SBMLFunctionDefinitionConverter& orig) :
  SBMLConverter(orig)
{
}

SBMLConverter* 
SBMLFunctionDefinitionConverter::clone() const
{
  return new SBMLFunctionDefinitionConverter(*this);
}

ConversionProperties
SBMLFunctionDefinitionConverter::getDefaultProperties() const
{
  static ConversionProperties prop;
  prop.addOption("expandFunctionDefinitions", true,
                 "Expand all function definitions in the model");
  prop.addOption("skipIds", "",
                 "Comma separated list of ids to skip during expansion");
  return prop;
}

bool 
SBMLFunctionDefinitionConverter::matchesProperties(const ConversionProperties &props) const
{
  if (&props == NULL || !props.hasOption("expandFunctionDefinitions"))
    return false;
  return true;
}


struct tokens: std::ctype<char> 
{
    tokens(): std::ctype<char>(get_table()) {}

    static std::ctype_base::mask const* get_table()
    {
        typedef std::ctype<char> cctype;
        static const cctype::mask *const_rc= cctype::classic_table();

        static cctype::mask rc[cctype::table_size];
        std::memcpy(rc, const_rc, cctype::table_size * sizeof(cctype::mask));

        rc[','] = std::ctype_base::space; 
        rc[';'] = std::ctype_base::space; 
        rc['\t'] = std::ctype_base::space; 
        rc[' '] = std::ctype_base::space; 
        return &rc[0];
    }
};

int 
SBMLFunctionDefinitionConverter::convert()
{
  if (mDocument == NULL) return LIBSBML_INVALID_OBJECT;
  Model* mModel = mDocument->getModel();
  if (mModel == NULL) return LIBSBML_INVALID_OBJECT;

  bool success = false;
  unsigned int i, j;

  /* if there are no function definitions bail now */
  if (mModel->getNumFunctionDefinitions() == 0)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }

  /* check consistency of model */
  /* since this function will write to the error log we should
  * clear anything in the log first
  */
  mDocument->getErrorLog()->clearLog();
  unsigned char origValidators = mDocument->getApplicableValidators();

  mDocument->setApplicableValidators(AllChecksON);


  unsigned int errors = mDocument->checkConsistency();

  if (expandFD_errors(errors) == true)
  {
    /* replace original consistency checks */
    mDocument->setApplicableValidators(origValidators);
    return LIBSBML_CONV_INVALID_SRC_DOCUMENT;
  }

  // parse possible lists of ids to skip
  IdList idsToSkip;

  if (mProps != NULL && mProps->hasOption("skipIds"))
  {
  std::stringstream ss(mProps->getOption("skipIds")->getValue());
  ss.imbue(std::locale(std::locale(), new tokens()));
  std::istream_iterator<std::string> begin(ss);
  std::istream_iterator<std::string> end;
  std::vector<std::string> skipVector(begin, end);
  std::vector<std::string>::iterator it;


  for (it = skipVector.begin(); it != skipVector.end(); ++it)
    idsToSkip.append(*it);
  }

  // for any math in document replace each function def
  for (i = 0; i < mModel->getNumRules(); i++)
  {
    if (mModel->getRule(i)->isSetMath())
    {
      SBMLTransforms::replaceFD(const_cast <ASTNode *>(mModel->getRule(i)
        ->getMath()), mModel->getListOfFunctionDefinitions(), &idsToSkip);
    }
  }
  for (i = 0; i < mModel->getNumInitialAssignments(); i++)
  {
    if (mModel->getInitialAssignment(i)->isSetMath())
    {
      SBMLTransforms::replaceFD(const_cast <ASTNode *>(mModel
        ->getInitialAssignment(i)->getMath()), 
        mModel->getListOfFunctionDefinitions(), &idsToSkip);
    }
  }
  for (i = 0; i < mModel->getNumConstraints(); i++)
  {
    if (mModel->getConstraint(i)->isSetMath())
    {
      SBMLTransforms::replaceFD(const_cast <ASTNode *>(mModel
        ->getConstraint(i)->getMath()), 
        mModel->getListOfFunctionDefinitions(), &idsToSkip);
    }
  }
  for (i = 0; i < mModel->getNumReactions(); i++)
  {
    if (mModel->getReaction(i)->isSetKineticLaw())
    {
      if (mModel->getReaction(i)->getKineticLaw()->isSetMath())
      {
        SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
          ->getReaction(i)->getKineticLaw()->getMath()), 
          mModel->getListOfFunctionDefinitions(), &idsToSkip);
      }
    }
    for (j = 0; j < mModel->getReaction(i)->getNumReactants(); j++)
    {
      if (mModel->getReaction(i)->getReactant(j)->isSetStoichiometryMath())
      {
        if (mModel->getReaction(i)->getReactant(j)->getStoichiometryMath()
          ->isSetMath())
        {
          SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
            ->getReaction(i)->getReactant(j)->getStoichiometryMath()->getMath()), 
            mModel->getListOfFunctionDefinitions(), &idsToSkip);
        }
      }
    }
    for (j = 0; j < mModel->getReaction(i)->getNumProducts(); j++)
    {
      if (mModel->getReaction(i)->getProduct(j)->isSetStoichiometryMath())
      {
        if (mModel->getReaction(i)->getProduct(j)->getStoichiometryMath()
          ->isSetMath(), &idsToSkip)
        {
          SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
            ->getReaction(i)->getProduct(j)->getStoichiometryMath()->getMath()), 
            mModel->getListOfFunctionDefinitions(), &idsToSkip);
        }
      }
    }
  }
  for (i = 0; i < mModel->getNumEvents(); i++)
  {
    if (mModel->getEvent(i)->isSetTrigger())
    {
      if (mModel->getEvent(i)->getTrigger()->isSetMath())
      {
        SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
          ->getEvent(i)->getTrigger()->getMath()),
          mModel->getListOfFunctionDefinitions(), &idsToSkip);
      }
    }
    if (mModel->getEvent(i)->isSetDelay())
    {
      if (mModel->getEvent(i)->getDelay()->isSetMath())
      {
        SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
          ->getEvent(i)->getDelay()->getMath()),
          mModel->getListOfFunctionDefinitions(), &idsToSkip);
      }
    }
    if (mModel->getEvent(i)->isSetPriority())
    {
      if (mModel->getEvent(i)->getPriority()->isSetMath())
      {
        SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
          ->getEvent(i)->getPriority()->getMath()),
          mModel->getListOfFunctionDefinitions(), &idsToSkip);
      }
    }

    for(j = 0; j < mModel->getEvent(i)->getNumEventAssignments(); j++)
    {
      if (mModel->getEvent(i)->getEventAssignment(j)->isSetMath())
      {
        SBMLTransforms::replaceFD(const_cast <ASTNode *> (mModel
          ->getEvent(i)->getEventAssignment(j)->getMath()),
          mModel->getListOfFunctionDefinitions(), &idsToSkip);
      }
    }
  }

  /* replace original consistency checks */
  mDocument->setApplicableValidators(origValidators);

  unsigned int size = mModel->getNumFunctionDefinitions();
  unsigned int skipped = 0;
  while (size--) 
  {
    const std::string& id = mModel->getListOfFunctionDefinitions()->get(size)->getId();
    if (idsToSkip.contains(id))
    {
      ++skipped;
      continue;
    }

    mModel->getListOfFunctionDefinitions()->remove(size);
  }

  success = (mModel->getNumFunctionDefinitions() == skipped);

  if (success) return LIBSBML_OPERATION_SUCCESS;
  return LIBSBML_OPERATION_FAILED;
  
}

/** @cond doxygen-libsbml-internal */
/*
 * Predicate returning true if the errors encountered are not ignorable.
 */
bool
SBMLFunctionDefinitionConverter::expandFD_errors(unsigned int errors)
{
  if (errors > 0)
  {
    if (mDocument->getErrorLog()->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) > 0)
      return true;
    else
    {  /* in L2V1 error 10214 (ie function used but not defined)
        * is actually reported as a warning
        */
      for (unsigned int i = 0; i < mDocument->getErrorLog()->getNumErrors(); i++)
      {
        if (mDocument->getErrorLog()->getError(i)->getErrorId() == ApplyCiMustBeUserFunction)
        {
          return true;
        }
      }

      return false;
    }
  }
  else
  {
    return false;
  }
}
/** @endcond */


/** @cond doxygen-c-only */


/** @endcond */

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */



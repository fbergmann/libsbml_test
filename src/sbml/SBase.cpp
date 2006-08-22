/**
 * \file    SBase.cpp
 * \brief   Base object of all SBML objects
 * \author  Ben Bornstein
 *
 * $Id$
 * $Source$
 */
/* Copyright 2002 California Institute of Technology and Japan Science and
 * Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is
 * provided in the file named "LICENSE.txt" included with this software
 * distribution.  It is also available online at
 * http://sbml.org/software/libsbml/license.html
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */


#include <sstream>

#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLNode.h>

#include <sbml/util/util.h>

#include "SBMLDocument.h"
#include "Model.h"
#include "KineticLaw.h"
#include "SBMLTypeCodes.h"
#include "SBase.h"


using namespace std;


/**
 * Only subclasses may create SBase objects.
 */
SBase::SBase (const string& id, const string& name) :
   mId        ( id   )
 , mName      ( name )
 , mNotes     ( 0 )
 , mAnnotation( 0 )
 , mNamespaces( 0 )
 , mSBML      ( 0 )
 , mLine      ( 0 )
 , mColumn    ( 0 )
 //, inReaction ( 0 )
{
}


/**
 * Destroy this SBase object.
 */
LIBSBML_EXTERN
SBase::~SBase ()
{
  delete mNotes;
  delete mAnnotation;
  delete mNamespaces;
}


/**
 * @return the metaid of this SBML object.
 */
const string&
SBase::getMetaId () const
{
  return mMetaId;
}


/**
 * @return the id of this SBML object.
 */
const string&
SBase::getId () const
{
  return mId;
}


/**
 * @return the name of this SBML object.
 */
const string&
SBase::getName () const
{
  return (getLevel() == 1) ? mId : mName;
}


/**
 * @return true if the metaid of this SBML object has been set, false
 * otherwise.
 */
bool
SBase::isSetMetaId () const
{
  return (mMetaId.empty() == false);
}


/**
 * @return true if the id of this SBML object has been set, false
 * otherwise.
 */
bool
SBase::isSetId () const
{
  return (mId.empty() == false);
}


/**
 * @return true if the name of this SBML object has been set, false
 * otherwise.
 */
bool
SBase::isSetName () const
{
  return (mName.empty() == false);
}


/**
 * @return true if the notes of this SBML object has been set, false
 * otherwise.
 */
bool
SBase::isSetNotes () const
{
  return (mNotes != 0);
}


/**
 * @return true if the annotation of this SBML object has been set,
 * false otherwise.
 */
bool
SBase::isSetAnnotation () const
{
  return (mAnnotation != 0);
}


/**
 * Sets the metaid field of the given SBML object to a copy of metaid.
 */
void
SBase::setMetaId (const string& id)
{
  mMetaId = id;
}


/**
 * Sets the id of this SBML object to a copy of sid.
 */
void
SBase::setId (const string& sid)
{
  mId = sid;
}


/**
 * Sets the name of this SBML object to a copy of name.
 */
void
SBase::setName (const string& name)
{
  if (getLevel() == 1) mId = name;
  else mName = name;
}


/**
 * Unsets the metaid of this SBML object.
 */
void
SBase::unsetMetaId ()
{
  mMetaId.erase();
}


/**
 * Unsets the id of this SBML object.
 */
void
SBase::unsetId ()
{
  mId.erase();
}


/**
 * Unsets the name of this SBML object.
 */
void
SBase::unsetName ()
{
  if (getLevel() == 1) mId.erase();
  else mName.erase();
}


/**
 * Unsets the notes of this SBML object.
 */
LIBSBML_EXTERN
void
SBase::unsetNotes ()
{
  delete mNotes;
}

/**
 * Unsets the annotation of this SBML object.
 */
LIBSBML_EXTERN
void
SBase::unsetAnnotation ()
{
  delete mAnnotation;
}


/**
 * @return the parent SBMLDocument of this SBML object.
 */
const SBMLDocument*
SBase::getSBMLDocument () const
{
  return mSBML;
}


/**
 * @return the parent Model of this SBML object.
 */
const Model*
SBase::getModel () const
{
  return (mSBML != 0) ? mSBML->getModel() : 0;
}


/**
 * @return the SBML level of this SBML object.
 */
unsigned int
SBase::getLevel () const
{
  return (mSBML) ? mSBML->mLevel : SBMLDocument::getDefaultLevel();
}


/**
 * @return the SBML version of this SBML object.
 */
unsigned int
SBase::getVersion () const
{
  return (mSBML) ? mSBML->mVersion : SBMLDocument::getDefaultVersion();
}


/**
 * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
 * (default).
 */
SBMLTypeCode_t
SBase::getTypeCode () const
{
  return SBML_UNKNOWN;
}


/**
 * @return the line number of this SBML object.
 */
unsigned int
SBase::getLine () const
{
  return mLine;
}


/**
 * @return the column number of this SBML object.
 */
unsigned int
SBase::getColumn () const
{
  return mColumn;
}


/**
 * Subclasses should override this method to create, store, and then
 * return an SBML object corresponding to the next XMLToken in the
 * XMLInputStream.
 *
 * @return the SBML object corresponding to next XMLToken in the
 * XMLInputStream or NULL if the token was not recognized.
 */
SBase*
SBase::createObject (XMLInputStream&)
{
  return 0;
}


/**
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
SBase::readOtherXML (XMLInputStream&)
{
  return false;
}


/**
 * @return the ordinal position of the element with respect to its siblings
 * or -1 (default) to indicate the position is not significant.
 */
int
SBase::getElementPosition () const
{
  return -1;
}

int
SBase::getElementPosition (unsigned int n) const
{
  return -1;
}


/**
 * @return the SBMLErrorLog used to log errors during while reading and
 * validating SBML.
 */
SBMLErrorLog*
SBase::getErrorLog ()
{
  return (mSBML != 0) ? mSBML->getErrorLog() : 0;
}


/**
 * Stores the location (line and column) and any XML namespaces (for
 * roundtripping) declared on this SBML (XML) element.
 */
void
SBase::setSBaseFields (const XMLToken& element)
{
  mLine   = element.getLine  ();
  mColumn = element.getColumn();

  if (element.getNamespaces().getLength() > 0)
  {
    mNamespaces = new XMLNamespaces( element.getNamespaces() );
  }
}


/**
 * Sets the parent SBMLDocument of this SBML object.
 */
void
SBase::setSBMLDocument (SBMLDocument* d)
{
  mSBML = d;
}


/**
 * @return the partial SBML that describes this SBML object.
 */
char*
SBase::toSBML ()
{
  ostringstream    os;
  XMLOutputStream  stream(os, "UTF-8", false);

  write(stream);

  return safe_strdup( os.str().c_str() );
}


/**
 * Reads (initializes) this SBML object by reading from XMLInputStream.
 */
void
SBase::read (XMLInputStream& stream)
{
  /* flags for ordering checks */
  static unsigned int inReaction = 0;
  static unsigned int inKineticLaw = 0;
  static unsigned int inConstraint = 0;
  static unsigned int inEvent = 0;
  static unsigned int inUnitDefinition = 0;
  static unsigned int ignoreMath = 0;
  static unsigned int reactionNo = 0;
  static unsigned int constraintNo = 0;
  static unsigned int eventNo = 0;

  if ( !stream.peek().isStart() ) return;

  const XMLToken  element  = stream.next();
  int             position =  0;

  setSBaseFields( element );
  readAttributes( element.getAttributes() );

  if ( element.isEnd() ) 
  {
    /* catch case where element ends on same line as start */
    if (!strcmp(element.getName().c_str(), "reaction"))
      inReaction = 0;
    else if (!strcmp(element.getName().c_str(), "kineticLaw"))
      inKineticLaw = 0;
    else if (!strcmp(element.getName().c_str(), "constraint"))
      inConstraint = 0;
    else if (!strcmp(element.getName().c_str(), "event"))
      inEvent = 0;
    else if (!strcmp(element.getName().c_str(), "unitDefinition"))
      inUnitDefinition = 0;
    else if (!strcmp(element.getName().c_str(), "rateRule")
      || !strcmp(element.getName().c_str(), "algebraicRule")
      || !strcmp(element.getName().c_str(), "assignmentRule")
      || !strcmp(element.getName().c_str(), "functionDefinition")
      || !strcmp(element.getName().c_str(), "initialAssignment"))
      ignoreMath = 0;

    return;
  }

  while ( stream.isGood() )
  {
    stream.skipText();
    const XMLToken& next = stream.peek();

    if ( next.isEndFor(element) )
    {
      /* unset flags */
      if (!strcmp(element.getName().c_str(), "reaction"))
        inReaction = 0;
      else if (!strcmp(element.getName().c_str(), "kineticLaw"))
        inKineticLaw = 0;
      else if (!strcmp(element.getName().c_str(), "constraint"))
        inConstraint = 0;
      else if (!strcmp(element.getName().c_str(), "event"))
        inEvent = 0;
      else if (!strcmp(element.getName().c_str(), "unitDefinition"))
        inUnitDefinition = 0;
      else if (!strcmp(element.getName().c_str(), "rateRule")
        || !strcmp(element.getName().c_str(), "algebraicRule")
        || !strcmp(element.getName().c_str(), "assignmentRule")
        || !strcmp(element.getName().c_str(), "functionDefinition")
        || !strcmp(element.getName().c_str(), "initialAssignment"))
        ignoreMath = 0;

      stream.next();
      break;
    }
    else if ( next.isStart() )
    {
      SBase* object = createObject(stream);

      /* need to catch other xml elements to increment order counts */
      if (!object)
      {
        if(!strcmp(next.getName().c_str(), "math"))
        {
          if(!ignoreMath) 
          {
            position = getCurrentElementPosition(object, inReaction, reactionNo,
              inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);
          
            checkOrder( position, object,  mSBML->getErrorLog(), inReaction, 
              reactionNo, inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);
          }
        }
        else if(!strcmp(next.getName().c_str(), "trigger"))
        {
          position = getCurrentElementPosition(object, inReaction, reactionNo,
            inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);
        
          checkOrder( position, object,  mSBML->getErrorLog(), inReaction, 
            reactionNo, inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);
        }
       else if (!strcmp(next.getName().c_str(), "message"))
        {
          position = getCurrentElementPosition(object, inReaction, reactionNo,
            inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);
        
          checkOrder( position, object,  mSBML->getErrorLog(), inReaction, 
            reactionNo, inKineticLaw, inConstraint, constraintNo, inEvent, 
            eventNo, inUnitDefinition, 1);
        }
       else if (!strcmp(next.getName().c_str(), "delay"))
        {
          position = getCurrentElementPosition(object, inReaction, reactionNo,
            inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);
        
          checkOrder( position, object,  mSBML->getErrorLog(), inReaction, 
            reactionNo, inKineticLaw, inConstraint, constraintNo, inEvent, 
            eventNo, inUnitDefinition, 0, 1);
        }
      }

      if (object)
      {
        /* set flags */
        /* need to reset the count of reactions etc within model */
        if (object->getTypeCode() == SBML_MODEL)
        {
          reactionNo = 0;
          constraintNo = 0;
          eventNo = 0;
        }
        else if (object->getTypeCode() == SBML_REACTION)
        {
          inReaction = 1;
          reactionNo++;
        }
        else if (object->getTypeCode() == SBML_KINETIC_LAW)
        {
          inKineticLaw = 1;
        }
        else if (object->getTypeCode() == SBML_CONSTRAINT)
        {
          inConstraint = 1;
          constraintNo++;
        }
        else if (object->getTypeCode() == SBML_EVENT)
        {
          inEvent = 1;
          eventNo++;
        }
        else if (object->getTypeCode() == SBML_UNIT_DEFINITION)
        {
          inUnitDefinition = 1;
        }
        else if (object->getTypeCode() == SBML_RATE_RULE
          || object->getTypeCode() == SBML_ASSIGNMENT_RULE
          || object->getTypeCode() == SBML_ALGEBRAIC_RULE
          || object->getTypeCode() == SBML_FUNCTION_DEFINITION
          || object->getTypeCode() == SBML_INITIAL_ASSIGNMENT)
        {
          ignoreMath = 1;
        }

        position = getCurrentElementPosition(object, inReaction, reactionNo,
          inKineticLaw, inConstraint, constraintNo, inEvent, eventNo, inUnitDefinition);

        object->mSBML = mSBML;
        object->read(stream);

        checkOrder( position, object,  mSBML->getErrorLog(), inReaction, 
          reactionNo, inKineticLaw, inConstraint, constraintNo, inEvent, 
          eventNo, inUnitDefinition);

      }
      else if ( !readOtherXML(stream) )
      {
        // logUnrecognized(next, log);
        stream.skipPastEnd( stream.next() );
      }
    }
  }
}


/**
  * this function uses static variables to keep track of the position
  * of each element being read into the Model
  */
int
SBase::getCurrentElementPosition(SBase* object, unsigned int inReaction,
                                 unsigned int reactionNo, unsigned int inKineticLaw,
                                 unsigned int inConstraint, unsigned int constraintNo,
                                 unsigned int inEvent, unsigned int eventNo,
                                 unsigned int inUnitDefinition)
{

  static unsigned int countReact = 0;
  static unsigned int countConst = 0;
  static unsigned int countEvent = 0;
  static unsigned int position_in_model = 0;
  static unsigned int position_in_reaction = 0;
  static unsigned int position_in_kl = 0;
  static unsigned int position_in_constraint = 0;
  static unsigned int position_in_event = 0;

  /** reset the count of elements inside elements
   * eg reaction, kineticLaw, constraint, event 
   */
  if (reactionNo > countReact)
  {
    countReact++;
    position_in_reaction = 0;
    position_in_kl = 0;
  }
  else if (constraintNo > countConst)
  {
    countConst++;
    position_in_constraint = 0;
  }
  else if (eventNo > countEvent)
  {
    countEvent++;
    position_in_event = 0;
  }

  /** math elements will be NULL but need to be counted */

  if (!object)
  {
    if (inKineticLaw)
    {
      position_in_kl++;
      return position_in_kl;
    }

    if (inConstraint)
    {
      position_in_constraint++;
      return position_in_constraint;
    }

    if (inEvent)
    {
      position_in_event++;
      return position_in_event;
    }
  }
  /**
  * to enable the order of certain elements to be checked
  * we need to keep track of what position we are in
  *
  * objects created here will be either listOf or sbml objects
  * to track order in the model we need to keep count of listOf
  */
  SBMLTypeCode_t type = object->getTypeCode();

  switch(type)
  {
    case SBML_MODEL:
      /* need to reset all position pointers */
     countReact = 0;
     countConst = 0;
     countEvent = 0;
     position_in_model = 0;
     position_in_reaction = 0;
     position_in_kl = 0;
     position_in_constraint = 0;
     position_in_event = 0;
     return -1;
    break;

    case SBML_LIST_OF:
      if (inReaction)
      {
        if (inKineticLaw)
        {
          ++position_in_kl;
          return position_in_kl;
        }
        
        ++position_in_reaction;
        return position_in_reaction;
      }
      else if (inEvent)
      {
        ++position_in_event;
        return position_in_event;
      }
      else if (inUnitDefinition)
      {
        return -1;
      }
      else
      {
        ++position_in_model;
        return position_in_model;
      }
      break;
    case SBML_KINETIC_LAW:
      ++position_in_reaction;
      return position_in_reaction;
      break;
    default:
      return -1;
      break;

  }
  

}

/**
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SBase::readAttributes (const XMLAttributes& attributes)
{
  attributes.readInto("metaid", mMetaId);
}


/**
 * Writes (serializes) this SBML object by writing it to XMLOutputStream.
 */
void
SBase::write (XMLOutputStream& stream) const
{
  stream.startElement( getElementName() );

  writeAttributes( stream );
  writeElements  ( stream );

  stream.endElement( getElementName() );
}


/**
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
SBase::writeAttributes (XMLOutputStream& stream) const
{
  if (mNamespaces) stream << *mNamespaces;

  if ( getLevel() == 2 && !mMetaId.empty() )
  {
    stream.writeAttribute("metaid", mMetaId);
  }
}


/**
 * Subclasses should override this method to write out their contained
 * SBML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SBase::writeElements (XMLOutputStream& stream) const
{
  if ( mNotes      ) stream << *mNotes;
  if ( mAnnotation ) stream << *mAnnotation;
}


/**
 * checks the order in which elements are read into a model
 * flags are necessary as it is only as the sbml is being read that
 * the order can be checked
 */
void
SBase::checkOrder (int position, SBase* object, SBMLErrorLog* log, 
                   unsigned int inReaction, unsigned int reactionNo, 
                   unsigned int inKineticLaw,
                   unsigned int inConstraint, unsigned int constraintNo,
                   unsigned int inEvent, unsigned int eventNo, 
                   unsigned int inUnitDefinition,
                   unsigned int messageFlag, unsigned int delayFlag)
{
  const string msg1002 = "The order of subelements within Model must be the "
    "following (where any one may be optional, but the ordering must be "
    "maintained): listOfFunctionDefinitions, listOfUnitDefinitions, "
    "listOfCompartmentTypes, listOfSpeciesTypes, listOfCompartments, "
    "listOfSpecies, listOfParameters, listOfInitialAssignments, "
    "listOfRules, listOfConstraints, listOfReactions and listOfEvents. "
    "(References: L2V2 Section 4.2.)";

  const string msg1608 = "The order of subelements within Reaction must be the "
    "following: listOfReactants (optional), listOfProducts (optional), "
    "listOfModifiers (optional), kineticLaw. (References: L2V2 Section 4.13.)";

  const string msg1609 = "The order of subelements within KineticLaw must be "
    "the following: math, listOfParameters. The listOfParameters is optional, "
    "but if present, must follow math. (References: L2V2 Section 4.13.9.).";

  const string msg2101 = "The order of subelements within Constraint must be "
    "the following: math, message. The message element is optional, but if "
    "present, must follow the math element. (References: L2V2 Section 4.12.)";

  const string msg1804 = "The order of subelements within Event must be the "
    "following: trigger, delay, listOfEventAssignments. The delay element "
    "is optional, but if present, must follow trigger. "
    "(References: L2V2 Section 4.14.)";

  int expected_pos = -1;


  /* inside reaction */
  if (inReaction)
  {
    if (inKineticLaw)
    {
      /* math element will be a null object */
      if (!object)
      {
        expected_pos = 1;
        
        if (position != expected_pos)
        {
          log->add(XMLError(1609, msg1609));
        }
      }
      else if (!strcmp(object->getElementName().c_str(), "listOfParameters"))
      {
        expected_pos = object->getElementPosition(reactionNo);
        
        if (position != expected_pos)
        {
          log->add(XMLError(1609, msg1609));
        }
      }
      else
      {
        expected_pos = object->getElementPosition();
        
        if (expected_pos == -1)
          return;
        
        if (position != expected_pos)
        {
          log->add(XMLError(1609, msg1609));
        }
      }
    }
    else if (!strcmp(object->getElementName().c_str(), "listOfReactants")
      || !strcmp(object->getElementName().c_str(), "listOfProducts")
      || !strcmp(object->getElementName().c_str(), "listOfModifiers"))
    {
      expected_pos = object->getElementPosition(reactionNo);
      
      if (position != expected_pos)
      {
        log->add(XMLError(1608, msg1608));
      }
    }
    else
    {
      expected_pos = object->getElementPosition();
      
      if (expected_pos == -1)
        return;
        
      if (position != expected_pos)
      {
        log->add(XMLError(1608, msg1608));
      }
    }
  }
  else if (inConstraint)
  {
      /* math and message element will be a null object 
       * only need to check once 
       */
      if (!object)
      {
        if (messageFlag)
        {
          expected_pos = 2;
        
          if (position != expected_pos)
          {
            log->add(XMLError(2101, msg2101));
          }
       }
     }
  }
  else if (inEvent)
  {
    /* math will be null */
    if (!object)
    {
      if (delayFlag)
      {
        expected_pos = 2;
                
        if (position != expected_pos)
        {
          log->add(XMLError(1804, msg1804));
        }
      }
    }
    else if (!strcmp(object->getElementName().c_str(), "listOfEventAssignments"))
    {
      expected_pos = object->getElementPosition(eventNo);
      
      if (position != expected_pos)
      {
        log->add(XMLError(1804, msg1804));
      }
    }
    else
    {
      expected_pos = object->getElementPosition();
      
      if (expected_pos == -1)
        return;
      
      if (position != expected_pos)
      {
        log->add(XMLError(1804, msg1804));
      }
    }
 
  }
  else if (inUnitDefinition)
  {
    return;
  }

  else
  {
    expected_pos = object->getElementPosition();

    if (expected_pos == -1)
      return;

    if (position != expected_pos)
    {
      log->add(XMLError(1002, msg1002));
    }
  }
}


/**
 * @return the metaid of this SBML object.
 */
LIBSBML_EXTERN
const char *
SBase_getMetaId (const SBase_t *sb)
{
  return sb->isSetMetaId() ? sb->getMetaId().c_str() : NULL;
}


/**
 * @return the id of this SBML object.
 */
LIBSBML_EXTERN
const char *
SBase_getId (const SBase_t *sb)
{
  return sb->isSetId() ? sb->getId().c_str() : NULL;
}


/**
 * @return the name of this SBML object.
 */
LIBSBML_EXTERN
const char *
SBase_getName (const SBase_t *sb)
{
  return sb->isSetName() ? sb->getName().c_str() : NULL;
}


/**
 * @return 1 if the metaid of this SBML object has been set, 0 otherwise.
 */
LIBSBML_EXTERN
int
SBase_isSetMetaId (const SBase_t *sb)
{
  return static_cast<int>( sb->isSetMetaId() );
}


/**
 * @return 1 if the id of this SBML object has been set, 0 otherwise.
 */
LIBSBML_EXTERN
int
SBase_isSetId (const SBase_t *sb)
{
  return static_cast<int>( sb->isSetId() );
}


/**
 * @return 1 if the name of this SBML object has been set, 0 otherwise.
 */
LIBSBML_EXTERN
int
SBase_isSetName (const SBase_t *sb)
{
  return static_cast<int>( sb->isSetName() );
}


/**
 * @return 1 if the notes of this SBML object has been set, 0 otherwise.
 */
LIBSBML_EXTERN
int
SBase_isSetNotes (const SBase_t *sb)
{
  return static_cast<int>( sb->isSetNotes() );
}


/**
 * @return 1 if the annotation of this SBML object has been set, 0
 * otherwise.
 */
LIBSBML_EXTERN
int
SBase_isSetAnnotation (const SBase_t *sb)
{
  return static_cast<int>( sb->isSetAnnotation() );
}


/**
 * Sets the metaid field of the given SBML object to a copy of metaid.
 */
LIBSBML_EXTERN
void
SBase_setMetaId (SBase_t *sb, const char *metaid)
{
  (metaid == NULL) ? sb->unsetMetaId() : sb->setMetaId(metaid);
}


/**
 * Sets the id field of the given SBML object to a copy of sid.
 */
LIBSBML_EXTERN
void
SBase_setId (SBase_t *sb, const char *sid)
{
  (sid == NULL) ? sb->unsetId() : sb->setId(sid);
}


/**
 * Sets the name field of the given SBML object to a copy of name.
 */
LIBSBML_EXTERN
void
SBase_setName (SBase_t *sb, const char *name)
{
  (name == NULL) ? sb->unsetName() : sb->setName(name);
}


/**
 * Unsets the metaid of this SBML object.
 */
LIBSBML_EXTERN
void
SBase_unsetMetaId (SBase_t *sb)
{
  sb->unsetMetaId();
}


/**
 * Unsets the id of this SBML object.
 */
LIBSBML_EXTERN
void
SBase_unsetId (SBase_t *sb)
{
  sb->unsetId();
}


/**
 * Unsets the name of this SBML object.
 */
LIBSBML_EXTERN
void
SBase_unsetName (SBase_t *sb)
{
  sb->unsetName();
}


/**
 * Unsets the notes of this SBML object.
 */
LIBSBML_EXTERN
void
SBase_unsetNotes (SBase_t *sb)
{
  sb->unsetNotes();
}


/**
 * Unsets the annotation of this SBML object.
 */
LIBSBML_EXTERN
void
SBase_unsetAnnotation (SBase_t *sb)
{
  sb->unsetAnnotation();
}


/**
 * @return the parent SBMLDocument of this SBML object.
 */
LIBSBML_EXTERN
const SBMLDocument_t *
SBase_getSBMLDocument (const SBase_t *sb)
{
  return sb->getSBMLDocument();
}


/**
 * @return the parent Model of this SBML object.
 */
LIBSBML_EXTERN
const Model_t *
SBase_getModel (const SBase_t *sb)
{
  return sb->getModel();
}


/**
 * @return the SBML level of this SBML object.
 */
LIBSBML_EXTERN
unsigned int
SBase_getLevel (const SBase_t *sb)
{
  return sb->getLevel();
}


/**
 * @return the SBML version of this SBML object.
 */
LIBSBML_EXTERN
unsigned int
SBase_getVersion (const SBase_t *sb)
{
  return sb->getVersion();
}


/**
 * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
 * (default).
 */
LIBSBML_EXTERN
SBMLTypeCode_t
SBase_getTypeCode (const SBase_t *sb)
{
  return sb->getTypeCode();
}


/**
 * @return the XML element name of this SBML object.
 */
LIBSBML_EXTERN
const char *
SBase_getElementName (const SBase_t *sb)
{
  return sb->getElementName().empty() ? NULL : sb->getElementName().c_str();
}


/**
 * @return the line number of this SBML object.
 */
LIBSBML_EXTERN
unsigned int
SBase_getLine (const SBase_t *sb)
{
  return sb->getLine();
}


/**
 * @return the column number of this SBML object.
 */
LIBSBML_EXTERN
unsigned int
SBase_getColumn (const SBase_t *sb)
{
  return sb->getColumn();
}

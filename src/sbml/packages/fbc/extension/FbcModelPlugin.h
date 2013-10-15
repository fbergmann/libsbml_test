/**
 * @file    FbcModelPlugin.h
 * @brief   Definition of FbcModelPlugin, the plugin class of
 *          fbc package for the Model element.
 * @author  Frank T. Bergmann
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2009-2013 California Institute of Technology.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *------------------------------------------------------------------------- -->
 *
 * @class FbcModelPlugin
 * @ingroup fbc
 * @brief @htmlinclude pkg-marker-fbc.html
 * Implementation of the 'fbc' package extention to the %Model construct.
 */

#ifndef FbcModelPlugin_h
#define FbcModelPlugin_h


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/fbc/common/fbcfwd.h>

#ifdef __cplusplus

#include <sbml/SBMLErrorLog.h>
#include <sbml/Model.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/fbc/sbml/FluxBound.h>
#include <sbml/packages/fbc/sbml/Objective.h>
#include <sbml/packages/fbc/sbml/GeneAssociation.h>

LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN FbcModelPlugin : public SBasePlugin
{
public:

  /**
   * Constructor
   */
  FbcModelPlugin  (const std::string &uri, const std::string &prefix,
                    FbcPkgNamespaces *fbcns);


  /**
   * Copy constructor. Creates a copy of this FbcModelPlugin object.
   */
  FbcModelPlugin (const FbcModelPlugin & orig);


  /**
   * Destroy this object.
   */
  virtual ~FbcModelPlugin  ();


  /**
   * Assignment operator for FbcModelPlugin .
   */
  FbcModelPlugin & operator=(const FbcModelPlugin & orig);


  /**
   * Creates and returns a deep copy of this FbcModelPlugin  object.
   * 
   * @return a (deep) copy of this FbcModelPlugin object
   */
  virtual FbcModelPlugin * clone () const;


  // --------------------------------------------------------
  //
  // overridden virtual functions for reading/writing/checking 
  // elements
  //
  // --------------------------------------------------------

  /** @cond doxygenLibsbmlInternal */
  /**
   * Subclasses must override this method to create, store, and then
   * return an SBML object corresponding to the next XMLToken in the
   * XMLInputStream if they have their specific elements.
   *
   * @return the SBML object corresponding to next XMLToken in the
   * XMLInputStream or NULL if the token was not recognized.
   */
  virtual SBase* createObject (XMLInputStream& stream);
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * This function is a bit tricky.
   * This function is used only for setting annotation element in case
   * gene associations are used. 
   * Thus, no attribute is written by this function.
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Subclasses must override this method to write out their contained
   * SBML objects as XML elements if they have their specific elements.
   */
  virtual void writeElements (XMLOutputStream& stream) const;
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Checks if this plugin object has all the required elements.
   *
   * Subclasses should override this function if they have their specific
   * elements.
   *
   * @return true if this pugin object has all the required elements,
   * otherwise false will be returned.
   */
  virtual bool hasRequiredElements() const ;
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Parses Gene Annotation Extension 
   */
  virtual bool readOtherXML (SBase* parentObject, XMLInputStream& stream);
  /** @endcond */


  /**
   * Returns the first child element found that has the given @p id in the model-wide SId namespace, or @c NULL if no such object is found.
   *
   * @param id string representing the id of objects to find
   *
   * @return a pointer to the SBase element with the given @p id.
   */
  virtual SBase* getElementBySId(const std::string& id);
  
  
  /**
   * Returns the first child element it can find with the given @p metaid, or itself if it has the given @p metaid, or @c NULL if no such object is found.
   *
   * @param metaid string representing the metaid of objects to find
   *
   * @return a pointer to the SBase element with the given @p metaid.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);
  
  /**
   * Returns a List of all child SBase* objects, including those nested to an arbitrary depth
   *
   * @return a List* of pointers to all children objects.
   */
  virtual List* getAllElements(ElementFilter* filter=NULL);
  
  
  /** @cond doxygenLibsbmlInternal */

  int appendFrom(const Model* model);

  /** @endcond */

  /** ------------------------------------------------------------------
   *
   *  Additional public functions
   *
   * ------------------------------------------------------------------
   */
  
  /**
   * Returns the ListOfFluxBounds in this plugin object.
   *
   * @return ListOfFluxBounds object in this plugin object.
   */
  const ListOfFluxBounds* getListOfFluxBounds () const;


  /**
   * Returns the ListOfFluxBounds in this plugin object.
   *
   * @return ListOfFluxBounds object in this plugin object.
   */
  ListOfFluxBounds* getListOfFluxBounds ();


  /**
   * Returns the FluxBound object that belongs to the given index. If the
   * index is invalid, @c NULL is returned.
   *
   * @param n the index number of the FluxBound to get.
   *
   * @return the nth FluxBound in the ListOfFluxBounds.
   */
  const FluxBound* getFluxBound (unsigned int n) const;


  /**
   * Returns the FluxBound object that belongs to the given index. If the
   * index is invalid, @c NULL is returned.
   *
   * @param n the index number of the FluxBound to get.
   *
   * @return the nth FluxBound in the ListOfFluxBounds.
   */
  FluxBound* getFluxBound (unsigned int n);


  /**
   * Returns the FluxBound object based on its identifier.
   *
   * @param sid a string representing the identifier 
   * of the FluxBound to get.
   * 
   * @return FluxBound in the ListOfFluxBounds with the given @p sid
   * or NULL if no such FluxBound exists.
   *
   * @see get(unsigned int n)
   * @see size()
   */
  FluxBound* getFluxBound (const std::string& sid);


  /**
   * Returns the FluxBound object based on its identifier.
   *
   * @param sid a string representing the identifier 
   * of the FluxBound to get.
   * 
   * @return FluxBound in the ListOfFluxBounds with the given @p sid 
   * or NULL if no such FluxBound exists.
   *
   * @see get(unsigned int n)
   * @see size()
   */
  const FluxBound* getFluxBound (const std::string& sid) const;

  /**
   * Adds a copy of the given FluxBound object to the list of FluxBounds.
   *
   * @param bound the FluxBound object to be added to the list of FluxBounds.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   */ 
  int addFluxBound (const FluxBound* bound);


  /**
   * Creates a new FluxBound object and adds it to the list of FluxBound objects
   * and returns it.
   *
   * @return a newly created FluxBound object
   */
  FluxBound* createFluxBound();


  /**
   * Removes the nth FluxBound object from this plugin object and
   * returns a pointer to it.
   *
   * The caller owns the returned object and is responsible for
   *  deleting it.
   *
   * @param n the index of the FluxBound object to remove
   *
   * @return the FluxBound object removed.  As mentioned above, the 
   * caller owns the returned object. @c NULL is returned if the 
   * given index is out of range.
   */
  FluxBound* removeFluxBound (unsigned int n);


  /**
   * Removes the FluxBound object with the given @p sid attribute from 
   * this plugin object and returns a pointer to it.
   *
   * The caller owns the returned object and is responsible for
   * deleting it.
   *
   * @param sid the id attribute of the FluxBound object to remove
   *
   * @return the FluxBound object removed.  As mentioned above, the 
   * caller owns the returned object. @c NULL is returned if the 
   * given index is out of range.
   */
  FluxBound* removeFluxBound (const std::string& sid);


  /**
   * Returns the number of FluxBound object in this plugin object.
   *
   * @return the number of FluxBound object in this plugin object.
   */
  unsigned int getNumFluxBounds() const;


    
  /**
   * Returns the ListOfObjectives in this plugin object.
   *
   * @return ListOfObjectives object in this plugin object.
   */
  const ListOfObjectives* getListOfObjectives () const;
 
  /**
   * Returns the ListOfObjectives in this plugin object.
   *
   * @return ListOfObjectives object in this plugin object.
   */
  ListOfObjectives* getListOfObjectives ();


  
  /**
   * Returns the Objective object that belongs to the given index. If the
   * index is invalid, @c NULL is returned.
   *
   * @param n the index number of the Objective to get.
   *
   * @return the nth Objective in the ListOfObjectives.
   */
  const Objective* getObjective (unsigned int n) const;


  /**
   * Returns the Objective object that belongs to the given index. If the
   * index is invalid, @c NULL is returned.
   *
   * @param n the index number of the Objective to get.
   *
   * @return the nth Objective in the ListOfObjectives.
   */
  Objective* getObjective (unsigned int n);


  /**
   * Returns the Objective object based on its identifier.
   *
   * @param sid a string representing the identifier 
   * of the Objective to get.
   * 
   * @return Objective in the ListOfObjectives with the given @p id
   * or NULL if no such Objective exists.
   *
   * @see get(unsigned int n)
   * @see size()
   */
  Objective* getObjective (const std::string& sid);


  /**
   * Returns the Objective object based on its identifier.
   *
   * @param sid a string representing the identifier 
   * of the Objective to get.
   * 
   * @return Objective in the ListOfObjectives with the given @p sid 
   * or NULL if no such Objective exists.
   *
   * @see get(unsigned int n)
   * @see size()
   */
  const Objective* getObjective (const std::string& sid) const;

  /**
   * Adds a copy of the given Objective object to the list of Objectives.
   *
   * @param bound the Objective object to be added to the list of Objectives.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   */ 
  int addObjective (const Objective* bound);


  /**
   * Creates a new Objective object and adds it to the list of Objective objects
   * and returns it.
   *
   * @return a newly created Objective object
   */
  Objective* createObjective();


  /**
   * Removes the nth Objective object from this plugin object and
   * returns a pointer to it.
   *
   * The caller owns the returned object and is responsible for
   *  deleting it.
   *
   * @param n the index of the Objective object to remove
   *
   * @return the Objective object removed.  As mentioned above, the 
   * caller owns the returned object. @c NULL is returned if the 
   * given index is out of range.
   */
  Objective* removeObjective (unsigned int n);


  /**
   * Removes the Objective object with the given @p sid attribute from 
   * this plugin object and returns a pointer to it.
   *
   * The caller owns the returned object and is responsible for
   * deleting it.
   *
   * @param sid the id attribute of the Objective object to remove
   *
   * @return the Objective object removed.  As mentioned above, the 
   * caller owns the returned object. @c NULL is returned if the 
   * given index is out of range.
   */
  Objective* removeObjective (const std::string& sid);


  /**
   * Returns the number of Objective object in this plugin object.
   *
   * @return the number of Objective object in this plugin object.
   */
  unsigned int getNumObjectives() const;

  /** 
   * Returns the current active objective. 
   */
  Objective* getActiveObjective();

  /** 
   * Returns the current active objective. 
   */
  const Objective *getActiveObjective() const;
  
  /** 
   * Sets the id of the active objective.
   */
  int setActiveObjectiveId(const std::string& objectiveId);

  /** 
   * returns the id of the current active objective.
   */  
  std::string getActiveObjectiveId() const;
  
  /** 
   * Unsets the active objective.
   */  
  void unsetActiveObjectiveId();

  /**
   * Returns the ListOfObjectives in this plugin object.
   *
   * @return ListOfObjectives object in this plugin object.
   */
  const ListOfGeneAssociations* getListOfGeneAssociations () const;

  /**
   * Returns the ListOfGeneAssociations in this plugin object.
   *
   * @return ListOfGeneAssociations object in this plugin object.
   */
  ListOfGeneAssociations* getListOfGeneAssociations ();

  
  /**
   * Returns the GeneAssociation object that belongs to the given index. If the
   * index is invalid, @c NULL is returned.
   *
   * @param n the index number of the GeneAssociation to get.
   *
   * @return the nth GeneAssociation in the ListOfGeneAssociations.
   */
  const GeneAssociation* getGeneAssociation (unsigned int n) const;


  /**
   * Returns the GeneAssociation object that belongs to the given index. If the
   * index is invalid, @c NULL is returned.
   *
   * @param n the index number of the GeneAssociation to get.
   *
   * @return the nth GeneAssociation in the ListOfGeneAssociations.
   */
  GeneAssociation* getGeneAssociation (unsigned int n);


  /**
   * Returns the GeneAssociation object based on its identifier.
   *
   * @param sid a string representing the identifier 
   * of the GeneAssociation to get.
   * 
   * @return GeneAssociation in the ListOfGeneAssociations with the given @p sid
   * or NULL if no such GeneAssociation exists.
   *
   * @see get(unsigned int n)
   * @see size()
   */
  GeneAssociation* getGeneAssociation (const std::string& sid);


  /**
   * Returns the GeneAssociation object based on its identifier.
   *
   * @param sid a string representing the identifier 
   * of the GeneAssociation to get.
   * 
   * @return GeneAssociation in the ListOfGeneAssociations with the given @p sid 
   * or NULL if no such GeneAssociation exists.
   *
   * @see get(unsigned int n)
   * @see size()
   */
  const GeneAssociation* getGeneAssociation (const std::string& sid) const;

  /**
   * Adds a copy of the given GeneAssociation object to the list of GeneAssociations.
   *
   * @param association the GeneAssociation object to be added to the list of GeneAssociations.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSBML_OPERATION_SUCCESS
   */ 
  int addGeneAssociation (const GeneAssociation* association);


  /**
   * Creates a new GeneAssociation object and adds it to the list of GeneAssociation objects
   * and returns it.
   *
   * @return a newly created GeneAssociation object
   */
  GeneAssociation* createGeneAssociation();


  /**
   * Removes the nth GeneAssociation object from this plugin object and
   * returns a pointer to it.
   *
   * The caller owns the returned object and is responsible for
   *  deleting it.
   *
   * @param n the index of the GeneAssociation object to remove
   *
   * @return the GeneAssociation object removed.  As mentioned above, the 
   * caller owns the returned object. @c NULL is returned if the 
   * given index is out of range.
   */
  GeneAssociation* removeGeneAssociation (unsigned int n);


  /**
   * Removes the GeneAssociation object with the given @p sid attribute from 
   * this plugin object and returns a pointer to it.
   *
   * The caller owns the returned object and is responsible for
   * deleting it.
   *
   * @param sid the id attribute of the GeneAssociation object to remove
   *
   * @return the GeneAssociation object removed.  As mentioned above, the 
   * caller owns the returned object. @c NULL is returned if the 
   * given index is out of range.
   */
  GeneAssociation* removeGeneAssociation (const std::string& sid);


  /**
   * Returns the number of GeneAssociation object in this plugin object.
   *
   * @return the number of GeneAssociation object in this plugin object.
   */
  int getNumGeneAssociations() const;

  // ---------------------------------------------------------
  //
  // virtual functions (internal implementation) which should
  // be overridden by subclasses.
  //
  // ---------------------------------------------------------

  /** @cond doxygenLibsbmlInternal */
  /**
   * Sets the parent SBMLDocument of this plugin object.
   *
   * Subclasses which contain one or more SBase derived elements must
   * override this function.
   *
   * @param d the SBMLDocument object to use
   *
   * @see connectToParent
   * @see enablePackageInternal
   */
  virtual void setSBMLDocument (SBMLDocument* d);
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Sets the *parent* of this SBML object to child SBML objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * @see setSBMLDocument
   * @see enablePackageInternal
   */
  virtual void connectToChild ();
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Sets the parent SBML object of this plugin object to
   * this object and child elements (if any).
   * (Creates a child-parent relationship by this plugin object)
   *
   * This function is called when this object is created by
   * the parent element.
   * Subclasses must override this this function if they have one
   * or more child elements.Also, SBasePlugin::connectToParent()
   * must be called in the overridden function.
   *
   * @param sbase the SBase object to use
   *
   * @see setSBMLDocument
   * @see enablePackageInternal
   */
  virtual void connectToParent (SBase *sbase);
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Enables/Disables the given package with child elements in this plugin
   * object (if any).
   * (This is an internal implementation invoked from
   *  SBase::enablePakcageInternal() function)
   *
   * @note Subclasses in which one or more SBase derived elements are
   * defined must override this function.
   *
   * @see setSBMLDocument
   * @see connectToParent
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix, bool flag);
  /** @endcond */

  /** @cond doxygenLibsbmlInternal */

  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */

  ListOfFluxBounds * getFluxBoundsForReaction(const std::string& reaction) const;

protected:
  /** @cond doxygenLibsbmlInternal */

  /*-- data members --*/

  ListOfFluxBounds mBounds;
  ListOfObjectives mObjectives;
  ListOfGeneAssociations mAssociations;

  /** @endcond */
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


LIBSBML_EXTERN
int
FbcModelPlugin_addFluxBound(SBasePlugin_t * fbc, FluxBound_t * fb);


LIBSBML_EXTERN
FluxBound_t *
FbcModelPlugin_getFluxBound(SBasePlugin_t * fbc, unsigned int n);


LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumFluxBounds(SBasePlugin_t * fbc);


LIBSBML_EXTERN
int
FbcModelPlugin_addObjective(SBasePlugin_t * fbc, Objective_t * obj);


LIBSBML_EXTERN
Objective_t *
FbcModelPlugin_getObjective(SBasePlugin_t * fbc, unsigned int n);


LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumObjectives(SBasePlugin_t * fbc);


LIBSBML_EXTERN
char *
FbcModelPlugin_getActiveObjectiveId(SBasePlugin_t * fbc);


LIBSBML_EXTERN
int
FbcModelPlugin_setActiveObjectiveId(SBasePlugin_t * fbc, char * activeId);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* FbcModelPlugin_h */

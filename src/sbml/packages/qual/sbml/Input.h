/**
 * @file   Input.h
 * @brief  Implementation of the Input class
 * @author Generated by autocreate code
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 * 
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
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
 *
 * @class Input
 * @sbmlbrief{qual} The input to a QualitativeSpecies.
 *
 * Each Input refers to a QualitativeSpecies that participates in the
 * corresponding Transition. In Petri nets, these are the input places of the
 * transition. In logical models, they are the regulators of the species
 * whose behaviour is defined by the transition.
 */


#ifndef Input_H__
#define Input_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>

LIBSBML_CPP_NAMESPACE_BEGIN

/**
 * @enum InputTransitionEffect_t
 * Enumeration of possible values for the 'transitionEffect' attribute of an Input.  Must be 'none' or 'consumption'.
 */
typedef enum
{
    INPUT_TRANSITION_EFFECT_NONE /*!< 'none': The level associated with the qualitativeSpecies is not modified. */
  , INPUT_TRANSITION_EFFECT_CONSUMPTION /*!< 'consumption': The level of the qualitativeSpecies is decreased by the resultLevel of the applicable FunctionTerm possibly modified by the thresholdLevel of the Input. */
  , INPUT_TRANSITION_EFFECT_UNKNOWN /*!< Unknown or illegal value:  anything other than 'none' or 'consumption'. */
} InputTransitionEffect_t;

/**
 * @enum InputSign_t
 * Enumeration of possible values for the 'transitionEffect' attribute of an Input.  Must be 'positive', 'negative', 'dual', or 'unknown'.
 */
typedef enum
{
    INPUT_SIGN_POSITIVE /*!< 'positive': The contribution of this input is positive. */
  , INPUT_SIGN_NEGATIVE /*!< 'negative': The contribution of this input is negative. */
  , INPUT_SIGN_DUAL /*!< 'dual': The contribution of this input is both negative and positive. */
  , INPUT_SIGN_UNKNOWN /*!< 'unknown': The contribution of this input is unknown. */
  , INPUT_SIGN_VALUE_NOTSET /*!< unset or illegal value: Anything other than 'positive', 'negative', 'dual', or 'unknown'. */
} InputSign_t;

LIBSBML_CPP_NAMESPACE_END


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/ListOf.h>
#include <sbml/packages/qual/extension/QualExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Input : public SBase
{

protected:

  /** @cond doxygenLibsbmlInternal */
  std::string   mId;
  std::string   mQualitativeSpecies;
  InputTransitionEffect_t   mTransitionEffect;
  std::string   mName;
  InputSign_t   mSign;
  int           mThresholdLevel;
  bool          mIsSetThresholdLevel;
  /** @endcond */


public:

  /**
   * Creates a new Input with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Input
   *
   * @param version an unsigned int, the SBML Version to assign to this Input
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this Input
   */
  Input(unsigned int level      = QualExtension::getDefaultLevel(),
        unsigned int version    = QualExtension::getDefaultVersion(),
        unsigned int pkgVersion = QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new Input with the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   */
  Input(QualPkgNamespaces* qualns);


  /**
   * Copy constructor for Input.
   *
   * @param orig the Input instance to copy.
   */
  Input(const Input& orig);


  /**
   * Assignment operator for Input.
   *
   * @param rhs the object whose values are used as the basis
   * of the assignment
   */
  Input& operator=(const Input& rhs);


  /**
   * Creates and returns a deep copy of this Input object.
   *
   * @return a (deep) copy of this Input object.
   */
  virtual Input* clone () const;


  /**
   * Destructor for Input.
   */
  virtual ~Input();


  /**
   * Returns the value of the "id" attribute of this Input.
   *
   * @return the value of the "id" attribute of this Input as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "qualitativeSpecies" attribute of this Input.
   *
   * @return the value of the "qualitativeSpecies" attribute of this Input as a string.
   */
  virtual const std::string& getQualitativeSpecies() const;


  /**
   * Returns the value of the "transitionEffect" attribute of this Input.
   *
   * @return the value of the "transitionEffect" attribute of this Input as a string.
   */
  InputTransitionEffect_t getTransitionEffect() const;


  /**
   * Returns the value of the "name" attribute of this Input.
   *
   * @return the value of the "name" attribute of this Input as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Returns the value of the "sign" attribute of this Input.
   *
   * @return the value of the "sign" attribute of this Input as a string.
   */
  InputSign_t getSign() const;


  /**
   * Returns the value of the "thresholdLevel" attribute of this Input.
   *
   * @return the value of the "thresholdLevel" attribute of this Input as a integer.
   */
  virtual int getThresholdLevel() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Input's "id" attribute has been set.
   *
   * @return @c true if this Input's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Input's "qualitativeSpecies" attribute has been set.
   *
   * @return @c true if this Input's "qualitativeSpecies" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetQualitativeSpecies() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Input's "transitionEffect" attribute has been set.
   *
   * @return @c true if this Input's "transitionEffect" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTransitionEffect() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Input's "name" attribute has been set.
   *
   * @return @c true if this Input's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Input's "sign" attribute has been set.
   *
   * @return @c true if this Input's "sign" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetSign() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * Input's "thresholdLevel" attribute has been set.
   *
   * @return @c true if this Input's "thresholdLevel" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetThresholdLevel() const;


  /**
   * Sets the value of the "id" attribute of this Input.
   *
   * @param id const std::string& value of the "id" attribute to be set
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "qualitativeSpecies" attribute of this Input.
   *
   * @param qualitativeSpecies const std::string& value of the "qualitativeSpecies" attribute to be set
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  virtual int setQualitativeSpecies(const std::string& qualitativeSpecies);


  /**
   * Sets the value of the "transitionEffect" attribute of this Input.
   *
   * @param transitionEffect const std::string& value of the "transitionEffect" attribute to be set
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setTransitionEffect(const InputTransitionEffect_t transitionEffect);


  /**
   * Sets the value of the "name" attribute of this Input.
   *
   * @param name const std::string& value of the "name" attribute to be set
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  virtual int setName(const std::string& name);


  /**
   * Sets the value of the "sign" attribute of this Input.
   *
   * @param sign const std::string& value of the "sign" attribute to be set
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setSign(const InputSign_t sign);


  /**
   * Sets the value of the "thresholdLevel" attribute of this Input.
   *
   * @param thresholdLevel int value of the "thresholdLevel" attribute to be set
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  virtual int setThresholdLevel(int thresholdLevel);


  /**
   * Unsets the value of the "id" attribute of this Input.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "qualitativeSpecies" attribute of this Input.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetQualitativeSpecies();


  /**
   * Unsets the value of the "transitionEffect" attribute of this Input.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTransitionEffect();


  /**
   * Unsets the value of the "name" attribute of this Input.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Unsets the value of the "sign" attribute of this Input.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetSign();


  /**
   * Unsets the value of the "thresholdLevel" attribute of this Input.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetThresholdLevel();


  /**
   * @copydoc doc_renamesidref_common
   */
   virtual void renameSIdRefs(const std::string& oldid, const std::string& newid);


  /**
   * Returns the XML name of this object.
   *
   * @return the name of this element.
   */
  virtual const std::string& getElementName () const;


  /**
   * Returns the libSBML type code of this object instance.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_QUAL_INPUT, SBMLQualTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode () const;


  /**
   * Predicate returning @c true if all the required attributes
   * for this Input object have been set.
   *
   * @note The required attributes for a Input object are:
   * @li "qualitativeSpecies"
   * @li "transitionEffect"
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /** @cond doxygenLibsbmlInternal */
  /**
   * Subclasses should override this method to write out their contained
   * SBML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Accepts the given SBMLVisitor.
   */
  virtual bool accept (SBMLVisitor& v) const;
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Sets the parent SBMLDocument.
   */
  virtual void setSBMLDocument (SBMLDocument* d);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Enables/Disables the given package with this element.
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
               const std::string& pkgPrefix, bool flag);


  /** @endcond */


protected:

  /** @cond doxygenLibsbmlInternal */
  /**
   * Get the list of expected attributes for this element.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Read values from the given XMLAttributes set into their specific fields.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Write values of XMLAttributes to the output stream.
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;


  /** @endcond */



};

/**
 * @class ListOfInputs
 * @sbmlbrief{qual} A list of Input objects.
 * 
 * The ListOfInputs is a container for the Inputs of a Transition.
 * 
 * @copydetails doc_what_is_listof
 *
 * @see Input
 */
class LIBSBML_EXTERN ListOfInputs : public ListOf
{

public:

  /**
   * Creates a new ListOfInputs with the given level, version, and package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ListOfInputs
   *
   * @param version an unsigned int, the SBML Version to assign to this ListOfInputs
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this ListOfInputs
   */
  ListOfInputs(unsigned int level      = QualExtension::getDefaultLevel(),
               unsigned int version    = QualExtension::getDefaultVersion(),
               unsigned int pkgVersion = QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfInputs with the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   */
  ListOfInputs(QualPkgNamespaces* qualns);


  /**
   * Creates and returns a deep copy of this ListOfInputs object.
   *
   * @return a (deep) copy of this ListOfInputs object.
   */
  virtual ListOfInputs* clone () const;


  /**
   * Get a Input from the ListOfInputs.
   *
   * @param n the index number of the Input to get.
   *
   * @return the nth Input in this ListOfInputs.
   *
   * @see size()
   */
  virtual Input* get(unsigned int n);


  /**
   * Get a Input from the ListOfInputs.
   *
   * @param n the index number of the Input to get.
   *
   * @return the nth Input in this ListOfInputs.
   *
   * @see size()
   */
  virtual const Input* get(unsigned int n) const;


  /**
   * Get a Input from the ListOfInputs
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Input to get.
   *
   * @return Input in this ListOfInputs
   * with the given id or NULL if no such
   * Input exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual Input* get(const std::string& sid);


  /**
   * Get a Input from the ListOfInputs
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Input to get.
   *
   * @return Input in this ListOfInputs
   * with the given id or NULL if no such
   * Input exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const Input* get(const std::string& sid) const;


  /**
   * Get a Input from the ListOfInputs
   * based on the qualitativeSpecies to which it refers.
   *
   * @param sid a string representing the qualitativeSpecies attribute
   * of the Input to get.
   *
   * @return the first Input in this ListOfInputs
   * with the given qualitativeSpecies or NULL if no such
   * Input exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  const Input* getBySpecies(const std::string& sid) const;


  /**
   * Get a Input from the ListOfInputs
   * based on the qualitativeSpecies to which it refers.
   *
   * @param sid a string representing the qualitativeSpecies attribute
   * of the Input to get.
   *
   * @return the first Input in this ListOfInputs
   * with the given qualitativeSpecies or NULL if no such
   * Input exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  Input* getBySpecies(const std::string& sid);


  /**
   * Removes the nth Input from this ListOfInputs
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the Input to remove.
   *
   * @see size()
   */
  virtual Input* remove(unsigned int n);


  /**
   * Removes the Input from this ListOfInputs with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the Input to remove.
   *
   * @return the Input removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual Input* remove(const std::string& sid);


  /**
   * Returns the XML name of this object.
   *
   * @return the name of this element.
   */
  virtual const std::string& getElementName () const;


  /**
   * Returns the libSBML type code for the SBML objects
   * contained in this ListOf object.
   * 
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for objects contained in this list:
   * @sbmlconstant{SBML_QUAL_INPUT, SBMLTypeCode_t} (default).
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode () const;


protected:

  /** @cond doxygenLibsbmlInternal */
  /**
   * Creates a new Input in this ListOfInputs
   */
  virtual SBase* createObject(XMLInputStream& stream);


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Write the namespace for the Qual package.
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;


  /** @endcond */



};



LIBSBML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Creates a new Input_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Input_t
 * @param version an unsigned int, the SBML Version to assign to this
 * Input_t
 * @param pkgVersion an unsigned int, the SBML 'Qual' package Version to assign to this
 * Input_t
 *
 * @return a pointer to the newly created Input_t structure.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
Input_t *
Input_create(unsigned int level, unsigned int version,
             unsigned int pkgVersion);


/**
 * Frees the given Input_t structure.
 *
 * @param i the Input_t structure to free.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
void
Input_free(Input_t * i);


/**
 * Returns a copy of the given Input_t structure.
 *
 * @param i the Input_t structure to copy.
 * 
 * @return a (deep) copy of the Input_t.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
Input_t *
Input_clone(Input_t * i);


/**
 * Takes an Input_t structure and returns its identifier.
 *
 * @param i the Input_t structure whose identifier is sought
 * 
 * @return the identifier of this Input_t, as a pointer to a string.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
char *
Input_getId(Input_t * i);


/**
 * Takes a Input_t structure and returns its qualitativeSpecies.
 *
 * @param i the Input_t whose qualitativeSpecies is sought.
 *
 * @return the qualitativeSpecies of the given Input_t, as a pointer to a string.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
char *
Input_getQualitativeSpecies(Input_t * i);


/**
 * Takes a Input_t structure and returns its transitionEffect as a ENUMTYPE 
 * (an enumerated value of legal possible values for the attribute).
 *
 * @param i the Input_t whose transitionEffect is sought.
 *
 * @return the transitionEffect of the given Input_t, as a ENUMTYPE
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
InputTransitionEffect_t
Input_getTransitionEffect(Input_t * i);


/**
 * Takes a Input_t structure and returns its name.
 *
 * @param i the Input_t whose name is sought.
 *
 * @return the name of this Input_t, as a pointer to a string.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
char *
Input_getName(Input_t * i);


/**
 * Takes a Input_t structure and returns its sign as a ENUMTYPE 
 * (an enumerated value of legal possible values for the attribute).
 *
 * @param i the Input_t whose sign is sought.
 *
 * @return the sign of the given Input_t, as a ENUMTYPE
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
InputSign_t
Input_getSign(Input_t * i);


/**
 * Takes a Input_t structure and returns its thresholdLevel.
 *
 * @param i the Input_t whose thresholdLevel is sought.
 *
 * @return the thresholdLevel attribute of the given Input_t, as an @c int.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_getThresholdLevel(Input_t * i);


/**
 * Predicate returning @c true or @c false depending on whether the given
 * Input_t structure's identifier is set.
 *
 * @param i the Input_t structure to query
 * 
 * @return @c non-zero (true) if the "id" attribute of the given
 * Input_t structure is set, zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_isSetId(Input_t * i);


/**
 * Predicate returning @c true or @c false depending on whether the given
 * Input_t structure's qualitativeSpecies is set.
 *
 * @param i the Input_t structure to query
 * 
 * @return @c non-zero (true) if the "qualitativeSpecies" attribute of the given
 * Input_t structure is set, zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_isSetQualitativeSpecies(Input_t * i);


/**
 * Predicate returning @c true or @c false depending on whether the given
 * Input_t structure's transitionEffect is set.
 *
 * @param i the Input_t structure to query
 * 
 * @return @c non-zero (true) if the "transitionEffect" attribute of the given
 * Input_t structure is set, zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_isSetTransitionEffect(Input_t * i);


/**
 * Predicate returning @c true or @c false depending on whether the given
 * Input_t structure's name is set.
 *
 * @param i the Input_t structure to query
 * 
 * @return @c non-zero (true) if the "name" attribute of the given
 * Input_t structure is set, zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_isSetName(Input_t * i);


/**
 * Predicate returning @c true or @c false depending on whether the given
 * Input_t structure's sign is set.
 *
 * @param i the Input_t structure to query
 * 
 * @return @c non-zero (true) if the "sign" attribute of the given
 * Input_t structure is set, zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_isSetSign(Input_t * i);


/**
 * Predicate returning @c true or @c false depending on whether the given
 * Input_t structure's thresholdLevel is set.
 *
 * @param i the Input_t structure to query
 * 
 * @return @c non-zero (true) if the "thresholdLevel" attribute of the given
 * Input_t structure is set, zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_isSetThresholdLevel(Input_t * i);


/**
 * Assigns the identifier of an Input_t structure.
 *
 * This makes a copy of the string passed in the param @p sid.
 *
 * @param i the Input_t structure to set.
 * @param sid the string to use as the identifier.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an id of NULL is equivalent to
 * unsetting the "id" attribute.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_setId(Input_t * i, const char * sid);


/**
 * Sets the qualitativeSpecies of the given Input_t to a copy of @p qualitativeSpecies.
 *
 * @param i the Input_t structure to set
 * @param qualitativeSpecies the qualitativeSpecies to assign to the given Input_t's "qualitativeSpecies" attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "qualitativeSpecies" attribute.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_setQualitativeSpecies(Input_t * i, const char * qualitativeSpecies);


/**
 * Sets the transitionEffect of this Input_t to a copy of the given InputTransitionEffect_t.
 *
 * @param i the Input_t structure to set
 * @param transitionEffect the InputTransitionEffect_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_setTransitionEffect(Input_t * i, InputTransitionEffect_t transitionEffect);


/**
 * Sets the name of the given Input_t to a copy of @p name.
 *
 * @param i the Input_t structure to set
 * @param name the name to assign to the given Input_t's "name" attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "name" attribute.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_setName(Input_t * i, const char * name);


/**
 * Sets the sign of this Input_t to a copy of the given InputSign_t.
 *
 * @param i the Input_t structure to set
 * @param sign the InputSign_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_setSign(Input_t * i, InputSign_t sign);


/**
 * Sets the "thresholdLevel" attribute of the given Input_t
 * structure.
 *
 * @param i the Input_t structure
 * 
 * @param thresholdLevel the value of thresholdLevel to assign to the "thresholdLevel" attribute
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_setThresholdLevel(Input_t * i, int thresholdLevel);


/**
 * Unsets the "id" attribute of the given Input_t structure.
 *
 * @param i the Input_t structure to unset
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_unsetId(Input_t * i);


/**
 * Unsets the "qualitativeSpecies" attribute of the given Input_t structure.
 *
 * @param i the Input_t structure to unset
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_unsetQualitativeSpecies(Input_t * i);


/**
 * Unsets the "transitionEffect" attribute of the given Input_t structure.
 *
 * @param i the Input_t structure to unset
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_unsetTransitionEffect(Input_t * i);


/**
 * Unsets the "name" attribute of the given Input_t structure.
 *
 * @param i the Input_t structure to unset
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_unsetName(Input_t * i);


/**
 * Unsets the "sign" attribute of the given Input_t structure.
 *
 * @param i the Input_t structure to unset
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_unsetSign(Input_t * i);


/**
 * Unsets the "thresholdLevel" attribute of the given Input_t structure.
 *
 * @param i the Input_t structure to unset
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_unsetThresholdLevel(Input_t * i);


/**
  * Predicate returning @c true or @c false depending on whether
  * all the required attributes for the given Input_t structure
  * have been set.
  *
  * @note The required attributes for a Input_t structure are:
  * @li useValuesfromTriggerTime ( L3 onwards )
  *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int
Input_hasRequiredAttributes(Input_t * i);


/**
 * Return the Input_t indicated by the given @p sid.
 *
 * @param lo the ListOf_t structure to use
 *
 * @param sid a string, the identifier of the
 * Input_t is being sought.
 *
 * @return the Input_t for the given variable, or @c NULL if no such
 * Input_t exits.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
Input_t *
ListOfInputs_getById(ListOf_t * lo, const char * sid);


/**
 * Removes the Input_t structure with the given @p sid
 * from the given ListOfInputs_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param lo the ListOf_t structure
 * @param sid the string of the "id" attribute of the Input_t sought
 *
 * @return the Input_t structure removed.  As mentioned above, the 
 * caller owns the returned structure. @c NULL is returned if no Input_t
 * structure with the "id" attribute exists in the given ListOfInputs_t structure.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
Input_t *
ListOfInputs_removeById(ListOf_t * lo, const char * sid);

/**
 * Returns the string version of the provided InputTransitionEffect_t enumeration.
 *
 * @param effect The InputTransitionEffect_t enumeration to convert
 *
 * @return A string corresponding to the given effect:  "none", 
 * "consumption", or NULL if the value is INPUT_TRANSITION_EFFECT_UNKNOWN 
 * or another invalid enumeration value.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
const char* 
InputTransitionEffect_toString(InputTransitionEffect_t effect);

/**
 * Returns the InputTransitionEffect_t enumeration corresponding to 
 * the given string, or INPUT_TRANSITION_EFFECT_UNKNOWN if there is 
 * no such match.  The matching is case-sensitive:  "none" will 
 * return INPUT_TRANSITION_EFFECT_NONE, but "NONE" will return 
 * INPUT_TRANSITION_EFFECT_UNKNOWN.
 *
 * @param s The string to convert to an InputTransitionEffect_t
 *
 * @return The corresponding InputTransitionEffect_t, or 
 * INPUT_TRANSITION_EFFECT_UNKNOWN if no match found.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
InputTransitionEffect_t 
InputTransitionEffect_fromString(const char* s);


/**
 * Predicate returning @c true (non-zero) or @c false (zero) depending on whether the given
 * InputTransitionEffect_t is valid.
 *
 * @param effect the InputTransitionEffect_t enumeration to query
 * 
 * @return @c non-zero (true) if the InputTransitionEffect_t is
 * INPUT_TRANSITION_EFFECT_NONE or INPUT_TRANSITION_EFFECT_CONSUMPTION,
 * zero (false) otherwise (including INPUT_TRANSITION_EFFECT_UNKNOWN).
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int 
InputTransitionEffect_isValidInputTransitionEffect(InputTransitionEffect_t effect);


/**
 * Predicate returning @c true (non-zero) or @c false (zero) depending 
 * on whether the given string is a valid InputTransitionEffect_t.  
 * The matching is case-sensitive:  "none" will return @c true, but 
 * "NONE" will return @c false.
 *
 * @param s The string to query
 * 
 * @return @c non-zero (true) if the string is
 * "none" or "consumption"; zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int 
InputTransitionEffect_isValidInputTransitionEffectString(const char* s);

/**
 * Returns the string version of the provided InputSign_t enumeration.
 *
 * @param effect The InputSign_t enumeration to convert
 *
 * @return A string corresponding to the given effect:  "positive", 
 * "negative", "dual", "unknown", or NULL if the value is INPUT_SIGN_VALUE_NOTSET
 * or some other invalid enumeration value.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
const char* 
InputSign_toString(InputSign_t effect);


/**
 * Returns the InputSign_t enumeration corresponding to 
 * the given string, or INPUT_SIGN_VALUE_NOTSET if there is 
 * no such match.  The matching is case-sensitive:  "negative" will 
 * return INPUT_SIGN_NEGATIVE, but "Negative" will return 
 * INPUT_SIGN_VALUE_NOTSET.
 *
 * @param s The string to convert to an InputSign_t
 *
 * @return The corresponding InputSign_t, or INPUT_SIGN_VALUE_NOTSET if no match found.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
InputSign_t 
InputSign_fromString(const char* s);


/**
 * Predicate returning @c true (non-zero) or @c false (zero) depending on whether the given
 * InputSign_t is valid.
 *
 * @param effect the InputSign_t enumeration to query
 * 
 * @return @c non-zero (true) if the InputSign_t is INPUT_SIGN_POSITIVE, 
 * INPUT_SIGN_NEGATIVE, INPUT_SIGN_DUAL, or INPUT_SIGN_UNKNOWN;
 * zero (false) otherwise (including INPUT_SIGN_VALUE_NOTSET).
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int 
InputSign_isValidInputSign(InputSign_t effect);


/**
 * Predicate returning @c true (non-zero) or @c false (zero) depending 
 * on whether the given string is a valid InputSign_t.  
 * The matching is case-sensitive:  "negative" will return @c true, but 
 * "Negative" will return @c false.
 *
 * @param s The string to query
 * 
 * @return @c non-zero (true) if the string is "positive",
 * "negative", "dual", or "unknown"; zero (false) otherwise.
 *
 * @memberof Input_t
 */
LIBSBML_EXTERN
int 
InputSign_isValidInputSignString(const char* s);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Input_H__  */

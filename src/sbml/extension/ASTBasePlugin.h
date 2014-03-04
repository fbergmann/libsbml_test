/**
 * @cond doxygenLibsbmlInternal
 *
 * @file    ASTBasePlugin.h
 * @brief   Definition of ASTBasePlugin, the base class of extension entities
 *          plugged in AST derived classes in the SBML Core package.
 * @author  Sarah Keating
 *
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2012 jointly by the following organizations: 
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

#ifndef ASTBasePlugin_h
#define ASTBasePlugin_h

#include <sbml/common/libsbml-config-common.h>

#ifndef LIBSBML_USE_LEGACY_MATH

#include <sbml/common/sbmlfwd.h>
#include <sbml/SBMLTypeCodes.h>
#include <sbml/SBMLErrorLog.h>
#include <sbml/math/ASTBase.h>
#include <sbml/SBMLDocument.h>



#ifdef __cplusplus

LIBSBML_CPP_NAMESPACE_BEGIN

class ASTBase;

class LIBSBML_EXTERN ASTBasePlugin
{
public:

  /**
   * Destroy this object.
   */
  virtual ~ASTBasePlugin ();


  /**
   * Assignment operator for ASTBasePlugin.
   */
  ASTBasePlugin& operator=(const ASTBasePlugin& orig);


  /**
   * Creates and returns a deep copy of this ASTBasePlugin object.
   * 
   * @return a (deep) copy of this SBase object
   */
  virtual ASTBasePlugin* clone () const;


  /**
   * Returns the XML namespace (URI) of the package extension
   * of this plugin object.
   *
   * @return the URI of the package extension of this plugin object.
   */
  const std::string& getElementNamespace() const;


  /**
   * Returns the prefix of the package extension of this plugin object.
   *
   * @return the prefix of the package extension of this plugin object.
   */
  virtual const std::string& getPrefix() const;


  /**
   * Returns the package name of this plugin object.
   *
   * @return the package name of this plugin object.
   */
  const std::string& getPackageName() const;




  /* open doxygen comment */

  // ---------------------------------------------------------
  //
  // virtual functions (internal implementation) which should 
  // be overridden by subclasses.
  //
  // ---------------------------------------------------------

  virtual int setSBMLExtension (const SBMLExtension* ext);

  virtual int setPrefix (const std::string& prefix);
  /**
   * Sets the parent SBML object of this plugin object to
   * this object and child elements (if any).
   * (Creates a child-parent relationship by this plugin object)
   *
   * This function is called when this object is created by
   * the parent element.
   * Subclasses must override this this function if they have one
   * or more child elements. Also, ASTBasePlugin::connectToParent(@if java SBase *sbase@endif)
   * must be called in the overridden function.
   *
   * @param sbase the SBase object to use
   *
   * @see setSBMLDocument
   * @see enablePackageInternal
   */
  virtual void connectToParent (ASTBase *astbase);


  /**
   * Enables/Disables the given package with child elements in this plugin 
   * object (if any).
   * (This is an internal implementation invoked from 
   *  SBase::enablePackageInternal() function)
   *
   * Subclasses which contain one or more SBase derived elements should 
   * override this function if elements defined in them can be extended by
   * some other package extension.
   *
   * @see setSBMLDocument
   * @see connectToParent
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix, bool flag);


  virtual bool stripPackage(const std::string& pkgPrefix, bool flag);


  /* end doxygen comment */

  // ----------------------------------------------------------


  /**
   * Gets the URI to which this element belongs to.
   * For example, all elements that belong to SBML Level 3 Version 1 Core
   * must would have the URI "http://www.sbml.org/sbml/level3/version1/core"; 
   * all elements that belong to Layout Extension Version 1 for SBML Level 3
   * Version 1 Core must would have the URI
   * "http://www.sbml.org/sbml/level3/version1/layout/version1/"
   *
   * Unlike getElementNamespace, this function first returns the URI for this 
   * element by looking into the SBMLNamespaces object of the document with 
   * the its package name. if not found it will return the result of 
   * getElementNamespace
   *
   * @return the URI this elements  
   *
   * @see getPackageName
   * @see getElementNamespace
   * @see SBMLDocument::getSBMLNamespaces
   * @see getSBMLDocument
   */
  std::string getURI() const;

  /* open doxygen comment */

  /**
   * Returns the parent ASTNode object to which this plugin 
   * object connected.
   *
   * @return the parent ASTNode object to which this plugin 
   * object connected.
   */
  ASTBase* getParentASTObject ();

  /* end doxygen comment */

  /* open doxygen comment */

  /**
   * Returns the parent ASTNode object to which this plugin 
   * object connected.
   *
   * @return the parent ASTNode object to which this plugin 
   * object connected.
   */
  const ASTBase* getParentASTObject () const;

  
  /* end doxygen comment */

  /**
   * Sets the XML namespace to which this element belongs to.
   * For example, all elements that belong to SBML Level 3 Version 1 Core
   * must set the namespace to "http://www.sbml.org/sbml/level3/version1/core"; 
   * all elements that belong to Layout Extension Version 1 for SBML Level 3
   * Version 1 Core must set the namespace to 
   * "http://www.sbml.org/sbml/level3/version1/layout/version1/"
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE @endlink
   */
  int setElementNamespace(const std::string &uri);

  /**
   * Returns the SBML level of the package extension of 
   * this plugin object.
   *
   * @return the SBML level of the package extension of
   * this plugin object.
   */
  unsigned int getLevel() const;


  /**
   * Returns the SBML version of the package extension of
   * this plugin object.
   *
   * @return the SBML version of the package extension of
   * this plugin object.
   */
  unsigned int getVersion() const;


  /**
   * Returns the package version of the package extension of
   * this plugin object.
   *
   * @return the package version of the package extension of
   * this plugin object.
   */
  unsigned int getPackageVersion() const;


  
  /* open doxygen comment */
  virtual SBMLNamespaces * getSBMLNamespaces() const;


  virtual bool isSetMath() const;

  virtual const ASTBase * getMath() const;

  virtual void createMath(int type);

  virtual int addChild(ASTBase * child);

  virtual ASTBase* getChild (unsigned int n) const;

  virtual unsigned int getNumChildren() const;

  virtual int insertChild(unsigned int n, ASTBase* newChild);

  virtual int prependChild(ASTBase* newChild);

  virtual int removeChild(unsigned int n);

  virtual int replaceChild(unsigned int n, ASTBase* newChild);



  virtual bool read(XMLInputStream& stream, const std::string& reqd_prefix,
                                            const XMLToken& currentElement);
  virtual void addExpectedAttributes(ExpectedAttributes& attributes, 
                                     XMLInputStream& stream, int type);

  virtual bool readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes,
                               XMLInputStream& stream, const XMLToken& element,
                               int type);

  virtual void writeAttributes(XMLOutputStream& stream, int type) const;

  virtual void writeXMLNS(XMLOutputStream& stream) const;

  virtual bool isNumberNode(int type) const;
  virtual bool isFunctionNode(int type) const;

  virtual bool isLogical(int type) const;
  virtual bool isConstantNumber(int type) const;
  virtual bool isCSymbolFunction(int type) const;
  virtual bool isCSymbolNumber(int type) const;
  virtual bool isName(int type) const;
  virtual bool isNumber(int type) const;
  virtual bool isOperator(int type) const;
  virtual bool isRelational(int type) const;
  virtual bool representsQualifier(int type) const;

  virtual bool isFunction(int type) const;
  virtual bool representsUnaryFunction(int type) const;
  virtual bool representsBinaryFunction(int type) const;
  virtual bool representsNaryFunction(int type) const;
  
  virtual bool isTopLevelMathMLFunctionNodeTag(const std::string& name) const;

  virtual bool isTopLevelMathMLNumberNodeTag(const std::string& name) const;
  
  virtual int getTypeFromName(const std::string& name) const;

  virtual const char * getNameFromType(int type) const;

  /* end doxygen comment */

protected:
  /* open doxygen comment */
  /**
   * Constructor. Creates an ASTBasePlugin object with the URI and 
   * prefix of an package extension.
   */
  ASTBasePlugin (const std::string &uri);

  ASTBasePlugin ();

  /**
   * Copy constructor. Creates a copy of this SBase object.
   */
  ASTBasePlugin(const ASTBasePlugin& orig);


  /*-- data members --*/

  //
  // An SBMLExtension derived object of corresponding package extension
  // The owner of this object is SBMLExtensionRegistry class.
  //
  const SBMLExtension  *mSBMLExt;

  //
  // Parent ASTNode object to which this plugin object
  // connected.
  //
  ASTBase                *mParent;

  //
  // XML namespace of corresponding package extension
  //
  std::string          mURI;

  //
  // SBMLNamespaces derived object of this plugin object.
  //
  SBMLNamespaces      *mSBMLNS;

  //
  // Prefix of corresponding package extension
  //
  std::string          mPrefix;

  /* end doxygen comment */
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */

#ifndef SWIG

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* !SWIG */

#endif /* LIBSBML_USE_LEGACY_MATH */

#endif  /* ASTBasePlugin_h */

/** @endcond */


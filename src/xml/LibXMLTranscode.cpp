/**
 * @file    LibXMLTranscode.cpp
 * @brief   Transcodes a LibXML xmlChar string to UTF-8.
 * @author  Akiya Jouraku
 *
 * $Id$
 * $HeadURL$
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2011 jointly by the following organizations: 
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
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sbml/xml/LibXMLTranscode.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal */

static const string NCRAmp = "&#38;"; 

/**
 * replaces each substring of "str" that matches "tstr" with "rstr". 
 */
int replaceAll(string& str, const string& tstr, const string& rstr)
{
  int    count = 0;
  size_t found = 0;
  const size_t tstrlen = tstr.length(); 

  while (1)
  {
    found = str.find(tstr,found);
    if ( found != string::npos )
    {
      str.replace(found, tstrlen, rstr);
      ++count;
    }
    else
    {
      break;
    }
  }
  
  return count;
}


LibXMLTranscode::operator string ()
{
  if (mBuffer == NULL)
  {
    return "";
  }
  else
  {
    string str =  (mLen == -1) ? string(mBuffer) : string(mBuffer, mLen);

    if ( mReplaceNCR )
    {
      //
      // replaces &#38; (numeric character reference of '&') with '&'
      // 
      if ( str.length() >= NCRAmp.length() ) 
        LIBSBML_CPP_NAMESPACE ::replaceAll(str, NCRAmp,"&");
    }

    return str;
  }
}


/** @endcond */

LIBSBML_CPP_NAMESPACE_END


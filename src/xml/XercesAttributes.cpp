/**
 * \file    XercesAttributes.cpp
 * \brief   Creates new XMLAttributes from "raw" Xerces-C++ attributes.
 * \author  Ben Bornstein
 *
 * $Id$
 * $Source$
 */
/* Copyright 2006 California Institute of Technology and Japan Science and
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


#include <string>
#include "XercesTranscode.h"
#include "XercesAttributes.h"


using namespace std;
using namespace xercesc;


/**
 * Creates a new XMLAttributes set that wraps the given "raw" Xerces-C++
 * Attributes set.
 */
XercesAttributes::XercesAttributes (const Attributes& attrs)
{
  unsigned int size = attrs.getLength();

  mNames .reserve(size);
  mValues.reserve(size);

  for (unsigned int n = 0; n < size; ++n)
  {
    const string            uri   = XercesTranscode( attrs.getURI      (n) );
    const string            name  = XercesTranscode( attrs.getLocalName(n) );
    const string            qname = XercesTranscode( attrs.getQName    (n) );
    const string            value = XercesTranscode( attrs.getValue    (n) );
    const string::size_type pos   = qname.find(":", 0);

    const string prefix = (pos != string::npos) ? qname.substr(0, pos) : "";

    //
    // Skip XML namespace declarations
    //
    if (prefix != "xmlns" && name != "xmlns")
    {
      mNames .push_back( XMLTriple(name, uri, prefix) );
      mValues.push_back( value );
    }
  }
}


/**
 * Destroys this XercesAttributes set.
 */
XercesAttributes::~XercesAttributes ()
{
}

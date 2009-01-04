#
# @file    TestRDFAnnotation.py
# @brief   fomula units data unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Ben Bornstein 
#
# $Id:$
# $HeadURL:$
#
# This test file was converted from src/sbml/test/TestRDFAnnotation.cpp
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2009 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#--------------------------------------------------------------------------->*/
import sys
import unittest
import libsbml

def wrapString(s):
  return s
  pass

class TestRDFAnnotation(unittest.TestCase):

  d = None
  m = None
  XOS = None
  OSS = None

  def equals(self, *x):
    if len(x) == 2:
      return x[0] == x[1]
    elif len(x) == 1:
      return x[0] == self.OSS.str()

  def setUp(self):
    self.OSS = libsbml.ostringstream()
    self.XOS = libsbml.XMLOutputStream(self.OSS)
    filename = "../../annotation/test/test-data/annotation.xml"
    self.d = libsbml.readSBML(filename)
    self.m = self.d.getModel()
    pass  

  def tearDown(self):
    self.d = None
    self.OSS = None
    self.XOS = None
    pass  

  def test_RDFAnnotation_delete(self):
    node = libsbml.RDFAnnotationParser.parseCVTerms(self.m.getCompartment(0))
    n1 = libsbml.RDFAnnotationParser.deleteRDFAnnotation(node)
    expected = wrapString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<annotation/>")
    self.assert_( n1.getNumChildren() == 0 )
    self.assert_( n1.getName() ==  "annotation" )
    n1.write(self.XOS)
    self.assertEqual( True, self.equals(expected) )
    node = None
    pass  

  def test_RDFAnnotation_deleteWithOther(self):
    c = self.m.getCompartment(1)
    node = libsbml.RDFAnnotationParser.deleteRDFAnnotation(c.getAnnotation())
    expected = wrapString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<annotation>\n" + 
    "  <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n" + 
    "    <jd2:header>\n" + 
    "      <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n" + 
    "      <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n" + 
    "      <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n" + 
    "    </jd2:header>\n" + 
    "  </jd2:JDesignerLayout>\n" + 
    "</annotation>")
    node.write(self.XOS)
    self.assertEqual( True, self.equals(expected) )
    pass  

  def test_RDFAnnotation_deleteWithOutOther(self):
    c = self.m.getCompartment(2)
    node = c.getAnnotation()
    expected = wrapString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<annotation>\n" + 
    "  <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n" + 
    "    <jd2:header>\n" + 
    "      <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n" + 
    "      <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n" + 
    "      <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n" + 
    "    </jd2:header>\n" + 
    "  </jd2:JDesignerLayout>\n" + 
    "</annotation>")
    node.write(self.XOS)
    self.assertEqual( True, self.equals(expected) )
    pass  

  def test_RDFAnnotation_getModelHistory(self):
    self.assertFalse( self.m == 0 )
    history = self.m.getModelHistory()
    self.assert_( history != None )
    mc = (history.getCreator(0))
    self.assert_((  "Le Novere" == mc.getFamilyName() ))
    self.assert_((  "Nicolas" == mc.getGivenName() ))
    self.assert_((  "lenov@ebi.ac.uk" == mc.getEmail() ))
    self.assert_((  "EMBL-EBI" == mc.getOrganisation() ))
    date = history.getCreatedDate()
    self.assert_( date.getYear() == 2005 )
    self.assert_( date.getMonth() == 2 )
    self.assert_( date.getDay() == 2 )
    self.assert_( date.getHour() == 14 )
    self.assert_( date.getMinute() == 56 )
    self.assert_( date.getSecond() == 11 )
    self.assert_( date.getSignOffset() == 0 )
    self.assert_( date.getHoursOffset() == 0 )
    self.assert_( date.getMinutesOffset() == 0 )
    self.assert_((  "2005-02-02T14:56:11Z" == date.getDateAsString() ))
    date = history.getModifiedDate()
    self.assert_( date.getYear() == 2006 )
    self.assert_( date.getMonth() == 5 )
    self.assert_( date.getDay() == 30 )
    self.assert_( date.getHour() == 10 )
    self.assert_( date.getMinute() == 46 )
    self.assert_( date.getSecond() == 2 )
    self.assert_( date.getSignOffset() == 0 )
    self.assert_( date.getHoursOffset() == 0 )
    self.assert_( date.getMinutesOffset() == 0 )
    self.assert_((  "2006-05-30T10:46:02Z" == date.getDateAsString() ))
    pass  

  def test_RDFAnnotation_parseCVTerms(self):
    node = libsbml.RDFAnnotationParser.parseCVTerms(self.m.getCompartment(0))
    self.assert_( node.getNumChildren() == 1 )
    rdf = node.getChild(0)
    self.assert_((  "RDF" == rdf.getName() ))
    self.assert_((  "rdf" == rdf.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == rdf.getURI() ))
    self.assert_( rdf.getNumChildren() == 1 )
    desc = rdf.getChild(0)
    self.assert_((  "Description" == desc.getName() ))
    self.assert_((  "rdf" == desc.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == desc.getURI() ))
    self.assert_( desc.getNumChildren() == 1 )
    is1 = desc.getChild(0)
    self.assert_((  "is" == is1.getName() ))
    self.assert_((  "bqbiol" == is1.getPrefix() ))
    self.assert_( is1.getNumChildren() == 1 )
    Bag = is1.getChild(0)
    self.assert_((  "Bag" == Bag.getName() ))
    self.assert_((  "rdf" == Bag.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == Bag.getURI() ))
    self.assert_( Bag.getNumChildren() == 4 )
    li = Bag.getChild(0)
    self.assert_((  "li" == li.getName() ))
    self.assert_((  "rdf" == li.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li.getURI() ))
    self.assert_( li.getNumChildren() == 0 )
    li1 = Bag.getChild(1)
    self.assert_((  "li" == li1.getName() ))
    self.assert_((  "rdf" == li1.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li1.getURI() ))
    self.assert_( li1.getNumChildren() == 0 )
    li2 = Bag.getChild(2)
    self.assert_((  "li" == li2.getName() ))
    self.assert_((  "rdf" == li2.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li2.getURI() ))
    self.assert_( li2.getNumChildren() == 0 )
    li3 = Bag.getChild(3)
    self.assert_((  "li" == li3.getName() ))
    self.assert_((  "rdf" == li3.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li3.getURI() ))
    self.assert_( li3.getNumChildren() == 0 )
    node = None
    pass  

  def test_RDFAnnotation_parseModelHistory(self):
    node = libsbml.RDFAnnotationParser.parseModelHistory(self.m)
    self.assert_( node.getNumChildren() == 1 )
    rdf = node.getChild(0)
    self.assert_((  "RDF" == rdf.getName() ))
    self.assert_((  "rdf" == rdf.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == rdf.getURI() ))
    self.assert_( rdf.getNumChildren() == 1 )
    desc = rdf.getChild(0)
    self.assert_((  "Description" == desc.getName() ))
    self.assert_((  "rdf" == desc.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == desc.getURI() ))
    self.assert_( desc.getNumChildren() == 3 )
    creator = desc.getChild(0)
    self.assert_((  "creator" == creator.getName() ))
    self.assert_((  "dc" == creator.getPrefix() ))
    self.assert_((  "http://purl.org/dc/elements/1.1/" == creator.getURI() ))
    self.assert_( creator.getNumChildren() == 1 )
    Bag = creator.getChild(0)
    self.assert_((  "Bag" == Bag.getName() ))
    self.assert_((  "rdf" == Bag.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == Bag.getURI() ))
    self.assert_( Bag.getNumChildren() == 1 )
    li = Bag.getChild(0)
    self.assert_((  "li" == li.getName() ))
    self.assert_((  "rdf" == li.getPrefix() ))
    self.assert_((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li.getURI() ))
    self.assert_( li.getNumChildren() == 3 )
    N = li.getChild(0)
    self.assert_((  "N" == N.getName() ))
    self.assert_((  "vCard" == N.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == N.getURI() ))
    self.assert_( N.getNumChildren() == 2 )
    Family = N.getChild(0)
    self.assert_((  "Family" == Family.getName() ))
    self.assert_((  "vCard" == Family.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Family.getURI() ))
    self.assert_( Family.getNumChildren() == 1 )
    Given = N.getChild(1)
    self.assert_((  "Given" == Given.getName() ))
    self.assert_((  "vCard" == Given.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Given.getURI() ))
    self.assert_( Given.getNumChildren() == 1 )
    EMAIL = li.getChild(1)
    self.assert_((  "EMAIL" == EMAIL.getName() ))
    self.assert_((  "vCard" == EMAIL.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == EMAIL.getURI() ))
    self.assert_( EMAIL.getNumChildren() == 1 )
    ORG = li.getChild(2)
    self.assert_((  "ORG" == ORG.getName() ))
    self.assert_((  "vCard" == ORG.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == ORG.getURI() ))
    self.assert_( ORG.getNumChildren() == 1 )
    Orgname = ORG.getChild(0)
    self.assert_((  "Orgname" == Orgname.getName() ))
    self.assert_((  "vCard" == Orgname.getPrefix() ))
    self.assert_((  "http://www.w3.org/2001/vcard-rdf/3.0#" == Orgname.getURI() ))
    self.assert_( Orgname.getNumChildren() == 1 )
    created = desc.getChild(1)
    self.assert_((  "created" == created.getName() ))
    self.assert_((  "dcterms" == created.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == created.getURI() ))
    self.assert_( created.getNumChildren() == 1 )
    cr_date = created.getChild(0)
    self.assert_((  "W3CDTF" == cr_date.getName() ))
    self.assert_((  "dcterms" == cr_date.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == cr_date.getURI() ))
    self.assert_( cr_date.getNumChildren() == 1 )
    modified = desc.getChild(2)
    self.assert_((  "modified" == modified.getName() ))
    self.assert_((  "dcterms" == modified.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == modified.getURI() ))
    self.assert_( modified.getNumChildren() == 1 )
    mo_date = created.getChild(0)
    self.assert_((  "W3CDTF" == mo_date.getName() ))
    self.assert_((  "dcterms" == mo_date.getPrefix() ))
    self.assert_((  "http://purl.org/dc/terms/" == mo_date.getURI() ))
    self.assert_( mo_date.getNumChildren() == 1 )
    node = None
    pass  

  def test_RDFAnnotation_recreate(self):
    c = self.m.getCompartment(1)
    expected = wrapString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<compartment id=\"A\">\n" + 
    "  <annotation>\n" + 
    "    <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n" + 
    "      <jd2:header>\n" + 
    "        <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n" + 
    "        <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n" + 
    "        <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n" + 
    "      </jd2:header>\n" + 
    "    </jd2:JDesignerLayout>\n" + 
    "    <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:dcterms=\"http://purl.org/dc/terms/\" xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n" + 
    "      <rdf:Description rdf:about=\"#\">\n" + 
    "        <bqbiol:is>\n" + 
    "          <rdf:Bag>\n" + 
    "            <rdf:li rdf:resource=\"http://www.geneontology.org/#GO:0007274\"/>\n" + 
    "          </rdf:Bag>\n" + 
    "        </bqbiol:is>\n" + 
    "      </rdf:Description>\n" + 
    "    </rdf:RDF>\n" + 
    "  </annotation>\n" + 
    "</compartment>")
    c.write(self.XOS)
    self.assertEqual( True, self.equals(expected) )
    pass  

  def test_RDFAnnotation_recreateFromEmpty(self):
    c = self.m.getCompartment(3)
    expected = wrapString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<compartment id=\"C\">\n" + 
    "  <annotation>\n" + 
    "    <rdf:RDF xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:dcterms=\"http://purl.org/dc/terms/\" xmlns:vCard=\"http://www.w3.org/2001/vcard-rdf/3.0#\" xmlns:bqbiol=\"http://biomodels.net/biology-qualifiers/\" xmlns:bqmodel=\"http://biomodels.net/model-qualifiers/\">\n" + 
    "      <rdf:Description rdf:about=\"#\">\n" + 
    "        <bqbiol:is>\n" + 
    "          <rdf:Bag>\n" + 
    "            <rdf:li rdf:resource=\"http://www.geneontology.org/#GO:0007274\"/>\n" + 
    "          </rdf:Bag>\n" + 
    "        </bqbiol:is>\n" + 
    "      </rdf:Description>\n" + 
    "    </rdf:RDF>\n" + 
    "  </annotation>\n" + 
    "</compartment>")
    c.write(self.XOS)
    self.assertEqual( True, self.equals(expected) )
    pass  

  def test_RDFAnnotation_recreateWithOutOther(self):
    c = self.m.getCompartment(2)
    expected = wrapString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<compartment id=\"B\">\n" + 
    "  <annotation>\n" + 
    "    <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n" + 
    "      <jd2:header>\n" + 
    "        <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n" + 
    "        <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n" + 
    "        <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n" + 
    "      </jd2:header>\n" + 
    "    </jd2:JDesignerLayout>\n" + 
    "  </annotation>\n" + 
    "</compartment>")
    c.write(self.XOS)
    self.assertEqual( True, self.equals(expected) )
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestRDFAnnotation))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

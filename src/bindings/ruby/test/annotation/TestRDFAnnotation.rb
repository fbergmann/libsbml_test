#
# @file    TestRDFAnnotation.rb
# @brief   fomula units data unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
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
# Copyright 2005-2008 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#--------------------------------------------------------------------------->*/
require 'test/unit'
require 'libSBML'

class TestRDFAnnotation < Test::Unit::TestCase

  def util_NaN
    z = 0.0
    return 0.0/z
  end

  def util_PosInf
    z = 0.0
    return 1.0/z
  end

  def util_NegInf
    z = 0.0
    return -1.0/z
  end

  def equals(*x)
    case x.size
    when 2
      e, s = x
      return e == s
    when 1
      e, = x
      return e == @@oss.str()
    end
  end

  def setup
    @@oss = LibSBML::Ostringstream.new()
    @@xos = LibSBML::XMLOutputStream.new(@@oss)
    filename = "../../annotation/test/test-data/annotation.xml"
    @@d = LibSBML::readSBML(filename)
    @@m = @@d.getModel()
  end

  def teardown
    @@d = nil
    @@oss = nil
    @@xos = nil
  end

  def test_RDFAnnotation_delete
    node = LibSBML::RDFAnnotationParser.parseCVTerms(@@m.getCompartment(0))
    n1 = LibSBML::RDFAnnotationParser.deleteRDFAnnotation(node)
    expected = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + "<annotation/>";
    assert( n1.getNumChildren() == 0 )
    assert( n1.getName() ==  "annotation" )
    n1.write(@@xos)
    assert_equal true, equals(expected)
    node = nil
  end

  def test_RDFAnnotation_deleteWithOther
    c = @@m.getCompartment(1)
    node = LibSBML::RDFAnnotationParser.deleteRDFAnnotation(c.getAnnotation())
    expected = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<annotation>\n" + 
    "  <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n" + 
    "    <jd2:header>\n" + 
    "      <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n" + 
    "      <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n" + 
    "      <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n" + 
    "    </jd2:header>\n" + 
    "  </jd2:JDesignerLayout>\n" + 
    "</annotation>"
    node.write(@@xos)
    assert_equal true, equals(expected)
  end

  def test_RDFAnnotation_deleteWithOutOther
    c = @@m.getCompartment(2)
    node = c.getAnnotation()
    expected = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
    "<annotation>\n" + 
    "  <jd2:JDesignerLayout version=\"2.0\" MajorVersion=\"2\" MinorVersion=\"0\" BuildVersion=\"41\">\n" + 
    "    <jd2:header>\n" + 
    "      <jd2:VersionHeader JDesignerVersion=\"2.0\"/>\n" + 
    "      <jd2:ModelHeader Author=\"Mr Untitled\" ModelVersion=\"0.0\" ModelTitle=\"untitled\"/>\n" + 
    "      <jd2:TimeCourseDetails timeStart=\"0\" timeEnd=\"10\" numberOfPoints=\"1000\"/>\n" + 
    "    </jd2:header>\n" + 
    "  </jd2:JDesignerLayout>\n" + 
    "</annotation>"
    node.write(@@xos)
    assert_equal true, equals(expected)
  end

  def test_RDFAnnotation_getModelHistory
    assert( !( @@m == 0) )
    history = @@m.getModelHistory()
    assert( history != nil )
    mc = (history.getCreator(0))
    assert ((  "Le Novere" == mc.getFamilyName() ))
    assert ((  "Nicolas" == mc.getGivenName() ))
    assert ((  "lenov@ebi.ac.uk" == mc.getEmail() ))
    assert ((  "EMBL-EBI" == mc.getOrganisation() ))
    date = history.getCreatedDate()
    assert( date.getYear() == 2005 )
    assert( date.getMonth() == 2 )
    assert( date.getDay() == 2 )
    assert( date.getHour() == 14 )
    assert( date.getMinute() == 56 )
    assert( date.getSecond() == 11 )
    assert( date.getSignOffset() == 0 )
    assert( date.getHoursOffset() == 0 )
    assert( date.getMinutesOffset() == 0 )
    assert ((  "2005-02-02T14:56:11Z" == date.getDateAsString() ))
    date = history.getModifiedDate()
    assert( date.getYear() == 2006 )
    assert( date.getMonth() == 5 )
    assert( date.getDay() == 30 )
    assert( date.getHour() == 10 )
    assert( date.getMinute() == 46 )
    assert( date.getSecond() == 2 )
    assert( date.getSignOffset() == 0 )
    assert( date.getHoursOffset() == 0 )
    assert( date.getMinutesOffset() == 0 )
    assert ((  "2006-05-30T10:46:02Z" == date.getDateAsString() ))
  end

  def test_RDFAnnotation_parseCVTerms
    node = LibSBML::RDFAnnotationParser.parseCVTerms(@@m.getCompartment(0))
    assert( node.getNumChildren() == 1 )
    rdf = node.getChild(0)
    assert ((  "RDF" == rdf.getName() ))
    assert ((  "rdf" == rdf.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == rdf.getURI() ))
    assert( rdf.getNumChildren() == 1 )
    desc = rdf.getChild(0)
    assert ((  "Description" == desc.getName() ))
    assert ((  "rdf" == desc.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == desc.getURI() ))
    assert( desc.getNumChildren() == 1 )
    is1 = desc.getChild(0)
    assert ((  "is" == is1.getName() ))
    assert ((  "bqbiol" == is1.getPrefix() ))
    assert( is1.getNumChildren() == 1 )
    bag = is1.getChild(0)
    assert ((  "Bag" == bag.getName() ))
    assert ((  "rdf" == bag.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == bag.getURI() ))
    assert( bag.getNumChildren() == 4 )
    li = bag.getChild(0)
    assert ((  "li" == li.getName() ))
    assert ((  "rdf" == li.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li.getURI() ))
    assert( li.getNumChildren() == 0 )
    li1 = bag.getChild(1)
    assert ((  "li" == li1.getName() ))
    assert ((  "rdf" == li1.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li1.getURI() ))
    assert( li1.getNumChildren() == 0 )
    li2 = bag.getChild(2)
    assert ((  "li" == li2.getName() ))
    assert ((  "rdf" == li2.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li2.getURI() ))
    assert( li2.getNumChildren() == 0 )
    li3 = bag.getChild(3)
    assert ((  "li" == li3.getName() ))
    assert ((  "rdf" == li3.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li3.getURI() ))
    assert( li3.getNumChildren() == 0 )
    node = nil
  end

  def test_RDFAnnotation_parseModelHistory
    node = LibSBML::RDFAnnotationParser.parseModelHistory(@@m)
    assert( node.getNumChildren() == 1 )
    rdf = node.getChild(0)
    assert ((  "RDF" == rdf.getName() ))
    assert ((  "rdf" == rdf.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == rdf.getURI() ))
    assert( rdf.getNumChildren() == 1 )
    desc = rdf.getChild(0)
    assert ((  "Description" == desc.getName() ))
    assert ((  "rdf" == desc.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == desc.getURI() ))
    assert( desc.getNumChildren() == 3 )
    creator = desc.getChild(0)
    assert ((  "creator" == creator.getName() ))
    assert ((  "dc" == creator.getPrefix() ))
    assert ((  "http://purl.org/dc/elements/1.1/" == creator.getURI() ))
    assert( creator.getNumChildren() == 1 )
    bag = creator.getChild(0)
    assert ((  "Bag" == bag.getName() ))
    assert ((  "rdf" == bag.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == bag.getURI() ))
    assert( bag.getNumChildren() == 1 )
    li = bag.getChild(0)
    assert ((  "li" == li.getName() ))
    assert ((  "rdf" == li.getPrefix() ))
    assert ((  "http://www.w3.org/1999/02/22-rdf-syntax-ns#" == li.getURI() ))
    assert( li.getNumChildren() == 3 )
    n = li.getChild(0)
    assert ((  "N" == n.getName() ))
    assert ((  "vCard" == n.getPrefix() ))
    assert ((  "http://www.w3.org/2001/vcard-rdf/3.0#" == n.getURI() ))
    assert( n.getNumChildren() == 2 )
    family = n.getChild(0)
    assert ((  "Family" == family.getName() ))
    assert ((  "vCard" == family.getPrefix() ))
    assert ((  "http://www.w3.org/2001/vcard-rdf/3.0#" == family.getURI() ))
    assert( family.getNumChildren() == 1 )
    given = n.getChild(1)
    assert ((  "Given" == given.getName() ))
    assert ((  "vCard" == given.getPrefix() ))
    assert ((  "http://www.w3.org/2001/vcard-rdf/3.0#" == given.getURI() ))
    assert( given.getNumChildren() == 1 )
    email = li.getChild(1)
    assert ((  "EMAIL" == email.getName() ))
    assert ((  "vCard" == email.getPrefix() ))
    assert ((  "http://www.w3.org/2001/vcard-rdf/3.0#" == email.getURI() ))
    assert( email.getNumChildren() == 1 )
    org = li.getChild(2)
    assert ((  "ORG" == org.getName() ))
    assert ((  "vCard" == org.getPrefix() ))
    assert ((  "http://www.w3.org/2001/vcard-rdf/3.0#" == org.getURI() ))
    assert( org.getNumChildren() == 1 )
    orgname = org.getChild(0)
    assert ((  "Orgname" == orgname.getName() ))
    assert ((  "vCard" == orgname.getPrefix() ))
    assert ((  "http://www.w3.org/2001/vcard-rdf/3.0#" == orgname.getURI() ))
    assert( orgname.getNumChildren() == 1 )
    created = desc.getChild(1)
    assert ((  "created" == created.getName() ))
    assert ((  "dcterms" == created.getPrefix() ))
    assert ((  "http://purl.org/dc/terms/" == created.getURI() ))
    assert( created.getNumChildren() == 1 )
    cr_date = created.getChild(0)
    assert ((  "W3CDTF" == cr_date.getName() ))
    assert ((  "dcterms" == cr_date.getPrefix() ))
    assert ((  "http://purl.org/dc/terms/" == cr_date.getURI() ))
    assert( cr_date.getNumChildren() == 1 )
    modified = desc.getChild(2)
    assert ((  "modified" == modified.getName() ))
    assert ((  "dcterms" == modified.getPrefix() ))
    assert ((  "http://purl.org/dc/terms/" == modified.getURI() ))
    assert( modified.getNumChildren() == 1 )
    mo_date = created.getChild(0)
    assert ((  "W3CDTF" == mo_date.getName() ))
    assert ((  "dcterms" == mo_date.getPrefix() ))
    assert ((  "http://purl.org/dc/terms/" == mo_date.getURI() ))
    assert( mo_date.getNumChildren() == 1 )
    node = nil
  end

  def test_RDFAnnotation_recreate
    c = @@m.getCompartment(1)
    expected = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
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
    "</compartment>"
    c.write(@@xos)
    assert_equal true, equals(expected)
  end

  def test_RDFAnnotation_recreateFromEmpty
    c = @@m.getCompartment(3)
    expected = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
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
    "</compartment>"
    c.write(@@xos)
    assert_equal true, equals(expected)
  end

  def test_RDFAnnotation_recreateWithOutOther
    c = @@m.getCompartment(2)
    expected = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + 
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
    "</compartment>"
    c.write(@@xos)
    assert_equal true, equals(expected)
  end

end

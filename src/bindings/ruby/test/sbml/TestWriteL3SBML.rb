#
# @file    TestWriteL3SBML.rb
# @brief   Write SBML unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestWriteL3SBML.cpp
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
require 'test/unit'
require 'libSBML'

class TestWriteL3SBML < Test::Unit::TestCase

  def LV_L3v1
    return "level=\"3\" version=\"1\">\n"
  end

  def NS_L3v1
    return "xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" "
  end

  def SBML_END
    return "</sbml>\n"
  end

  def SBML_START
    return "<sbml "
  end

  def XML_START
    return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
  end

  def wrapSBML_L3v1(s)
    r = XML_START()
    r += SBML_START()
    r += NS_L3v1()
    r += LV_L3v1()
    r += s
    r += SBML_END()
    return r
  end

  def wrapXML(s)
    r = XML_START()
    r += s
    return r
  end

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
    @@d = LibSBML::SBMLDocument.new()
    @@d.setLevelAndVersion(3,1)
    @@s = 0
  end

  def teardown
    @@d = nil
    @@s = nil
  end

  def test_SBMLWriter_L3_create
    w = LibSBML::SBMLWriter.new()
    assert( w != nil )
    w = nil
  end

  def test_SBMLWriter_L3_setProgramName
    w = LibSBML::SBMLWriter.new()
    assert( w != nil )
    i = w.setProgramName( "sss")
    assert( i == LibSBML::LIBSBML_OPERATION_SUCCESS )
    i = w.setProgramName("")
    assert( i == LibSBML::LIBSBML_OPERATION_SUCCESS )
    w = nil
  end

  def test_SBMLWriter_L3_setProgramVersion
    w = LibSBML::SBMLWriter.new()
    assert( w != nil )
    i = w.setProgramVersion( "sss")
    assert( i == LibSBML::LIBSBML_OPERATION_SUCCESS )
    i = w.setProgramVersion("")
    assert( i == LibSBML::LIBSBML_OPERATION_SUCCESS )
    w = nil
  end

  def test_WriteL3SBML_Compartment
    expected =  "<compartment id=\"A\" constant=\"true\"/>";
    c = @@d.createModel().createCompartment()
    c.setId("A")
    c.setConstant(true)
    assert_equal true, equals(expected,c.toSBML())
  end

  def test_WriteL3SBML_Compartment_spatialDimensions
    expected = "<compartment id=\"A\" spatialDimensions=\"2.1\" " + "constant=\"false\"/>";
    expected1 =  "<compartment id=\"A\" constant=\"false\"/>";
    c = @@d.createModel().createCompartment()
    c.setId("A")
    c.setConstant(false)
    c.setSpatialDimensions(2.1)
    assert_equal true, equals(expected,c.toSBML())
    c.unsetSpatialDimensions()
    assert_equal true, equals(expected1,c.toSBML())
  end

  def test_WriteL3SBML_Event
    expected =  "<event id=\"e\" useValuesFromTriggerTime=\"true\"/>";
    e = @@d.createModel().createEvent()
    e.setId("e")
    e.setUseValuesFromTriggerTime(true)
    assert_equal true, equals(expected,e.toSBML())
  end

  def test_WriteL3SBML_INF
    expected = "<parameter id=\"p\" value=\"INF\"" + " constant=\"true\"/>";
    p = @@d.createModel().createParameter()
    p.setId("p")
    p.setValue(util_PosInf())
    assert_equal true, equals(expected,p.toSBML())
  end

  def test_WriteL3SBML_KineticLaw_ListOfParameters
    expected = "<kineticLaw>\n" + 
    "  <listOfLocalParameters>\n" + 
    "    <localParameter id=\"n\" value=\"1.2\"/>\n" + 
    "  </listOfLocalParameters>\n" + 
    "</kineticLaw>"
    kl = @@d.createModel().createReaction().createKineticLaw()
    p = kl.createLocalParameter()
    p.setId("n")
    p.setValue(1.2)
    kl.addLocalParameter(p)
    assert_equal true, equals(expected,kl.toSBML())
  end

  def test_WriteL3SBML_Model
    expected = wrapSBML_L3v1("  <model/>\n"  
    )
    m = @@d.createModel("")
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_Model_conversionFactor
    expected = wrapSBML_L3v1("  <model conversionFactor=\"p\"/>\n"  
    )
    m = @@d.createModel("")
    m.setConversionFactor("p")
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_Model_otherUnits
    expected = wrapSBML_L3v1("  <model volumeUnits=\"litre\" areaUnits=\"area\" lengthUnits=\"metre\"/>\n"  
    )
    m = @@d.createModel("")
    m.setVolumeUnits("litre")
    m.setAreaUnits("area")
    m.setLengthUnits("metre")
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_Model_substanceUnits
    expected = wrapSBML_L3v1("  <model substanceUnits=\"mole\"/>\n"  
    )
    m = @@d.createModel("")
    m.setSubstanceUnits("mole")
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_Model_timeUnits
    expected = wrapSBML_L3v1("  <model timeUnits=\"second\"/>\n"  
    )
    m = @@d.createModel("")
    m.setTimeUnits("second")
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_NaN
    expected = "<parameter id=\"p\" value=\"NaN\"" + " constant=\"true\"/>";
    p = @@d.createModel().createParameter()
    p.setId("p")
    p.setValue(util_NaN())
    assert_equal true, equals(expected,p.toSBML())
  end

  def test_WriteL3SBML_NegINF
    expected = "<parameter id=\"p\" value=\"-INF\"" + " constant=\"true\"/>";
    p = @@d.createModel().createParameter()
    p.setId("p")
    p.setValue(util_NegInf())
    assert_equal true, equals(expected,p.toSBML())
  end

  def test_WriteL3SBML_Parameter
    expected = "<parameter id=\"Km1\" value=\"2.3\"" + " units=\"second\" constant=\"true\"/>";
    p = @@d.createModel().createParameter()
    p.setId("Km1")
    p.setValue(2.3)
    p.setUnits("second")
    p.setConstant(true)
    assert_equal true, equals(expected,p.toSBML())
  end

  def test_WriteL3SBML_Reaction
    expected = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\"/>";
    r = @@d.createModel().createReaction()
    r.setId("r")
    r.setReversible(false)
    r.setFast(true)
    assert_equal true, equals(expected,r.toSBML())
  end

  def test_WriteL3SBML_Reaction_compartment
    expected = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\" compartment=\"c\"/>";
    expected1 = "<reaction id=\"r\" reversible=\"false\"" + " fast=\"true\"/>";
    r = @@d.createModel().createReaction()
    r.setId("r")
    r.setReversible(false)
    r.setFast(true)
    r.setCompartment("c")
    assert_equal true, equals(expected,r.toSBML())
    r.unsetCompartment()
    assert_equal true, equals(expected1,r.toSBML())
  end

  def test_WriteL3SBML_Reaction_full
    expected = "<reaction id=\"v1\" reversible=\"true\" fast=\"false\">\n" + 
    "  <listOfReactants>\n" + 
    "    <speciesReference species=\"x0\" constant=\"false\"/>\n" + 
    "  </listOfReactants>\n" + 
    "  <listOfProducts>\n" + 
    "    <speciesReference species=\"s1\" constant=\"false\"/>\n" + 
    "  </listOfProducts>\n" + 
    "  <listOfModifiers>\n" + 
    "    <modifierSpeciesReference species=\"m1\"/>\n" + 
    "  </listOfModifiers>\n" + 
    "  <kineticLaw>\n" + 
    "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\">\n" + 
    "      <apply>\n" + 
    "        <divide/>\n" + 
    "        <apply>\n" + 
    "          <times/>\n" + 
    "          <ci> vm </ci>\n" + 
    "          <ci> s1 </ci>\n" + 
    "        </apply>\n" + 
    "        <apply>\n" + 
    "          <plus/>\n" + 
    "          <ci> km </ci>\n" + 
    "          <ci> s1 </ci>\n" + 
    "        </apply>\n" + 
    "      </apply>\n" + 
    "    </math>\n" + 
    "  </kineticLaw>\n" + 
    "</reaction>"
    @@d.createModel()
    r = @@d.getModel().createReaction()
    r.setId("v1")
    r.setReversible(true)
    r.createReactant().setSpecies("x0")
    r.createProduct().setSpecies("s1")
    r.createModifier().setSpecies("m1")
    r.createKineticLaw().setFormula("(vm * s1)/(km + s1)")
    assert_equal true, equals(expected,r.toSBML())
  end

  def test_WriteL3SBML_SBMLDocument_L3v1
    expected = wrapXML("<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" " + "level=\"3\" version=\"1\"/>\n")
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_Species
    expected = "<species id=\"Ca2\" compartment=\"cell\" initialAmount=\"0.7\"" + 
    " substanceUnits=\"mole\" hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"/>"
    s = @@d.createModel().createSpecies()
    s.setId("Ca2")
    s.setCompartment("cell")
    s.setInitialAmount(0.7)
    s.setUnits("mole")
    s.setBoundaryCondition(true)
    s.setHasOnlySubstanceUnits(false)
    s.setConstant(true)
    assert_equal true, equals(expected,s.toSBML())
  end

  def test_WriteL3SBML_SpeciesReference
    expected = "<speciesReference species=\"s\"" + " stoichiometry=\"3\" constant=\"true\"/>";
    sr = @@d.createModel().createReaction().createReactant()
    sr.setSpecies("s")
    sr.setStoichiometry(3)
    sr.setConstant(true)
    assert_equal true, equals(expected,sr.toSBML())
  end

  def test_WriteL3SBML_Species_conversionFactor
    expected = "<species id=\"Ca2\" compartment=\"cell\"" + 
    " hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"" + 
    " conversionFactor=\"p\"/>"
    expected1 = "<species id=\"Ca2\" compartment=\"cell\"" + 
    " hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"true\" constant=\"true\"/>"
    s = @@d.createModel().createSpecies()
    s.setId("Ca2")
    s.setCompartment("cell")
    s.setBoundaryCondition(true)
    s.setHasOnlySubstanceUnits(false)
    s.setConstant(true)
    s.setConversionFactor("p")
    assert_equal true, equals(expected,s.toSBML())
    s.unsetConversionFactor()
    assert_equal true, equals(expected1,s.toSBML())
  end

  def test_WriteL3SBML_Unit
    expected = "<unit kind=\"kilogram\" exponent=\"0.2\"" + " scale=\"-3\" multiplier=\"3.2\"/>";
    u = @@d.createModel().createUnitDefinition().createUnit()
    u.setKind(LibSBML::UNIT_KIND_KILOGRAM)
    exp = 0.2
    u.setExponent(exp)
    u.setScale(-3)
    u.setMultiplier(3.2)
    assert_equal true, equals(expected,u.toSBML())
  end

  def test_WriteL3SBML_UnitDefinition
    expected = "<unitDefinition id=\"myUnit\">\n" + 
    "  <listOfUnits>\n" + 
    "    <unit kind=\"mole\" exponent=\"1\" scale=\"0\" multiplier=\"1.8\"/>\n" + 
    "  </listOfUnits>\n" + 
    "</unitDefinition>"
    ud = @@d.createModel().createUnitDefinition()
    ud.setId("myUnit")
    u1 = ud.createUnit()
    u1.setKind(LibSBML::UnitKind_forName("mole"))
    u1.setMultiplier(1.8)
    u1.setScale(0)
    u1.setExponent(1)
    assert_equal true, equals(expected,ud.toSBML())
  end

  def test_WriteL3SBML_Unit_noValues
    expected = "<unit kind=\"(Invalid UnitKind)\" exponent=\"NaN\"" + " scale=\"2147483647\" multiplier=\"NaN\"/>";
    u = @@d.createModel().createUnitDefinition().createUnit()
    assert_equal true, equals(expected,u.toSBML())
  end

  def test_WriteL3SBML_bzip2
    file = [
                        "../../../examples/sample-models/from-spec/level-3/algebraicrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/assignmentrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/boundarycondition.xml",
                        "../../../examples/sample-models/from-spec/level-3/delay.xml",
                        "../../../examples/sample-models/from-spec/level-3/dimerization.xml",
                        "../../../examples/sample-models/from-spec/level-3/enzymekinetics.xml",
                        "../../../examples/sample-models/from-spec/level-3/events.xml",
                        "../../../examples/sample-models/from-spec/level-3/functiondef.xml",
                        "../../../examples/sample-models/from-spec/level-3/multicomp.xml",
                        "../../../examples/sample-models/from-spec/level-3/overdetermined.xml",
                        "../../../examples/sample-models/from-spec/level-3/twodimensional.xml",
                        "../../../examples/sample-models/from-spec/level-3/units.xml"
    ]
    bz2file = "test.xml.bz2"
    file.each do |f|
      d = LibSBML::readSBML(f)
      assert( d != nil )
      if not LibSBML::SBMLWriter::hasBzip2()
        assert( LibSBML::writeSBML(d,bz2file) == 0 )
        d = nil
        next
      end
      result = LibSBML::writeSBML(d,bz2file)
      assert_equal 1, result
      dg = LibSBML::readSBML(bz2file)
      assert( dg != nil )
      assert( ( dg.toSBML() != d.toSBML() ) == false )
      d = nil
      dg = nil
    end 
  end


  def test_WriteL3SBML_elements
    expected = wrapSBML_L3v1("  <model>\n" + 
    "    <listOfFunctionDefinitions>\n" + 
    "      <functionDefinition/>\n" + 
    "    </listOfFunctionDefinitions>\n" + 
    "    <listOfUnitDefinitions>\n" + 
    "      <unitDefinition/>\n" + 
    "    </listOfUnitDefinitions>\n" + 
    "    <listOfCompartments>\n" + 
    "      <compartment constant=\"true\"/>\n" + 
    "    </listOfCompartments>\n" + 
    "    <listOfSpecies>\n" + 
    "      <species hasOnlySubstanceUnits=\"false\"" + 
    " boundaryCondition=\"false\" constant=\"false\"/>\n" + 
    "    </listOfSpecies>\n" + 
    "    <listOfParameters>\n" + 
    "      <parameter constant=\"true\"/>\n" + 
    "    </listOfParameters>\n" + 
    "    <listOfInitialAssignments>\n" + 
    "      <initialAssignment/>\n" + 
    "    </listOfInitialAssignments>\n" + 
    "    <listOfRules>\n" + 
    "      <algebraicRule/>\n" + 
    "    </listOfRules>\n" + 
    "    <listOfConstraints>\n" + 
    "      <constraint/>\n" + 
    "    </listOfConstraints>\n" + 
    "    <listOfReactions>\n" + 
    "      <reaction reversible=\"true\" fast=\"false\"/>\n" + 
    "    </listOfReactions>\n" + 
    "    <listOfEvents>\n" + 
    "      <event useValuesFromTriggerTime=\"true\"/>\n" + 
    "    </listOfEvents>\n" + 
    "  </model>\n")
    m = @@d.createModel()
    m.createUnitDefinition()
    m.createFunctionDefinition()
    m.createCompartment()
    m.createEvent()
    m.createParameter()
    m.createAlgebraicRule()
    m.createInitialAssignment()
    m.createConstraint()
    m.createReaction()
    m.createSpecies()
    @@s = LibSBML::writeSBMLToString(@@d)
    assert_equal true, equals(expected,@@s)
  end

  def test_WriteL3SBML_error
    d = LibSBML::SBMLDocument.new()
    w = LibSBML::SBMLWriter.new()
    assert_equal false, w.writeSBML(d, "/tmp/impossible/path/should/fail")
    assert( d.getNumErrors() == 1 )
    assert( d.getError(0).getErrorId() == LibSBML::XMLFileUnwritable )
    d = nil
    w = nil
  end

  def test_WriteL3SBML_gzip
    file = [
                        "../../../examples/sample-models/from-spec/level-3/algebraicrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/assignmentrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/boundarycondition.xml",
                        "../../../examples/sample-models/from-spec/level-3/delay.xml",
                        "../../../examples/sample-models/from-spec/level-3/dimerization.xml",
                        "../../../examples/sample-models/from-spec/level-3/enzymekinetics.xml",
                        "../../../examples/sample-models/from-spec/level-3/events.xml",
                        "../../../examples/sample-models/from-spec/level-3/functiondef.xml",
                        "../../../examples/sample-models/from-spec/level-3/multicomp.xml",
                        "../../../examples/sample-models/from-spec/level-3/overdetermined.xml",
                        "../../../examples/sample-models/from-spec/level-3/twodimensional.xml",
                        "../../../examples/sample-models/from-spec/level-3/units.xml"
    ]
    gzfile = "test.xml.gz"
    file.each do |f|
      d = LibSBML::readSBML(f)
      assert( d != nil )
      if not LibSBML::SBMLWriter::hasZlib()
        assert( LibSBML::writeSBML(d,gzfile) == 0 )
        d = nil
        next
      end
      result = LibSBML::writeSBML(d,gzfile)
      assert_equal 1, result
      dg = LibSBML::readSBML(gzfile)
      assert( dg != nil )
      assert( ( dg.toSBML() != d.toSBML() ) == false )
      d = nil
      dg = nil
    end 
  end


  def test_WriteL3SBML_locale
    expected = "<parameter id=\"p\" value=\"3.31\"" + " constant=\"true\"/>";
    p = @@d.createModel().createParameter()
    p.setId("p")
    p.setValue(3.31)
    assert_equal true, equals(expected,p.toSBML())
  end

  def test_WriteL3SBML_zip
    file = [
                        "../../../examples/sample-models/from-spec/level-3/algebraicrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/assignmentrules.xml",
                        "../../../examples/sample-models/from-spec/level-3/boundarycondition.xml",
                        "../../../examples/sample-models/from-spec/level-3/delay.xml",
                        "../../../examples/sample-models/from-spec/level-3/dimerization.xml",
                        "../../../examples/sample-models/from-spec/level-3/enzymekinetics.xml",
                        "../../../examples/sample-models/from-spec/level-3/events.xml",
                        "../../../examples/sample-models/from-spec/level-3/functiondef.xml",
                        "../../../examples/sample-models/from-spec/level-3/multicomp.xml",
                        "../../../examples/sample-models/from-spec/level-3/overdetermined.xml",
                        "../../../examples/sample-models/from-spec/level-3/twodimensional.xml",
                        "../../../examples/sample-models/from-spec/level-3/units.xml"
    ]
    zipfile = "test.xml.zip"
    file.each do |f|
      d = LibSBML::readSBML(f)
      assert( d != nil )
      if not LibSBML::SBMLWriter::hasZlib()
        assert( LibSBML::writeSBML(d,zipfile) == 0 )
        d = nil
        next
      end
      result = LibSBML::writeSBML(d,zipfile)
      assert_equal 1, result
      dg = LibSBML::readSBML(zipfile)
      assert( dg != nil )
      assert( ( dg.toSBML() != d.toSBML() ) == false )
      d = nil
      dg = nil
    end 
  end


end

# @file    TestSBMLConvert.rb
# @brief   SBMLConvert unit tests
#
# @author  Akiya Jouraku (Ruby conversion)
# @author  Ben Bornstein 
#
#
# ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
#
# DO NOT EDIT THIS FILE.
#
# This file was generated automatically by converting the file located at
# src/sbml/test/TestSBMLConvert.c
# using the conversion program dev/utilities/translateTests/translateTests.pl.
# Any changes made here will be lost the next time the file is regenerated.
#
# -----------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2010 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
# -----------------------------------------------------------------------------
require 'test/unit'
require 'libSBML'

class TestSBMLConvert < Test::Unit::TestCase

  def test_SBMLConvert_addModifiersToReaction
    d = LibSBML::SBMLDocument.new(1,2)
    m = d.createModel()
    r = m.createReaction()
    kl = r.createKineticLaw()
    kl.setFormula( "k1*S1*S2*S3*S4*S5")
    s1 = m.createSpecies()
    s1.setId( "S1" )
    s2 = m.createSpecies()
    s2.setId( "S2")
    s3 = m.createSpecies()
    s3.setId( "S3")
    s4 = m.createSpecies()
    s4.setId( "S4")
    s5 = m.createSpecies()
    s5.setId( "S5")
    sr1 = r.createReactant()
    sr2 = r.createReactant()
    sr3 = r.createProduct()
    sr1.setSpecies( "S1")
    sr2.setSpecies( "S2")
    sr3.setSpecies( "S5")
    assert( r.getNumModifiers() == 0 )
    assert( d.setLevelAndVersion(2,1,false) == true )
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 1 )
    assert( m.getReaction(0).getNumModifiers() == 2 )
    ssr1 = m.getReaction(0).getModifier(0)
    ssr2 = m.getReaction(0).getModifier(1)
    assert ((  "S3" == ssr1.getSpecies() ))
    assert ((  "S4" == ssr2.getSpecies() ))
    d = nil
  end

  def test_SBMLConvert_convertFromL3
    d = LibSBML::SBMLDocument.new(3,1)
    m = d.createModel()
    sid =  "C";
    c = m.createCompartment()
    c.setId(sid)
    c.setSize(1.2)
    c.setConstant(true)
    c.setSpatialDimensions(3.4)
    assert( d.setLevelAndVersion(1,1,true) == false )
    assert( d.setLevelAndVersion(1,2,true) == false )
    assert( d.setLevelAndVersion(2,1,true) == false )
    assert( d.setLevelAndVersion(2,2,true) == false )
    assert( d.setLevelAndVersion(2,3,true) == false )
    assert( d.setLevelAndVersion(2,4,true) == false )
    assert( d.setLevelAndVersion(3,1,true) == true )
  end

  def test_SBMLConvert_convertFromL3_conversionFactor
    d = LibSBML::SBMLDocument.new(3,1)
    m = d.createModel()
    sid =  "P";
    m.setConversionFactor(sid)
    c = m.createParameter()
    c.setId(sid)
    c.setConstant(true)
    assert( d.setLevelAndVersion(1,1,true) == false )
    assert( d.setLevelAndVersion(1,2,true) == false )
    assert( d.setLevelAndVersion(2,1,true) == false )
    assert( d.setLevelAndVersion(2,2,true) == false )
    assert( d.setLevelAndVersion(2,3,true) == false )
    assert( d.setLevelAndVersion(2,4,true) == false )
    assert( d.setLevelAndVersion(3,1,true) == true )
  end

  def test_SBMLConvert_convertFromL3_initialValue
    d = LibSBML::SBMLDocument.new(3,1)
    m = d.createModel()
    e = m.createEvent()
    t = e.createTrigger()
    t.setInitialValue(0)
    assert( d.setLevelAndVersion(1,1,false) == false )
    assert( d.setLevelAndVersion(1,2,false) == true )
    assert( d.setLevelAndVersion(2,1,false) == true )
    assert( d.setLevelAndVersion(2,2,false) == true )
    assert( d.setLevelAndVersion(2,3,false) == true )
    assert( d.setLevelAndVersion(2,4,false) == true )
    assert( d.setLevelAndVersion(3,1,false) == true )
  end

  def test_SBMLConvert_convertFromL3_modelUnits
    d = LibSBML::SBMLDocument.new(3,1)
    m = d.createModel()
    m.setVolumeUnits( "litre")
    assert( m.getNumUnitDefinitions() == 0 )
    assert( d.setLevelAndVersion(2,4,false) == true )
    m = d.getModel()
    assert( m.getNumUnitDefinitions() == 1 )
    ud = m.getUnitDefinition(0)
    assert ((  "volume" == ud.getId() ))
    assert( ud.getNumUnits() == 1 )
    assert( ud.getUnit(0).getKind() == LibSBML::UNIT_KIND_LITRE )
  end

  def test_SBMLConvert_convertFromL3_persistent
    d = LibSBML::SBMLDocument.new(3,1)
    m = d.createModel()
    e = m.createEvent()
    t = e.createTrigger()
    t.setPersistent(0)
    assert( d.setLevelAndVersion(1,1,false) == false )
    assert( d.setLevelAndVersion(1,2,false) == true )
    assert( d.setLevelAndVersion(2,1,false) == true )
    assert( d.setLevelAndVersion(2,2,false) == true )
    assert( d.setLevelAndVersion(2,3,false) == true )
    assert( d.setLevelAndVersion(2,4,false) == true )
    assert( d.setLevelAndVersion(3,1,false) == true )
  end

  def test_SBMLConvert_convertFromL3_priority
    d = LibSBML::SBMLDocument.new(3,1)
    m = d.createModel()
    e = m.createEvent()
    p = e.createPriority()
    assert( d.setLevelAndVersion(1,1,false) == false )
    assert( d.setLevelAndVersion(1,2,false) == true )
    assert( d.setLevelAndVersion(2,1,false) == true )
    assert( d.setLevelAndVersion(2,2,false) == true )
    assert( d.setLevelAndVersion(2,3,false) == true )
    assert( d.setLevelAndVersion(2,4,false) == true )
    assert( d.setLevelAndVersion(3,1,false) == true )
  end

  def test_SBMLConvert_convertToL1_SBMLDocument
    d = LibSBML::SBMLDocument.new(2,1)
    assert( d.setLevelAndVersion(1,2,false) == true )
    assert( d.getLevel() == 1 )
    assert( d.getVersion() == 2 )
    d = nil
  end

  def test_SBMLConvert_convertToL1_Species_Amount
    d = LibSBML::SBMLDocument.new(2,1)
    m = d.createModel()
    sid =  "C";
    c = LibSBML::Compartment.new(2,4)
    s = LibSBML::Species.new(2,4)
    c.setId(sid)
    m.addCompartment(c)
    s.setCompartment(sid)
    s.setInitialAmount(2.34)
    m.addSpecies(s)
    assert( d.setLevelAndVersion(1,2,true) == true )
    assert( s.getInitialAmount() == 2.34 )
    d = nil
  end

  def test_SBMLConvert_convertToL1_Species_Concentration
    d = LibSBML::SBMLDocument.new(2,1)
    m = d.createModel()
    sid =  "C";
    c = LibSBML::Compartment.new(2,1)
    s = LibSBML::Species.new(2,1)
    c.setId(sid)
    c.setSize(1.2)
    m.addCompartment(c)
    s.setId( "s"  )
    s.setCompartment(sid)
    s.setInitialConcentration(2.34)
    m.addSpecies(s)
    assert( d.setLevelAndVersion(1,2,true) == true )
    s1 = m.getSpecies(0)
    assert( s1 != nil )
    assert ((  "C" == s1.getCompartment() ))
    assert( m.getCompartment( "C").getSize() == 1.2 )
    assert( s1.getInitialConcentration() == 2.34 )
    assert( s1.isSetInitialConcentration() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL2_SBMLDocument
    d = LibSBML::SBMLDocument.new(1,2)
    assert( d.setLevelAndVersion(2,1,false) == true )
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 1 )
    assert( d.setLevelAndVersion(2,2,false) == true )
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 2 )
    assert( d.setLevelAndVersion(2,3,false) == true )
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 3 )
    d = nil
  end

  def test_SBMLConvert_convertToL2v4_DuplicateAnnotations_doc
    d = LibSBML::SBMLDocument.new(2,1)
    d.createModel()
    annotation =  "<rdf/>\n<rdf/>";
    i = (d).setAnnotation(annotation)
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 1 )
    assert( (d).getAnnotation().getNumChildren() == 2 )
    assert( d.setLevelAndVersion(2,4,true) == true )
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 4 )
    assert( (d).getAnnotation().getNumChildren() == 1 )
    d = nil
  end

  def test_SBMLConvert_convertToL2v4_DuplicateAnnotations_model
    d = LibSBML::SBMLDocument.new(2,1)
    m = d.createModel()
    annotation =  "<rdf/>\n<rdf/>";
    i = (m).setAnnotation(annotation)
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 1 )
    assert( (m).getAnnotation().getNumChildren() == 2 )
    assert( d.setLevelAndVersion(2,4,true) == true )
    assert( d.getLevel() == 2 )
    assert( d.getVersion() == 4 )
    m = d.getModel()
    assert( (m).getAnnotation().getNumChildren() == 1 )
    d = nil
  end

  def test_SBMLConvert_convertToL3_compartment
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    sid =  "C";
    c = m.createCompartment()
    c.setId(sid)
    assert( d.setLevelAndVersion(3,1,false) == true )
    c1 = m.getCompartment(0)
    assert( c1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_defaultUnits
    d = LibSBML::SBMLDocument.new(1,2)
    m = d.createModel()
    sid =  "C";
    c = m.createCompartment()
    c.setId(sid)
    c.setSize(1.2)
    c.setUnits( "volume")
    assert( m.getNumUnitDefinitions() == 0 )
    assert( d.setLevelAndVersion(3,1,true) == true )
    assert( m.getNumUnitDefinitions() == 2 )
    ud = m.getUnitDefinition(0)
    assert( ud != nil )
    assert ((  "volume" == ud.getId() ))
    assert( ud.getNumUnits() == 1 )
    u = ud.getUnit(0)
    assert( u.getKind() == LibSBML::UNIT_KIND_LITRE )
    assert( u.getExponent() == 1 )
    assert( u.getMultiplier() == 1 )
    assert( u.getScale() == 0 )
    ud = m.getUnitDefinition(1)
    assert( ud != nil )
    assert ((  "time" == ud.getId() ))
    assert( ud.getNumUnits() == 1 )
    u = ud.getUnit(0)
    assert( u.getKind() == LibSBML::UNIT_KIND_SECOND )
    assert( u.getExponent() == 1 )
    assert( u.getMultiplier() == 1 )
    assert( u.getScale() == 0 )
    assert ((  "time" == m.getTimeUnits() ))
    d = nil
  end

  def test_SBMLConvert_convertToL3_event
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    e = m.createEvent()
    assert( d.setLevelAndVersion(3,1,false) == true )
    e1 = m.getEvent(0)
    assert( e1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_localParameters
    d = LibSBML::SBMLDocument.new(1,2)
    m = d.createModel()
    c = m.createCompartment()
    c.setId( "c" )
    s = m.createSpecies()
    s.setId( "s")
    s.setCompartment( "c")
    r = m.createReaction()
    sr = r.createReactant()
    sr.setSpecies( "s")
    kl = r.createKineticLaw()
    kl.setFormula( "s*k")
    p = kl.createParameter()
    p.setId( "k")
    assert( kl.getNumLocalParameters() == 0 )
    assert( d.setLevelAndVersion(3,1,false) == true )
    m = d.getModel()
    r = m.getReaction(0)
    kl = r.getKineticLaw()
    assert( kl.getNumLocalParameters() == 1 )
    lp = kl.getLocalParameter(0)
    d = nil
  end

  def test_SBMLConvert_convertToL3_parameter
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    sid =  "C";
    p = m.createParameter()
    p.setId(sid)
    assert( d.setLevelAndVersion(3,1,false) == true )
    p1 = m.getParameter(0)
    assert( p1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_product
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    r = m.createReaction()
    sr = r.createProduct()
    sr.setSpecies( "s" )
    assert( d.setLevelAndVersion(3,1,false) == true )
    sr1 = m.getReaction(0).getProduct(0)
    assert( sr1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_reactant
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    r = m.createReaction()
    sr = r.createReactant()
    sr.setSpecies( "s" )
    assert( d.setLevelAndVersion(3,1,false) == true )
    sr1 = m.getReaction(0).getReactant(0)
    assert( sr1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_reaction
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    sid =  "C";
    r = m.createReaction()
    r.setId(sid)
    assert( d.setLevelAndVersion(3,1,false) == true )
    r1 = m.getReaction(0)
    assert( r1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_species
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    sid =  "C";
    s = m.createSpecies()
    s.setId(sid)
    s.setCompartment( "comp")
    assert( d.setLevelAndVersion(3,1,false) == true )
    s1 = m.getSpecies(0)
    assert( s1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_stoichiometryMath
    d = LibSBML::SBMLDocument.new(2,1)
    m = d.createModel()
    c = m.createCompartment()
    c.setId( "c" )
    s = m.createSpecies()
    s.setId( "s")
    s.setCompartment( "c")
    r = m.createReaction()
    sr = r.createReactant()
    sr.setSpecies( "s")
    sm = sr.createStoichiometryMath()
    ast = LibSBML::parseFormula("c*2")
    sm.setMath(ast)
    assert( m.getNumRules() == 0 )
    assert( sr.isSetId() == false )
    assert( d.setLevelAndVersion(3,1,false) == true )
    m = d.getModel()
    r = m.getReaction(0)
    sr = r.getReactant(0)
    assert( m.getNumRules() == 1 )
    assert( sr.isSetId() == true )
    rule = m.getRule(0)
    assert( sr.getId() == rule.getVariable() )
    d = nil
  end

  def test_SBMLConvert_convertToL3_trigger
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    e = m.createEvent()
    t = e.createTrigger()
    assert( d.setLevelAndVersion(3,1,false) == true )
    t1 = m.getEvent(0).getTrigger()
    assert( t1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_convertToL3_unit
    d = LibSBML::SBMLDocument.new(2,2)
    m = d.createModel()
    sid =  "C";
    ud = m.createUnitDefinition()
    ud.setId(sid)
    u = ud.createUnit()
    u.setKind(LibSBML::UNIT_KIND_MOLE)
    assert( d.setLevelAndVersion(3,1,false) == true )
    u1 = m.getUnitDefinition(0).getUnit(0)
    assert( u1.hasRequiredAttributes() == true )
    d = nil
  end

  def test_SBMLConvert_invalidLevelVersion
    d = LibSBML::SBMLDocument.new(2,1)
    m = d.createModel()
    sid =  "C";
    c = m.createCompartment()
    c.setId(sid)
    c.setSize(1.2)
    c.setUnits( "volume")
    assert( d.setLevelAndVersion(1,3,true) == false )
    assert( d.setLevelAndVersion(2,5,true) == false )
    assert( d.setLevelAndVersion(3,2,true) == false )
    assert( d.setLevelAndVersion(4,1,true) == false )
  end

end

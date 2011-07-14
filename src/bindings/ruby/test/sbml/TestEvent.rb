# @file    TestEvent.rb
# @brief   SBML Event unit tests
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
# src/sbml/test/TestEvent.c
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

class TestEvent < Test::Unit::TestCase

  def setup
    @@e = LibSBML::Event.new(2,4)
    if (@@e == nil)
    end
  end

  def teardown
    @@e = nil
  end

  def test_Event_create
    assert( @@e.getTypeCode() == LibSBML::SBML_EVENT )
    assert( @@e.getMetaId() == "" )
    assert( @@e.getNotes() == nil )
    assert( @@e.getAnnotation() == nil )
    assert( @@e.getId() == "" )
    assert( @@e.getName() == "" )
    assert( @@e.getTrigger() == nil )
    assert( @@e.getDelay() == nil )
    assert( @@e.getTimeUnits() == "" )
    assert_equal false, @@e.isSetId()
    assert_equal false, @@e.isSetTrigger()
    assert_equal false, @@e.isSetDelay()
    assert_equal true, @@e.isSetUseValuesFromTriggerTime()
    assert( @@e.getNumEventAssignments() == 0 )
  end

  def test_Event_createWithNS
    xmlns = LibSBML::XMLNamespaces.new()
    xmlns.add( "http://www.sbml.org", "testsbml")
    sbmlns = LibSBML::SBMLNamespaces.new(2,4)
    sbmlns.addNamespaces(xmlns)
    object = LibSBML::Event.new(sbmlns)
    assert( object.getTypeCode() == LibSBML::SBML_EVENT )
    assert( object.getMetaId() == "" )
    assert( object.getNotes() == nil )
    assert( object.getAnnotation() == nil )
    assert( object.getLevel() == 2 )
    assert( object.getVersion() == 4 )
    assert( object.getNamespaces() != nil )
    assert( object.getNamespaces().getLength() == 2 )
    object = nil
  end

  def test_Event_free_NULL
  end

  def test_Event_full
    math1 = LibSBML::parseFormula("0")
    trigger = LibSBML::Trigger.new(2,4)
    math = LibSBML::parseFormula("0")
    e = LibSBML::Event.new(2,4)
    ea = LibSBML::EventAssignment.new(2,4)
    ea.setVariable( "k")
    ea.setMath(math)
    trigger.setMath(math1)
    e.setTrigger(trigger)
    e.setId( "e1")
    e.setName( "Set k2 to zero when P1 <= t")
    e.addEventAssignment(ea)
    assert( e.getNumEventAssignments() == 1 )
    assert( e.getEventAssignment(0) != ea )
    math = nil
    e = nil
  end

  def test_Event_removeEventAssignment
    o1 = @@e.createEventAssignment()
    o2 = @@e.createEventAssignment()
    o3 = @@e.createEventAssignment()
    o3.setVariable("test")
    assert( @@e.removeEventAssignment(0) == o1 )
    assert( @@e.getNumEventAssignments() == 2 )
    assert( @@e.removeEventAssignment(0) == o2 )
    assert( @@e.getNumEventAssignments() == 1 )
    assert( @@e.removeEventAssignment("test") == o3 )
    assert( @@e.getNumEventAssignments() == 0 )
    o1 = nil
    o2 = nil
    o3 = nil
  end

  def test_Event_setDelay
    math1 = LibSBML::parseFormula("0")
    delay = LibSBML::Delay.new(2,4)
    delay.setMath(math1)
    @@e.setDelay(delay)
    assert( @@e.getDelay() != nil )
    assert_equal true, @@e.isSetDelay()
    if (@@e.getDelay() == delay)
    end
    @@e.setDelay(@@e.getDelay())
    assert( @@e.getDelay() != delay )
    @@e.setDelay(nil)
    assert_equal false, @@e.isSetDelay()
    if (@@e.getDelay() != nil)
    end
  end

  def test_Event_setId
    id =  "e1";
    @@e.setId(id)
    assert (( id == @@e.getId() ))
    assert_equal true, @@e.isSetId()
    if (@@e.getId() == id)
    end
    @@e.setId(@@e.getId())
    assert (( id == @@e.getId() ))
    @@e.setId("")
    assert_equal false, @@e.isSetId()
    if (@@e.getId() != nil)
    end
  end

  def test_Event_setName
    name =  "Set_k2";
    @@e.setName(name)
    assert (( name == @@e.getName() ))
    assert_equal true, @@e.isSetName()
    if (@@e.getName() == name)
    end
    @@e.setName(@@e.getName())
    assert (( name == @@e.getName() ))
    @@e.setName("")
    assert_equal false, @@e.isSetName()
    if (@@e.getName() != nil)
    end
  end

  def test_Event_setTimeUnits
    e1 = LibSBML::Event.new(2,1)
    units =  "second";
    e1.setTimeUnits(units)
    assert (( units == e1.getTimeUnits() ))
    assert_equal true, e1.isSetTimeUnits()
    if (e1.getTimeUnits() == units)
    end
    e1.setTimeUnits(e1.getTimeUnits())
    assert (( units == e1.getTimeUnits() ))
    e1.setTimeUnits("")
    assert_equal false, e1.isSetTimeUnits()
    if (e1.getTimeUnits() != nil)
    end
    e1 = nil
  end

  def test_Event_setTrigger
    math1 = LibSBML::parseFormula("0")
    trigger = LibSBML::Trigger.new(2,4)
    trigger.setMath(math1)
    @@e.setTrigger(trigger)
    assert( @@e.getTrigger() != nil )
    assert_equal true, @@e.isSetTrigger()
    if (@@e.getTrigger() == trigger)
    end
    @@e.setTrigger(@@e.getTrigger())
    assert( @@e.getTrigger() != trigger )
    @@e.setTrigger(nil)
    assert_equal false, @@e.isSetTrigger()
    if (@@e.getTrigger() != nil)
    end
  end

  def test_Event_setUseValuesFromTriggerTime
    object = LibSBML::Event.new(2,4)
    object.setUseValuesFromTriggerTime(false)
    assert( object.getUseValuesFromTriggerTime() == false )
    object.setUseValuesFromTriggerTime(true)
    assert( object.getUseValuesFromTriggerTime() == true )
    object = nil
  end

end

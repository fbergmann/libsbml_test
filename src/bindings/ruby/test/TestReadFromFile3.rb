#
# @file    TestReadFromFile3.rb
# @brief   Reads tests/l1v1-rules.xml into memory and tests it.
# @author  Akiya Jouraku (Ruby conversion)
# @author  Ben Bornstein 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestReadFromFile3.c
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

class TestReadFromFile3 < Test::Unit::TestCase

  def test_read_l1v1_rules
    filename = "../../sbml/test/test-data/l1v1-rules.xml"
    d = LibSBML::readSBML(filename)
    if (d == nil)
    end
    assert( d.getLevel == 1 )
    assert( d.getVersion == 1 )
    m = d.getModel
    assert( m.getNumCompartments == 1 )
    c = m.getCompartment(0)
    assert ((  "cell" == c.getName ))
    assert( c.getVolume == 1 )
    assert( m.getNumSpecies == 6 )
    s = m.getSpecies(0)
    assert ((  "s1"    == s.getName ))
    assert ((  "cell"  == s.getCompartment ))
    assert( s.getInitialAmount == 4 )
    assert( s.getBoundaryCondition == false )
    s = m.getSpecies(1)
    assert ((  "s2"    == s.getName ))
    assert ((  "cell"  == s.getCompartment ))
    assert( s.getInitialAmount == 2 )
    assert( s.getBoundaryCondition == false )
    s = m.getSpecies(2)
    assert ((  "x0"    == s.getName ))
    assert ((  "cell"  == s.getCompartment ))
    assert( s.getInitialAmount == 1 )
    assert( s.getBoundaryCondition == false )
    s = m.getSpecies(3)
    assert ((  "x1"    == s.getName ))
    assert ((  "cell"  == s.getCompartment ))
    assert( s.getInitialAmount == 0 )
    assert( s.getBoundaryCondition == false )
    s = m.getSpecies(4)
    assert ((  "x2"    == s.getName ))
    assert ((  "cell"  == s.getCompartment ))
    assert( s.getInitialAmount == 1 )
    assert( s.getBoundaryCondition == false )
    s = m.getSpecies(5)
    assert ((  "x3"    == s.getName ))
    assert ((  "cell"  == s.getCompartment ))
    assert( s.getInitialAmount == 0 )
    assert( s.getBoundaryCondition == false )
    assert( m.getNumParameters == 7 )
    p = m.getParameter(0)
    assert ((  "k1" == p.getName ))
    assert( p.getValue == 1.2 )
    p = m.getParameter(1)
    assert ((  "k2" == p.getName ))
    assert( p.getValue == 1000 )
    p = m.getParameter(2)
    assert ((  "k3" == p.getName ))
    assert( p.getValue == 3000 )
    p = m.getParameter(3)
    assert ((  "k4" == p.getName ))
    assert( p.getValue == 4.5 )
    assert( m.getNumRules == 4 )
    pr = m.getRule(0)
    assert ((  "t" == pr.getVariable ))
    assert ((  "s1 + s2" == pr.getFormula ))
    ud = pr.getDerivedUnitDefinition
    assert( ud.getNumUnits == 2 )
    assert( ud.getUnit(0).getKind == LibSBML::UNIT_KIND_MOLE )
    assert( ud.getUnit(0).getExponent == 1 )
    assert( ud.getUnit(1).getKind == LibSBML::UNIT_KIND_LITRE )
    assert( ud.getUnit(1).getExponent == -1 )
    assert( pr.containsUndeclaredUnits == false )
    pr = m.getRule(1)
    assert ((  "k" == pr.getVariable ))
    assert ((  "k3/k2" == pr.getFormula ))
    ud = pr.getDerivedUnitDefinition
    assert( ud.getNumUnits == 0 )
    assert( pr.containsUndeclaredUnits == true )
    scr = m.getRule(2)
    assert ((  "x2" == scr.getVariable ))
    assert ((  "k * (s1+s2)/(1 + k)" == scr.getFormula ))
    scr = m.getRule(3)
    assert ((  "x3" == scr.getVariable ))
    assert ((  "p*(t - s2)" == scr.getFormula ))
    assert( m.getNumReactions == 2 )
    r = m.getReaction(0)
    assert ((  "j1" == r.getName ))
    assert( r.getReversible != false )
    assert( r.getFast == false )
    r = m.getReaction(1)
    assert ((  "j3" == r.getName ))
    assert( r.getReversible != false )
    assert( r.getFast == false )
    r = m.getReaction(0)
    assert( r.getNumReactants == 1 )
    assert( r.getNumProducts == 1 )
    sr = r.getReactant(0)
    assert ((  "x0" == sr.getSpecies ))
    assert( sr.getStoichiometry == 1 )
    assert( sr.getDenominator == 1 )
    sr = r.getProduct(0)
    assert ((  "s1" == sr.getSpecies ))
    assert( sr.getStoichiometry == 1 )
    assert( sr.getDenominator == 1 )
    kl = r.getKineticLaw
    assert ((  "k1 * x0" == kl.getFormula ))
    r = m.getReaction(1)
    assert( r.getNumReactants == 1 )
    assert( r.getNumProducts == 1 )
    sr = r.getReactant(0)
    assert ((  "s2" == sr.getSpecies ))
    assert( sr.getStoichiometry == 1 )
    assert( sr.getDenominator == 1 )
    sr = r.getProduct(0)
    assert ((  "x1" == sr.getSpecies ))
    assert( sr.getStoichiometry == 1 )
    assert( sr.getDenominator == 1 )
    kl = r.getKineticLaw
    assert ((  "k4 * s2" == kl.getFormula ))
    d = nil
  end

end

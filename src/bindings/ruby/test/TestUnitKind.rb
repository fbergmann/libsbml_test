#
# @file    TestUnitKind.rb
# @brief   UnitKind enumeration unit tests
# @author  Akiya Jouraku (Ruby conversion)
# @author  Ben Bornstein 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestUnitKind.c
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
#
require 'test/unit'
require 'libSBML'

class TestUnitKind < Test::Unit::TestCase

  def test_UnitKind_equals
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_AMPERE,LibSBML::UNIT_KIND_AMPERE)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_INVALID,LibSBML::UNIT_KIND_INVALID)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_LITER,LibSBML::UNIT_KIND_LITER)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_LITRE,LibSBML::UNIT_KIND_LITRE)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_METER,LibSBML::UNIT_KIND_METER)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_METRE,LibSBML::UNIT_KIND_METRE)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_LITER,LibSBML::UNIT_KIND_LITRE)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_LITRE,LibSBML::UNIT_KIND_LITER)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_METER,LibSBML::UNIT_KIND_METRE)
    assert_equal 1, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_METRE,LibSBML::UNIT_KIND_METER)
    assert_equal 0, LibSBML::UnitKind_equals(LibSBML::UNIT_KIND_AMPERE,LibSBML::UNIT_KIND_WEBER)
  end

  def test_UnitKind_forName
    assert( LibSBML::UnitKind_forName("ampere") == LibSBML::UNIT_KIND_AMPERE )
    assert( LibSBML::UnitKind_forName("becquerel") == LibSBML::UNIT_KIND_BECQUEREL )
    assert( LibSBML::UnitKind_forName("candela") == LibSBML::UNIT_KIND_CANDELA )
    assert( LibSBML::UnitKind_forName("Celsius") == LibSBML::UNIT_KIND_CELSIUS )
    assert( LibSBML::UnitKind_forName("coulomb") == LibSBML::UNIT_KIND_COULOMB )
    assert( LibSBML::UnitKind_forName("dimensionless") == LibSBML::UNIT_KIND_DIMENSIONLESS )
    assert( LibSBML::UnitKind_forName("farad") == LibSBML::UNIT_KIND_FARAD )
    assert( LibSBML::UnitKind_forName("gram") == LibSBML::UNIT_KIND_GRAM )
    assert( LibSBML::UnitKind_forName("gray") == LibSBML::UNIT_KIND_GRAY )
    assert( LibSBML::UnitKind_forName("henry") == LibSBML::UNIT_KIND_HENRY )
    assert( LibSBML::UnitKind_forName("hertz") == LibSBML::UNIT_KIND_HERTZ )
    assert( LibSBML::UnitKind_forName("item") == LibSBML::UNIT_KIND_ITEM )
    assert( LibSBML::UnitKind_forName("joule") == LibSBML::UNIT_KIND_JOULE )
    assert( LibSBML::UnitKind_forName("katal") == LibSBML::UNIT_KIND_KATAL )
    assert( LibSBML::UnitKind_forName("kelvin") == LibSBML::UNIT_KIND_KELVIN )
    assert( LibSBML::UnitKind_forName("kilogram") == LibSBML::UNIT_KIND_KILOGRAM )
    assert( LibSBML::UnitKind_forName("liter") == LibSBML::UNIT_KIND_LITER )
    assert( LibSBML::UnitKind_forName("litre") == LibSBML::UNIT_KIND_LITRE )
    assert( LibSBML::UnitKind_forName("lumen") == LibSBML::UNIT_KIND_LUMEN )
    assert( LibSBML::UnitKind_forName("lux") == LibSBML::UNIT_KIND_LUX )
    assert( LibSBML::UnitKind_forName("meter") == LibSBML::UNIT_KIND_METER )
    assert( LibSBML::UnitKind_forName("metre") == LibSBML::UNIT_KIND_METRE )
    assert( LibSBML::UnitKind_forName("mole") == LibSBML::UNIT_KIND_MOLE )
    assert( LibSBML::UnitKind_forName("newton") == LibSBML::UNIT_KIND_NEWTON )
    assert( LibSBML::UnitKind_forName("ohm") == LibSBML::UNIT_KIND_OHM )
    assert( LibSBML::UnitKind_forName("pascal") == LibSBML::UNIT_KIND_PASCAL )
    assert( LibSBML::UnitKind_forName("radian") == LibSBML::UNIT_KIND_RADIAN )
    assert( LibSBML::UnitKind_forName("second") == LibSBML::UNIT_KIND_SECOND )
    assert( LibSBML::UnitKind_forName("siemens") == LibSBML::UNIT_KIND_SIEMENS )
    assert( LibSBML::UnitKind_forName("sievert") == LibSBML::UNIT_KIND_SIEVERT )
    assert( LibSBML::UnitKind_forName("steradian") == LibSBML::UNIT_KIND_STERADIAN )
    assert( LibSBML::UnitKind_forName("tesla") == LibSBML::UNIT_KIND_TESLA )
    assert( LibSBML::UnitKind_forName("volt") == LibSBML::UNIT_KIND_VOLT )
    assert( LibSBML::UnitKind_forName("watt") == LibSBML::UNIT_KIND_WATT )
    assert( LibSBML::UnitKind_forName("weber") == LibSBML::UNIT_KIND_WEBER )
    assert( LibSBML::UnitKind_forName(nil) == LibSBML::UNIT_KIND_INVALID )
    assert( LibSBML::UnitKind_forName("") == LibSBML::UNIT_KIND_INVALID )
    assert( LibSBML::UnitKind_forName("foobar") == LibSBML::UNIT_KIND_INVALID )
  end

  def test_UnitKind_isValidUnitKindString
    assert_equal 0, LibSBML::UnitKind_isValidUnitKindString("fun-foam-unit for kids!",1,1)
    assert_equal 1, LibSBML::UnitKind_isValidUnitKindString("litre",2,2)
    assert_equal 0, LibSBML::UnitKind_isValidUnitKindString("liter",2,2)
    assert_equal 1, LibSBML::UnitKind_isValidUnitKindString("liter",1,2)
    assert_equal 0, LibSBML::UnitKind_isValidUnitKindString("meter",2,3)
    assert_equal 1, LibSBML::UnitKind_isValidUnitKindString("metre",2,1)
    assert_equal 1, LibSBML::UnitKind_isValidUnitKindString("meter",1,2)
    assert_equal 1, LibSBML::UnitKind_isValidUnitKindString("Celsius",2,1)
    assert_equal 0, LibSBML::UnitKind_isValidUnitKindString("Celsius",2,2)
  end

  def test_UnitKind_toString
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_AMPERE)
    assert ((  "ampere" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_BECQUEREL)
    assert ((  "becquerel" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_CANDELA)
    assert ((  "candela" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_CELSIUS)
    assert ((  "Celsius" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_COULOMB)
    assert ((  "coulomb" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_DIMENSIONLESS)
    assert ((  "dimensionless" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_FARAD)
    assert ((  "farad" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_GRAM)
    assert ((  "gram" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_GRAY)
    assert ((  "gray" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_HENRY)
    assert ((  "henry" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_HERTZ)
    assert ((  "hertz" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_ITEM)
    assert ((  "item" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_JOULE)
    assert ((  "joule" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_KATAL)
    assert ((  "katal" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_KELVIN)
    assert ((  "kelvin" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_KILOGRAM)
    assert ((  "kilogram" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_LITER)
    assert ((  "liter" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_LITRE)
    assert ((  "litre" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_LUMEN)
    assert ((  "lumen" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_LUX)
    assert ((  "lux" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_METER)
    assert ((  "meter" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_METRE)
    assert ((  "metre" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_MOLE)
    assert ((  "mole" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_NEWTON)
    assert ((  "newton" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_OHM)
    assert ((  "ohm" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_PASCAL)
    assert ((  "pascal" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_RADIAN)
    assert ((  "radian" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_SECOND)
    assert ((  "second" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_SIEMENS)
    assert ((  "siemens" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_SIEVERT)
    assert ((  "sievert" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_STERADIAN)
    assert ((  "steradian" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_TESLA)
    assert ((  "tesla" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_VOLT)
    assert ((  "volt" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_WATT)
    assert ((  "watt" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_WEBER)
    assert ((  "weber" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_INVALID)
    assert ((  "(Invalid UnitKind)" == s ))
    s = LibSBML::UnitKind_toString(-1)
    assert ((  "(Invalid UnitKind)" == s ))
    s = LibSBML::UnitKind_toString(LibSBML::UNIT_KIND_INVALID + 1)
    assert ((  "(Invalid UnitKind)" == s ))
  end

end

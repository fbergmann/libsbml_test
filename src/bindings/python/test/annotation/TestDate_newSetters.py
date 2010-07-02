#
# @file    TestDate_newSetters.py
# @brief   Date unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating 
#
# $Id$
# $HeadURL$
#
# This test file was converted from src/sbml/test/TestDate_newSetters.c
# with the help of conversion sciprt (ctest_converter.pl).
#
#<!---------------------------------------------------------------------------
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
#--------------------------------------------------------------------------->*/
import sys
import unittest
import libsbml


class TestDate_newSetters(unittest.TestCase):


  def test_Date_setDateAsString(self):
    date = libsbml.Date(2007,10,23,14,15,16,1,3,0)
    self.assert_( date != None )
    i = date.setDateAsString( "20081-12-30T12:15:45+02:00")
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_((                                 "2007-10-23T14:15:16+03:00" == date.getDateAsString() ))
    i = date.setDateAsString( "200-12-30T12:15:45+02:00")
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_((                                 "2007-10-23T14:15:16+03:00" == date.getDateAsString() ))
    i = date.setDateAsString("")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_((                             "2000-01-01T00:00:00Z" == date.getDateAsString() ))
    i = date.setDateAsString( "2008-12-30T12:15:45+02:00")
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getYear() == 2008 )
    self.assert_( date.getMonth() == 12 )
    self.assert_( date.getDay() == 30 )
    self.assert_( date.getHour() == 12 )
    self.assert_( date.getMinute() == 15 )
    self.assert_( date.getSecond() == 45 )
    self.assert_( date.getSignOffset() == 1 )
    self.assert_( date.getHoursOffset() == 2 )
    self.assert_( date.getMinutesOffset() == 0 )
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setDay(self):
    date = libsbml.Date(2005,2,12,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setDay(29)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getDay() == 1 )
    i = date.setDay(31)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getDay() == 1 )
    i = date.setDay(15)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getDay() == 15 )
    self.assert_((                             "2005-02-15T12:15:45+02:00" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setHour(self):
    date = libsbml.Date(2005,12,30,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setHour(434)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getHour() == 0 )
    i = date.setHour(12121)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getHour() == 0 )
    i = date.setHour(9)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getHour() == 9 )
    self.assert_((                             "2005-12-30T09:15:45+02:00" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setMinute(self):
    date = libsbml.Date(2005,12,30,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setMinute(434)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getMinute() == 0 )
    i = date.setMinute(12121)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getMinute() == 0 )
    i = date.setMinute(32)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getMinute() == 32 )
    self.assert_((                             "2005-12-30T12:32:45+02:00" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setMinutesOffset(self):
    date = libsbml.Date(2005,12,30,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setMinutesOffset(434)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getMinutesOffset() == 0 )
    i = date.setMinutesOffset(60)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getMinutesOffset() == 0 )
    i = date.setMinutesOffset(45)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getMinutesOffset() == 45 )
    self.assert_((                             "2005-12-30T12:15:45+02:45" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setMonth(self):
    date = libsbml.Date(2005,12,30,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setMonth(434)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getMonth() == 1 )
    i = date.setMonth(12121)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getMonth() == 1 )
    i = date.setMonth(11)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getMonth() == 11 )
    self.assert_((                             "2005-11-30T12:15:45+02:00" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setSecond(self):
    date = libsbml.Date(2005,12,30,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setSecond(434)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getSecond() == 0 )
    i = date.setSecond(12121)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getSecond() == 0 )
    i = date.setSecond(32)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getSecond() == 32 )
    self.assert_((                             "2005-12-30T12:15:32+02:00" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

  def test_Date_setYear(self):
    date = libsbml.Date(2005,12,30,12,15,45,1,2,0)
    self.assert_( date != None )
    i = date.setYear(434)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getYear() == 2000 )
    i = date.setYear(12121)
    self.assert_( i == libsbml.LIBSBML_INVALID_ATTRIBUTE_VALUE )
    self.assert_( date.getYear() == 2000 )
    i = date.setYear(2008)
    self.assert_( i == libsbml.LIBSBML_OPERATION_SUCCESS )
    self.assert_( date.getYear() == 2008 )
    self.assert_((                             "2008-12-30T12:15:45+02:00" == date.getDateAsString() ))
    _dummyList = [ date ]; _dummyList[:] = []; del _dummyList
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestDate_newSetters))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)

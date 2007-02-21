/**
 * \file   TestConsistencyValidator.cpp
 * \brief  Runs the ConsistencyValidator on each SBML file in test-data/
 * \author Ben Bornstein
 * 
 * $Id$
 * $Source$
 */
/* Copyright 2005 California Institute of Technology and
 * Japan Science and Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
 * documentation provided hereunder is on an "as is" basis, and the
 * California Institute of Technology and Japan Science and Technology
 * Corporation have no obligations to provide maintenance, support,
 * updates, enhancements or modifications.  In no event shall the
 * California Institute of Technology or the Japan Science and Technology
 * Corporation be liable to any party for direct, indirect, special,
 * incidental or consequential damages, including lost profits, arising
 * out of the use of this software and its documentation, even if the
 * California Institute of Technology and/or Japan Science and Technology
 * Corporation have been advised of the possibility of such damage.  See
 * the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * The original code contained here was initially developed by:
 *
 *     Ben Bornstein
 *     The Systems Biology Markup Language Development Group
 *     ERATO Kitano Symbiotic Systems Project
 *     Control and Dynamical Systems, MC 107-81
 *     California Institute of Technology
 *     Pasadena, CA, 91125, USA
 *
 *     http://www.sbml.org
 *     mailto:sbml-team@caltech.edu
 *
 * Contributor(s):
 */


#include <iostream>
#include <set>

#include <algorithm>

#include "TestFile.h"
#include "TestValidator.h"

#include "ConsistencyValidator.h"
#include "L1CompatibilityValidator.h"
#include "L2v1CompatibilityValidator.h"
#include "L2v2CompatibilityValidator.h"


using namespace std;


/**
 * @return true if the Validator behaved as expected when validating
 * TestFile, false otherwise.
 */
bool
runTest (const TestFile& file)
{
  ConsistencyValidator validator;
  TestValidator        tester(validator);


  validator.init();

  return tester.test(file);
}

/**
 * @return true if the Validator behaved as expected when validating
 * TestFile, false otherwise.
 */
bool
runL1Test (const TestFile& file)
{
  L1CompatibilityValidator validator;
  TestValidator            tester(validator);


  validator.init();

  return tester.test(file);
}

/**
 * @return true if the Validator behaved as expected when validating
 * TestFile, false otherwise.
 */
bool
runL2v1Test (const TestFile& file)
{
  L2v1CompatibilityValidator validator;
  TestValidator            tester(validator);


  validator.init();

  return tester.test(file);
}

/**
 * @return true if the Validator behaved as expected when validating
 * TestFile, false otherwise.
 */
bool
runL2v2Test (const TestFile& file)
{
  L2v2CompatibilityValidator validator;
  TestValidator            tester(validator);


  validator.init();

  return tester.test(file);
}

/**
 * Runs the libSBML ConsistencyValidator on all consistency TestFiles in
 * the test-data/ directory.
 * Runs the libSBML L1CompatibilityValidator on all TestFiles in the
 * test-data-l2-l1-conversion/ directory.
 */
int
main (int argc, char* argv[])
{
  cout.precision(0);
  cout.width(3);

  cout << "Testing Consistency Constraints (10000 - 30000)." << endl;


  set<TestFile> files    = TestFile::getFilesIn("test-data", 10000, 29999);
  unsigned int  passes   = count_if(files.begin(), files.end(), runTest);
  unsigned int  failures = files.size() - passes;
  double        percent  = (static_cast<double>(passes) / files.size()) * 100;


  cout << static_cast<int>(percent) << "%: Checks: " << files.size();
  cout << ", Failures: " << failures << endl;

  cout << "Testing L1 Compatability Constraints (90000 - 91999)." << endl;


  set<TestFile> files1    = TestFile::getFilesIn("test-data-l2-l1-conversion", 90000, 91999);
  unsigned int  passes1   = count_if(files1.begin(), files1.end(), runL1Test);
  unsigned int  failures1 = files1.size() - passes1;
  double        percent1  = (static_cast<double>(passes1) / files1.size()) * 100;


  cout << static_cast<int>(percent1) << "%: Checks: " << files1.size();
  cout << ", Failures: " << failures1 << endl;

  cout << "Testing L1 Compatability Constraints (92000 - 92999)." << endl;


  set<TestFile> files2    = TestFile::getFilesIn("test-data-l2-l1-conversion", 92000, 92999);
  unsigned int  passes2   = count_if(files2.begin(), files2.end(), runL2v1Test);
  unsigned int  failures2 = files2.size() - passes2;
  double        percent2  = (static_cast<double>(passes2) / files2.size()) * 100;


  cout << static_cast<int>(percent2) << "%: Checks: " << files2.size();
  cout << ", Failures: " << failures2 << endl;
  cout << "Testing L1 Compatability Constraints (93000 - 93999)." << endl;


  set<TestFile> files3    = TestFile::getFilesIn("test-data-l2-l1-conversion", 93000, 93999);
  unsigned int  passes3   = count_if(files3.begin(), files3.end(), runL2v2Test);
  unsigned int  failures3 = files3.size() - passes3;
  double        percent3  = (static_cast<double>(passes3) / files3.size()) * 100;


  cout << static_cast<int>(percent3) << "%: Checks: " << files3.size();
  cout << ", Failures: " << failures3 << endl;

  return failures;
}


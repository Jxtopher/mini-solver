///
/// @file test_solution.hpp
/// @author Jxtopher
/// @version 1
/// @copyright CC-BY-NC-SA
/// @date 2021-04
/// @brief
///

#include "tests.h"

#ifndef TEST_SOLUTIONARRAY_H
#define TEST_SOLUTIONARRAY_H

using namespace CppUnit;

class Test_solution : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(Test_solution);
    CPPUNIT_TEST(get_set_case);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void) {
    }
    void tearDown(void) {
    }

    void get_set_case(void) { 
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test_solution);

#endif
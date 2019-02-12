// output_bt.cc
//
// Includes the following tests: 
//
//
// Megan Goodland, University of Toronto
// January 2019

#include "initialization.h"
#include <iostream>
#include <fstream>
#define BOOST_TEXT_DYN_LINK
#define BOOST_TEST_MODULE output_bt
#include <boost/test/included/unit_test.hpp>

//void initialize_uniform(rarray<int,2>& number, int total)
//{
    // place the ants evenly on the table
//    int n = 0; // linear index
//    for (int i = 0; i < number.extent(0); i++) {
//        for (int j = 0; j < number.extent(1); j++) {            
//            number[i][j] = ((long long)(n+1)*total)/number.size() - ((long long)(n)*total)/number.size();
//            n++;
//        }/
//    }    
//}


// Test for the initialization module, which performs:
// Uniform initialization of the simulation of ants walking on a table, subdivided into squares. 
// >>> Want to test this function with 5 cases. Small tables, making sure the ants get distributed uniformly.

BOOST_AUTO_TEST_CASE(initialize_uniform_test){
    namespace tt = boost::test_tools;
    // create two 2x2 rarrays, one to put in the function and another to compare with it
    int length = 2;
    rarray<int,2> function_test(length,length);
    rarray<int,2> compare(length,length); 
    // fill compare array with 4's
    compare.fill(4);
    // number we want to distribute is 4x4 = 16
    int n = 16;
    // run function with test array and n
    initialize_uniform(function_test, n);
    // check if the arrays are the same
    BOOST_CHECK(function_test[1][1]==compare[1][1], tt::tolerance(1));
    
}


// could also just go through every element, check if they're all the same, and then check if they add up to n?

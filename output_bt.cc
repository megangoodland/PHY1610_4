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
// what does it do when the number can't be distributed absolutely evenly?

BOOST_AUTO_TEST_CASE(initialize_uniform_test){
    // create two 2x2 rarrays, one to put in the function and another to compare with it
    int length = 2;
    rarray<int,2> function_test(length,length);
    rarray<int,2> compare(length,length); 
    // number we want to distribute is 16
    int n = 16;
    // f is the number that should appear in each square
    int f = n/(length*length);
    // fill compare array with 4's
    compare.fill(f);
    compare[1][1] = 5;
    // run function with test array and n
    initialize_uniform(function_test, n);
    // check if the arrays are the same
    // fill compare array with difference between old value and corresponding element from function_test
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++){
            BOOST_CHECK_MESSAGE(function_test[i][j] == compare[i][j], "Value at " << i << " " << j << " does not match");
        }
    }
}

//int add(int i, int j){
//    return i+j;
//}

//BOOST_AUTO_TEST_CASE(add_test){
//    BOOST_CHECK(add(2,2)==4);

//}


// could also just go through every element, check if they're all the same, and then check if they add up to n?

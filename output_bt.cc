// output_bt.cc
//
// Includes the following tests: 
//
// Test for the initialization module, which performs:
// Uniform initialization of the simulation of ants walking on a table, subdivided into
// squares. 
//
// Megan Goodland, University of Toronto
// January 2019

#include "initialization.h"
#include <iostream>
#include <fstream>
#define BOOST_TEXT_DYN_LINK
#define BOOST_TEST_MODULE output_bt
#include <boost/test/uni_test.hpp>

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
int add(int i, int j){
    return i+j;
}

BOOST_AUTO_TEST_CASE(add_test){
    BOOST_CHECK(add(2,2)==5);
    
}




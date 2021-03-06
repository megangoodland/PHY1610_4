// Megan Goodland, University of Toronto
// February 2019

// Tests for the randompartition module, which performs:
// Implementation of the function to randomly divide a number 'total'
// into a set of 'numdivision' numbers that add up to 'total'. Uses
// c++11 random library to generate the randomness.

// >>> Want a test for rand_partition that partitions 100 into 10 parts. 
//     Run this 10 times, each time checking that the parts add up to 100.

#include "randompartition.h"
#include <iostream>
#include <fstream>
#define BOOST_TEXT_DYN_LINK
#define BOOST_TEST_MODULE randompartition_test
#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_CASE(splitting_100){
    int total = 100;
    int nparts = 10;
    size_t seed = 11;
    rarray<int,1> nperpart(10);
    int sum = 0; // sum will store the sum of the values from nperpart
    for (int i=0; i<10; i++){ // we want to do this test 10 times
        rand_partition(total, nparts, nperpart, seed);
        // loop to sum up components of nperpart
        for (int n=0; n<nparts; n++){ 
            sum = sum + nperpart[n];
        }
        BOOST_CHECK_MESSAGE(sum == total, "randomly partitioned 100");
        // zeroing values that loop
        sum = 0;
        nperpart.fill(0);
    }
}

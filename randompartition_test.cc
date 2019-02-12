// Megan Goodland, University of Toronto
// February 2019

// Tests for the randompartition module, which performs:
// Implementation of the function to randomly divide a number 'total'
// into a set of 'numdivision' numbers that add up to 'total'. Uses
// c++11 random library to generate the randomness.

// >>> Want a test that partitions 100 into 10 parts. Run this 10 times, each time checking that the parts add up to 100.

#include "randompartition.h"
#include <iostream>
#include <fstream>
#define BOOST_TEXT_DYN_LINK
#define BOOST_TEST_MODULE randompartition_test
#include <boost/test/included/unit_test.hpp>

//void rand_partition(int total, int nparts, rarray<int,1>& nperpart, size_t seed)

// TEST CASE: Testing if function places a remainder of 5 in even positions across the matrix
BOOST_AUTO_TEST_CASE(splitting_100){
    int total = 100;
    int nparts = 10;
    size_t seed = 11;
    rarray<int,1> nperpart(10);
    int sum = 0;
    for (int i=0; i<10; i++){
        rand_partition(total, nparts, nperpart, seed);
        for (int n=0; n<nparts; n++){
            sum = sum + nperpart[i];
        }
        BOOST_CHECK_MESSAGE(sum == total, "randomly partitioned 100");
        sum = 0;
    }
}

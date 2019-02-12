//  std::cout << function_test[i][j] << " " << i << " " << j << std::endl;
//
//
// Megan Goodland, University of Toronto
// February 2019

#include "initialization.h"
#include <iostream>
#include <fstream>
#define BOOST_TEXT_DYN_LINK
#define BOOST_TEST_MODULE initialization_test
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


// Tests for the initialization module, which performs:
// Uniform initialization of the simulation of ants walking on a table, subdivided into squares. 
// >>> Want to test this function with 5 cases. Small tables, making sure the ants get distributed uniformly.

// what does it do when the number can't be distributed absolutely evenly?

BOOST_AUTO_TEST_CASE(basic_test){
    int length = 2;
    rarray<int,2> function_test(length,length);
    int n = 400; // number we want to distribute
    int f = n/(length*length); // f is the number that should appear in each square
    initialize_uniform(function_test, n); // run function with test array and n
    // check if the arrays are the same and inform of where a mismatch occurs
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++){
            BOOST_CHECK_MESSAGE(function_test[i][j] == f, "value at " << i << " " << j);
        }
    }
}

BOOST_AUTO_TEST_CASE(larger_numbers){
    // create two 5x5 rarrays, one to put in the function and another to compare with it
    int length = 5;
    rarray<int,2> function_test(length,length);
    rarray<int,2> compare(length,length); 
    int n = 10000; // number we want to distribute is n
    int f = n/(length*length); // f is the number that should appear in each square
    compare.fill(f);
    initialize_uniform(function_test, n); // run function with test array and n
    // check if the arrays are the same
    int test_result = 1; // 1 means pass, 0 means fail
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++){
            if (function_test[i][j] == compare[i][j]){
                test_result = 1;}
            else {
                test_result = 0;
                goto end_of_test;}
        }
    }
    goto end_of_test;
    end_of_test: BOOST_CHECK_MESSAGE(test_result == 1, "function initialize_uniform with larger numbers");
}


BOOST_AUTO_TEST_CASE(uneven_division_R1){
    // create two 5x5 rarrays, one to put in the function and another to compare with it
    int length = 5;
    rarray<int,2> function_test(length,length);
    rarray<int,2> compare(length,length); 
    int n = 10001; // number we want to distribute, should have a remainder of 1 when divided by lengthxlength
    int f = n/(length*length); // the number that should appear in each square, other than the one in the last position
    int ff = f+1; // the number that should appear in the final position
    compare.fill(f);
    compare[length-1][length-1] = ff; 
    // run function with test array and n
    initialize_uniform(function_test, n);
    // check if the arrays are the same
    int test_result = 1; // 1 means pass, 0 means fail
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++){
            if (function_test[i][j] == compare[i][j]){
                test_result = 1;}
            else {
                test_result = 0;
                goto end_of_test;}
        }
    }
    goto end_of_test;
    end_of_test: BOOST_CHECK_MESSAGE(test_result == 1, "function initialize_uniform with an uneven division, remainder 1");
}

BOOST_AUTO_TEST_CASE(uneven_division_R3){
    // create two 5x5 rarrays, one to put in the function and another to compare with it
    int length = 5;
    rarray<int,2> function_test(length,length);
    rarray<int,2> compare(length,length); 
    int n = 10003; // number we want to distribute, should have a remainder of 3 when divided by lengthxlength
    int f = n/(length*length); // the number that should appear in each square, other than the one in the last 3 positions
    // last 3 positions have i = length-1, j = length-1, length-2, length-3
    int ff = f+1; // the number that should appear in the final 3 positions
    compare.fill(f);
    compare[length-1][length-1] = ff; compare[length-1][length-2] = ff; compare[length-1][length-3] = ff; 
    initialize_uniform(function_test, n); // run function with test array and n
    // check if the arrays are the same
    int test_result = 1; // 1 means pass, 0 means fail
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++){
            if (function_test[i][j] == compare[i][j]){
                test_result = 1;}
            else {
                test_result = 0;
                goto end_of_test;}
        }
    }
    goto end_of_test;
    end_of_test: BOOST_CHECK_MESSAGE(test_result == 1, "function initialize_uniform with an uneven division, remainder 3");
}
// could also just go through every element, check if they're all the same, and then check if they add up to n?

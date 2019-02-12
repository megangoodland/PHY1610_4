// Megan Goodland, University of Toronto
// February 2019

// Tests for the timestep module, which performs:
// Summarize and reports ants on a table.

// >>> Want a test for perform_one_timestep function that makes sure that the total 
//     number of ants on the table either stays the same or decreases when used once

#include "randompartition.h"
#include "timestep.h"
#include <iostream>
#include <fstream>
#define BOOST_TEXT_DYN_LINK
#define BOOST_TEST_MODULE timestep_test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(no_additional_ants){

    int length = 5; // length of table
    int num = 4;    // number of ants on each square of original table
    size_t seed = 11;
    rarray<int,2> number_of_ants(length,length);     // distribution of ants on the table over squares
    rarray<int,2> new_number_of_ants(length,length); // auxiliary array used in time step to hold the new distribution of ants
    
    number_of_ants.fill(num); // put num ants on each square of table
    perform_one_timestep(number_of_ants, new_number_of_ants, seed);
    int sum1 = num*length*length; // original number of ants on the table
    int sum2 = 0;
    
    // to get sum2, loop through and add all elements of new_number_of_ants
    for (int i=0; i<length; i++){
        for (int j=0; j<length; j++){
            sum2 = sum2 + new_number_of_ants[i][j];
        }
    }
    BOOST_CHECK_MESSAGE(sum2 <= sum1, "total # of ants on table did not increase");

}

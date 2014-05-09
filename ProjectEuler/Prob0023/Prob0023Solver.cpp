//
//  Prob0023Solver.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 05/02/2013.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
 
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <iostream>
#include <fstream>
#include <math.h>
#include "Prob0023Solver.h"

#define UPPER_BOUND 28124
#define LAST_POSSIBLE_ABUNDANT_NUMBER   28123

bool Prob0023Solver::solve()
{
    int64 total = 0;
    int firstAbundantNumber = 12;
    int numAbundantNumbers = 0;
    int *abundantNumbers = new int[(LAST_POSSIBLE_ABUNDANT_NUMBER+1)];
    int *sumOf2Table = new int[UPPER_BOUND];
    memset(sumOf2Table, 0, sizeof(int)*UPPER_BOUND);
    
    // find adundant numbers
    for (int n = firstAbundantNumber; n <= LAST_POSSIBLE_ABUNDANT_NUMBER; ++n) {
        if (isAbundant(n)) {
            abundantNumbers[numAbundantNumbers++] = n;
        }
    }
    
    std::cout << "there are " << numAbundantNumbers << " abundant numbers" << std::endl;
    
    // calculate numbers that are the sum of two abundant numbers.
    for (int i = 0; i < numAbundantNumbers; ++i) {
        // determine if i ca be writen as the sum of two abundant numbers
        for (int j = (i); j < numAbundantNumbers; ++j) {
            int sumOfTwoAbundantNumbers = abundantNumbers[i] + abundantNumbers[j];
            
            //std::cout << sumOfTwoAbundantNumbers << " " << abundantNumbers[i] << " " << abundantNumbers[j] << std::endl;
            if (sumOfTwoAbundantNumbers < UPPER_BOUND) {
                sumOf2Table[sumOfTwoAbundantNumbers] = 1;
            }
        }
    }
    
    for (int i = 0; i < UPPER_BOUND; ++i) {
        if (!sumOf2Table[i]) {
            //std::cout << i << std::endl;
            total += i;
        }
    }
    
    this->m_i64Result = total;
    return true;
}

bool Prob0023Solver::isAbundant(const int intToTest) const {
    // find the sum of all divisors
    int maxDivisor = (int)floor(sqrt(intToTest));
    int sumOfDivisors = 1;
    
    for (int curDivisor = 2; curDivisor <= maxDivisor; ++curDivisor) {
        int r = intToTest/curDivisor;
        if ((r*curDivisor) == intToTest) {
            sumOfDivisors += curDivisor;
            if (curDivisor != r) {
                sumOfDivisors += r;
            }
        }
    }
    
    if (sumOfDivisors > intToTest) {
        std::cout << "A " << intToTest << " " << maxDivisor << " " << sumOfDivisors << std::endl;
    } else if (sumOfDivisors == intToTest){
        std::cout << "P " << intToTest << std::endl;
    } else {
        //std::cout << "D " << intToTest << std::endl;
    }

    return (sumOfDivisors > intToTest);
}

//
//  Prob0021Solver.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
 
 Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 
 Evaluate the sum of all the amicable numbers under 10000.
 
 */

#include <iostream>
#include "Prob0021Solver.h"
#include <math.h>

#define COUNT   10000

bool Prob0021Solver::solve()
{
    // contains the sum of proper divisors for [0,COUNT)
    // m_sums[i] = d(i)
    
    m_sums = new int[COUNT];
    m_sums[0] = 0;  
    m_sums[1] = 0;
    m_sums[2] = 1; // 1,2 
    m_sums[3] = 1; // 1,3
    m_sums[4] = 3; // 1,2,4
    
    int sumOfAllAmicableNumbers = 0;
    
    for (int i = 2; i < COUNT; ++i) {
        m_sums[i] = sumOfProperDivisors(i);
        
        //std::cout << i << " " << m_sums[i] << std::endl;
    }
    
    for (int A = 0; A < COUNT; ++A) {
        int dOfA = m_sums[A];       // d(a) = b
        int B = dOfA;
        int dOfB = m_sums[B];    // d(b) = ?
        
        if (dOfB == A && (dOfA != dOfB)) {
            sumOfAllAmicableNumbers += A;          
            std::cout << A << " " << dOfA << " " << dOfB << " " << sumOfAllAmicableNumbers << std::endl;
        }
    }
    
    m_i64Result = sumOfAllAmicableNumbers;
    return true;
}

// iValue >= 2
int Prob0021Solver::sumOfProperDivisors(const int iValue) const
{
    int sqrtI = floor(sqrt(iValue));
    int sumOfDivisors = 1; // 1*iValue
    
    for (int iDivisor = 2; iDivisor <= sqrtI; ++iDivisor) {
        int result = iValue / iDivisor;
        int remainder = iValue - result*iDivisor;
        
        if (0 == remainder) {
            if (iDivisor == result) {
                sumOfDivisors += iDivisor;
            }
            else {
                sumOfDivisors += (iDivisor + result);
            }
        }
    }
    
    return sumOfDivisors;
}


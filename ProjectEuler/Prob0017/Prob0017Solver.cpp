//
//  Prob0017Solver.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0017Solver.h"

/*
 
 If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 
 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 
 
 NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 
 */


void Prob0017Solver::init()
{
    m_numToLetterCount[0] = 0;
    m_numToLetterCount[1] = strlen("one");
    m_numToLetterCount[2] = strlen("two");  
    m_numToLetterCount[3] = strlen("three");  
    m_numToLetterCount[4] = strlen("four");  
    m_numToLetterCount[5] = strlen("five");  
    m_numToLetterCount[6] = strlen("six");  
    m_numToLetterCount[7] = strlen("seven");  
    m_numToLetterCount[8] = strlen("eight");  
    m_numToLetterCount[9] = strlen("nine");
    m_numToLetterCount[10] = strlen("ten");
    m_numToLetterCount[11] = strlen("eleven");
    m_numToLetterCount[12] = strlen("twelve");
    m_numToLetterCount[13] = strlen("thirteen");
    m_numToLetterCount[14] = strlen("fourteen");
    m_numToLetterCount[15] = strlen("fifteen");
    m_numToLetterCount[16] = strlen("sixteen");
    m_numToLetterCount[17] = strlen("seventeen");
    m_numToLetterCount[18] = strlen("eighteen");
    m_numToLetterCount[19] = strlen("nineteen");
    m_numToLetterCount[20] = strlen("twenty");
    m_numToLetterCount[30] = strlen("thirty");
    m_numToLetterCount[40] = strlen("forty");
    m_numToLetterCount[50] = strlen("fifty");
    m_numToLetterCount[60] = strlen("sixty");
    m_numToLetterCount[70] = strlen("seventy");
    m_numToLetterCount[80] = strlen("eighty");
    m_numToLetterCount[90] = strlen("ninety");
    m_numToLetterCount[100] = strlen("hundred");
    m_numToLetterCount[1000] = strlen("thousand");
}

bool Prob0017Solver::solve()
{
    init();
    int64 total = 0;
    int N = 1000;
    for(int i = 1; i <= N; ++i){
        int thousands = i/1000;
        int hundreds = ((i - thousands*1000)/100);
        int tens = (i % 100); 
        
        int subTotal = 0;
        
        // compute lenth of ones and tens place
        if (tens <= 20) {
            subTotal += m_numToLetterCount[tens];
        } else {
            int ones = tens % 10;
            subTotal += (m_numToLetterCount[ones] + m_numToLetterCount[tens - ones]);
        }
                      
        if (hundreds > 0) {
            subTotal += (m_numToLetterCount[hundreds] + m_numToLetterCount[100]);
        }
        
        if ((tens > 0) && (hundreds > 0)) {
            subTotal += 3; // and
        }
        
        if (thousands > 0) {
            subTotal += (m_numToLetterCount[thousands] +  m_numToLetterCount[1000]);
        }   
        
        total += subTotal;
          std::cout << thousands << " " << hundreds << " " << tens << " " << subTotal << " " << total << std::endl;
    }
    
    m_i64Result = total;
    return true;
}
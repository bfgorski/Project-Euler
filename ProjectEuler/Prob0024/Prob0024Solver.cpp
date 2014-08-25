//
//  Prob0024Solver.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 6/2/13.
//
//

/*
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include "Prob0024Solver.h"
#include <iostream>

// range => positions, digits => symbols
void Prob0024Solver::permutation(Range& r, Digits& d) {
    if(m_NumPermutations >= m_PermToFind) {
        return;
    }
    if (2 == r.size) {
        if((NUM_DIGITS-2) == r.start) {
            m_NumPermutations += 2;
            if(m_NumPermutations == m_PermToFind) {
                m_FinalDigits = d;
                int temp = m_FinalDigits.d[NUM_DIGITS-1];
                m_FinalDigits.d[NUM_DIGITS-1] = m_FinalDigits.d[NUM_DIGITS-2];
                m_FinalDigits.d[NUM_DIGITS-2] = temp;
                return;
            }
            //std::cout << "P: " << d.d[0] << "," << d.d[1] << "," << d.d[2] << "," << d.d[3] << std::endl;
            //std::cout << "P: " << d.d[0] << "," << d.d[1] << "," << d.d[3] << "," << d.d[2] << std::endl;
            return;
        } else {
            //std::cerr << "Start and Size Mismatch Start: " << r.start << " Size: " << r.size << std::endl;
            return;
        }
    } else {
        // iterating position start + i
        Range newRange = {r.start + 1, r.size - 1};
        Digits newDigits = d;
        
        // cycle through all values for digit r.start
        // which is all digits
        for(int i = 0; i < (r.size); ++i) {
            newDigits.count = d.count - i;
            
            // starting digit is d.digits[i+r.start]
            // e.g digits are A C D
            // starting digit sequence in current digit is A => C => D
            int startDigit = d.d[i+r.start];
            //std::cout << "Start Digit " << startDigit << " Pos " << (i+r.start) << std::endl;
            
            // new digits are the digits in d[r.start] ... d[r.start + r.size] except startDigir
            // newDigits.d[i+r.start+1] ... newDigits.d[NUM_DIGITS] is all digits
            int k = r.start+1;
            for (int j = r.start; j < NUM_DIGITS; ++j) {
                if(d.d[j] != startDigit) {
                    newDigits.d[k++] = d.d[j];
                }
            }
            newDigits.d[r.start] = startDigit;
            //std::cout << "ND " << newDigits.d[0] << "," << newDigits.d[1] << "," << newDigits.d[2] << "," << newDigits.d[3] << std::endl;

            permutation(newRange,newDigits);
        }
    }
}

void Prob0024Solver::printFinalDigits() const
{
    std::cout << "[";
    for(int i = 0; i < NUM_DIGITS; ++i) {
        std::cout << m_FinalDigits.d[i];
    }
    std::cout << "]" << std::endl;
}

bool Prob0024Solver::solve()
{
    m_PermToFind = 1000000;
    m_NumPermutations = 0;
    Range r = {0,10};
    Digits d = { 4, {0, 1,2,3, 4, 5, 6, 7, 8, 9} };
    
    permutation(r,d);
    printFinalDigits();
    return true;
}


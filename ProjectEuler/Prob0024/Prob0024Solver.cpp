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
#include <fstream>
#include <math.h>

#define MAX_PERM 1000000
#define LAST_POSITION 9
#define MAX_VALUE 9

bool Prob0024Solver::solve()
{
    int count = 1;
    m_numPerms = 1;
    m_startPos = 8;
    m_endPos = 9;
    //m_perm = {0,1,2,3,4,5,6,7,8,9};
    
    //nextPerm(LAST_POSITION-1);
    
    return true;
}

/*int Prob0024Solver::nextPerm(int curPos) {
    
    if (curPos < (LAST_POSITION-1)) {
        nextPerm(curPos+1);
        
        if (MAX_VALUE == m_perm[curPos]) {
            return 0;
        }
        
        // increment digit and recurse again
        m_perm[curPos]++;
        m_startPos = curPos;
        resetPerm();
        int finished = nextPerm(curPos+1);
    } else {
        // count this permutation
        m_numPerms++;
        
        
    }
    
}*/

void Prob0024Solver::resetPerm() {
    /*if (MAX_VALUE == m_perm[m_startPos]) {
        // m_startPos - 1 will be incremented 1 and m_startPos ... m_endPos will be reset
        m_perm[m_startPos-1]++;
        
        int isUsed[10] = {0};
        
        for (int i = 0; i < m_startPos; ++i) {
            isUsed[m_perm[i]] = 1;
        }
        
        // go through the digits and reset the permutation
        for (int i = 0; i < 10; ++i) {
            if (!isUser[i]) {
                m_perm[m_startPos++] = i;
            }
        }
        return;
    }*/
}

void Prob0024Solver::printPerm() {
   // std::cout << "[" << m_perm[0] << "," << m_perm[1] << "," <<< m_perm[2] << "," << m_perm[3] << "," << m_perm[4] << ","
     //                << m_perm[5] << "," <<< m_perm[6] << "," << m_perm[7] << "," << m_perm[8] << "," << m_perm[9] << "]" << std::endl;
}




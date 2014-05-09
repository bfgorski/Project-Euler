//
//  Prob0024Solver.h
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

#ifndef __ProjectEuler__Prob0024Solver__
#define __ProjectEuler__Prob0024Solver__

#include "ProblemSolver.h"

class Prob0024Solver : public ProblemSolver {
    
public:
    
    Prob0024Solver() {}
    
    virtual bool solve();
    
private:
    int m_perm[10];
    int m_startPos;
    int m_endPos;
    int m_numPerms;
    int nextPerm();
    
    void printPerm();
    void resetPerm();
    
};

#endif /* defined(__ProjectEuler__Prob0024Solver__) */

//
//  Prob0017Solver.h
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ProjectEuler_Prob0017Solver_h
#define ProjectEuler_Prob0017Solver_h

/*
 
 If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 
 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 
 
 NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 
 */

#include "ProblemSolver.h"
#include <map>

class Prob0017Solver : public ProblemSolver {
    
public :
    
    Prob0017Solver() : ProblemSolver() {}
    
    virtual bool solve();
    
private:
    void init();
    std::map<int,int> m_numToLetterCount;    // counts for 1 to 100
};

#endif

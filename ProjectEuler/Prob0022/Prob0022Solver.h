//
//  Prob0022Solver.h
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
 
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.
 
 What is the total of all the name scores in the file?
 
 */

#ifndef ProjectEuler_Prob0022Solver_h
#define ProjectEuler_Prob0022Solver_h

#include "ProblemSolver.h"

class Prob0022Solver : public ProblemSolver {
    
public:
    
    Prob0022Solver() {}
    
    virtual bool solve();
    
};

#endif

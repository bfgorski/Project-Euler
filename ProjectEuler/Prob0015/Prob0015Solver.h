//
//  Prob0015Solver.h
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
 
 Starting in the top left corner of a 2x2 grid, 
 there are 6 routes (without backtracking) to the bottom right corner.
  _ _
 |_|_|
 |_|_|
 
 How many routes are there through a 2020 grid?
 
*/

#ifndef ProjectEuler_Prob0015Solver_h
#define ProjectEuler_Prob0015Solver_h

#include "ProblemSolver.h"

class Prob0015Solver : public ProblemSolver {
    
public :
    
    Prob0015Solver() : ProblemSolver() {}
    
    virtual bool solve();
};

#endif

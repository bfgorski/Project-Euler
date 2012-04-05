//
//  main.cpp
//  Prob0022
//
//  Created by Benjamin Gregorski on 3/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0022Solver.h"

int main (int argc, const char * argv[])
{
    // insert code here...
    Prob0022Solver * pSolver = new Prob0022Solver();
    pSolver->solve();
    int64 result = pSolver->geti64Result();
    
    std::cout << "Prob 0021 Result " << result << std::endl;
    return 0;

}


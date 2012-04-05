//
//  main.cpp
//  Prob0015
//
//  Created by Benjamin Gregorski on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0015Solver.h"

int main (int argc, const char * argv[])
{

    // insert code here...
    Prob0015Solver * pSolver = new Prob0015Solver();
    pSolver->solve();
    int64 result = pSolver->geti64Result();
    
    std::cout << "Prob 0015 Result " << result << std::endl;

    return 0;
}


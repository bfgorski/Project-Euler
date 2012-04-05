//
//  main.cpp
//  Prob0017
//
//  Created by Benjamin Gregorski on 3/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0017Solver.h"

int main (int argc, const char * argv[])
{
    // insert code here...
    Prob0017Solver * pSolver = new Prob0017Solver();
    pSolver->solve();
    int64 result = pSolver->geti64Result();
    
    std::cout << "Prob 0017 Result " << result << std::endl;
    return 0;
}


//
//  main.cpp
//  Prob0018
//
//  Created by Benjamin Gregorski on 3/13/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0018Solver.h"

int main (int argc, const char * argv[])
{

    // insert code here...
    Prob0018Solver * pSolver = new Prob0018Solver();
    pSolver->solve();
    int64 result = pSolver->geti64Result();
    
    std::cout << "Prob 0018 Result " << result << std::endl;
    return 0;
}


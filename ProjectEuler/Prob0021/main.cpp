//
//  main.cpp
//  Prob0021
//
//  Created by Benjamin Gregorski on 3/20/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0021Solver.h"

int main (int argc, const char * argv[])
{

    // insert code here...
    Prob0021Solver * pSolver = new Prob0021Solver();
    pSolver->solve();
    int64 result = pSolver->geti64Result();
    
    std::cout << "Prob 0021 Result " << result << std::endl;
    return 0;

}


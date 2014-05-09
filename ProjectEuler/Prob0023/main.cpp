//
//  main.cpp
//  Prob00223
//
//  Created by Benjamin Gregorski on 05/02/2013.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0023Solver.h"

int main (int argc, const char * argv[])
{
    // insert code here...
    Prob0023Solver * pSolver = new Prob0023Solver();
    pSolver->solve();
    int64 result = pSolver->geti64Result();
    
    std::cout << "Prob 0023 Result " << result << std::endl;
    return 0;
    
}


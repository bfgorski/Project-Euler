//
//  main.cpp
//  Prob0024
//
//  Created by Benjamin Gregorski on 05/02/2013.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "Prob0024Solver.h"

int main (int argc, const char * argv[])
{
    // insert code here...
    Prob0024Solver * pSolver = new Prob0024Solver();
    pSolver->solve();
    std::string result = pSolver->getResultAsString();
    
    std::cout << "Prob 0024 Result " << result << std::endl;
    return 0;
    
}


//
//  prob0012.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "prob0012.h"
#include "Util.h"
#include <iostream>

void solveProb0012()
{
    bool found = false;
    int64 nextNaturalNum = 2;
    int64 triangleNumber = 1;
    while( !found ) {
        size_t numDivisors = Util::countDivisors(triangleNumber);
        
        if (numDivisors > 500) {
            found = true;
        } else {
            triangleNumber += nextNaturalNum;
            ++nextNaturalNum;      
        }
    }
    
    std::cout << "The first triangle umber with > 500 divisors: " << triangleNumber << " Next Natural Number " << nextNaturalNum << std::endl;
    return;
}
//
//  Util.h
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef _UTIL_H_
#define _UTIL_H_

#include <set>
#include <math.h>

using namespace std;
typedef long long int int64;

namespace Util {

    void primeFactor(int64 p, set<int64> & primeFactors);
    /**
        Count the numbers that divide p.
     */
    size_t countDivisors(int64 p);
}

#endif // _UTIL_H_
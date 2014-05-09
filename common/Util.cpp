//
//  Util.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 8/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Util.h"

namespace Util {
    
    void primeFactor(int64 p, set<int64> & primeFactors)
    {
        if( primeFactors.find(p) != primeFactors.end() ) {
            return;
        }
        
        // p is prime if all ints up to sqrt(p) do not successfully divide p
        int64 sqrtP = static_cast<int64>( sqrt(double(p)) );
        
        for( int64 i = sqrtP ; i > 2; --i)
        {
            int64 f = p / i;
            if( f*i == p )
            {
                primeFactor(i, primeFactors);
                primeFactor(f, primeFactors);
                return;
            }
        }
        
        // if we didn't find any numbers that divide p then it is prime
        primeFactors.insert(p);
    }
    
    /**
     Count the numbers that divide p.
     */
    size_t countDivisors(int64 p)
    {
        set<int64> divisors;
        
        // check all numbers up to sqrt(p)
        int64 sqrtP = static_cast<int64>( sqrt(double(p)) );
        
        for( int64 i = sqrtP ; i >= 2; --i)
        {
            int64 f = p / i;
            if( f*i == p )
            {
                divisors.insert(f);
                divisors.insert(i);
            }
        }
        
        return divisors.size();
    }

}
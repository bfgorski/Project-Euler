//
//  Prob0015Solver.m
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Prob0015Solver.h"
#include "prob0015.h"

@implementation Prob0015Solver
{
}

-(void) solve 
{
    Prob0015 * pProb = new Prob0015();
    self.m_result = pProb->solve();
    delete pProb;
    
    NSLog (@"The solution to probl 0015 is %d", self.m_result);
}
@end

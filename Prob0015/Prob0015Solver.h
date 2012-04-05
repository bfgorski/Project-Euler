//
//  Prob0015Solver.h
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "../common/ProblemSolver.h"
#import "../common/Util.h"

@interface Prob0015Solver : ProblemSolver
{
    int64 m_result;
}

-(int64)getResult;
-(void)solve;

@end

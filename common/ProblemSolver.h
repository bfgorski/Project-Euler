//
//  ProblemSolver.h
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ProjectEuler_ProblemSolver_h
#define ProjectEuler_ProblemSolver_h

typedef long long int int64;

class ProblemSolver {
  
public :
    ProblemSolver() {};
    virtual ~ProblemSolver() {}
    
    virtual bool solve() = 0;
    
    int64 geti64Result() { return m_i64Result; }
    
protected:
    int64 m_i64Result;
    
};

#endif

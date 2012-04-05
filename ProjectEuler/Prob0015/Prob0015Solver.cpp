//
//  Prob0015Solver.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Prob0015Solver.h"

/*
 
 Starting in the top left corner of a 2x2 grid, 
 there are 6 routes (without backtracking) to the bottom right corner.
 
       width
        _ _
height |_|_|
       |_|_|
 
 How many routes are there through a 2020 grid?
 
 */

bool Prob0015Solver::solve()
{
    std::cout << "Prob0015 solve" << std::endl;
    m_i64Result = 123;
    
    static const int cellW = 20;
    static const int cellH = 20;
    static const int pointW = cellW + 1;
    static const int pointH = cellH + 1;
    
    int64 grid[pointW][pointH];
    memset(grid, 0, sizeof(int)*pointW*pointH);
    
    grid[0][0] = 0;
    grid[1][0] = 1;
    grid[0][1] = 1;
       
    
    /*
        Rotate the grid to be a diamond and    
        calculate triangle numbers for the grid points 
     
        cellW = 4
        cellH = 4
        pointW = 5
        pointH = 5
     
        0 1 1 1 1
        1 2 3 4
        1 3 6
        1 4
        1
     */
    
    // top half of diamond
    for (int w = 2; w < pointW; ++w) {
        int numPointsInDiagonal = w;
        for (int curPoint = 0; curPoint <= numPointsInDiagonal; ++curPoint) {
            int curPointWidth = (w - curPoint);
            int curPointHeight = curPoint;
            
            int64 val1 = (curPointHeight > 0) ? (grid[curPointWidth][curPointHeight-1]) : 0;
            int64 val2 = (curPointWidth > 0) ? (grid[curPointWidth-1][curPointHeight]) : 0;
            
            std::cout << curPointWidth << " " << curPointHeight << " " << ( val1 + val2) << std::endl;
            
            grid[curPointWidth][curPointHeight] = val1 + val2;
        }
    }
    
    // bottom half of diamond
    for (int h = 1; h < pointH; ++h) {
        int numPointsInDiagonal = (pointH - h);
        for (int curPoint = 0; curPoint < numPointsInDiagonal; ++curPoint) {
            int curPointWidth = cellW - curPoint;
            int curPointHeight = (curPoint + h);
        
            int64 val1 = (curPointHeight > 0) ? (grid[curPointWidth][curPointHeight-1]) : 0;
            int64 val2 = (curPointWidth > 0) ? (grid[curPointWidth-1][curPointHeight]) : 0;
            
            std::cout << curPointWidth << " " << curPointHeight << " " << ( val1 + val2) << std::endl;
            
            grid[curPointWidth][curPointHeight] = val1 + val2;
        }
    }
    
    m_i64Result = grid[cellW][cellH];
    
    
    return true;
}

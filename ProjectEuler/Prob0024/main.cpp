//
//  main.cpp
//  Prob0024
//
//  Created by Benjamin Gregorski on 6/2/13.
//
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include "math.h"

#define NUM_COLS 5
#define NUM_ROWS 5

int matrix[NUM_ROWS][NUM_COLS] = {
    {2, 3, 4, 5, 6},
    {7, 8, 9, 1, 2},
    {10,11,12,13,14},
    {0, 1, 2, 3, 4},
    {20,21,22,23,24}
};

int getMatrix(int i, int j) {
    return matrix[i][j];
}

void rotateMatrix() {
	int outMatrix[NUM_COLS][NUM_ROWS];
    
	// rotate 90 degrees clockwise
	for(int row=0 ; row < NUM_ROWS; ++row) {
		for(int col = 0; col < NUM_COLS; ++col) {
            outMatrix[col][NUM_ROWS - row - 1] = matrix[row][col];
		}
	}
    
    for(int i = 0; i < NUM_COLS; ++i) {
        for(int j = 0; j < NUM_ROWS; ++j) {
            std::cout << outMatrix[i][j] << " " ;
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    // in place rotate for square matrix
    /*
     
     
     */
    
    int level = 0;
    for (int i = 0; i <= 2; ++i, ++level) { //((NUM_ROWS-1)/2); ++i, ++level) {
        
        for (int j = 0; j < ((NUM_COLS-1)-2*level); ++j) {
            // rotate point (i,j) (j,NUM_COLS-1-row) ((NUM_ROWS-1-cols),(NUM_COLS-j-row)) (NUM_ROWS-j,0)
            int p0 = getMatrix(level,level+j);
            int p1 = getMatrix(level+j,(NUM_COLS-1)-level);
            int p2 = getMatrix((NUM_ROWS-1)-level,(NUM_COLS-1)-level-j);
            int p3 = getMatrix((NUM_ROWS-1)-level-j, level);
            
            std::cout << p0 << " " << p1 << " " << p2 << " " << p3 << std::endl;
            
            matrix[level+j][(NUM_COLS-1)-level] = p0;
            matrix[(NUM_ROWS-1)-level][(NUM_COLS-1)-level-j] = p1;
            matrix[(NUM_ROWS-1)-level-j][level] = p2;
            matrix[level][level+j] = p3;
            
            //int temp = matrix[i+level][j+level];
            //matrix[i+level][j+level] = matrix[NUM_ROWS-level-1][j+level];
            //matrix[NUM_ROWS-level][0] = matrix[NUM_ROWS-1][NUM_COLS-j];
        }
    }
    
    std::cout << std::endl;
    
    for(int i = 0; i < NUM_COLS; ++i) {
        for(int j = 0; j < NUM_ROWS; ++j) {
            std::cout << matrix[i][j] << " " ;
        }
        
        std::cout << std::endl;
    }
}

int check(int *a, int numElements, int midIndex) {
    if (midIndex-1 < 0) {
        return -1;
    }
    
    if (midIndex+1 > (numElements-1)) {
        return -1;
    }
    
    int mid = a[midIndex];
    int leftMid = a[midIndex-1];
    int rightMid = a[midIndex+1];
    
    if (leftMid > mid && rightMid > mid) {
        return midIndex;
    }
    return -1;
}

int problem3_1(int* a, int numElements, int lower, int upper) {
/*
 Given a sequence of numbers such that A[0] >= A[1] and A[N-1] >= A[N-2] 
 find at-least one triplet such that A[n-1] >= A[n] <= A[n+1]. Better than linear time is expected.
 */
    std::cout << lower << " " << upper << std::endl;
    
    if ((upper-lower) < 2) {
        if (-1 != check(a, numElements, lower)) {
            return lower;
        }
        if (-1 != check(a, numElements, upper)) {
            return upper;
        }
        return -1;
    }
    
    int midIndex = ((upper+lower) >> 1);
    
    if (midIndex-1 < 0) {
        return -1;
    }
    
    if (midIndex+1 > (numElements-1)) {
        return -1;
    }
    
    int mid = a[midIndex];
    int leftMid = a[midIndex-1];
    int rightMid = a[midIndex+1];
    
    std::cout << midIndex << " " << mid << " " << leftMid << " " << rightMid << std::endl;
    
    if (leftMid > mid && rightMid > mid) {
        return midIndex;
    } else if (rightMid < mid) {
        return problem3_1(a, numElements, (midIndex), upper);
    } else {
        return problem3_1(a, numElements, lower, midIndex);
    }
}

struct sequence {
    int start;
    int end;
    bool printed;
};

typedef struct sequence sequence;

int problem3_2() {
 /*
  Given a set of numbers, find the longest subset with consecutive numbers be it any order.
  
  Input:
  S = { 5, 1, 9, 3, 8, 20, 4, 10, 2, 11, 3}
  
  we have 2 consecutive sets
  s1 = {1, 2, 3, 4, 5}
  s2 = { 8, 9, 10, 11}
  
  Ans.
  s1 = {1, 2, 3, 4, 5}
  
  */
    
    int s[] =  { 5, 1, 9, 3, 8, 20, 4, 10, 2, 11, 3};
    std::vector<int> myvector (s, s+11);
    
    // using default comparison (operator <):
    std::sort (myvector.begin(), myvector.begin()+11);

    for (std::vector<int>::iterator it=myvector.begin(); it != myvector.end(); ++it) {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;
    
    int curVal = myvector[0];
    int sequenceLength = 1;
    
    for (int i = 1; i < myvector.size(); ++i) {
        if (myvector[i] == (curVal)) {
            sequenceLength++;
        } else if (myvector[i] == (curVal+1)) {
            sequenceLength++;
            curVal++;
        }else {
            std::cout << "Sequence Length " << sequenceLength << " Start "  << (i-sequenceLength) << std::endl;
            sequenceLength = 1;
            curVal = myvector[i];
        }
    }
    
    // hash solution
    std::unordered_map<int, sequence*> sequences;
    std::unordered_map<int, sequence*>::iterator it;
    
    for (int i = 0; i < 11; ++i) {
        int val = s[i];
        
        it = sequences.find(val);
        if (it != sequences.end()) {
            sequence *se = (*it).second;
            if (val >= se->start && val <= se->end) {
                continue;
            }
        }
        
        it = sequences.find(val-1);
        
        if (sequences.end() == it) {
            it = sequences.find(val+1);
            if (sequences.end() == it) {
                sequence * se = new sequence;
                se->start = val;
                se->end = val;
                se->printed = false;
                sequences[val] = se;
                //std::cout << "new sequence " << i << " " << val << std::endl;
            } else {
                sequence *se = (*it).second;
                se->start--;
                sequences[val] = se;
            }
        } else {
            sequence *se = (*it).second;
            se->end++;
            sequences[val] = se;
        }
    }

    for (it = sequences.begin(); it != sequences.end(); ++it) {
        sequence *se = (*it).second;
        
        if (se->printed == false) {
            std::cout << "S " << (*it).first << " " << se->start << " " << se->end << std::endl;
            se->printed = false;
        }
    }
    
    for (int i = 0; i < 11; ++i) {
        int val = s[i];
        it = sequences.find(val);
        sequence *curSeq = (*it).second;
        
        // early out if value is already in a sequence
        if (val > curSeq->start && val < curSeq->end) {
            continue;
        }
        
        it = sequences.find(val-1);
        if (sequences.end() == it) {
            it = sequences.find(val+1);
            if (sequences.end() != it) {
                sequence *se = (*it).second;
                
                if (se != curSeq) {
                    curSeq->end = se->end;
                    se->start = curSeq->start;
                    
                    se = (*sequences.find(se->end)).second;
                    se->start = curSeq->start;
                    
                    se = (*sequences.find(curSeq->start)).second;
                    se->end = curSeq->end;
                    
                }
            }
        } else {
            sequence *se = (*it).second;
            //if ((val >= se->start && val <= se->end)) {
              //  continue;
            //}
            if (curSeq != se) {
                std::cout << "New B " << i << " " << val << " " << curSeq->start << " " << curSeq->end << std::endl;
                std::cout << se->start << " " << se->end << std::endl;
                curSeq->start = se->start;
                se->end = curSeq->end;
                
                se = (*sequences.find(se->start)).second;
                se->end = curSeq->end;
                
                se = (*sequences.find(curSeq->end)).second;
                se->start = curSeq->start;
                
                std::cout << "New S " << i << " " << val << " " << curSeq->start << " " << curSeq->end << std::endl;
            }
        }
    }
    
    for (it = sequences.begin(); it != sequences.end(); ++it) {
        sequence *se = (*it).second;
        
        if (se->printed == false && ((se->end - se->start) > 0)) {
            std::cout << "S " << (*it).first << " " << se->start << " " << se->end << std::endl;
            se->printed = true;
        }
    }
    
    
    return 0;
}

struct subarray {
    int start;
    int end;
    int sum;
};

typedef struct subarray subarray;

void problem3_3(int * a, int count) {
    /*
     Given an array of integers. Find two disjoint contiguous sub-arrays such that the absolute difference between the sum of two sub-array is maximum.
     * The sub-arrays should not overlap.
     
     eg- [2 -1 -2 1 -4 2 8] ans - (-1 -2 1 -4) (2 8), diff = 16
     
     I gave him o(n^2) algorithm but he was not satisfied.
     
     
     */
    
    //int a[] = { 2,-1,-2,1,-4,2,8};
    subarray *max = new subarray[count];
    subarray *min = new subarray[count];
    
    if (a[0] > 0) {
        max[0].start = 0;
        max[0].end = 0;
        max[0].sum = a[0];
        min[0].start = -1;
        min[0].end = -1;
        min[0].sum = 0;
    } else {
        max[0].start = max[0].end = -1;
        max[0].sum = 0;
        min[0].start = 0;
        min[0].end = 0;
        min[0].sum = a[0];
    }
    
    // first pass calculate max.min arrays
    for (int i = 1; i < count; ++i) {
        if (a[i] > 0 ) {
            // a[i-1] > 0 means we are in an existing run
            if (a[i-1] > 0) {
                max[i].start = max[i-1].start;
                max[i].end = i;
                max[i].sum = max[i-1].sum + a[i];
                
                // take previous min values
                min[i] = min[i-1];
            } else {
                // negative to positive transition
                
                // check if it is work absorbing negative values to get large positive value
                if (abs(max[i-1].sum) > abs(min[i-1].sum)) {
                    
                } else {
                    max[i].sum = a[i] + min[i-1].sum + max[i-1].sum;
                    min[i].sum
                }
            }
        } else if (a[i] < 0){
            if (a[i-1] < 0) {
                // existing negative run
                min[i].start = min[i-1].start;
                min[i].end = i;
                min[i].sum = min[i-1].sum + a[i];
                
                
                max[i] = max[i-1];
            } else {
                // transition from positive to negative
                if (abs(a[i]) > abs(max[i-1].sum)) {
                    // the new negative value is greater than accumulated positive values
                    
                    if (abs(min[i-1].sum) > abs(max[i-1].sum)) {
                        min[i].sum = a[i] + max[i-1].sum + min[i-1].sum;
                    } else {
                        min[i].sum = a[i];
                    }
                    
                    // new max sequence is started at this point
                    max[i].start = i;
                    max[i].end = i;
                    max[i].sum = 0;
                } else {
                    // max accumulation > the new negative number
                    // so absorb negative number for now.
                    max[i].start = max[i-1].start;
                    max[i].end = i;
                    max[i].sum = max[i-1].sum + a[i];
                    
                    //start new min sequence
                    min[i].start = i;
                    min[i].end = i;
                    min[i].sum = a[i];
                }
            }
        }
    }
    
    // second pass find max sum
    for (int i = 0; i < count; ++i) {
        std::cout << i << " " << max[i].sum << "," << min[i].sum << std::endl;
    }
    std::cout << std::endl;
}
int main(int argc, char **argv) {
    //int a[20] = {14,13,12,11,10,9,-8,-7,-5,-4,-3,-2,-1,-0,1,10,11,12,13,14}; // find 4,3,5
    //int numElements = sizeof(a) / sizeof(int);
    //rotateMatrix();
    //int midIndex = problem3_1(a,numElements,0,numElements-1);
    //std::cout << "Mid Index " << midIndex << std::endl;
    int a[] = { 2,-1,-2,1,-4,2,8};
    problem3_3(a, 7);
    
    /*int b[] = {-10,2,3,4,-6};
    problem3_3(b, 5);
    
    int c[] = {10,-2,-3,-4,6};
    problem3_3(c, 5);
    
    int d[] = {2,-1,-2,3,-4,2,8};
    problem3_3(d,7);
    
    int e[] = {100, -500, 2, -7, 50, -51, 3, -2, 4, 300, -150 };
    problem3_3(e,11);*/
    
	return 0;
}


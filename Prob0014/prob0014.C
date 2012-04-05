/*

 The following iterative sequence is defined for the set of positive integers:
 
 n  n/2 (n is even)
 n  3n + 1 (n is odd)
 
 Using the rule above and starting with 13, we generate the following sequence:
 
 13  40  20  10  5  16  8  4  2  1
 It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 
 Which starting number, under one million, produces the longest chain?
 
 NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>

#include "../common/BigInt.h"

typedef unsigned long long uint64;

int longestChain = -1;
uint64 longestChainNumber = 0;

#define MAX_NUMBER 1000000


unsigned int * chainLength = NULL;

void calcChain(const uint64 startNum)
{
    int curLen = 1;
    uint64 curNum = startNum;
    bool found = false;
    while( !found ) {
        if( (curNum < MAX_NUMBER) && (chainLength[curNum] != 0) ) {
            curLen += chainLength[curNum] - 1;
            chainLength[startNum] = curLen;

            if( curLen > longestChain ) {
                longestChain = curLen;
                longestChainNumber = startNum;
            }
            std::cout << "Found " << startNum << " " << curLen << std::endl;
            
            return;
        }
        else if(1 == curNum) 
        {
            chainLength[startNum] = curLen;
            found = true;
            std::cout << "Found " << startNum << " " << curLen << std::endl;
            return;
        }
        else
        {
            curNum = (curNum & 0x1) ? (curNum*3 + 1) : (curNum >> 1);
            //std::cout << old << " " << curNum << std::endl;
            curLen++;
        }
    }
}

int main(void)
{
    chainLength = new unsigned int[MAX_NUMBER];
    std::cout << sizeof(uint64) << std::endl;
    
    for( int i = 1 ; i < MAX_NUMBER; ++i )
    {
        chainLength[i] = 0;
    }
    
    for( int i = 1 ; i < MAX_NUMBER; ++i )
    {
        calcChain(i);
    }
    
    std::cout << "The number " << longestChainNumber << " Chain Length " << longestChain << std::endl;
    return 0;
}

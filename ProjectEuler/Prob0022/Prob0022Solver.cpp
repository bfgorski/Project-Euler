//
//  Prob0022Solver.cpp
//  ProjectEuler
//
//  Created by Benjamin Gregorski on 3/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
 
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.
 
 What is the total of all the name scores in the file?
 
 */

#include <iostream>
#include <fstream>
#include "Prob0022Solver.h"
#include <vector>

int compare( char ** s0,  char ** s1);

int compare( char ** s0,  char ** s1) {
    
    
    //if (0 == strcmp("\"VICTORINA\"", s0))
    //std::cout << "Compare " << s0 << " " << s1 << std::endl;
    
    if (NULL == (*s0) && *s1) {
        return 1;
    } else if ((*s0) && NULL == (*s1)) {
        return -1;
    } else if( !(*s0) && !(*s1)) {
        return 0;
    }
    
    return strcmp(*s0, *s1);
}

struct myclass {
    bool operator() (std::string * s0, std::string * s1) { return (*s0 < *s1);}
} myobject;

bool Prob0022Solver::solve()
{
    std::ifstream infile;
    infile.open("names.txt", std::ios::in);
    
    long begin = infile.tellg();
    infile.seekg (0, std::ios::end);
    long end = infile.tellg();
    
    std::cout << "size is: " << (end-begin) << " bytes.\n";
    std::cout << (46*1024) << std::endl;
    
    if (infile.is_open()) {
        infile.seekg (0, std::ios::beg);
        long bufferSize = (end-begin) + 1;
        char * data = new char[bufferSize];
        memset(data, 0, bufferSize);
        infile.read(data, bufferSize);
        
        std::vector<std::string*> names;
        
        char * pch = strtok (data, ",");
        while (pch != NULL)
        {
            std::string * s = new std::string(pch);
            names.push_back(s);
            //std::cout << s << std::endl;
            pch = strtok (NULL, ",");
        }
        
        std::sort(names.begin(), names.end(), myobject);
        
        int64 total = 0;
        int i = 1;
        int base = int('A') - 1;
        for (std::vector<std::string*>::iterator it = names.begin(); it != names.end(); ++it, ++i) {
            std::string * s = (*it);
            const char * cStr = s->c_str();
            
            int score = 0;
            while((*cStr) != '\0') {
                char c = *cStr;
                if (isalpha(c)) {
                    score += (int(c) - base);
                }
                ++cStr;
            }
            
            total += (i*score);
            std::cout << (*(*it)) << " " << (i*score) << " " << total << std::endl;
        }
        
        this->m_i64Result = total;
    } else {
        std::cout << "Unable to open names.txt" << std::endl;
    }
    
    return true;
}
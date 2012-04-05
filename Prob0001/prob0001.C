
/*
Project Euler Problem 1.

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23.  
Find the sum of all the multiples of 3 or 5 below 1000.

*/

#include <iostream>

int main()
{
  using namespace std;
  unsigned int total = 0;
  
  for( int i = 3; i < 1000; ++i)
  {
    if( 0 == (i % 3) )
    {
       total += i;
    }
    else if( 0 == (i % 5) )
    {
       total += i;
    }
  } 

  cout << "The sum of all the multiples of 3 or 5 below 1000 is: " << total << endl ;
  return 0;
}


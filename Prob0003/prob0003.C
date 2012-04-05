/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <set>
#include <math.h>

using namespace std;
typedef long long int int64;

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

  // if we didn't find any numbers thaqt divide p then it is prime
  primeFactors.insert(p);
}


int main(void)
{
  int64 num = 600851475143;
 
  set< int64 > primeFactors;
  primeFactor(num, primeFactors);

  set<int64>::iterator it = primeFactors.begin();

  int64 total = 1;
  cout << "prime factors for " << " " << num << " " ;
  for(; it != primeFactors.end(); ++it)
  {
    total *= (*it);
    cout << (*it) << " " ;

  }
  cout << endl << " " << total << endl ;
  return 0;
}

/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include <iostream>
#include <vector>
#include <math.h>

int main(int argc, char * argv[])
{
  using namespace std;
  unsigned int maxPrime = atoi(argv[1]);
  vector<unsigned int> primes;
  primes.reserve(150000);

  primes.push_back(2);
  long long sumOfPrimes = 2;

  for( unsigned int i = 3 ; i < maxPrime ; i+=2) {
    bool isPrime = true;
    unsigned int lastPrimeToCheck = static_cast<unsigned int>( floor( sqrt(i) ) );

    for(unsigned int j = 1 ; (j < primes.size()) && (primes[j] <= lastPrimeToCheck) ; ++j) {
      unsigned int p = i / primes[j];
      if( p*primes[j] == i ) {
        isPrime = false;
        break;
      } 
    }
    if( isPrime ) { 
      primes.push_back(i);
      sumOfPrimes += i;  
      cout << "Prime " << primes.size() << " " << i << " " << sumOfPrimes << endl;
    }
  }

  cout << "The sum of all the primes below " << maxPrime << " is " << sumOfPrimes << endl;

  return 0;
}


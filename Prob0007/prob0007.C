/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?

*/

#include <iostream>
#include <vector>

static const int PRIME_COUNT = 10001;

int main()
{
   using namespace std;
   long long primes[PRIME_COUNT] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
   int primeCount = 11;

   long long currentVal = 32;

   while(primeCount < PRIME_COUNT) {
     bool isPrime = true;
     for( int i = 0 ; i < primeCount; ++i ) {
       long long d = currentVal / primes[i];
       if( d*primes[i] == currentVal ) {
          isPrime = false;
          break;
       } 
     }
    
     if( isPrime ) {
       primes[primeCount++] = currentVal;
     }

     currentVal++;
   }

   cout << "The 10001st prime number is " << primes[PRIME_COUNT-1] << endl;
   return 0;
}



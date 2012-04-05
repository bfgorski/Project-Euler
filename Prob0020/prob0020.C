/*
n! means n  (n  1)  ...  3  2  1

Find the sum of the digits in the number 100!

*/

#include <iostream>
#include "../common/BigInt.h"

int main(int argc, char * argv[])
{
  if( argc < 2 ) {
    std::cout << "Usage: sumFact X" << std::endl;
    std::cout << "Sum the digits in X!" << std::endl;
    return 0;
  }

  int X = atoi(argv[1]);

  using namespace std;

  BigInt b( 10, 1  );
  b.Factorial(X);

  cout << b << " " << b.SumDigits() << endl;
  return 0;
}

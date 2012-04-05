/*

The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.



*/

#include <iostream>

int main()
{
  using namespace std;

  unsigned int squareOfSum = (100*101) >> 1;
  squareOfSum *= squareOfSum;

  unsigned sumOfSquares = 0;
  for( int i = 0 ; i <= 100; ++i)
  {  
    sumOfSquares += i*i;
  }

  unsigned int diff = (sumOfSquares > squareOfSum) ? ( sumOfSquares - squareOfSum) : (squareOfSum - sumOfSquares);

  cout << "Diff is " << diff << endl;
  return 0;
}


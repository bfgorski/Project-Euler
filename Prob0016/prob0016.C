/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/

#include <iostream>
#include "../common/BigInt.h"

int main(void)
{
  using namespace std;

  BigInt b( 305, 1  );

  for( int i = 0 ; i < 1000; ++i ) {
    b.Double();
  }

  cout << b << endl;
  cout << "the sum of the digits of the number 2^1000 " << b.SumDigits() << endl;
  return 0;
}

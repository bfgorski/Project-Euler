/*

A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#include <iostream>

int main(int argc, char * argv[] )
{
  using namespace std;

  const unsigned int sum = 1000;
  unsigned int squares[sum+1];

  for( unsigned int i = 1 ; i <= sum; ++i) {
    squares[i] = (i)*(i);
  }

  unsigned int c = 0, b = 0, a = 0;

  // a,b,c must be non-zero
  for( c = (sum-2); c > 0; --c ) {
    unsigned int BPlusA = sum - c;
    unsigned int BStart = BPlusA - 1;
    unsigned int bMin = BPlusA >> 1;
    for( b = BStart; b >= bMin; --b ) {
      a = (BPlusA - b);
      if( squares[c] == (squares[b] + squares[a]) ) {
        cout << "A/B/C " << a << " " << b << " " << c << " " << "(" << squares[a] << " + " << squares[b] << ") = " << squares[c] << " (a*b*a) = " << (a*b*c) << endl;
        return 0;
      }
    } 
  }

  return 0;
}



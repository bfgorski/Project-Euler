/*

A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <iostream>

bool isPalindrome(unsigned int p)
{
  unsigned int digits[6];  
  unsigned int newP = p;

  for(int i = 0 ; i < 6; ++i) {
    digits[i] = newP % 10;
    newP = newP / 10;  
  }

  if( digits[0] != digits[5] ||
      digits[1] != digits[4] ||
      digits[2] != digits[3]) { return false; }
  return true;
}

int main(void)
{
  using namespace std;

  unsigned int maxPal = 0;
  for( unsigned int i = 100 ; i < 999; ++i) {
    for( unsigned int j = 100 ; j < 999; ++j) {
      unsigned p = i*j;
      if( isPalindrome(p) ) {
        if( p > maxPal ) { maxPal = p; }
      }
    }
  }

  cout << "The largest palindrome made from the product of two 3-digit numbers is " << maxPal << endl;
  return 0;
}


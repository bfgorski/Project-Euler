#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <iostream>
#include <math.h>

class BigInt
{
  public :
     BigInt(const int size, const int initialValue = 0): m_size(size), m_digits() 
     {
       Init(initialValue); 
     }

     BigInt( const BigInt& b ) : m_size(b.m_size), m_digits(b.m_digits)
     {
     }

     unsigned int size() const { return m_digits.size(); }
     void Set(unsigned int index, unsigned int value) { m_digits[index] = value; }

     friend std::ostream& operator<<(std::ostream& os, const BigInt& b)
     {
       using namespace std;
       for( int i = (b.m_digits.size()-1); i >= 0; --i)
       {
         os << b.m_digits[i];
       }
       return os;
     }

     BigInt& operator+=(const BigInt& b ) 
     {
using namespace std;

       int carry = 0;
       for(int i = 0; i < b.m_size; ++i) {
         int result = m_digits[i] + b.m_digits[i] + carry;

         if( result > 9 ) {
           m_digits[i] = result - 10;
           carry = 1;
          }
          else {
            m_digits[i] = result;
            carry = 0;
          } 
       }
 
       if( carry > 0 ) { m_digits[b.size()] = carry; }

     }
/*
     BigInt& operator*=( const unsigned int a )
     {
using namespace std;

        BigInt b(m_size,0);

        unsigned int rhs = a;
        unsigned int startPosition = 0;

        while( rhs > 0 ) {
           unsigned int lsd = rhs % 10;
           rhs = rhs / 10;
           MulAddLessThan10( b, (*this), lsd, startPosition ); 
           startPosition++;
cout << (*this) << " " << b << " " << lsd << endl;
        }

        m_digits = b.m_digits;
        return (*this); 
     }
*/
     void Init(const int initialValue)
     {
       m_digits.clear();
       m_digits.reserve(m_size);

       for( int i = 0 ; i < m_size; ++i ) { m_digits.push_back(0) ; }

       int curVal = initialValue;
       int curIndex = 0;
       do {
         int digit = curVal % 10;
         curVal /= 10;
         m_digits[curIndex] = digit;
         curIndex++; 
       } while(curVal > 0);
     }

     void Double()
     {
       int carry = 0;
       for(int i = 0; i < m_digits.size(); ++i) {
         int result = m_digits[i]*2 + carry;
         if( result > 9 ) {
           m_digits[i] = result - 10;
           carry = 1;
          }
          else {
            m_digits[i] = result;
            carry = 0;
          } 
       } 

       if( carry > 0 ) { m_digits.push_back(carry); }
     }

     unsigned int SumDigits() {
       unsigned int sum = 0;
       for( int i = 0 ; i < m_digits.size(); ++i ) {
         sum += m_digits[i];
       }
       return sum;
     }

     //
     // Set value to X!
     //
     void Factorial(unsigned int X)
     {
       using namespace std;
       // estimate number of digits in f!

       float f = static_cast<float>(X);
       float estSize = ceil(f*log10(f)); 
       unsigned int size = static_cast<unsigned int>(estSize);
//cout << "Size of " << X << "! " << size << endl;

       DigitsType a(size,0), b(size,0);
       a[0] = 1;

       DigitsType * pSource = &a, * pDest = &b;

       for(int i = 1 ; i <= f; ++i) {
         Multiply( pSource, i, pDest );
         // Multiply A*i and store result in B
         // then flip and multiple B*i and store result in A
         DigitsType * pTemp = pDest;
         pDest = pSource;      
         pSource = pTemp;
       }

       m_digits = (*pSource);
       m_size = size;
     }

  private:

    typedef std::vector<unsigned int> DigitsType;

    void Print( const DigitsType& d, std::ostream& os ) 
    {
       for( int i = (d.size()-1); i >= 0 ; --i ) {
         os << d[i];
       }
    }


    // pDest = pSource * X;
    void Multiply( const DigitsType * pSource, unsigned int X, DigitsType * pDest )
    {
        using namespace std;
        unsigned int rhs = X;
        unsigned int startPosition = 0;
        
        for( int i = 0 ; i < pDest->size(); ++i ) { (*pDest)[i] = 0; }

        while( rhs > 0 ) {
           unsigned int lsd = rhs % 10;
           rhs = rhs / 10;
           MulAddLessThan10( (*pDest), (*pSource) , lsd, startPosition ); 
           startPosition++;
        }



    }

    //
    // Calculate C = C + B*A. 
    // A < 10
    // cDigitStartIndex indicates what place in C to start adding B*A
    // i.e to multiply B by 800 A = 8 cDigitStart = 2.
    //
    static void MulAddLessThan10(DigitsType& C, const DigitsType& B, unsigned int A, unsigned int cDigitStartIndex)
    {
      unsigned int carry = 0;
      for( int i = 0 ; i < B.size() ; ++i ) {
        int result = B[i]*A + carry + C[i+cDigitStartIndex];

        if( (i+cDigitStartIndex) >= C.size() ) {
          C.push_back( result % 10 );
        }
        else {
          C[i+cDigitStartIndex] = result % 10;
        }

        carry = result / 10;
      }
    } 


    int m_size;
    DigitsType m_digits; // 0 is least significant digit.

};

#endif // BIGINT_H

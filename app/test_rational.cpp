#include "ra/rational.hpp"
#include <cassert>
#include <limits>
#include <iostream>
#include <algorithm>
int main()
{
    using namespace std;
    using namespace ra::math;
    
   // rational<int> a;
   // cin >> a;
    
    //test for default constructor
    rational<int> t1;
    assert(t1.numerator() == 0 && t1.denominator() == 0);
    
    cout<<"passes default constructor!"<< endl;
    //test for two value constructor
    rational<int> t2(1,3);
    assert(t2.numerator() == 1 && t2.denominator() == 3);
    cout<<"passes two value constructor!"<< endl;
   
    //test for denominator 0
    rational<int> t3(4,0);
    assert(t3.numerator() == numeric_limits<int>::max() && t3.denominator() == 1);   
    cout<<"passes denominator 0!"<< endl;
    
    //check for coprime
    rational<int> t4(2296,113);
    int gcd = __gcd(2296,113);
    assert(t4.numerator() == 2296/gcd && t4.denominator() == 113/gcd);   
    cout<<"passes coprime "<< endl;
    
    //check for negative denominator
    rational<int> t5(3,-6);
    assert(t5.numerator() == -1 && t5.denominator() == 2);   
    
    //+=
    rational<int> a1(1,2);
    rational<int> a2(1,4);
    a1 += a2;
    assert(a1.numerator() == 3 && a1.denominator() == 4);
    
    //-=
    rational<int> m1(1,2);
    rational<int> m2(1,-4);
    m1 -= m2;
    assert(m1.numerator() == 3 && m1.denominator() == 4);

    //-=
    rational<int> m11(1,2);
    rational<int> m21(1,4);
    m21 -= m11;
    assert(m21.numerator() == -1 && m21.denominator() == 4);
    
    //*=
    rational<int> mm11(6,-9);
    rational<int> mm21(3,4);
    mm21 *= mm11;
    assert(mm21.numerator() == -1 && mm21.denominator() == 2);

    //*=
    rational<int> mm1(1,2);
    rational<int> mm2(1,4);
    mm1 *= mm2;
    assert(mm1.numerator() == 1 && mm1.denominator() == 8);

    // /= 
    rational<int> d1(1,2);
    rational<int> d2(1,-4);
    d1 /= d2;
    assert(d1.numerator() == -2 && d1.denominator() == 1);
       

    cout<<"All tests passes!"<< endl;
    return 0;
}

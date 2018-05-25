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
       
    
    // truncate
    rational<int> tr1(-2296,113);
    int number = tr1.truncate();
    assert(number == -20);

    //truncate
    rational<int> tr2(-2296,41);
    int number2 = tr2.truncate();
    assert(number2 == -56);
    
    //truncate
    rational<int> tr3(-2,4);
    cout << "Rational!" << endl;
    int number3 = tr3.truncate();
    assert(tr3.numerator() == 0 && tr3.denominator() == 1);
    assert(number3 == 0);

    //is_int
    rational<int> isint1(3,4);
    rational<int> isint2(2,-2);
    rational<int> isint3(10,5);
    assert(!isint1.is_integer() && isint2.is_integer() && isint3.is_integer());

    //!
    rational<int> zero1(3,4);
    rational<int> zero2(2,-2);
    rational<int> zero3(0,5);
    assert(!zero1 == false && !zero2 == false && !zero3);
    assert(zero3.numerator() == 0 && zero3.denominator() == 1);
    cout<<"All tests passes!"<< endl;
    return 0;

    //==
    rational<int> eq1(3,4);
    rational<int> eq2(6,8);
    rational<int> eq3(10,5);
    rational<int> eq4(5,10);

    assert(eq1==eq2);
    assert(!(eq1 == eq3) && !(eq1 == eq4));
    
    assert(eq1 != eq3 && eq1 != eq4);
    
    assert(eq4 < eq2);
    assert(eq3 > eq2 && eq3 > eq4);

    assert(eq4 <= eq2);
    assert(eq3 >= eq2 && eq3 >= eq4);

    //prefix add
    rational<int> add(4,6);
    add++;
    assert(add.numerator() == 5 && add.denominator() == 3);
    ++add;
    assert(add.numerator() == 8 && add.denominator() == 3);
}

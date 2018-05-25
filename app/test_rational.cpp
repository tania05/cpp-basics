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
    rational<int> t4(2296,112);
    int gcd = __gcd(2296,112);
    cout<< gcd << endl;
    
    assert(t4.numerator() == 2296/gcd && t4.denominator() == 113/gcd);   
    cout<<"passes coprime check"<< endl;
    
    
    cout<<"All tests passes!"<< endl;
    return 0;
}

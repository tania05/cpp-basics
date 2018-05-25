#include <iostream>
#include "ra/random.hpp"
#include <cassert>

int main() 
{
    using namespace ra::random;
    using namespace std;

    linear_congruential_generator gen(2,4,5,4);

    cout << gen() << endl;
    cout << gen() << endl;
    cout << gen() << endl;
    cout << gen() << endl;
    gen.discard(2);
    cout << gen.min() << endl;
    cout << gen.max() << endl;
    cout << gen() << endl;
    cout << gen() << endl;
    cout << gen() << endl;
    cout << gen() << endl;
    
    linear_congruential_generator another1(2,4,5,4);
    linear_congruential_generator another2(2,4,5,4);
    assert(another1==another2);
    another1();
    assert(another1!=another2);
//copy
    linear_congruential_generator c1(1,2,3,4);
    linear_congruential_generator c2(c1);
    assert(c1==c2);

//move 
    linear_congruential_generator m1(1,2,3,4);
    linear_congruential_generator m2(std::move(m1));
    
    cout<< m2 << "\n";

    return 0;
}


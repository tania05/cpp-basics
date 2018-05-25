#include <iostream>
#include "ra/random.hpp"

namespace ra{
namespace random {

    linear_congruential_generator::linear_congruential_generator(linear_congruential_generator::int_type multiplier, linear_congruential_generator::int_type increment,  linear_congruential_generator::int_type modulus, linear_congruential_generator::int_type seed) :
        multiplier_(multiplier),
        increment_(increment),
        modulus_(modulus),
        x0_(seed),
        xi_(seed),
        prev_(seed)
    {
        
    }

    /* linear_congruential_generator::linear_congruential_generator(linear_congruential_generator& other) 
    {
        multiplier_ = other.multiplier_;
        increment_ = other.increment_;
        modulus_ = other.modulus_;
        x0_ = other.x0_;
        xi_ = other.xi_;
        prev_ = other.prev_;
    }*/
		//Returns the multiplier value a 
    linear_congruential_generator::int_type linear_congruential_generator::multiplier() const 
    {
        return multiplier_;
    }
		
		//returns the increment value c
    linear_congruential_generator::int_type linear_congruential_generator::increment() const 
    {
        return increment_;
    }
		
		//returne the modulus value m
    linear_congruential_generator::int_type linear_congruential_generator::modulus() const 
    {
        return modulus_;
    }
		
    void linear_congruential_generator::seed(linear_congruential_generator::int_type new_seed)
    {
        x0_ = new_seed;
        xi_ = x0_;
        prev_ = x0_;
    }
		//Returns the default seed value x0
    linear_congruential_generator::int_type linear_congruential_generator::default_seed()
    {
        return 1;
    }
		
        //Advances the generator to the next position
    linear_congruential_generator::int_type linear_congruential_generator::operator()()
    {
        prev_ = xi_;
        xi_ = (multiplier_*prev_ + increment_) % modulus_;
        return xi_;
    }
		
		//Discards the next n numbers in the generated sequence
    void linear_congruential_generator::discard(unsigned long long n)
    {
        for(unsigned long long i=0; i< n; i++)
        {
           (*this)();
        }
    }
		
		//Returns the potential smallest value
    linear_congruential_generator::int_type linear_congruential_generator::min() const
    {
        return increment_ == 0 ? 1 : 0;
    }
		
		//Returns the potential largest value
    linear_congruential_generator::int_type linear_congruential_generator::max() const
    {
        return modulus_ - 1;
    }
		
		//Equality
    bool linear_congruential_generator::operator==(const linear_congruential_generator& other) const
    {
        return xi_ == other.xi_ && increment_ == other.increment_ && multiplier_ == other.multiplier_ && modulus_ == other.modulus_;
    }
		
		//Inequality
    bool linear_congruential_generator::operator!=(const linear_congruential_generator& other) const
    {
        return xi_ != other.xi_ || increment_ != other.increment_  || modulus_ != other.modulus_ || multiplier_ != other.multiplier_;
    }
		
    std::ostream& operator<<(std::ostream& os, const linear_congruential_generator& other) 
    {
        os << other.multiplier_ << ' ' << other.increment_ << ' ' << other.modulus_ << ' ' << other.xi_;
        return os;
    }

}
}

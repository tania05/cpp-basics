#ifndef RANDOM_H
#define RANDOM_H 

#include <iostream>
namespace ra
{
namespace random
{
class linear_congruential_generator { 
    public:
        using int_type =  unsigned long long;
		linear_congruential_generator(int_type multiplier, int_type increment, int_type modulus, int_type seed = default_seed());
		linear_congruential_generator(linear_congruential_generator&&) = default;
		linear_congruential_generator(linear_congruential_generator&) = default;
		~linear_congruential_generator() = default;
	    linear_congruential_generator& operator=(linear_congruential_generator&&) = default;
        linear_congruential_generator& operator=(linear_congruential_generator&) = default;      

		//Returns the multiplier value a 
        int_type multiplier() const;
		
		//returns the increment value c
		int_type increment() const;
		
		//returne the modulus value m
		int_type modulus() const;
		
		//Returns the default seed value x0
		static int_type default_seed();
        
        void seed(int_type new_seed);        

		//Advances the generator to the next position
		int_type operator()();
		
		//Discards the next n numbers in the generated sequence
		void discard(unsigned long long n);
		
		//Returns the potential smallest value
		int_type min() const;
		
		//Returns the potential largest value
		int_type max() const;
		
		//Equality
		bool operator==(const linear_congruential_generator& other) const;
		
		//Inequality
		bool operator!=(const linear_congruential_generator& other) const;
		
    private:
        int_type multiplier_;
        int_type increment_;
        int_type modulus_;
        int_type x0_;
        int_type xi_;
        int_type prev_;
        friend std::ostream& operator<<(std::ostream& os, const linear_congruential_generator&);
};

        std::ostream& operator<<(std::ostream& os, const linear_congruential_generator&);
};
};
#endif

#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>

class linear_congruential_generator { 
    public:
		linear_congruential_generator(int_type multiplier, int_type increment, int_type modulus, int_type seed = default_seed());
		linear_congruential_generator(linear_congruential_generator&&);
		linear_contruential_generator(linear_congruential_generator&);
		~linear_congruential_generator();
		
		//Returns the multiplier value a 
		int_type multiplier();
		
		//returns the increment value c
		int_type increment();
		
		//returne the modulus value m
		int_type modulus();
		
		//Returns the default seed value x0
		static int_type default_seed();
        
        int_type seed(int_type new_seed);        

		//Advances the generator to the next position
		int_type operator()();
		
		//Discards the next n numbers in the generated sequence
		void discard(unsigned long long n);
		
		//Returns the potential smallest value
		int_type min();
		
		//Returns the potential largest value
		int_type max();
		
		//Equality
		bool operator==(const linear_congruential_generator& other);
		
		//Inequality
		bool operator!=(const linear_congruential_generator& other);
		
		ostream& operator<<(ostream& os, const linear_congruential_generator& generator)

    private:
        int_type multiplier;
        int_type increment;
        int_type modulus;
        int_type x0;
}

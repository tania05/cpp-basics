#include <iostream>
#include "include/ra/random.hpp"

		
    linear_contruential_generator::linear_congruential_generator(int_type multiplier, int_type increment, int_type modulus, int_type seed = default_seed())
    {
        this.multiplier = multiplier;
        this.increment = increment;
        this.modulus = modulus;
        this.x0 = seed;
    };
		
    linear_contruential_generator::linear_congruential_generator(linear_congruential_generator&&) = default;
		
    linear_congruential_generator::linear_contruential_generator(linear_congruential_generator&) = default;
		
    linear_congruential_generator::~linear_congruential_generator() = default;
		
		//Returns the multiplier value a 
    int_type linear_congruential_generator::multiplier()
    {
        return multiplier;
    };
		
		//returns the increment value c
    int_type linear_contruential_generator::increment()
    {
        return increment;
    };
		
		//returne the modulus value m
    int_type linear_congruential_generator::modulus()
    {
        return modulus;
    };
		
    void linear_congruential_generator::seed(int_type new_seed)
    {
        this.x0 = new_seed
    }
		//Returns the default seed value x0
    static int_type linear_contruential_generator::default_seed()
    {
        return 1;
    };
		
        //Advances the generator to the next position
    int_type linear_contruential_generator::operator()();
		
		//Discards the next n numbers in the generated sequence
    void linear_congruential_generator::discard(unsigned long long n);
		
		//Returns the potential smallest value
    int_type linear_contruential_generator::min();
		
		//Returns the potential largest value
    int_type linear_contruential_generator::max();
		
		//Equality
    bool linear_contruential_generator::operator==(const linear_congruential_generator& other);
		
		//Inequality
    bool linear_contruential_generator::operator!=(const linear_congruential_generator& other);
		
    ostream& linear_contruential_generator::operator<<(ostream& os, const linear_congruential_generator& generator)
			


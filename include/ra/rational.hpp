#include <iostream>

namespace ra{
namspace math{
    template <typename T>
    class rational
    {
        public:
            using int_type = T;
            rational() : n_(0), d_(0) {}
            rational(int_type n, int_type d = 1) :  n_(n), d_(d)
            {
                //TODO
            }
            rational(rational&&) = default;
            rational& operator=(rational&&) = default;

            rational(rational&) = default;
            rational& operator=(rational&) = default;
            
            ~rational() = default;
            
            int_type numerator() const
            {
                return n_;
            }

            int_type denominator() const
            {
                return d_;
            }

            //TODO
            rational& operator+=(const rational& other)
            {
                return *this;
            }

            //TODO
            rational& operator-=(const rational& other)
            {
                return *this;
            }

            //TODO
            rational& operator*=(const rational& other)
            {   
                return *this;
            }

            //TODO
            rational& operator/=(const rational& other)
            {
               return *this;
            }
            
            //TODO    
            int_type truncate() const
            {
                return 0;
            }

            bool is_integer() const
            {
                return n_ % d_ == 0;
            }
            
            bool operator!() const
            {
                return n_ = 0;
            }


            bool operator==(const rational& other) const 
            {
                return n_/d_ == other.n_ / other.d_;
            }

            bool operator!=(const rational& other) const 
            {
                return n_/d_ != other.n_ / other.d_;
            }
            
            bool operator<(const rational& other) const
            {
                return n_/d_ < other.n_ / other.d_;
            }

            bool operator>(const rational& other) const
            {
                return n_/d_ > other.n_ / other.d_;
            }
            
            bool operator<=(const rational& other) const
            {
                return n_/d_ < other._n/other.d_ || n_/d_ == other.n_/other.d_;
            }
            
            bool operator>=(const rational& other) const
            {
                return n_/d_ < other.n_/other.d_ || n_/d_ == other.n_/other.d_;
            }
            
            //Preincrement
            rational& operator++()
            {
                n_ = n_+d_;
                return *this;
            } 

            rational operator++(int)
            {
                rational tmp(*this);
                operator++();
                return tmp;
            }

        private:
            int_type n_;
            int_type d_;
    }
    //TODO
    //binary plus
    template<typename T>
    rational<T> operator+(rational<T>& a, rational<T>& b)
    {
        return rational<T>();
    }

    //binary minus
    template<typename T>
    rational<T> operator-(rational<T>&a, rational<T>& b)
    {
        return rational<T>();
    }

    //binary multiply
    template<typename T>
    rational<T> operator*(rational<T>&a, rational<T>& b)
    {
        return rational<T>();
    }
    
    //binary divide
    template<typename T>
    rational<T> operator/(rational<T>&a, rational<T>& b)
    {
        return rational<T>();
    }
   
    //unary minus 
    template<typename T>
    rational<T> operator-(const rational<T>&a)
    {
        return rational<T>();
    }

    //unary plus
     template<typename T>
    rational<T> operator+(const rational<T>&a)
    {
        return rational<T>();
    }
}
}

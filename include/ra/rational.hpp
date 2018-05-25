#include <iostream>
#include <numeric>
#include <limits>

namespace ra{
namespace math{

    template <typename T>
    class rational
    {
        public:
            using int_type = T;
            rational() : n_(0), d_(0) {}
            rational(int_type n, int_type d = 1) :  n_(n), d_(d)
            {
                if(d == 0)
                {
                    n_ = std::numeric_limits<int_type>::max();
                    d_ = int_type(1); 
                }
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

            //to be used by the non-member stream extractor
            int_type& numerator()
            {
                return n_;
            }

            //to be used by the non-member stream extractor
            int_type& denominator()
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
            
             //prefix
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

            //prefix
            rational& operator--()
            {
                n_ = n_-d_;
                return *this;
            } 

            rational operator--(int)
            {
                rational tmp(*this);
                operator--();
                return tmp;
            }

        private:
            int_type n_;
            int_type d_;
            void make_coprime()
            {
                using namespace std;
               int_type gcd_ = (int_type) __gcd(n_,d_);
               n_ = n_/gcd_;
               d_ = d_/gcd_;
            } 
            void check_negative_denominator()
            {
                if(d_ < 0)
                {
                    n_ = n_*-1;
                    d_ = d_*-1; 
                }
            }
    };
    //TODO
    //binary plus
    template<typename T>
    rational<T> operator+(rational<T>& a, rational<T>& b)
    {   rational<T> tmp;
        tmp = a+b;
        return tmp;
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

    template<typename T>
    std::ostream& operator<<(std::ostream& os, rational<T>& r)
    {
        if(r.numerator() < 0)
        {
            os << "-";
        }
        os << r.numerator() << "/" << r.denominator();
        return os;
    }

    template<typename T>
    std::istream& operator>>(std::istream& is, rational<T>& r)
    {
       char sign;
       char slash;
       if(is.peek() == '-' || is.peek() == '+')
       {
           is >> sign;
       }
       else
       {
           //to be used for checking if we need to make things negative
           sign = '+';
       }

       is >> r.numerator();
       is >> slash;
       if(slash != '/')
       {
           is.setstate(std::ios_base::failbit);
       }
       else
       {
           is >> r.denominator();
       }

       if(sign == '-')
       {
           //TODO
           //Make thins negative
       }
       return is;

    }
};
};

#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>

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
                make_coprime();
            }
            rational(rational&&) = default;
            rational& operator=(rational&&) = default;

            rational(const rational&) = default;
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
                n_ = n_*other.d_ + other.n_*d_ ;
                d_ *= other.d_;
                make_coprime();
                return *this;
            }

            //TODO
            rational& operator-=(const rational& other)
            {
                n_ = n_*other.d_ - other.n_*d_ ;
                d_ *= other.d_;
                make_coprime();
                return *this;
            }

            //TODO
            rational& operator*=(const rational& other)
            {   
                n_ *= other.n_; 
                d_ *= other.d_;
                make_coprime();
                return *this;
            }

            //TODO
            rational& operator/=(const rational& other)
            {
                n_ *= other.d_; 
                d_ *= other.n_;
                make_coprime();
                return *this;
            }
            
            //TODO    
            int_type truncate() const
            {   
                
                return (int_type) (n_ - (n_ % d_)) / d_;
            }

            bool is_integer() const
            {
                return n_ % d_ == 0;
            }
            
            bool operator!() const
            {
                return n_ == 0;
            }


            bool operator==(const rational& other) const 
            {
                return is_equals(other);
            }

            bool operator!=(const rational& other) const 
            {
                return n_ != other.n_ || d_ != other.d_;
            }
            
            bool operator<(const rational& other) const
            {
                return is_less(other);
            }

            bool operator>(const rational& other) const
            {
                return is_more(other);
            }
            
            bool operator<=(const rational& other) const
            {
                return is_less(other) || is_equals(other);
            }
            
            bool operator>=(const rational& other) const
            {
                return is_equals(other) || is_more(other);
            }
            
             //prefix
            rational& operator++()
            {
               n_ = n_ + d_;
               make_coprime(); 
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
                make_coprime();
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
            bool is_equals(const rational& other) const 
            {
                return n_ == other.n_ && d_ == other.d_;
            }

            bool is_less(const rational& other) const
            {
                return n_*other.d_ < other.n_*d_;
            }

            bool is_more(const rational& other) const
            {
                return n_*other.d_ > other.n_*d_;
            }

            void make_coprime()
            {
               check_negative_denominator();
               using namespace std;
               int_type gcd_ = (int_type) __gcd(n_,d_);
               n_ = n_/abs(gcd_);
               d_ = d_/abs(gcd_);
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
    rational<T> operator+(const rational<T>& a, const rational<T>& b)
    {   
        rational<T> tmp(a);
        tmp.operator+=(b);
        return tmp;
    }

    //binary minus
    template<typename T>
    rational<T> operator-(const rational<T>&a, const rational<T>& b)
    {
        rational<T> tmp(a);
        tmp.operator-=(b);
        return tmp;
    }

    //binary multiply
    template<typename T>
    rational<T> operator*(const rational<T>&a, const rational<T>& b)
    {
        rational<T> tmp(a);
        tmp.operator*=(b);
        return tmp;
    }
    
    //binary divide
    template<typename T>
    rational<T> operator/(const rational<T>&a, const rational<T>& b)
    {
        rational<T> tmp(a);
        tmp.operator/=(b);
        return tmp;
    }
   
    //unary plus 
    template<typename T>
    rational<T> operator+(const rational<T>&a)
    {
        return rational<T>(a);
    }

    //unary minus
    template<typename T>
    rational<T> operator-(const rational<T>&a)
    {
        rational<T> tmp(a.numerator()*-1, a.denominator());
        return tmp;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const rational<T>& r)
    {
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
           is.setstate(std::ios_base::failbit);
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

       return is;

    }
};
};

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
        private:
            int_type n_;
            int_type d_;
    }
}
}

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <limits>



class Fixed
{
    private:
    int fp_Nbr;
    static const int fraction_bit = 8; 

    public:

    Fixed();
    ~Fixed();

    Fixed(const Fixed& other);

    //Copy assignment operator called
    Fixed& operator=(const Fixed& other);


    int getRawBits(void) const;
    void setRawBits(int const raw);

};


#endif
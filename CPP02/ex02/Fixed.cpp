/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:43:12 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 10:57:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(){
     std::cout << "Default constructor called" << std::endl;
     setRawBits(0); 
}; 

// convert to fixed-point values -> init to 8;
//  Shift bits left by 8 to convert to fixed point
//  '<<' now as bitshift operator '8' positions 
// 2 << 8 = 2*256 = 512 ( 2 ^ fraction_bit)
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point_Nbr = value << this->fraction_bit;
};

//converts float to fixed-point value(int)
// dezimalstellen werden gerundet
// 1 << fraction_bit= (0000 0001) = 256 -> 0001 0000 0000
// saves->  1,5 *256 = 384 (binary) 0000 0001 1000 0000
// convertig back 384/256 = 1,5 in toFloat
Fixed::Fixed(const float float_value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point_Nbr = roundf(float_value *(1 << this->fraction_bit));
};

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point_Nbr = other.getRawBits();

};

Fixed::~Fixed(){
    //std::cout << "Destructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;\
    if(this != &other)
    {
        this->fixed_point_Nbr = other.getRawBits();
    }
    return *this;
};

int Fixed::getRawBits(void) const
{
    return(this->fixed_point_Nbr);
};

 void Fixed::setRawBits (int const raw)
 {
    this->fixed_point_Nbr = raw;
 };



// 384 becomes 384.0 (float)
//  shifted left bei 8 zeros -> 1 becomes 256 (Fraction part is 8 bits long)
// smaller Fraction part -> more space for integer part (32 bits so 32 0 and 1)
// 1 << this->fraction_bit so its scaleable 2^fraction_bit
// convertig back 384/256 = 1,5 
float Fixed::toFloat( void ) const{
    float value = (float)this->fixed_point_Nbr; 
    float dominator = (1 << this->fraction_bit);
    return value/dominator;
};


// fixed point nbr 
int Fixed::toInt(void) const {
    // std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    int value = this->fixed_point_Nbr;
    return value >> this->fraction_bit;
};



// friend function
std::ostream& operator<<(std::ostream& output_obj, const Fixed&object_fixed)
{
    output_obj << object_fixed.toFloat();
    return(output_obj);
}



bool Fixed::operator<(const Fixed& out_object) const
{
    if(this->fixed_point_Nbr < out_object.fixed_point_Nbr)
        return true;
    return false;
};

bool Fixed::operator>(const Fixed& out_object) const
{
    if(this->fixed_point_Nbr > out_object.fixed_point_Nbr)
        return true;
    return false;
};

bool Fixed::operator<=(const Fixed& out_object) const
{
    if(this->fixed_point_Nbr <= out_object.fixed_point_Nbr)
        return true;
    return false;
};

bool Fixed::operator>=(const Fixed& out_object) const
{
    if(this->fixed_point_Nbr >= out_object.fixed_point_Nbr)
        return true;
    return false;
};

bool Fixed::operator==(const Fixed& o_object) const
{
    if(this->fixed_point_Nbr == o_object.fixed_point_Nbr)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& o_object) const
{
    if(this->fixed_point_Nbr != o_object.fixed_point_Nbr)
        return true;
    return false;
}


// Arithmetic operators
// return by value not by reference (Fixed&)
Fixed Fixed::operator*(const Fixed& o_object) const
{
    Fixed tmp_object;
    tmp_object.fixed_point_Nbr = (long long)this->fixed_point_Nbr *o_object.fixed_point_Nbr;// save for overflow
    tmp_object.fixed_point_Nbr = tmp_object.fixed_point_Nbr >> fraction_bit;
    return (tmp_object);
}

/*
a = 1,5 -> fixed_point_Nbr = round (1,5 *256) = 384 in binary 0000 0001 1000 0000 (8 bits reserved for the fraction part)
b = 2    -> fixed_point_Nbr = round (2 * 256) = 512 in binary 0000 0011 0000 0000 

384 * 512 = 196608 
in binary => 0000 0011 0000 0000 0000 0000 0000
both nubers are scaled by 256 -> result is scaled by 256*256
-> shift back by 8 bits(Franction part) divide by 256

*/

Fixed Fixed::operator/(const Fixed& o_object) const
{
    Fixed tmp_object;
    long long numerator = (long long)this->fixed_point_Nbr << fraction_bit;// get fraction part shift 8 binary to the left ( *256)
    tmp_object.fixed_point_Nbr = numerator  / o_object.fixed_point_Nbr; 
    return (tmp_object);
}
/*
Fixed(5.05f) -> fixed_point_Nbr = round(5.05 *256) = 1293
Fixed(2)      -> fixed_point_Nbr = 2 << 8 = 512
BUT 523 / 256 = 2.0 it should be 2.525
1293 / 512 = 2      int division, fractional part lost 
*/

Fixed Fixed::operator+(const Fixed& o_object) const
{
    Fixed tmp_object;
    long long a = (long long) this->fixed_point_Nbr << fraction_bit;
    long long b = (long long) o_object.fixed_point_Nbr << fraction_bit;
    tmp_object.fixed_point_Nbr = (a + b) >> fraction_bit;
    return(tmp_object);
}

Fixed Fixed::operator-(const Fixed& o_object) const 
{
    Fixed tmp_object;
    long long a = (long long) this->fixed_point_Nbr << fraction_bit;
    long long b = (long long) o_object.fixed_point_Nbr << fraction_bit;
    tmp_object.fixed_point_Nbr = (a - b) >> fraction_bit;
    return(tmp_object);
}


// increment, decrement  

// pre increment 
// ++a ->       a.operator++();
// ++(++a) works by returning by reference 
// if returnung by value-> returns a temporary , can not increment it temporary 
Fixed& Fixed::operator++()
{
    this->fixed_point_Nbr += 1;
    return (*this);
}
// post increment 
// a++ -> a.operator++(0) // return a copy before incrementing copy is temporay
// int as a dummy parameter to distinguish pre and post increm (int = 0);
Fixed Fixed::operator++(int) 
{
    Fixed copy_obj;
    // copy_obj = this->fixed_point_Nbr; use of int constructor 
    copy_obj  = *this; // only parse a pointer, calls copy constructor
    this->fixed_point_Nbr += 1;
    return(copy_obj);
}

// compilor differs automatecially if given parameter is const object, a const object needs to bee returned
Fixed& Fixed::min( Fixed& a_object, Fixed& b_object)
{
    return(a_object < b_object) ? a_object : b_object;
}

Fixed& Fixed::max(Fixed& a , Fixed& b)
{
    return(a > b) ? a : b;
}

const Fixed& Fixed::min( const Fixed& a_object, const Fixed& b_object)
{
    return(a_object < b_object) ? a_object : b_object;
}
const Fixed& Fixed::max( const Fixed& a , const Fixed& b )
{
    return(a > b) ? a : b;
}
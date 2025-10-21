/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:58:33 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 12:05:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <limits>

#include <cmath> 

class Fixed
{
    private:
    int fixed_point_Nbr;
    static const int fraction_bit = 8;
    static const float float_fraction_bit = 8;

    public:

    Fixed();
    Fixed(const int value);
    Fixed(const float float_value);

    Fixed(const Fixed& others);

    Fixed& operator=(const Fixed& other);
    
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits (int const raw);

    float toFloat( void ) const;
    int toInt(void ) const;



    

    // int Fixed::Increase_by_epsilon(void) const;
    friend std::ostream& operator<<(std::ostream& output_obj, const Fixed&obj_fixed);

    // a < b  => a.object(b)
    bool operator<(const Fixed& o_object) const;
    bool operator>(const Fixed& o_object) const;
    bool operator<=(const Fixed& o_object) const;
    bool operator>=(const Fixed& o_object) const;
    bool operator==(const Fixed& o_object) const;
    bool operator!=(const Fixed& o_object) const;


    Fixed operator*(const Fixed& o_object) const;
    Fixed operator/(const Fixed& o_object) const;

    Fixed operator+(const Fixed& o_object) const;
    Fixed operator-(const Fixed& o_object) const;


// Pre incremnt 
    Fixed& operator++();
    Fixed operator++(int); 
    // Fixed& Fixed::operator++(int);
    
};


#endif
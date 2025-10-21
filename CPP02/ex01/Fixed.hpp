/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:09:20 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 10:26:27 by poverbec         ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream& os, const Fixed&obj);

#endif
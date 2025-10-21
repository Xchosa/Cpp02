/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:09:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 10:09:40 by poverbec         ###   ########.fr       */
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
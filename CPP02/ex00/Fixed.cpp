/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:47:17 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/15 09:47:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// Fixed a
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fp_Nbr = 0; // clearify working with member variable 

}


// Fixed b(a) // copy constructor 
Fixed::Fixed(const Fixed& other) // pass by reference
{
        std::cout << "Copy constructor called" << std::endl;
        // this->fp_Nbr = other.fp_Nbr; // cpy raw bits intho other object  
        this->fp_Nbr = other.getRawBits();
}

//Copy assignment operator called
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        // this->fp_Nbr = other.fp_Nbr;
        this->fp_Nbr = other.getRawBits(); // for the exact same output
    }
    return (*this);
}

Fixed::~Fixed(){
        std::cout << "Destructor called" << std::endl;
    };

int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    // returns the raw value of the fixed-point value
    return (this->fp_Nbr);
}


void Fixed::setRawBits(int const raw)
{
 //sets the raw value of the fixed-point number
    this->fp_Nbr = raw;

};




// Fixed::Fixed(int value) : fp_Nbr(fp_Nbr)
// {
//     std::cout << "Parameterized constructor called" << std::endl;

// }
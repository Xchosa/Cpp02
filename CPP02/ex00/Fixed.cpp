/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:47:17 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 09:28:12 by poverbec         ###   ########.fr       */
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
        // this->fp_Nbr = other.fp_Nbr; // bad practice -> using encapsulated getter function , calling a 
        // const method not modifiying the source object. 
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


//sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
    this->fp_Nbr = raw;
};



// List initalization
// Fixed::Fixed(int value) : fp_Nbr(fp_Nbr)
// {
//     std::cout << "Parameterized constructor called" << std::endl;

// }
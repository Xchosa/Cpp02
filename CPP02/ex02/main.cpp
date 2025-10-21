/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:43:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 10:48:18 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath> 
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    // Fixed const d( b );
    // a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;
    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    if (b < c) // a.operator<(c);
        std::cout << b << " b is smaler then c " << c << std::endl;

        
    
    //Fixed a;
    //Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    //std::cout << a << std::endl;
    //std::cout << ++a << std::endl;
    //std::cout << a << std::endl;
    //std::cout << a++ << std::endl;
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << Fixed::max( a, b ) << std::endl;
    //return 0;

        


    Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) ); // Fixed(5.05f).operator*(Fixed(2))
    Fixed const f( Fixed( 5.05f ) / Fixed( 2 ) );// std::cout << a << std::endl;
    Fixed g( Fixed( 5.05f ) + Fixed( 2 ) );// std::cout << a << std::endl;
    Fixed h( Fixed( 5.05f ) - Fixed( 2 ) );// std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << f << std::endl;
    // std::cout << a++ << std::endl;
    std::cout << "result of multiplication  5.05f with 2:  " << d << std::endl;
    std::cout << "result of division        5.05f with 2:  " << f << std::endl;
    std::cout << "result of addition        5.05f with 2:  " << g << std::endl;
    std::cout << "result of substraction    5.05f with 2:  " << h << std::endl;

    std::cout << "minimum pre- increment of h (3.305075):  " << ++h << std::endl;
    std::cout << "value of h after incr   h (3.305075):    " << h << std::endl;
    std::cout << "minimum post- increment of h (3.305075): " << h++ << std::endl; // temporary created by copy assignment 
    std::cout << "value of h after incr   h (3.305075):    " << h << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    
    Fixed& x = Fixed::max( h, g );
    std::cout << "max of d:   "<< d <<  "and f: "<< f << " max: "<< Fixed::max( d, f ) << std::endl;
    std::cout << "max of h:   "<< h <<  "and g: "<< g << " max: "<< x << std::endl;

    Fixed& y = Fixed::max( h, g );
    std::cout << "min of d:   "<< d <<  "and f: "<< f << " min: "<< Fixed::min( d, f ) << std::endl;
    std::cout << "min of h:   "<< h <<  "and g: "<< g << " min: "<< y << std::endl;


    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // // std::cout << Fixed::max( a, b ) << std::endl;
    // return 0;


    return 0;
}


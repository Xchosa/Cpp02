/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:09:42 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 10:09:45 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <limits>

// #include <vector>
// #include <algorithm>
// #include <cmath> 

#include "Fixed.hpp"

int main( ) 
{
    Fixed a;    // 0
    Fixed b( a ); // cpy constructor + get.RawBits
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
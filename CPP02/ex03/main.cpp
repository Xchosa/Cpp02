/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:58:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 12:44:13 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath> 
#include <iostream>


int main()
{
    Point const a = Point(1 ,1);
    Point const b = Point(2, 3);
    Point const c = Point (3, 1);

    Point const check = Point(2,  0.07f);
    
    if(bsp(a, b, c, check) == true)
    {
        std::cout << "check Point"  << " is insight " << "a b and c"<< std::endl;
    }
    else 
        std::cout << "check is outside of the triangle" << std::endl;
}

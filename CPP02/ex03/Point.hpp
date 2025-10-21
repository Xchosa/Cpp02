/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:58:51 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 12:42:04 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include <cmath> 
#include "Fixed.hpp"

class Point
{
    private:
    const Fixed x;
    const Fixed y;
    

    public:

    Point();
    Point(const float value_a, const float value_b);
    Point(const Point& object);
    Point& operator=(const Point& Object);
    ~Point();
    float get_X() const;
    float get_Y() const;
    
};
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

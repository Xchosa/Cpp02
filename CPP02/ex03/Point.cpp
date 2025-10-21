/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:58:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 12:44:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include "Point.hpp"

// default constructor 
Point::Point() : x(0) , y(0) 
{
    std::cout << "Point Default constructor" << std::endl;
};

//constructor that takes two constant floating-point numbers as parameters.
//It initializes x and y with those parameters
Point::Point(const float value_a, const float value_b) : x(value_a) , y(value_b)
{
     std::cout << "Point(float, float) constructor called" << std::endl;
};


// cpy constructor
Point::Point(const Point& object) : x(object.x), y(object.y)
{
    std::cout << "Point copy constructor" << std::endl;
};

// copy assignment constructor
// Point a(1.0f, 2.0f);
// Point b;
// b = a; 
Point& Point::operator=(const Point& other) {
    (void) other;
    // Assignment is not possible due to const members
    std::cerr << "Assignment not allowed: Point has const members." << std::endl;
    return *this;
}

// destructor 
Point::~Point()
{
     std::cout << "Point Destructor called" << std::endl;
}

float Point::get_X() const 
{
    return this->x.toFloat() ;

}
float Point::get_Y() const 
{
    return this->y.toFloat();
}

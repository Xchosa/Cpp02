

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
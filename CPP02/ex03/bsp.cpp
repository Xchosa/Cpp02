/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:58:24 by poverbec          #+#    #+#             */
/*   Updated: 2025/10/21 12:44:39 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include "Point.hpp"



// ony 2 D 
bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    Fixed ax = a.get_X();
    Fixed ay = a.get_Y();
    Fixed bx = b.get_X();
    Fixed by = b.get_Y();
    Fixed cx = c.get_X();
    Fixed cy = c.get_Y();
    Fixed px = point.get_X();
    Fixed py = point.get_Y();

    // area formular 
//     Compute the area of triangle ABC.
// Compute the area of triangle PAB, PBC, and PCA (where P is your point).
// If the sum of the three sub-areas equals the area of ABC and none of the 
// sub-areas are zero, the point is inside.
// if the point is not on an edge its inside

    // calculate all possible triangles 
    Fixed ABC = ((ax*(by-cy) + bx*(cy-ay) + cx*(ay-by)) / Fixed(2));
    Fixed PBC = ((px*(by-cy) + bx*(cy-py) + cx*(py-by)) / Fixed(2));
    Fixed PCA = ((ax*(py-cy) + px*(cy-ay) + cx*(ay-py)) / Fixed(2));
    Fixed PAB = ((ax*(by-py) + bx*(py-ay) + px*(ay-by)) / Fixed(2));
    
    std::cout << "ABC area: " << ABC << std::endl;
    std::cout << "PBC area: " << PBC << std::endl;
    std::cout << "PCA area: " << PCA << std::endl;
    std::cout << "PAB area: " << PAB << std::endl;
    
    Fixed epsilon(0.01f);
    // substrate the the original triangle

    if(ABC == Fixed(0))
        return false;

    bool signs_positiv =   ((ABC > Fixed(0)) == (PBC > Fixed(0)))
                        && ((ABC > Fixed(0)) == (PCA > Fixed(0)))
                        && ((ABC > Fixed(0)) == (PAB > Fixed(0)));
    std::cout << "Same sign check: " << signs_positiv << std::endl;

    //edge check
    bool edge_vertrix = (PBC != Fixed(0)) && (PCA != Fixed(0)) && (PAB != Fixed(0));
    std::cout << "Not on edge check: " << edge_vertrix << std::endl;

    return (signs_positiv && edge_vertrix);

    
}



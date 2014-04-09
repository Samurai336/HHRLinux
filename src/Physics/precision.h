/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of Henry Hudson's Revenge. A Cross Platform project,      **
**  also Known as HHR_X and referd to as such thoughout.						**
**  																			**
**  HHR_X is free software: you can redistribute it and/or modify			  	**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  HHR_X is distributed in the hope that it will be useful,					**
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with HHR_X.  If not, see <http://www.gnu.org/licenses/>.			  	**
**  																			**
**********************************************************************************/




#ifndef PRECISION_H_INCLUDED
#define PRECISION_H_INCLUDED

#include <math.h>

namespace HHR_Physics
{

    #define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)


    typedef float real;


    //create a function pointer to our
    //math libs function for floats
    typedef real (*p_sqrtf) (real);
    static p_sqrtf real_sqrt = &sqrtf;

    typedef real (*p_fabs) (real);
    static  p_fabs real_abs = &fabsf;

    typedef real (*p_cosf) (real);
    static p_cosf real_cos = &cosf;

    typedef real (*p_sinf) (real);
    static p_sinf real_sin= &sinf;




}
#endif // PRECISION_H_INCLUDED

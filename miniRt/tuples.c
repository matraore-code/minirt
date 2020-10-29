/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 05:50:23 by matraore          #+#    #+#             */
/*   Updated: 2020/10/28 06:31:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <assert.h>



//Tuples --Operations

const double epsilon = 0.00001;

typedef struct tuples {
    double x;
    double y;
    double z;
    double w;
} t_tuple;



 // A tuple with w=1.0 is a point
 // A tuple with w=0.0 is a vector

t_tuple point(double x, double y, double z)
{
    t_tuple t_point;

    t_point.x = x;
    t_point.y = y;
    t_point.z = z;
    t_point.w = 1;
    return (t_point);
}

t_tuple vector(double x, double y, double z)
{
    t_tuple t_vect;

    t_vect.x = x;
    t_vect.y = y;
    t_vect.z = z;
    t_vect.w = 0;
    return (t_vect);
}

int equal(double a, double b)
{
    double i;

    i = (fabs(a - b) < epsilon) ? 1 : 0;
    return (i);
}

int comparingTuples(t_tuple a, t_tuple b)
{
    if(equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w, b.w))
        return (1);
    return 0;
}

t_tuple sumTuples(t_tuple a, t_tuple b)
{
    t_tuple c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    c.w = a.w + b.w;
    return (c);
}

t_tuple subTuples(t_tuple a, t_tuple b)
{
    t_tuple c;

    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    c.w = a.w - b.w;
    return (c);
}

t_tuple multiTuples(double a, t_tuple b)
{
    t_tuple c;

    c.x = a * b.x;
    c.y = a * b.y;
    c.z = a * b.z;
    c.w = a * b.w;
    return (c);
}

t_tuple divTuples(double a, t_tuple b)
{
    t_tuple c;

    c.x = a / b.x;
    c.y = a / b.y;
    c.z = a / b.z;
    c.w = a / b.w;
    return (c);
}

double magnetudeVector(t_tuple vect)
{
    double mag;

    mag = sqrt((vect.x * vect.x) + (vect.y * vect.y) + (vect.z * vect.z));
    return (mag);
}

t_tuple normalizeVector(t_tuple vect)
{
    t_tuple unitVect;

    unitVect.x = vect.x / magnetudeVector(vect);
    unitVect.y = vect.y / magnetudeVector(vect);
    unitVect.z = vect.z / magnetudeVector(vect);
    unitVect.w = 0;
    return (unitVect);
}

double scalarTuples(t_tuple a, t_tuple b)
{
    double c;

    c= a.x * b.x + a.y * b.y + a.z * b.z;
    return (c);
}

t_tuple crossTuples(t_tuple a, t_tuple b)
{
    return vector(a.y * b.z - a.z * b.y, 
        a.z * b.x - a.x * b.z, 
        a.x * b.y - a.y * b.x);
}

int main(int argc, char *argv[]) {

   t_tuple a;
   t_tuple b;
   t_tuple c;

    a = vector(1, 2, 3);
    b = vector(2, 3, 4);
    c = crossTuples(b, a);
    
    printf("vector(%f, %f, %f)", c.x, c.y, c.z);
    return (0);
}
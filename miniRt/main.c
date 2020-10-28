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
#include <assert.h>

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

t_tuple point(double x, double y, double z)
{
    t_tuple t_vect;

    t_vect.x = x;
    t_vect.y = y;
    t_vect.z = z;
    t_vect.w = 1;
    return (t_point);
}

t_tuple tuple(double x, double y, double z, double w) 
{
    t_tuple rt = {x,y,z,w};
    return (rt);    
}

int main(int argc, char *argv[]) {

   
    t_tuple a = tuple(4.3, -4.2, 3.1, 1.0);
    assert(a.x == 4.3);
    assert(a.y == -4.2);
    return (0);
}
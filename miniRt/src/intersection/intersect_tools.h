/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:03:36 by matraore          #+#    #+#             */
/*   Updated: 2020/11/19 13:19:51 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERSECT_TOOLS_H
# define _INTERSECT_TOOLS_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../tuples/tuples.h"
#include "../rays/rays.h"
#include "../sphere/sphere_tools.h"



typedef struct inter{
  double a;
  double b;
  double c;
  double dis;
  double *t;
}t_inter;

typedef struct object
{
    t_sphere s;
    
}t_object;


typedef struct intersect
{
    t_object obj;//for the object 
    double t;
    
}t_intersect;

t_inter  discriminant(t_rays r, t_tuple origine_sphere);
double *intersection_points(t_rays r, t_object obj);
double  *intersections(double t1, double t2);
t_inter  discriminant(t_rays r, t_tuple origine_sphere);
t_sphere new_sphere(double r, t_tuple pt);

#endif
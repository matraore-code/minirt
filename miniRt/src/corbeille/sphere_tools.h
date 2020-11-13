/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:51:05 by matraore          #+#    #+#             */
/*   Updated: 2020/11/13 02:59:35 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPHERE_TOOLS_H
# define _SPHERE_TOOLS_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "../tuples/tuples.h"
#include "../rays/rays.h"

static int id;

typedef struct sphere
{
  t_tuple origine;
  int rayon;
  int id_u;
}t_sphere;



typedef struct intersect{
    double a;
  double b;
  double c;
  double dis;
  double t1;
  double t2;
}t_inter;

t_sphere new_sphere(double r, t_tuple pt);
t_inter  discriminant(t_rays r, t_tuple origine_sphere);
double *intersect_tools(t_rays r, t_sphere s);

#endif
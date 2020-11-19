/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:04:36 by matraore          #+#    #+#             */
/*   Updated: 2020/11/19 13:24:45 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_tools.h"

//sphere_to_ray is the distance between sphere and the origine of sphere
t_inter  discriminant(t_rays r, t_tuple origine_sphere)
{
  t_tuple sphere_to_ray;
  t_inter delta;

  sphere_to_ray = subTuples(r.origine, origine_sphere);
  delta.a = scalarTuples(r.direction, r.direction);
  delta.b = 2 * scalarTuples(r.direction, sphere_to_ray);
  delta.c = scalarTuples(sphere_to_ray, sphere_to_ray) - 1;
  delta.dis = (delta.b * delta.b) - (4 * delta.a * delta.c);
  return (delta);
}

double  *intersection_points (t_rays r, t_object obj)
{
  t_inter delta;
  double x;
  double y;

  delta = discriminant(r, obj.s.origine);
  delta.t = tools_malloc(sizeof(double) * 3);
  if (delta.dis < 0)
  {
      tools_free(delta.t, (sizeof(double) *3));
      return(0);
  } 
  else
  {
    x = (-delta.b - sqrt(delta.dis));
    y = (-delta.b + sqrt(delta.dis));
    delta.t[0] = x / (2 * delta.a);
    delta.t[1] = y / (2 * delta.a);
    if(delta.t[1] == delta.t[0])
       delta.t[3] = 1;
    else
        delta.t[3] = 2;
  }
  return (delta.t);
}


double  *intersections(t_intersect i1, t_intersect i2)
{
    t_inter delta;
    double *xs;
    
    xs = tools_malloc(sizeof(double) * 3);
    if (delta.t == NULL)
    {
      tools_free(xs, (sizeof(double) *3));
      return(0);
    }
    else
    {
      i1.t = delta.t[0];
      i2.t = delta.t[1];
      if(i1 == i2)
       delta.t[3] = 1;
      else
        delta.t[3] = 2;
    }
    return (xs);
}


int     main(int argc, char *argv[]) 

{

  t_tuple a;
  t_tuple b;
  double *delt;
  t_rays r;
  t_object p;

  a = point(0, 0, 0);
  r = create_ray(point(0, 3, -5), vector(0, 0, 1));
  p.s = new_sphere(2, a);
  delt = intersection_points(r, p);
  if(delt != NULL)
  {
      printf("%f | %f", delt[0], delt[1]);
  }
  else {
      printf("Pas de point d'intersection");
  }
    

    return (0);
}
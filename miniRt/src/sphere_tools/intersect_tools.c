/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:04:36 by matraore          #+#    #+#             */
/*   Updated: 2020/11/13 03:48:14 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_tools.h"

t_sphere new_sphere(double r, t_tuple pt)
{
    t_sphere sph;

    sph.origine = pt;
    sph.rayon = r;
    sph.id_u = id;
    id++;
    return (sph);
}

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

double  *intersect_tools(t_rays r, t_object obj)
{
  t_inter delta;
  double *t;
  double x;
  double y;

  delta = discriminant(r, obj.s.origine);
  t = tools_malloc(sizeof(double) * 3);
  if (delta.dis < 0)
    return(0);
  else
  {
    x = (-delta.b - sqrt(delta.dis));
    y = (-delta.b + sqrt(delta.dis));
    t[0] = x / (2 * delta.a);
    t[1] = y / (2 * delta.a);

  }
    return (t);

}

// double  *intersections(double t1, double t2)
// {
//     t_intersect i;
//     t_rays r;
//     double i1;
//     double i2;
//     double *t;
    
//     t = tools_malloc(sizeof(double) * 3);
//     t = intersect_tools(r, i.obj);
    
// }



int     main(int argc, char *argv[]) 

{

  t_tuple a;
  t_tuple b;
  double *delt;
  t_rays r;
  t_object p;

  a = point(0, 0, 0);
  r = create_ray(point(0, 0, -5), vector(0, 0, 1));
  p.s = new_sphere(2, a);
  delt = intersect_tools(r, p);
  // t = intersect();
    printf("%f | %f", delt[0], delt[1]);

    return (0);
}
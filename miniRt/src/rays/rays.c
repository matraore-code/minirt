/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 05:43:38 by matraore          #+#    #+#             */
/*   Updated: 2020/11/11 06:55:08 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"


typedef struct sphere
{
  t_tuple origine;
  int rayon;
  int id_u;
}t_sphere;

t_sphere new_sphere(double r, t_tuple pt)
{
    t_sphere sph;

    sph.origine = pt;
    sph.rayon = r;
    sph.id_u = id;
    id++;
    return (sph);
}

t_rays create_ray(t_tuple ori, t_tuple dir)
{
    t_rays r;

    r.origine = point(ori.x, ori.y, ori.z);
    r.direction = vector(dir.x, dir.y, dir.z);
    return (r);
}

t_tuple position_point(t_rays r, double t)
{
    t_tuple sum;
    t_tuple pos;

    pos =  multiTuples(t, r.direction);
    sum = sumTuples(r.origine, pos);
    return (sum);
}


int     main(int argc, char *argv[]) {

   t_tuple a;
   t_tuple b;
  t_sphere p;
  t_sphere p1;
  t_sphere p2;
  a = point(1, 0, 0);

  p = new_sphere(2, a);
  p1 = new_sphere(2, a);
  p2 = new_sphere(2, a);

  printf("%d %d %d", p.id_u, p1.id_u, p2.id_u);

    return (0);
}
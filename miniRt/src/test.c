/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:45:45 by matraore          #+#    #+#             */
/*   Updated: 2020/11/11 05:28:51 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>
 

typedef struct projectiles
{
  t_tuple position_point;
  t_tuple velocity_vect;
}t_pro;

typedef struct environment
{
  t_tuple gravity_vect;
  t_tuple wind_vect;
}t_env;

t_pro init_pro(t_pro p)
{
  p.position_point = point(0, 1, 0);
  p.velocity_vect = normalizeVector(vector(1, 1, 0));
  return(p);
}

t_env init_env(t_env e)
{
  e.gravity_vect= vector(0, -0.1, 0);
  e.wind_vect = vector(-0.01, 0, 0);
  return(e);
}

t_pro tick(t_env env, t_pro pro)
{
  t_pro projectile;

  projectile.position_point = sumTuples(pro.position_point, pro.velocity_vect);
  projectile.velocity_vect = sumTuples(pro.velocity_vect, sumTuples(env.gravity_vect, env.wind_vect));
  return (projectile);
}




int main(void)
{
  t_canvas r;
  createCanvas(10, 2);
  colorVec color;
  colorVec color0;
  colorVec color3;
  color0.red = 0;
  color0.green = 0 ;
  color0.blue = 0;

  colorVec color1;
  color1.red = 1;
  color1.green = 0.8;
  color1.blue = 0.6;
  color = addingColor(color0, color1);
  color = scalarColor(255, color);
  int i, j;
  int x, y;
  int fp = open("first.ppm", O_WRONLY |  O_CREAT, 0777); 
  (void) dprintf(fp, "P3\n%d %d\n255\n",10, 2);
  for (j = 0; j < 2; ++j)
  {
    for (i = 0; i < 10; ++i)
    {

    dprintf(fp, "%d %d %d ", (int)color.red, (int)color.green, (int)color.blue);
    
    }
    dprintf(fp,"\n");
  }

  // color3.red = 0;
  // color3.green = 1;
  // color3.blue = 0;
  
  // for (j = 300; j < 800; ++j)
  // {
  //   for (i = 300; i < 800; ++i)
  //   {

  //   dprintf(fp, "%d %d %d ", (int)color3.red, (int)color3.green, (int)color3.blue);
    
  //   }
  //   dprintf(fp,"\n");
  // }

 

  
  
  //(void) fclose(fp);
  return EXIT_SUCCESS;
}
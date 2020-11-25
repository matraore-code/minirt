/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:45:45 by matraore          #+#    #+#             */
/*   Updated: 2020/11/25 03:10:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>
#include "mlx.h"
 

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
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Moctar");
  t_canvas r;
  createCanvas(800, 800);
  int color = 0;
  colorVec color1;
  color1.red = 1;
  color1.green = 0;
  color1.blue = 1;
  color = color_rgb_to_hex(color1);
  
  int i, j;
  printf("%f %f %f %d", color1.red, color1.green, color1.blue, color);
  for (j = 250; j < 300; ++j)
  {
    for (i = 250; i < 300; ++i)
    {
      mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
    }
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

 

  
  mlx_loop(mlx_ptr);
  //(void) fclose(fp);*/
  return EXIT_SUCCESS;
}

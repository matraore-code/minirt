/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:30:41 by matraore          #+#    #+#             */
/*   Updated: 2021/01/24 09:26:08 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <mlx.h>
# include <math.h>
#include <stdlib.h>
#include "tuple.h"
#include "gnl.h"
#include "outils.h"
#include "object.h"
#include "parsing.h"

typedef struct	s_hit
{
	t_tuple		hit_point;
	t_tuple		hit_normal;
	t_list		*objects;
	t_object	*closest_object;
	t_ray		ray;
}				t_hit;

typedef	struct	s_image {
	void		*img;
	char			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;


typedef struct	s_data
{
	t_canvas		*canvas;
	int			camera_number;
	void		*id;
	void		*window;
	t_image		image;
}				t_data;


t_ray			ray_to_pixel(int x, int y, t_canvas *sene);
int		handle_key(int key, t_data *data);
int		close_window(t_data *data);
void	trace_ray(t_data *data, int save);
void			initialize_mlx(char *filepath, int save);
int		get_obj_hit(t_ray ray, t_object *object, double *t);
int		hit_objects(t_list *objects, t_ray ray,
							t_object **closest_object, double *t_min);
t_tuple			get_normal(t_tuple point, t_object *object);
t_color		light_contribution(t_light light, t_hit hit_point, t_canvas canvas);
t_color		compute_lights(t_canvas *canvas, t_ray ray, t_object *closest_object,
																double t_min);
int				get_color(t_canvas *canvas, t_ray ray);
void	render(int camera_number, t_data *data, int save);
t_tuple		get_normal(t_tuple point, t_object *object);
t_hit		create_hit(t_tuple hit_point, t_tuple hit_normal,
									t_object *closest_object, t_ray ray);
t_color		mix_colors(t_light light, double d, t_hit hit_point);
double			spec_coeff(t_light light, t_hit hit_point);





#endif
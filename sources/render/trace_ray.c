/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:23:32 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 11:54:24 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

t_color		mix_colors(t_light light, double d, t_hit hit)
{
	t_color	result;
	t_color	light_color;
	t_color	object_color;

	light_color = color_coeff(light.color, light.intensity);
	object_color = hit.closest_object->color;
	result = color_coeff(color_mult(light_color, object_color), d);
	return (result);
}

t_color		compute_light(t_light light, t_hit hit, t_canvas canvas)
{
	t_object	*closest_object;
	double		t;
	t_tuple		light_ray;
	t_ray		lray;
	double		dot;

	dot = 0;
	light_ray = substract(light.p0, hit.hit_point);
	normalize_vector(&light_ray);
	lray = create_ray(tuple_add(hit.hit_point,
				tuple_multiply(hit.hit_normal, 0.1)), light_ray);
	if (!hit_objects(canvas.objects, lray, &closest_object, &t)
			|| t > vector_len(substract(light.p0, hit.hit_point)))
	{
		dot = fmax(0, dot_product(hit.hit_normal, light_ray));
	}
	return (mix_colors(light, dot, hit));
}

t_color		compute_lights(t_canvas *canvas, t_ray ray,
		t_object *closest_object, double t_min)
{
	t_tuple		hit_point;
	t_tuple		hit_normal;
	t_list		*node;
	t_color		result;
	t_color		addition;

	result = int_color(0);
	hit_point = tuple_add(ray.origin, tuple_multiply(ray.direction, t_min));
	hit_normal = get_normal(hit_point, closest_object);
	if (dot_product(ray.direction, hit_normal) > 0)
		hit_normal = substract(create_tuple(0, 0, 0),
				tuple_multiply(hit_normal, 1));
	node = canvas->lights;
	while (node != NULL)
	{
		addition = compute_light(*(t_light *)(node->content),
		create_hit(hit_point, hit_normal, closest_object, ray),
					*canvas);
		result = color_add(result, addition);
		node = node->next;
	}
	return (result);
}

int			get_color(t_canvas *canvas, t_ray ray)
{
	double		t_min;
	t_object	*n_object;
	t_color		result;
	t_color		ambient_color;

	if (hit_objects(canvas->objects, ray, &n_object, &t_min))
	{
		ambient_color = color_coeff(canvas->ambient_color,
				canvas->ambient_intensity);
		result = color_add(color_mult(n_object->color, ambient_color),
				compute_lights(canvas, ray, n_object, t_min));
		return (to_int(result));
	}
	else
		return (0);
}

void		trace_ray(t_data *data, int save)
{
	int				x;
	int				y;
	int				color;
	char			*dest;
	t_pixel			**buffer;

	x = 0;
	y = 0;
	buffer = create_buffer(data->canvas->height, data->canvas->width);
	while (y < data->canvas->height)
	{
		x = 0;
		while (x < data->canvas->width)
		{
			color = get_color(data->canvas, ray_to_pixel(x, y, data->canvas));
			if (save == 1)
				buffer[y][x] = pixel_to_int(color);
			else
				dest = parse_dest(color, x, y, data);
			x++;
		}
		y++;
	}
	free_and_saving(buffer, data, save);
}

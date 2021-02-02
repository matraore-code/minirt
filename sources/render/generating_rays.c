/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generating_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:48:59 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:47:30 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"
#include "../../includes/tuple.h"

t_ray		create_ray(t_tuple origin, t_tuple direction)
{
	t_ray result;

	result.origin = origin;
	result.direction = direction;
	return (result);
}

t_camera	pick_camera(t_canvas *canvas)
{
	t_list	*node;
	int		i;

	i = 0;
	node = canvas->cameras;
	while (i < canvas->selected_camera && node != NULL)
	{
		i++;
		node = node->next;
	}
	return (*(t_camera *)node->content);
}

t_tuple		get_direction(int x, int y, t_canvas *canvas, t_camera camera)
{
	double fov_coeff;
	double aspect_ratio;
	double p_x;
	double p_y;

	fov_coeff = tan((double)camera.fov / 2 * M_PI / 180);
	aspect_ratio = (double)canvas->width / (double)canvas->height;
	p_x = (2 * (x + 0.5) / (double)canvas->width - 1) *
		aspect_ratio * fov_coeff;
	p_y = (1 - 2 * (y + 0.5) / (double)canvas->height) * fov_coeff;
	return (create_tuple(p_x, p_y, 1));
}

t_ray		ray_to_pixel(int x, int y, t_canvas *canvas)
{
	t_tuple		origin;
	t_tuple		direction;
	t_matrix	c2w;
	t_camera	camera;

	camera = pick_camera(canvas);
	c2w = look_at(camera.origin, camera.direction);
	origin = multiply_by_matrix(create_tuple(0, 0, 0), c2w);
	direction = get_direction(x, y, canvas, camera);
	direction = multiply_by_matrix(direction, c2w);
	direction = substract(direction, origin);
	normalize_vector(&direction);
	return (create_ray(origin, direction));
}

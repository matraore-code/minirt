/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:21:04 by matraore          #+#    #+#             */
/*   Updated: 2021/01/24 09:05:16 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

t_tuple		get_normal(t_tuple point, t_object *object)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(point, *(t_sphere *)object->ptr));
	else
		return (get_plane_normal(*(t_plane *)object->ptr));
}

t_tuple		get_sphere_normal(t_tuple point, t_sphere sphere)
{
	t_tuple n;

	n = substract(point, sphere.center);
	normalize_vector(&n);
	return (n);
}

t_tuple		get_triangle_normal(t_triangle triangle)
{
	t_tuple side1;
	t_tuple side2;
	t_tuple normal;

	side1 = substract(triangle.c2, triangle.c1);
	side2 = substract(triangle.c3, triangle.c1);
	normal = cross_product(side2, side1);
	normalize_vector(&normal);
	return (normal);
}

t_tuple	get_plane_normal(t_plane plane)
{
	t_tuple ret;

	ret = plane.normal;
	return (ret);
}
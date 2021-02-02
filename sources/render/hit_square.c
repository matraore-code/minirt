/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:09:54 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 11:10:45 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/object.h"

int			hit_square(t_ray ray, t_square square, double *t)
{
	double	denom;
	t_tuple	hit_point;
	t_tuple	p0l0;

	denom = dot_product(square.vector, ray.direction);
	if (fabs(denom) > EPSILON)
	{
		p0l0 = substract(square.center, ray.origin);
		*t = dot_product(p0l0, square.vector) / denom;
		hit_point = tuple_add(ray.origin, tuple_multiply(ray.direction, *t));
		if (*t >= 0)
		{
			if (fabs(hit_point.x - square.center.x) > (square.size / 2))
				return (0);
			if (fabs(hit_point.y - square.center.y) > (square.size / 2))
				return (0);
			if (fabs(hit_point.z - square.center.z) > (square.size / 2))
				return (0);
			else
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

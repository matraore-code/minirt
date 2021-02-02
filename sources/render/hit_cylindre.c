/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:16:17 by matraore          #+#    #+#             */
/*   Updated: 2021/02/02 12:20:59 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/object.h"

t_cal			calcul_elemnt(t_cylindre cylinder, t_ray ray)
{
	t_cal		calcul;

	calcul.x = substract(ray.origin, cylinder.pos);
	calcul.a_elements = pow(dot_product(ray.direction, cylinder.vector), 2);
	calcul.b_elements = dot_product(ray.direction, cylinder.vector) *
		dot_product(calcul.x, cylinder.vector);
	return (calcul);
}

t_cylindre		*new_cylinder(t_tuple p, t_tuple normal,
					double radius, double height)
{
	t_cylindre	*cylinder;

	cylinder = malloc(sizeof(t_cylindre));
	cylinder->pos = p;
	cylinder->vector = normal;
	cylinder->size = radius;
	cylinder->height = height;
	return (cylinder);
}

void			check_t(double *t, t_cylindre cylinder, t_ray ray)
{
	double	m;

	m = dot_product(ray.direction, tuple_multiply(cylinder.vector, *t))
		+ dot_product(substract(ray.origin, cylinder.pos), cylinder.vector);
	if (m >= cylinder.height || m <= 0)
		*t = -1;
}

int				cyl_get_roots(double *t0, double *t1,
					t_cylindre cylinder, t_ray ray)
{
	t_cal	c;
	double	a;
	double	b;
	double	y;

	c = calcul_elemnt(cylinder, ray);
	a = dot_product(ray.direction, ray.direction) - c.a_elements;
	b = 2 * (dot_product(ray.direction, c.x) - c.b_elements);
	y = dot_product(c.x, c.x) - pow(dot_product(c.x, cylinder.vector), 2)
		- pow(cylinder.size, 2);
	if (!solve_quadratic(create_tuple(a, b, y), t0, t1))
		return (0);
	return (1);
}

int				hit_cylindre(t_ray ray, t_cylindre cylinder, double *t)
{
	double s0;
	double s1;

	if (!cyl_get_roots(&s0, &s1, cylinder, ray))
		return (0);
	if (s1 < s0)
		*t = s1;
	else
		*t = s0;
	if (s0 > 0)
		check_t(&s0, cylinder, ray);
	if (s1 > 0)
		check_t(&s1, cylinder, ray);
	if (s0 < 0 && s1 < 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 08:09:48 by matraore          #+#    #+#             */
/*   Updated: 2021/01/26 17:30:30 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/object.h"
#include <stdio.h>


t_triangle *new_triangle(t_tuple x, t_tuple y, t_tuple z)
{
    t_triangle *triangle;

    triangle = malloc(sizeof(t_triangle));
    triangle->c1 = x;
    triangle->c2 = y;
    triangle->c3 = z;
    return (triangle);
}

int			step2(t_triangle triangle, t_tuple p, t_tuple n)
{
	t_tuple	c;
	t_tuple	edge;
	t_tuple	vp;

	edge = substract(triangle.c2, triangle.c1);
	vp = substract(p, triangle.c1);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	edge = substract(triangle.c3 , triangle.c2);
	vp = substract(p, triangle.c2);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	edge = substract(triangle.c1, triangle.c3);
	vp = substract(p, triangle.c3);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	return (1);
}


int     hit_triangle(t_ray ray, t_triangle triangle, double *t)
{
	t_tuple a;
	t_tuple b;
	t_tuple	n;
    double ndotraydir;
	t_tuple	p;

    a = substract(triangle.c2, triangle.c1);
	b = substract(triangle.c3, triangle.c1);
	n = cross_product(a, b);
	normalize_vector(&n);
	ndotraydir = dot_product(n, ray.direction);
	if (fabs(ndotraydir) < EPSILON)
		return (0);
	*t = (dot_product(n, substract(triangle.c1, ray.origin))) / ndotraydir;
	if (*t < 0)
		return (0);
	p = tuple_add(ray.origin, tuple_multiply(ray.direction, *t));
	return (step2(triangle, p, n));
}

// int     hit_triangle(t_ray ray, t_triangle triangle, double *t)
// {
// 	t_tuple edge1;
// 	t_tuple edge2;
// 	t_tuple pvec;
// 	t_tuple tvec;
// 	t_tuple qvec;
// 	double det;
// 	double inver_det;
// 	double *u;
// 	double *v;

// 	edge1 = substract(triangle.c2, triangle.c1);
// 	edge2 = substract(triangle.c3, triangle.c1);
// 	pvec = cross_product(ray.direction, edge2);
// 	det = dot_product(edge1, pvec);
// 	if (det > -EPSILON && det < EPSILON)
// 		return (0);
// 	inver_det = 1.0 / det;
// 	tvec = substract(ray.origin, triangle.c1);
// 	*u = dot_product(tvec, pvec) * inver_det;
// 	if (*u < 0.0 || *u > 1.0)
// 		return (0);
// 	qvec = cross_product(tvec, edge1);
// 	*v = dot_product(ray.direction, qvec) * inver_det;
// 	if (*v < 0.0 || *u + *v > 1.0)
// 		return (0);
// 	*t = dot_product(edge2, qvec) * inver_det;
// 	return(1);
// }
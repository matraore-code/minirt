/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 08:09:48 by matraore          #+#    #+#             */
/*   Updated: 2021/01/24 09:49:43 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/object.h"
#define EPSILON 0.000001

t_triangle *new_triangle(t_tuple x, t_tuple y, t_tuple z)
{
    t_triangle *triangle;

    triangle = malloc(sizeof(t_triangle));
    triangle->c1 = x;
    triangle->c2 = y;
    triangle->c3 = z;
    return (triangle);
}

t_tuple    local_normal_at(t_triangle triangle, t_tuple point)
{
    t_tuple normal;

    normal = get_triangle_normal(triangle);
    return (normal);
}

int     hit_triangle(t_ray ray, t_triangle triangle, double *t)
{
    t_tuple side1;
    t_tuple side2;
    t_tuple e2;
    double det;
    
    side1 = substract(triangle.c2, triangle.c1);
    side2 = substract(triangle.c3, triangle.c1);
    e2 = cross_product(ray.direction, side2);
    det = dot_product(side1, e2);
    if (det < EPSILON)
        return (0);
    return (1);
}
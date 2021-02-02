/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_suites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:48:21 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 12:03:32 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tuple.h"

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_tuple	substract(t_tuple vec1, t_tuple vec2)
{
	t_tuple result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

t_tuple	tuple_multiply(t_tuple vec1, double x)
{
	t_tuple result;

	result.x = vec1.x * x;
	result.y = vec1.y * x;
	result.z = vec1.z * x;
	return (result);
}

t_tuple	multiply_by_matrix(t_tuple p, t_matrix m)
{
	t_tuple res;

	res.x = p.x * m.d[0][0] + p.y * m.d[1][0] + p.z * m.d[2][0] + m.d[3][0];
	res.y = p.x * m.d[0][1] + p.y * m.d[1][1] + p.z * m.d[2][1] + m.d[3][1];
	res.z = p.x * m.d[0][2] + p.y * m.d[1][2] + p.z * m.d[2][2] + m.d[3][2];
	return (res);
}

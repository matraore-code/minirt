/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:58:41 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 05:35:46 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple		*scalar_tuple(t_tuple *p, double a)
{
	t_tuple		*s;

	s = create_tuple((p->x * a), (p->y * a), (p->z * a));
	if (s == NULL)
		return (NULL);
	return (s);
}

t_tuple		*normalize_tuple(t_tuple *p)
{
	double		m;
	double		i;
	t_tuple		*s;

	m = magnetude_tuple(p);
	i = 1 / m;
	s = create_tuple((p->x * i), (p->y * i), (p->z * i));
	if (s == NULL)
		return (NULL);
	return (s);
}

double		dot_product(t_tuple *a, t_tuple *b)
{
	double		d;

	d = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
	return (d);
}

t_tuple		*cross_product(t_tuple *a, t_tuple *b)
{
	double		x;
	double		y;
	double		z;
	t_tuple		*s;

	x = (a->y * b->z) - (a->z * b->y);
	y = (a->z * b->x) - (a->x * b->z);
	z = (a->x * b->y) - (a->y - b->x);
	s = create_tuple(x, y, z);
	if (s == NULL)
		return (NULL);
	return (s);
}

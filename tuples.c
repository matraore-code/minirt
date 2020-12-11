/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:47:37 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 04:58:21 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>

t_tuple		*create_tuple(double x, double y, double z)
{
	t_tuple		*p;

	p = tools_malloc(sizeof(t_tuple));
	if (p == NULL)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

void		destroy_tuple(t_tuple **p)
{
	tools_free((void**)p, sizeof(t_tuple));
}

double		magnetude_tuple(t_tuple *p)
{
	double		m;

	m = sqrt((p->x * p->x) + (p->y * p->y) + (p->z * p->z));
	return (m);
}

t_tuple		*add_tuple(t_tuple *a, t_tuple *b)
{
	t_tuple		*s;

	s = create_tuple((a->x + b->x), (a->y + b->y), (a->z + b->z));
	if (s == NULL)
		return (NULL);
	return (s);
}

t_tuple		*sub_tuple(t_tuple *a, t_tuple *b)
{
	t_tuple		*s;

	s = create_tuple((a->x - b->x), (a->y - b->y), (a->z - b->z));
	if (s == NULL)
		return (NULL);
	return (s);
}

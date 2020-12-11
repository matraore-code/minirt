/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:04:27 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 06:19:28 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools/tools.h"
#include "tuples/tuples.h"
#include "matrix/matrix.h"
#include <stdio.h>


int main ()
{
	t_tuple *v = create_tuple(4, 5, 6);
	t_tuple *p = create_tuple(4, 9, 6);
	t_tuple *s = sub_tuple(v, p);
	t_tuple *n = normalize_tuple(v);
	double m = magnetude_tuple(v);
	printf("v (%.0f %.0f %.0f)\n", v->x, v->y, v->z);
	printf("%f\n", m);
	printf("s (%.0f %.2f %.0f)\n", n->x, n->y, n->z);
	
	destroy_tuple(&p);
	if (p == NULL)
		printf("Memoire liberee\n");
	t_mat *mat = create_matrix(3);
	printf("%.2f\n", mat->entries[0]);
	int i = 0;
	while (mat->entries[i] != '\0')
		i++;
	printf("%d", i);
	return(0);
}

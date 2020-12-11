/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:40:26 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 06:23:52 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat		*create_matrix(int i)
{
	t_mat		*mat;
	double		*j;
	int			k;

	if (i > 4 || i < 2)
		return (NULL);
	mat = tools_malloc(sizeof(t_mat));
	if (mat == NULL)
		return (NULL);
	mat->entries = tools_malloc(sizeof(double) * i * i);
	if (mat->entries == NULL)
	{
		free(mat);
		return (NULL);
	}
	j = mat->entries;
	k = 0;
	while (k < i * i)
	{
		mat->entries[k]= 0;
		k++;
	}
	mat->dim = i;
	return (mat);
}



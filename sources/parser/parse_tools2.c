/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:19 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:36:52 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		allowed_symbol(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '.' || c == ',' ||
	(c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

void	free_d_str(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

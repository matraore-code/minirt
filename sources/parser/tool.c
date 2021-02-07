/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:46:19 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 11:42:37 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void handle_vir(char *array)
{
	int i;

	i = 0;
	while(array[i])
	{
		if (array[i] == ',' && array[i + 1] == ',')
			print_error("Trop de virgules dans la chaine");
		if (array[i] == '.' && array[i + 1] == '.')
			print_error("Trop de point dans la chaine");
		i++;
	}
}

int		checker_color(char *color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (color[i] != '\0')
	{
		if (color[i] == '.')
			print_error("Couleur mal definie");
		i++;
	}
	return (1);
}

int		ch_normal(t_tuple *n)
{
	if (n->x < -1 || n->x > 1 || n->y < -1 || n->y > 1 || n->z < -1
			|| n->z > 1)
		return (0);
	return (1);
}

void	parse_normal_coords(t_tuple *point, char *field, char *errmsg)
{
	char **coords;

	handle_vir(field);
	coords = ft_split(field, ',');
	if (line_fields(coords) != 3)
		print_error(errmsg);
	point->x = ft_atod(coords[0]);
	point->y = ft_atod(coords[1]);
	point->z = ft_atod(coords[2]);
	if (!ch_normal(point))
		print_error("les coordonnees sont comprise [-1.0, 1.0]");
	free_d_str(coords);
}

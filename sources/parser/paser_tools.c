/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paser_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:09 by matraore          #+#    #+#             */
/*   Updated: 2021/01/29 17:49:10 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!allowed_symbol(line[i]) && i > 2)
			return (0);
		i++;
	}
	return (1);
}

int		check_color(t_color c)
{
	if (c.r < 0 || c.r > 1 || c.g < 0 || c.g > 1 || c.b < 0 ||
	c.b > 1)
		return (0);
	return (1);
}

void	parse_colors(t_color *result, char *field, char *errmsg)
{
	char **color;

	color = ft_split(field, ',');
	if (line_fields(color) != 3)
		print_error(errmsg);
	result->r = (double)ft_atoi(color[0]) / 256;
	result->g = (double)ft_atoi(color[1]) / 256;
	result->b = (double)ft_atoi(color[2]) / 256;
}

void	parse_coords(t_tuple *point, char *field, char *errmsg)
{
	char **coords;

	coords = ft_split(field, ',');
	if (line_fields(coords) != 3)
		print_error(errmsg);
	point->x = ft_atod(coords[0]);
	point->y = ft_atod(coords[1]);
	point->z = ft_atod(coords[2]);
}

int		check_normal(t_tuple n)
{
	if (n.x < -1 || n.x > 1 || n.y < -1 || n.y > 1 || n.z < -1 || n.z > 1)
		return (0);
	return (1);
}

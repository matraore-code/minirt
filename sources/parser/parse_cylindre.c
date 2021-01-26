/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:43:24 by matraore          #+#    #+#             */
/*   Updated: 2021/01/26 10:42:15 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_cylindre(t_canvas *canvas, char **array)
{
	t_object	*object;
	t_cylindre	*cylindre;

	if (line_fields(array) != 6)
		print_error("le Cylindre mal definie");
	object = malloc(sizeof(t_object));
	cylindre = malloc(sizeof(t_cylindre));
	parse_coords(&(cylindre->pos), array[1], "Cylindre mal definie");
    parse_coords(&(cylindre->vector), array[2], "Cylindre mal definie");
    normalize_vector(&(cylindre->vector));
	cylindre->size = ft_atod(array[4]);
    cylindre->height = ft_atod(array[5]);
	parse_colors(&(object->color), array[3], "Cylindre mal definie");
	if (!check_color(object->color))
		print_error("Cylindre mal definie");
	object->type = CYLINDER;
	object->ptr = cylindre;
	ft_lstadd_back(&(canvas->objects), ft_lstnew(object));
}
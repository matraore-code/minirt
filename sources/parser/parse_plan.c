/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:48:06 by matraore          #+#    #+#             */
/*   Updated: 2021/01/29 17:48:07 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"


void	parse_plane(t_canvas *canvas, char **array)
{
	t_object	*object;
	t_plane		*plane;

	if (line_fields(array) != 4)
		print_error("plan mal definie");
	object = malloc(sizeof(t_object));
	plane = malloc(sizeof(t_plane));
	parse_coords(&plane->p0, array[1], "plan mal definie");
	parse_coords(&plane->normal, array[2], "plan mal definie");
	normalize_vector(&plane->normal);
	parse_colors(&object->color, array[3], "plan mal definie");
	if (!check_color(object->color))
		print_error("plan mal definie");
	object->type = PLANE;
	object->ptr = plane;
	ft_lstadd_back(&(canvas->objects), ft_lstnew(object));
}
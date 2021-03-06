/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:51:52 by matraore          #+#    #+#             */
/*   Updated: 2021/02/02 11:09:54 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_square(t_canvas *canvas, char **array)
{
	t_object	*object;
	t_square	*square;

	if (line_fields(array) != 5)
		print_error(" le square mal definie");
	object = malloc(sizeof(t_object));
	square = malloc(sizeof(t_square));
	parse_coords(&(square->center), array[1], "square mal definie");
	parse_normal_coords(&(square->vector), array[2], "square mal definie");
	normalize_vector(&(square->vector));
	square->size = ft_atod(array[3]);
	if (square->size < 0)
		print_error("le rayon du carree doit etre positif");
	parse_colors(&(object->color), array[4], "couleur square mal definie");
	if (!check_color(object->color))
		print_error("square couleur mal definie");
	object->type = SQUARE;
	object->ptr = square;
	ft_lstadd_back(&(canvas->objects), ft_lstnew(object));
}

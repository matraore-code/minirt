/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:13:53 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:38:19 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_triangle(t_canvas *canvas, char **array)
{
	t_object	*object;
	t_triangle	*triangle;

	if (line_fields(array) != 5)
		print_error("Triangle mal definie");
	object = malloc(sizeof(t_object));
	triangle = malloc(sizeof(t_triangle));
	parse_coords(&(triangle->c1), array[1], "Triangle mal definie");
	parse_coords(&(triangle->c2), array[2], "Triangle mal definie");
	parse_coords(&(triangle->c3), array[3], "Triangle mal definie");
	parse_colors(&(object->color), array[4], "Triangle mal definie");
	if (!check_color(object->color))
		print_error("Triangle mal definie");
	object->type = TRIANGLE;
	object->ptr = triangle;
	ft_lstadd_back(&(canvas->objects), ft_lstnew(object));
}

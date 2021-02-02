/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:14:26 by matraore          #+#    #+#             */
/*   Updated: 2021/02/02 10:55:15 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_sphere(t_canvas *canvas, char **array)
{
	t_object	*object;
	t_sphere	*sphere;

	if (line_fields(array) != 4)
		print_error("Sphere mal definie");
	object = malloc(sizeof(t_object));
	sphere = malloc(sizeof(t_sphere));
	parse_coords(&(sphere->center), array[1], "Sphere mal definie");
	sphere->radius = ft_atod(array[2]) / 2;
	if (sphere->radius < 0)
		print_error("le rayon de la sphere doit etre positif");
	parse_colors(&(object->color), array[3], "Sphere mal definie");
	if (!check_color(object->color))
		print_error("Sphere mal definie");
	object->type = SPHERE;
	object->ptr = sphere;
	ft_lstadd_back(&(canvas->objects), ft_lstnew(object));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:29 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:33:57 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_resolution(t_canvas *canvas, char **array)
{
	if (canvas->width != 0 || canvas->height != 0)
		print_error("La resolution ne peut etre declare qu'une fois.");
	if (line_fields(array) != 3)
		print_error("Resolution mal declaree");
	canvas->width = ft_atoi(array[1]);
	canvas->height = ft_atoi(array[2]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:29 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 11:57:30 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_resolution(t_canvas *canvas, char **array)
{
	canvas->count_res++;
	if (line_fields(array) != 3)
		print_error("Resolution mal declaree");
	if (ft_strchr(array[1], '-') || ft_strchr(array[2], '-'))
		print_error("Resolution incorrect");
	canvas->width = ft_atoi(array[1]);
	canvas->height = ft_atoi(array[2]);	
}

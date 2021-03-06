/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:41 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 12:00:59 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_ambient(t_canvas *canvas, char **array)
{
	canvas->count_ambi++;
	if (canvas->ambient_color.r != -1)
		print_error("La lumiere ambiante doit etre declarer une seule fois.");
	if (line_fields(array) != 3)
		print_error("La lumiere ambiante est mal declare");
	canvas->ambient_intensity = ft_atod(array[1]);
	if (canvas->ambient_intensity < 0 || canvas->ambient_intensity > 1)
		print_error("l'intenisite doit etre dans l'interval [0, 1.0]");
	parse_colors(&(canvas->ambient_color), array[2],
					"Format de la couleur incorrecte");
	if (!check_color(canvas->ambient_color))
		print_error("Format de la couleur invalide.");
}

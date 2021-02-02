/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:26:23 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:16:32 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/main.h"

t_pixel		**create_buffer(int height, int width)
{
	t_pixel	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(t_pixel *) * height);
	while (i < height)
	{
		result[i] = malloc(sizeof(t_pixel) * width);
		i++;
	}
	return (result);
}

void		free_buffer(t_pixel **buffer, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		if (buffer[i] != NULL)
			free(buffer[i]);
		i++;
	}
	free(buffer);
}

t_pixel		pixel_to_int(int color)
{
	t_col	tc;
	t_pixel	result;

	tc = int_to_color(color);
	result.b = tc.b;
	result.g = tc.g;
	result.r = tc.r;
	return (result);
}

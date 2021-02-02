/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:01:41 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 11:53:55 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int		handle_key(int key, t_data *data)
{
	if (key == 124)
		data->camera_number += 1;
	else if (key == 123)
		data->camera_number -= 1;
	else if (key == 53)
		exit(0);
	render(data->camera_number, data, 0);
	return (0);
}

void	free_and_saving(t_pixel **buffer, t_data *data, int save)
{
	if (save)
		write_bmp("minirt.bmp", data->canvas->width, data->canvas->height,
				buffer);
	free_buffer(buffer, data->canvas->height);
}

char	*parse_dest(int color, int x, int y, t_data *data)
{
	char *dest;

	dest = data->image.addr + (y * data->image.line_length + x *
			(data->image.bits_per_pixel / 8));
	*(unsigned int*)dest = color;
	return (dest);
}

void	render(int camera_number, t_data *data, int save)
{
	int cameras_available;

	cameras_available = ft_lstsize(data->canvas->cameras);
	data->canvas->selected_camera = camera_number % cameras_available;
	trace_ray(data, save);
	if (save == 0)
		mlx_put_image_to_window(data->id, data->window, data->image.img, 0, 0);
}

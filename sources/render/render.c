/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:01:41 by matraore          #+#    #+#             */
/*   Updated: 2021/01/23 11:01:42 by matraore         ###   ########.fr       */
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


void	render(int camera_number, t_data *data, int save)
{
	int cameras_available;

	cameras_available = ft_lstsize(data->canvas->cameras);
	data->canvas->selected_camera = camera_number % cameras_available;
	trace_ray(data, save);
	mlx_put_image_to_window(data->id, data->window, data->image.img, 0, 0);
}
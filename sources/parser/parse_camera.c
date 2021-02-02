/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:38 by matraore          #+#    #+#             */
/*   Updated: 2021/02/02 11:06:45 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_camera(t_canvas *canvas, char **array)
{
	t_camera	*camera;
	t_list		*list_cam;

	if (line_fields(array) != 4)
		print_error("Camera mal definie");
	camera = malloc(sizeof(t_camera));
	parse_coords(&(camera->origin), array[1], "Camera mal definie");
	parse_normal_coords(&(camera->direction), array[2], "Camera mal definie");
	normalize_vector(&(camera->direction));
	camera->fov = ft_atoi(array[3]);
	if (camera->fov < 0 || camera->fov > 180)
		print_error("Camera mal definie");
	list_cam = ft_lstnew(camera);
	ft_lstadd_back(&(canvas->cameras), list_cam);
}

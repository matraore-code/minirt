/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:27:13 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 12:00:31 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void		free_all(char *line, char **array)
{
	int i;

	i = 0;
	if (line != NULL)
	{
		free(line);
	}
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void		init_canvas(t_canvas *canvas)
{
	canvas->cameras = NULL;
	canvas->lights = NULL;
	canvas->objects = NULL;
	canvas->height = 0;
	canvas->width = 0;
	canvas->ambient_color.r = -1;
	canvas->ambient_color.g = -1;
	canvas->ambient_color.b = -1;
	canvas->count_res = 0;
	canvas->count_ambi = 0;
}

void		check_canvas(t_canvas *canvas)
{
	if (canvas->cameras == NULL)
		print_error("le canvas doit avoir au moins une camera.");
	if (canvas->count_ambi != 1)
		print_error("Ambiante doit etre declaree une et une seule fois");
	if (canvas->ambient_color.r < 0 || canvas->ambient_color.g < 0
	|| canvas->ambient_color.b < 0)
		print_error("lumiere ambiante incorrect");
	if (canvas->width > 2560 || canvas->width == -1)
		canvas->width = 2560;
	if (canvas->height > 1440 || canvas->height == -1)
		canvas->height = 1440;
	if (canvas->count_res != 1)
		print_error("Resolution doit etre declaree une et une seule fois");
}

void		parse_line(t_canvas *canvas, char **array)
{
	if (line_fields(array) == 0)
		return ;
	else if (line_fields(array) < 2)
		print_error("Element de la canavs inconnue");
	if (ft_strncmp(array[0], "R", 1) == 0)
		parse_resolution(canvas, array);
	else if (ft_strncmp(array[0], "A", 1) == 0 && ft_strlen(array[0]) == 1)
		parse_ambient(canvas, array);
	else if (ft_strncmp(array[0], "c", 1) == 0 && ft_strlen(array[0]) == 1)
		parse_camera(canvas, array);
	else if (ft_strncmp(array[0], "l", 1) == 0 && ft_strlen(array[0]) == 1)
		parse_light(canvas, array);
	else if (ft_strncmp(array[0], "sp", 2) == 0 && ft_strlen(array[0]) == 2)
		parse_sphere(canvas, array);
	else if (ft_strncmp(array[0], "pl", 2) == 0 && ft_strlen(array[0]) == 2)
		parse_plane(canvas, array);
	else if (ft_strncmp(array[0], "tr", 2) == 0 && ft_strlen(array[0]) == 2)
		parse_triangle(canvas, array);
	else if (ft_strncmp(array[0], "cy", 2) == 0 && ft_strlen(array[0]) == 2)
		parse_cylindre(canvas, array);
	else if (ft_strncmp(array[0], "sq", 2) == 0 && ft_strlen(array[0]) == 2)
		parse_square(canvas, array);
	else
		print_error("Identifiant inconnu.");
}

t_canvas	*get_scene_info(char *path)
{
	int			fd;
	int			ret;
	char		*line;
	t_canvas	*canvas;
	char		**array;

	if ((fd = open_file(path)) == -1)
		return (0);
	canvas = malloc(sizeof(t_canvas));
	init_canvas(canvas);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		array = replace_tab_split(line);
		if (!check_line(line))
			print_error("Identifiant incorrect!");
		parse_line(canvas, array);
		free_all(line, array);
	}
	array = replace_tab_split(line);
	parse_line(canvas, array);
	free_all(line, array);
	check_canvas(canvas);
	close(fd);
	return (canvas);
}

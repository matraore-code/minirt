#include "../../includes/parsing.h"

void	init_canvas(t_canvas *canvas)
{
	canvas->cameras = NULL;
	canvas->lights = NULL;
	canvas->objects = NULL;
	canvas->height = 0;
	canvas->width = 0;
	canvas->ambient_color.r = -1;
	canvas->ambient_color.g = -1;
	canvas->ambient_color.b = -1;
}

void	check_canvas(t_canvas *canvas)
{
	if (canvas->cameras == NULL)
		print_error("la canavs doit avoir au moins une camera.");
	if (canvas->ambient_color.r < 0 || canvas->ambient_color.g < 0
	|| canvas->ambient_color.b < 0)
		print_error("lumiere ambiante incorrect");
	if (canvas->width <= 0 || canvas->height <= 0)
		print_error("la taille de l'image est incorrect");
	if (canvas->width > 2560)
		canvas->width = 2560;
	if (canvas->height > 1440)
		canvas->height = 1440;
}

void	parse_line(t_canvas *canvas, char **array)
{
	if (line_fields(array) == 0)
		return ;
	else if (line_fields(array) < 2)
		print_error("Element de la canavs inconnue");
	if (ft_strncmp(array[0], "R", 1) == 0)
		parse_resolution(canvas, array);
	else if (ft_strncmp(array[0], "A", 1) == 0)
		parse_ambient(canvas, array);
	else if (ft_strncmp(array[0], "c", 1) == 0)
		parse_camera(canvas, array);
	else if (ft_strncmp(array[0], "l", 1) == 0)
		parse_light(canvas, array);
	else if (ft_strncmp(array[0], "sp", 2) == 0)
		parse_sphere(canvas, array);
	else if (ft_strncmp(array[0], "pl", 2) == 0)
		parse_plane(canvas, array);
	else
		print_error("Identifiant inconnu.");
}


t_canvas	*get_canavs_info(char *path)
{
	int		fd;
	int		ret;
	char	*line;
	t_canvas	*canvas;
	char	**array;

	fd = open_file(path);
	if (fd == -1)
		return (0);
	canvas = malloc(sizeof(t_canvas));
	init_canvas(canvas);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		array = ft_split(line, ' ');
		if (!check_line(line))
			print_error("Identifiant incorrect!");
		parse_line(canvas, array);
		free(line);
	}
	array = ft_split(line, ' ');
	parse_line(canvas, array);
	free(line);
	check_canvas(canvas);
	close(fd);
	return (canvas);
}
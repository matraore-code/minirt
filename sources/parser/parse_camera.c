#include "../../includes/parsing.h"

void	parse_camera(t_canvas *canvas, char **array)
{
	t_camera	*camera;

	if (line_fields(array) != 4)
		print_error("Camera mal definie");
	camera = malloc(sizeof(t_camera));
	parse_coords(&(camera->origin), array[1], "Camera mal definie");
	parse_coords(&(camera->direction), array[2], "Camera mal definie");
	normalize_vector(&(camera->direction));
	camera->fov = ft_atoi(array[3]);
	if (camera->fov < 0 || camera->fov > 180)
		print_error("Camera mal definie");
	ft_lstadd_back(&(canvas->cameras), ft_lstnew(camera));
}
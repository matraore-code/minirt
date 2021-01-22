#include "../../includes/parsing.h"

void	parse_light(t_canvas *canvas, char **array)
{
	t_light	*light;


	if (line_fields(array) != 4)
		print_error("Lumiere mal de definie");
	light = malloc(sizeof(t_light));
	parse_coords(&(light->p0), array[1], "Lumiere mal de definie");
	light->intensity = ft_atod(array[2]);
	parse_colors(&(light->color), array[3], "Lumiere mal de definie");
	if (!check_color2(light->color))
		print_error("Lumiere mal de definie");
	ft_lstadd_back(&(canvas->lights), ft_lstnew(light));
}
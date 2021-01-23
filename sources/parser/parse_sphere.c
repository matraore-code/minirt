#include "../../includes/parsing.h"

void	parse_sphere(t_canvas *canvas, char **array)
{
	t_object	*object;
	t_sphere	*sphere;

	if (line_fields(array) != 4)
		print_error("Sphere mal definie");
	object = malloc(sizeof(t_object));
	sphere = malloc(sizeof(t_sphere));
	parse_coords(&(sphere->center), array[1], "Sphere mal definie");
	sphere->radius = ft_atod(array[2]) / 2;
	parse_colors(&(object->color), array[3], "Sphere mal definie");
	if (!check_color(object->color))
		print_error("Sphere mal definie");
	object->type = SPHERE;
	object->ptr = sphere;
	ft_lstadd_back(&(canvas->objects), ft_lstnew(object));
}
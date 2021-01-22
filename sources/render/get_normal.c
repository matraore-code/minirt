#include "../../includes/main.h"

t_tuple		get_normal(t_tuple point, t_object *object)
{
	if (object->type == SPHERE)
		return (get_sphere_normal(point, *(t_sphere *)object->ptr));
	if (object->type == PLANE)
		return (get_plane_normal(*(t_plane *)object->ptr));
}

t_tuple		get_sphere_normal(t_tuple point, t_sphere sphere)
{
	t_tuple n;

	n = substract(point, sphere.center);
	normalize_vector(&n);
	return (n);
}

t_tuple	get_plane_normal(t_plane plane)
{
	t_tuple ret;

	ret = plane.normal;
	return (ret);
}
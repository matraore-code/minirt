#include "../../includes/object.h"


t_plane	*new_plane(t_tuple p0, t_tuple normal)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	plane->p0 = p0;
	plane->normal = normal;
	return (plane);
}

int		hit_plane(t_ray ray, t_plane plane, double *t)
{
	double	denom;
	t_tuple	p0l0;

	denom = dot_product(plane.normal, ray.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract(plane.p0, ray.origin);
		*t = dot_product(p0l0, plane.normal) / denom;
		return (*t >= 0);
	}
	return (0);
}
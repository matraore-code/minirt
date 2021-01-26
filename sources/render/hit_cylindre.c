#include "../../includes/object.h"

t_cylindre	*new_cylinder(t_tuple p, t_tuple normal, double radius, double height)
{
	t_cylindre *cylinder;

	cylinder = malloc(sizeof(t_cylindre));
	cylinder->pos = p;
	cylinder->vector = normal;
	cylinder->size = radius;
	cylinder->height = height;
	return (cylinder);
}

t_tuple		get_cylindre_normal(t_tuple point, t_cylindre cylinder)
{
	t_tuple ctp;
	t_tuple normal;

	ctp = substract(point, cylinder.pos);
	normal = substract(ctp, tuple_multiply(cylinder.vector,
										dot_product(cylinder.vector, ctp)));
	normalize_vector(&normal);
	return (normal);
}

void		check_t(double *t, t_cylindre cylinder, t_ray ray)
{
	t_tuple q;
	t_tuple p2;

	p2 = tuple_add(cylinder.pos, tuple_multiply(cylinder.vector, cylinder.height));
	q = tuple_add(ray.origin, tuple_multiply(ray.direction, *t));
	if (dot_product(cylinder.vector, substract(q, cylinder.pos)) <= 0)
		*t = -1;
	if (dot_product(cylinder.vector, substract(q, p2)) >= 0)
		*t = -1;
}

int			cyl_get_roots(double *t0, double *t1, t_cylindre cylinder,
								t_ray ray)
{
	t_tuple	a_sqrt;
	t_tuple	right;
	double	a;
	double	b;
	double	c;

	a_sqrt = substract(ray.direction,
								tuple_multiply(cylinder.vector,
								dot_product(ray.direction, cylinder.vector)));
	a = dot_product(a_sqrt, a_sqrt);
	right = substract(substract(ray.origin, cylinder.pos),
						tuple_multiply(cylinder.vector,
							dot_product(substract(ray.origin, cylinder.pos),
							cylinder.vector)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - (cylinder.size * cylinder.size);
	if (!solve_quadratic(create_tuple(a, b, c), t0, t1))
		return (0);
	return (1);
}

int			intersect_cylindre(t_ray ray, t_cylindre cylinder, double *t)
{
	double t0;
	double t1;

	if (!cyl_get_roots(&t0, &t1, cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylinder, ray);
	if (t1 > 0)
		check_t(&t1, cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	if (t1 < t0)
		if (t1 > 0)
			*t = t1;
		else
			*t = t0;
	else
	{
		if (t0 > 0)
			*t = t0;
		else
			*t = t1;
	}
	return (1);
}
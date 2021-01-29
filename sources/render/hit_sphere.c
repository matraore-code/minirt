#include "../../includes/object.h"

void		swap_doubles(double *a, double *b)
{
	double buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

t_sphere	*new_sphere(t_tuple center, double radius)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

int			solve_quadratic(t_tuple params, double *x0, double *x1)
{
	double discr;
	double q;

	discr = pow(params.y, 2) - 4 * params.x * params.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * params.y / params.x;
		*x1 = -0.5 * params.y / params.x;
	}
	else
	{
		*x0 = ((-1 * params.y) - sqrt(discr)) / (2 * params.x);
		*x1 = ((-1 * params.y) + sqrt(discr)) / (2 * params.x);
	}
	return (1);
}

int			get_roots(double *t0, double *t1, t_ray ray, t_sphere sphere)
{
	t_tuple	l;
	double	a;
	double	b;
	double	c;

	l = substract(ray.origin, sphere.center);
	a = dot_product(ray.direction, ray.direction);
	b = 2.0 * dot_product(ray.direction, l);
	c = dot_product(l, l) - (sphere.radius * sphere.radius);
	if (solve_quadratic(create_tuple(a, b, c), t0, t1) == 0)
		return (0);
	return (1);
}

int			hit_sphere(t_ray ray, t_sphere sphere, double *t)
{
	double t0;
	double t1;

	if (get_roots(&t0, &t1, ray, sphere) == 0)
		return (0);
	if (t0 < 0)
	{
		t0 = t1;
		if (t0 < 0)
			return (0);
	}
	*t = t0;
	return (1);
}

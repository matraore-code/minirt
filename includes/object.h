#ifndef OBJECTS_H
# define OBJECTS_H

# include "tuple.h"
# include "outils.h"
#include "main.h"

typedef struct	s_plane
{
	t_tuple p0;
	t_tuple normal;
}				t_plane;

typedef struct	s_sphere
{
	t_tuple	center;
	double	radius;
}				t_sphere;

t_plane			*new_plane(t_tuple p0, t_tuple normal);
t_tuple			get_plane_normal(t_plane plane);
int				hit_plane(t_ray ray, t_plane plane, double *t);

void			swap_doubles(double *a, double *b);
int				solve_quadratic(t_tuple params, double *x0, double *x1);
t_sphere		*new_sphere(t_tuple center, double radius);
t_tuple			get_sphere_normal(t_tuple point, t_sphere sphere);
int				hit_sphere(t_ray ray, t_sphere sphere, double *t);
int				get_roots(double *t0, double *t1, t_ray ray, t_sphere sphere);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:31:10 by matraore          #+#    #+#             */
/*   Updated: 2021/02/02 12:14:58 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "tuple.h"
# include "outils.h"
# include <stdlib.h>
# include <stdio.h>
# define EPSILON 0.000001

typedef struct		s_ray
{
	t_tuple			origin;
	t_tuple			direction;
}					t_ray;

typedef	struct		s_plane
{
	t_tuple			p0;
	t_tuple			normal;
}					t_plane;

typedef	struct		s_triangle
{
	t_tuple			c1;
	t_tuple			c2;
	t_tuple			c3;
}					t_triangle;

typedef	struct		s_sphere
{
	t_tuple			center;
	double			radius;
}					t_sphere;

typedef	struct		s_cylinder
{
	t_tuple			pos;
	t_tuple			vector;
	double			size;
	double			height;
}					t_cylindre;

typedef	struct		s_square
{
	t_tuple			center;
	t_tuple			vector;
	double			size;
}					t_square;

typedef struct		s_calculus
{
	t_tuple			x;
	double			a_elements;
	double			b_elements;
}					t_cal;

t_ray				create_ray(t_tuple origin, t_tuple direction);
t_plane				*new_plane(t_tuple p0, t_tuple normal);
t_tuple				get_plane_normal(t_plane plane);
int					hit_plane(t_ray ray, t_plane plane, double *t);
void				swap_doubles(double *a, double *b);
int					solve_quadratic(t_tuple params, double *x0, double *x1);
t_sphere			*new_sphere(t_tuple center, double radius);
t_tuple				get_sphere_normal(t_tuple point, t_sphere sphere);
int					hit_sphere(t_ray ray, t_sphere sphere, double *t);
int					get_roots(double *t0, double *t1, t_ray ray,
						t_sphere sphere);
t_tuple				get_triangle_normal(t_triangle triangle);
int					hit_triangle(t_ray ray, t_triangle triangle,
						double *t);
int					hit_square(t_ray ray, t_square square, double *t);
t_tuple				get_square_normal(t_square square);
t_cylindre			*new_cylinder(t_tuple p, t_tuple normal,
						double radius, double height);
void				check_t(double *t, t_cylindre cylinder, t_ray ray);
int					cyl_get_roots(double *t0, double *t1,
						t_cylindre cylinder, t_ray ray);
int					hit_cylindre(t_ray ray,
						t_cylindre cylinder, double *t);
t_tuple				get_cylindre_normal(t_tuple point,
						t_cylindre cylinder);

#endif

#ifndef MAIN_H
# define MAIN_H


# include <mlx.h>
# include <math.h>
#include <stdlib.h>
#include "tuple.h"
#include "gnl.h"
#include "outils.h"
#include "object.h"
#include "parsing.h"

typedef struct	s_camera
{
	t_tuple	origin;
	t_tuple	direction;
	int		fov;
}				t_camera;

typedef struct	s_canvas
{
	t_list		*objects;
	t_list		*lights;
	int			width;
	int			height;
	double		ambient_intensity;
	t_color	ambient_color;
	t_list		*cameras;
	int			selected_camera;
}				t_canvas;



typedef enum	e_object_type
{
	SPHERE,
	CUBE,
	PLANE,
	LIGHT,
	TRIANGLE,
	SQUARE,
	CYLINDER,
}				t_otype;

typedef struct	s_object
{
	t_otype		type;
	void		*ptr;
	t_color	color;
	double		albedo;

}				t_object;

typedef struct	s_light
{
	t_tuple		p0;
	double		intensity;
	t_color	color;
}				t_light;

typedef struct	s_ray
{
	t_tuple origin;
	t_tuple direction;
}   t_ray;

typedef struct	s_hit
{
	t_tuple		hit_point;
	t_tuple		hit_normal;
	t_list		*objects;
	t_object	*closest_object;
	t_ray		ray;
}				t_hit;

typedef	struct	s_image {
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_canvas
{
	t_list		*objects;
	t_list		*lights;
	int			width;
	int			height;
	double		ambient_intensity;
	t_color	ambient_color;
	t_list		*cameras;
	int			selected_camera;
}				t_canvas;


typedef struct	s_data
{
	t_canvas		*canvas;
	int			camera_number;
	void		*id;
	void		*window;
	t_image		image;
}				t_data;

t_ray			create_ray(t_tuple origin, t_tuple direction);
t_ray			ray_to_pixel(int x, int y, t_canvas *sene);
int		handle_key(int key, t_data *data);
int		close_window(t_data *data);
void	trace_ray(t_data *data, int save);
void			initialize_mlx(char *filepath, int save);
int		get_obj_hit(t_ray ray, t_object *object, double *t);
int		hit_objects(t_list *objects, t_ray ray,
							t_object **closest_object, double *t_min);
t_ tuple			get_normal(t_ tuple point, t_object *object);
t_color		light_contribution(t_light light, t_hit hit_point, t_canvas canvas);
t_color		compute_lights(t_canvas *canvas, t_ray ray, t_object *closest_object,
																double t_min);
int				get_color(t_canvas *canvas, t_ray ray);
t_tuple		get_normal(t_tuple point, t_object *object);
t_hit		create_hit(t_tuple hit_point, t_tuple hit_normal,
									t_object *closest_object, t_ray ray)
t_color		mix_colors(t_light light, double coeff, t_hit hit_point);
double			spec_coeff(t_light light, t_hit hit_point);
t_color		specular(t_light light, t_hit hit_point);





#endif
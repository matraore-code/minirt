/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:31:38 by matraore          #+#    #+#             */
/*   Updated: 2021/01/23 11:10:59 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>
# include <stdlib.h>
# include "gnl.h"
# include "outils.h"
# include "object.h"

typedef struct	s_camera
{
	t_tuple	origin;
	t_tuple	direction;
	int		fov;
}				t_camera;



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


typedef struct	s_canvas
{
	t_list		*objects;
	t_list		*lights;
	int			width;
	int			height;
	double		ambient_intensity;
	t_color     ambient_color;
	t_list		*cameras;
	int			selected_camera;
}				t_canvas;

t_canvas	*get_scene_info(char *path);
void	check_canvas(t_canvas *canvas);
void	init_canvas(t_canvas *canvas);
void	parse_line(t_canvas *canvas, char **array);
void	parse_coordinates(t_tuple *point, char *line, int *i, int *move);
void	parse_color(t_object *object, char *line, int *i, int *move);
int		open_file(char *path);
void	print_error(char *err);
void	parse_sphere(t_canvas *canvas, char **array);
void	parse_plane(t_canvas *canvas, char **array);
void	parse_resolution(t_canvas *canvas, char **array);
void	parse_ambient(t_canvas *canvas, char **array);
void	parse_camera(t_canvas *canvas, char **array);
void	parse_light(t_canvas *canvas, char **array);
char	**ft_split(char const *s, char c);
int		line_fields(char **array);
int		check_color(t_color c);
void	parse_colors(t_color *result, char *field, char *err);
void	parse_coords(t_tuple *point, char *field, char *err);
int		check_normal(t_tuple n);
void	check_canvas(t_canvas *canvas);
int		allowed_symbol(char c);
int		check_line(char *line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
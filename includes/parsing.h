#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>
# include "gnl.h"
# include "main.h"
# include "outils.h"

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
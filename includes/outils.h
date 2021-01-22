#ifndef OUTILS_H
# define OUTILS_H

#include <unistd.h>


typedef struct	s_color
{
	double r;
	double g;
	double b;
}				t_color;


typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}    t_list;


int		ft_atoi(const char *str);
int				ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ten_to(int pow);
double	dot_part(char *str, int *len);
double	ft_atod(char *str);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *list);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

t_color			int_to_color(int color);
int				color_to_int(t_color color);
t_color		int_color(int color);
t_color		from_color(t_color a);
t_color		color_add(t_color a, t_color b);
t_color		color_mult(t_color a, t_color b);
t_color		color_coeff(t_color a, double coeff);
t_color		from_rgb(int r, int g, int b);
t_color		from_rgb(int r, int g, int b);
int				to_int(t_color a);



#endif
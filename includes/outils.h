/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:31:28 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 10:28:41 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTILS_H
# define OUTILS_H

# include <unistd.h>
# include <math.h>

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef union		u_int_color
{
	int				integer;
	unsigned char	comps[4];
}					t_int_color;

typedef	struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
double				ten_to(int pow);
void				ft_putstr_fd(char *s);
void				ft_putchar_fd(char c);
double				dot_part(char *str, int *len);
double				ft_atod(char *str);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *list);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				free_list(t_list *head);
t_col				int_to_color(int color);
int					color_to_int(t_col color);
t_color				int_color(int color);
t_color				from_color(t_color a);
t_color				color_add(t_color a, t_color c);
t_color				color_mult(t_color a, t_color b);
t_color				color_coeff(t_color a, double coeff);
t_color				from_rgb(int r, int g, int b);
t_color				from_rgb(int r, int g, int b);
int					to_int(t_color a);
char				*ft_strchr(const char *s, int c);
char				**replace_tab_split(char *str);
char				**ft_split(char const *s, char c);

#endif

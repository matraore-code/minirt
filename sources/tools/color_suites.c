#include "../../includes/outils.h"


typedef struct	s_col
{
	int r;
	int g;
	int b;
}				t_col;

typedef union	u_int_color
{
	int				integer;
	unsigned char	comps[4];
}				t_int_color;


t_col	int_to_color(int col)
{
	t_int_color	a;
	t_col	result;

	a.integer = col;
	result.r = a.comps[2];
	result.g = a.comps[1];
	result.b = a.comps[0];
	return (result);
}

int		color_to_int(t_col color)
{
	t_int_color a;

	a.comps[2] = color.r;
	a.comps[1] = color.g;
	a.comps[0] = color.b;
	return (a.integer);
}

int			to_int(t_color a)
{
	int		color;
	t_col this;

	this.r = a.r * 256;
	this.g = a.g * 256;
	this.b = a.b * 256;
	color = color_to_int(this);
	return (color);
}

t_color	int_color(int color)
{
	t_col		this;
	t_color	result;

	this = int_to_color(color);
	result.r = (double)this.r / 256;
	result.g = (double)this.g / 256;
	result.b = (double)this.b / 256;
	return (result);
}

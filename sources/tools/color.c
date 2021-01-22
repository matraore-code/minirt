#include "../../includes/outils.h"

t_color	color_add(t_color a, t_color b)
{
	t_color	color;

	color.r = fmin(a.r + b.r, 0.99);
	color.g = fmin(a.g + b.g, 0.99);
	color.b = fmin(a.b + b.b, 0.99);
	return (color);
}

t_color	color_mult(t_color a, t_color b)
{
	t_color color;

	color.r = fmin(a.r * b.r, 1);
	color.g = fmin(a.g * b.g, 1);
	color.b = fmin(a.b * b.b, 1);
	return (color);
}

t_color	color_coeff(t_color a, double coeff)
{
	t_color color;

	color.r = fmin(a.r * coeff, 1);
	color.g = fmin(a.g * coeff, 1);
	color.b = fmin(a.b * coeff, 1);
	return (color);
}

t_color	from_color(t_color a)
{
	t_color	result;

	result.r = a.r / 256;
	result.g = a.g / 256;
	result.b = a.b / 256;
	return (result);
}

t_color	from_rgb(int r, int g, int b)
{
	t_color	result;

	result.r = (double)r / 256;
	result.g = (double)g / 256;
	result.b = (double)b / 256;
	return (result);
}

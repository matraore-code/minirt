#include "../../includes/tuple.h"

void	normalize_vector(t_tuple *vector)
{
	double len;

	len = sqrt(vector->x * vector->x + vector->y
	* vector->y + vector->z * vector->z);
	vector->x /= len;
	vector->y /= len;
	vector->z /= len;
}

t_tuple	create_tuple(double x, double y, double z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

double	vector_len(t_tuple vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y +
													vector.z * vector.z));
}

double	dot_product(t_tuple a, t_tuple b)
{
	double sum;

	sum = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (sum);
}

t_tuple	tuple_add(t_tuple vec1, t_tuple vec2)
{
	t_tuple result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

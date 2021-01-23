#include "../../includes/main.h"

t_hit		create_hit(t_tuple hit_point, t_tuple hit_normal,
									t_object *closest_object, t_ray ray)
{
	t_hit hit;

	hit.hit_point = hit_point;
	hit.hit_normal = hit_normal;
	hit.closest_object = closest_object;
	hit.ray = ray;
	return (hit);
}

int		get_obj_hit(t_ray ray, t_object *object, double *t)
{
	if (object->type == SPHERE)
		return (hit_sphere(ray, *(t_sphere *)object->ptr, t));
	else 
		return (hit_plane(ray, *(t_plane *)object->ptr, t));
}

int		hit_objects(t_list *objects, t_ray ray,
									t_object **closest_object, double *t_min)
{
	t_list		*node;
	t_object	*this_object;
	double		t;

	*closest_object = NULL;
	node = objects;
	*t_min = INFINITY;
	while (node != NULL)
	{
		this_object = node->content;
		if (get_obj_hit(ray, this_object, &t))
		{
			if (t < *t_min)
			{
				*closest_object = this_object;
				*t_min = t;
			}
		}
		node = node->next;
	}
	if (*closest_object != NULL)
		return (1);
	else
		return (0);
}
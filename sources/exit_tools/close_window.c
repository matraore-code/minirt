#include "../../includes/main.h"

int		close_window(t_data *data)
{
	mlx_destroy_window(data->id, data->window);
	exit(0);
}
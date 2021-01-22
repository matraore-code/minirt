#include "includes/main.h"

void	intialize_mlx(char *filepath, int save)
{
	t_data data;

	data.canvas = get_scene_info(filepath);
	data.camera_number = 0;
	if (save == 1)
	{
		render(0, &data, 1);
		return ;
	}
	data.id = mlx_init();
	data.window = mlx_new_window(data.id, data.canvas->width,
									data.canvas->height, "miniRT");
	data.image.img = mlx_new_image(data.id, data.canvas->width,
										data.canvas->height);
	data.image.addr = (int *)mlx_get_data_addr(data.image.img,
										&(data.image.bits_per_pixel),
										&(data.image.line_length),
										&(data.image.endian));
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_key_hook(data.window, handle_key, &data);
	render(0, &data, save);
	mlx_loop(data.id);
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		return (42);
	else
	{
		if (ac == 2)
			intialise_mlx(av[1], 0);
		else if (ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
			intialise_mlx(av[1], 1);
	}
	return (0);

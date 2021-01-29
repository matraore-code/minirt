/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:12:49 by matraore          #+#    #+#             */
/*   Updated: 2021/01/23 15:51:02 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

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
	data.window = mlx_new_window(data.id, data.canvas->width,data.canvas->height, "RayTracing");
	data.image.img = mlx_new_image(data.id, data.canvas->width,data.canvas->height);
	data.image.addr = mlx_get_data_addr(data.image.img,&(data.image.bits_per_pixel),&(data.image.line_length),&(data.image.endian));
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_key_hook(data.window, handle_key, &data);
	render(0, &data, save);
	mlx_loop(data.id);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		print_error("Argument invalid");
	else
	{
		if (argc == 2)
			intialize_mlx(argv[1], 0);
		else if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
			initialize_mlx(argv[1], 1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:12:49 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 10:36:20 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	check_filepath(char **argv)
{
	char	*filepath;
	
	filepath = argv[1] + ft_strlen(argv[1]) - 4;
	if (ft_strlen(argv[1]) <= 3 || *filepath == '/')
		print_error("Ce fichier est un fichier masque");
}

void	intialize_mlx(char *filepath, int save)
{
	t_data data;

	data.canvas = get_scene_info(filepath);
	data.camera_number = 0;
	if (save == 1)
	{
		render(0, &data, 1);
		free(data.canvas);
		return ;
	}
	data.id = mlx_init();
	data.window = mlx_new_window(data.id,
			data.canvas->width, data.canvas->height, "RayTracing");
	data.image.img = mlx_new_image(data.id, data.canvas->width,
			data.canvas->height);
	data.image.addr = mlx_get_data_addr(data.image.img,
			&(data.image.bits_per_pixel),
			&(data.image.line_length), &(data.image.endian));
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_key_hook(data.window, handle_key, &data);
	render(0, &data, save);
	mlx_loop(data.id);
}

int		main(int argc, char **argv)
{
	char	*filepath;

	if (argc < 2 || argc > 3)
		print_error("Arguments invalides");
	else
	{
		filepath = argv[1] + ft_strlen(argv[1]) - 3;
		check_filepath(argv);
		if (ft_strncmp(filepath, ".rt", ft_strlen(filepath)) == 0)
		{
			if (argc == 2)
				intialize_mlx(argv[1], 0);
			else if (ft_strncmp(argv[2], "--save", ft_strlen("--save")) == 0)
				intialize_mlx(argv[1], 1);
			else
				print_error("Option invalide");
		}
		else
		{
			ft_putstr_fd("Usage: ./miniRt file_name [--save]\n");
			print_error("Extension invalide");
		}
	}
	return (0);
}

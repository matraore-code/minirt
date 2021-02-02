/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:50:11 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 10:20:12 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <stdio.h>

void	print_error(char *err)
{
	ft_putstr_fd("Error");
	ft_putstr_fd("\n");
	ft_putstr_fd(err);
	ft_putstr_fd("\n");
	exit(-1);
}

int		open_file(char *path)
{
	int			fd;
	extern int	errno;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error(strerror(errno));
	return (fd);
}

int		line_fields(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

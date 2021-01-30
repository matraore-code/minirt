/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:50:11 by matraore          #+#    #+#             */
/*   Updated: 2021/01/29 17:51:28 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <stdio.h>

void	print_error(char *err)
{
	printf("Error\n");
	printf("%s\n", err);
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
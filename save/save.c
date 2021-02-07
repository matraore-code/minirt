/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:40:51 by matraore          #+#    #+#             */
/*   Updated: 2021/02/06 08:16:04 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/main.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	*lim;

	str = b;
	lim = b + len;
	while (str != lim)
		*(str++) = (unsigned char)c;
	return (b);
}

void		fill_header(unsigned char *header)
{
	ft_memset(header, 0, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[10] = 54;
	header[14] = 40;
	header[26] = 1;
	header[28] = 24;
}

void		fill_sizes(unsigned char *header, unsigned int height,
				unsigned int width)
{
	unsigned int	pixels_in_row;
	unsigned int	padding_in_row;

	*(unsigned int *)(&header[18]) = width;
	*(unsigned int *)(&header[22]) = height;
	pixels_in_row = width * sizeof(t_pixel);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	header[2] = 54 + (pixels_in_row + padding_in_row) * height;
}

void		write_file(unsigned int height, unsigned int width,
				t_pixel **pixels, int fd)
{
	unsigned int	pixels_in_row;
	unsigned int	padding_in_row;
	unsigned char	zeroes[3];
	int				row;

	zeroes[0] = 0;
	zeroes[1] = 0;
	zeroes[2] = 0;
	pixels_in_row = width * sizeof(t_pixel);
	padding_in_row = (4 - (pixels_in_row % 4)) % 4;
	row = height;
	while (row >= 0)
	{
		write(fd, pixels[row], pixels_in_row);
		write(fd, zeroes, padding_in_row);
		row--;
	}
}

int			write_bmp(char *filename, unsigned int width,
				unsigned int height, t_pixel **pixels)
{
	int				fd;
	unsigned char	header[54];

	fill_header(header);
	fill_sizes(header, height, width);
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	write(fd, header, 54);
	write_file(height, width, pixels, fd);
	close(fd);
	return (0);
}

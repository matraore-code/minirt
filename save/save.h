#ifndef BMP_H
# define BMP_H

# define PIXEL_DATA_OFFSET 54
# define HEADER_SIZE 40
# define PLANES 1
# define BITS_PER_PIXEL 24
# include "../includes/outils.h"


typedef struct	s_pixel{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}				t_pixel;

int				write_bmp(char *filename, unsigned int width, unsigned int height, t_pixel **pixels);

t_pixel	**create_buffer(int height, int width);
void	free_buffer(t_pixel **buffer, int height);
t_pixel	pix_from_int(int color);

#endif
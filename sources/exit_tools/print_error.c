#include "../../includes/parsing.h"

void	print_error(char *err)
{
	write(2, "Error\n", 6);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(-1);
}

int		open_file(char *path)
{
	int			fd;
	extern int	errno;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(strerror(errno));
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
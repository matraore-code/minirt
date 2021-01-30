/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:49:59 by matraore          #+#    #+#             */
/*   Updated: 2021/01/29 17:50:00 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gnl.h"
#include "../../includes/outils.h"

char	*resize(t_buffer *buffer)
{
	char	*result;
	int		i;
	int		y;
	int		current_length;

	current_length = ft_strlen(buffer->str) - buffer->position;
	buffer->length = current_length;
	if (!(result = malloc(sizeof(char) * (BUFFER_SIZE + current_length + 1))))
		return (NULL);
	i = buffer->position;
	y = 0;
	while (buffer->str[i])
		result[y++] = buffer->str[i++];
	result[y] = '\0';
	free(buffer->str);
	buffer->str = result;
	buffer->position = 0;
	return (result);
}

int		find_nl(t_buffer buffer)
{
	int		i;
	char	*str;

	str = &buffer.str[buffer.position];
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		read_to_mem(t_buffer *buffer, int fd)
{
	int			received;
	char		*resized;

	resized = "start";
	if (buffer->str == NULL || buffer->fd != fd)
	{
		buffer->position = 0;
		buffer->length = 0;
		if ((buffer->str = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
			return (-1);
	}
	else
		resized = resize(buffer);
	buffer->fd = fd;
	if ((received = read(fd, buffer->str + buffer->length, BUFFER_SIZE)) == -1
			|| !resized)
	{
		free(buffer->str);
		buffer->str = NULL;
		return (-1);
	}
	(buffer->str)[buffer->length + received] = '\0';
	return (received);
}

int		copy_to_line(t_buffer *buffer, char **line)
{
	int i;
	int line_size;

	if (find_nl(*buffer) == -1)
		line_size = ft_strlen(&(buffer->str[buffer->position]));
	else
		line_size = find_nl(*buffer);
	if ((*line = malloc(sizeof(char) * (line_size + 1))) == NULL)
		return (-1);
	i = 0;
	while (i < line_size)
		(*line)[i++] = buffer->str[buffer->position++];
	buffer->position++;
	(*line)[i] = '\0';
	return (line_size);
}

int		get_next_line(int fd, char **line)
{
	int				received;
	static t_buffer	buffer;
	int				line_size;

	if (!line || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	if ((received = read_to_mem(&buffer, fd)) == -1)
		return (-1);
	while (received >= BUFFER_SIZE && (find_nl(buffer) == -1))
		if ((received = read_to_mem(&buffer, fd)) == -1)
			return (-1);
	if ((line_size = copy_to_line(&buffer, line)) == -1)
		return (-1);
	if (received < BUFFER_SIZE && line_size >= ft_strlen(buffer.str))
	{
		free(buffer.str);
		buffer.str = NULL;
		return (0);
	}
	else if (received == -1)
		return (-1);
	else
		return (1);
}

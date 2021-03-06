/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:31:04 by matraore          #+#    #+#             */
/*   Updated: 2021/01/31 09:17:25 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct		s_buffer
{
	char			*str;
	int				position;
	int				length;
	int				last_received;
	int				fd;
}					t_buffer;

int					read_to_mem(t_buffer *buffer, int fd);
int					copy_to_line(t_buffer *buffer, char **line);
int					get_next_line(int fd, char **line);
char				*resize(t_buffer *buffer);
int					find_nl(t_buffer buffer);

#endif

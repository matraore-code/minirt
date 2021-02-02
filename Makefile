# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matraore <matraore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 14:17:05 by matraore          #+#    #+#              #
#    Updated: 2021/02/02 11:17:38 by matraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c save/save.c save/save_tools.c sources/exit_tools/close_window.c\
	   sources/exit_tools/print_error.c sources/librairies_tools/gnl_tools.c\
	   sources/librairies_tools/libft_list.c\
	   sources/librairies_tools/libft_tools.c\
	   sources/librairies_tools/libft_tools2.c\
	   sources/librairies_tools/libft_tools3.c sources/parser/parse_ambient.c\
	   sources/parser/parse_light.c sources/parser/parse_sphere.c\
	   sources/parser/parse_triangle.c sources/parser/parse_camera.c\
	   sources/parser/parse_plan.c sources/parser/parse_square.c\
	   sources/parser/parser.c sources/parser/parse_cylindre.c\
	   sources/parser/parse_resolution.c sources/parser/parse_tools2.c\
	   sources/parser/paser_tools.c sources/render/generating_rays.c\
	   sources/render/hit.c sources/render/hit_plane.c\
	   sources/render/render.c sources/render/hit_square.c\
	   sources/render/get_normal.c sources/render/hit_cylindre.c\
	   sources/render/hit_sphere.c sources/render/hit_triangle.c\
	   sources/render/trace_ray.c sources/tools/color.c\
	   sources/tools/look_at.c sources/tools/color_suites.c\
	   sources/tools/tuples.c sources/tools/tuples_suites.c\
	   sources/parser/tool.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

CFLAGS = -Wall -Wextra -Werror


all:		$(NAME)

.c.o:
			gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			gcc -o $(NAME) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all

SRCS = 
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
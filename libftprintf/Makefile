SRCS =	ft_printf.c\
		print_nbr.c\
		print_ptr.c\
		print_hex.c\
		print_str.c\
		print_unsigned_nbr.c\
		utils_output.c\
		
OBJS = $(SRCS:c=o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -rf
HEADER = ft_printf.h

NAME = libftprintf.a

all: $(OBJ) $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(HEADER) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean:		clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean
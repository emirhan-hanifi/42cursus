.SILENT:

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchr.c ft_putstr.c ft_putptr.c ft_putnbr.c \
		ft_putunbr.c ft_puthex.c ft_print_format.c ft_putpercent.c

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME):$(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY:all $(NAME) clean fclean re
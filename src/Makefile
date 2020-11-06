NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = ft_printf.c get.c identify.c parse.c route.c utils1.c utils2.c
OBJ = ft_printf.o get.o identify.o parse.o route.o utils1.o utils2.o
all: $(NAME)

$(NAME): $(SRC) libftprintf.h
	gcc $(CFLAGS) -c $(SRC)
	ar rc $@ $(OBJ)
	ranlib libftprintf.a

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

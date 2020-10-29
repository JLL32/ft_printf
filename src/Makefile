NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -pedantic
# SRC = ft_printf.c routers.c validators.c getters.c printers.c utils1.c utils2.c
SRC = *.c
# OBJ = ft_printf.o routers.o validators.o getters.o printers.o utils1.o utils2.o
OBJ = *.o
# BSRC =
# BOBJ =
# TODO: Add the header files as a dependency
all: $(NAME)

$(NAME): $(SRC) *.h
	gcc $(CFLAGS) -c $(SRC)
	ar rc $@ $(OBJ)
	ranlib libftprintf.a

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

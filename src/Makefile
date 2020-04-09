NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = ft_printf.c routers.c validators.c getters.c printers.c
OBJ = ft_printf.o routers.o validators.o getters.o printers.o libft/libft.a
# BSRC =
# BOBJ =
# TODO: Add the header files as a dependency
all: $(NAME)

$(NAME): $(SRC)
	(cd libft; make)
	gcc $(CFLAGS) -c $^
	ar rc $@ $(OBJ)
	ranlib libftprintf.a

clean:
	(cd libft; make clean)
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	(cd libft; make fclean)
	rm -f $(NAME)

re: fclean all

debug: $(SRC)
	gcc -g main.c $(CFLAGS) $^ -L ./libft -lft -o main

# bonus: $(BSRC)
# 	gcc $(CFLAGS) -c $^
# 	ar rcs $(NAME) $(BOBJ)

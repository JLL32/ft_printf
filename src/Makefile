NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = ft_printf.c routers.c validators.c getters.c printers.c utils.c
OBJ = ft_printf.o routers.o validators.o getters.o printers.o utils.o
# BSRC =
# BOBJ =
# TODO: Add the header files as a dependency
all: $(NAME)

$(NAME): $(SRC)
	gcc $(CFLAGS) -c $^
	ar rc $@ $(OBJ)
	ranlib libftprintf.a

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: $(SRC)
	gcc -g main.c $(CFLAGS) $^ -o main

test: debug
	./main

# bonus: $(BSRC)
# 	gcc $(CFLAGS) -c $^
# 	ar rcs $(NAME) $(BOBJ)

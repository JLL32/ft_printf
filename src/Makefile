NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = *.c
OBJ = *.o
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

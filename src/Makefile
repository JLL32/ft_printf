NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c libftprintf.h
OBJ = ft_printf.o
# BSRC =
# BOBJ =

all: $(NAME)

$(NAME): $(SRC)
	(cd libft; make)
	gcc $(CFLAGS) -c $^
	ar rcs $@ $(OBJ)

clean:
	(cd libft; make clean)
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	(cd libft; make fclean)
	rm -f $(NAME)

re: fclean all

# bonus: $(BSRC)
# 	gcc $(CFLAGS) -c $^
# 	ar rcs $(NAME) $(BOBJ)

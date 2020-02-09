# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 11:03:15 by mhaddi            #+#    #+#              #
#    Updated: 2020/01/23 11:35:43 by mhaddi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

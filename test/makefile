CFLAGS = -Wall -Werror -Wextra -pedantic -g
SRC = ../src/*.c

test:
	(cd ../src/; make)
	cc $(CFLAGS) main.c $(SRC) -o main
	./main

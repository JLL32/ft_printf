CFLAGS = -Wall -Werror -Wextra -pedantic

test:
	(cd ../src/; make)
	cc $(CFLAGS) main.c -L ../src  -lftprintf -o main
	./main

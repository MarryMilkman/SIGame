NAME_LIB	:= lib_sqlite.a
NAME		:=sql_shell

SRC		:= ./shell.c ./sqlite3.c

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc *.o -o $(NAME)
	ar rc $(NAME_LIB) sqlite3.o
	ranlib $(NAME_LIB)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME) $(NAME_LIB)

re: fclean all

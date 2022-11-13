OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o
FLAGS = -Werror -Wall -Wextra
NAME = so_long

$(NAME) : $(OBJFILES) libft.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES) libft.a

all : $(NAME)

re : fclean all

clean :
	rm -f $(OBJFILES) libft.a

fclean :
	rm -f $(NAME) $(OBJFILES) libft.a

libft.a :
	make -C libft
	cp libft/libft.a libft.a

%.o : %.c
	$(CC) -c $(FLAGS) -o $@ $^

.PHONY : clean fclean re

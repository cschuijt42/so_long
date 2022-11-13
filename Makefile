OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o
FLAGS = -Werror -Wall -Wextra
NAME = libft.a

$(NAME) : $(OBJFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES)

all : $(NAME)

re : fclean all

clean :
	rm -f $(OBJFILES)

fclean :
	rm -f $(NAME) $(OBJFILES)

%.o : %.c
	$(CC) -c $(FLAGS) -o $@ $^

.PHONY : clean fclean re

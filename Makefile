OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o map_rendering.o
FLAGS = -Werror -Wall -Wextra -g
MAC_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long

$(NAME) : $(OBJFILES) libft.a so_long.h
	$(CC) $(FLAGS) $(MAC_FLAGS) -o $(NAME) $(OBJFILES) libft.a lib/libmlx42.a

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

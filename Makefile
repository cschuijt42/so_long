OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o map_rendering.o \
						sprites_parsing.o map_rendering_passes.o category_pass_helpers.o \
						category_pass_updaters.o wall_pass_helpers.o wall_sprite_functions.o \
						wall_sprite_functions_part_two.o wall_edge_sprite_functions.o \
						bitmask_helpers.o sprite_management.o render_helpers.o lava_pass.o
FLAGS = -Werror -Wall -Wextra -g
MAC_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LINUX_FLAGS = -ldl -lglfw -pthread -lm
NAME = so_long

$(NAME) : $(OBJFILES) libft.a so_long.h
	$(CC) $(FLAGS) $(MAC_FLAGS) -o $(NAME) $(OBJFILES) libft.a lib/libmlx42.a

all : $(NAME)

$(NAME)_linux : $(OBJFILES) libft.a so_long.h
	$(CC) $(FLAGS) -o $(NAME)_linux $(OBJFILES) libft.a lib/linux/libmlx42.a $(LINUX_FLAGS)

linux : $(NAME)_linux

re : fclean all

clean :
	rm -f $(OBJFILES) libft.a

fclean :
	rm -f $(NAME) $(NAME)_linux $(OBJFILES) libft.a
	make -C libft fclean

libft.a : libft/libft.a
	cp libft/libft.a libft.a

libft/libft.a :
	make -C libft

%.o : %.c 
	$(CC) -c $(FLAGS) -o $@ $^

.PHONY : clean fclean re

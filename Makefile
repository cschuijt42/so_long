OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o map_rendering.o \
						sprites_parsing.o map_rendering_passes.o category_pass_helpers.o \
						category_pass_updaters.o wall_pass_helpers.o wall_sprite_functions.o \
						wall_sprite_functions_part_two.o wall_edge_sprite_functions.o \
						bitmask_helpers.o sprite_management.o render_helpers.o lava_pass.o
FLAGS = -Werror -Wall -Wextra -g -I lib
MAC_FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LINUX_FLAGS = -ldl -lglfw -pthread -lm
LIBFT_A = lib/libft/libft.a
MLX42_A = lib/mlx42/libmlx42.a
NAME = so_long

$(NAME) : $(OBJFILES) $(LIBFT_A) $(MLX42_A) so_long.h
	$(CC) $(FLAGS) $(MAC_FLAGS) -o $(NAME) $(OBJFILES) $(LIBFT_A) $(MLX42_A)

all : $(NAME)

$(NAME)_linux : $(OBJFILES) $(LIBFT_A) $(MLX42_A) so_long.h
	$(CC) $(FLAGS) -o $(NAME)_linux $(OBJFILES) $(LIBFT_A) $(MLX42_A) $(LINUX_FLAGS)

linux : $(NAME)_linux

re : fclean all

clean :
	rm -f $(OBJFILES) libft.a

fclean :
	rm -f $(NAME) $(NAME)_linux $(OBJFILES)
	make -C lib/libft fclean
	make -C lib/mlx42 fclean

$(LIBFT_A) :
	make -C lib/libft

$(MLX42_A) :
	make -C lib/mlx42

%.o : %.c 
	$(CC) -c $(FLAGS) -o $@ $^

.PHONY : clean fclean re

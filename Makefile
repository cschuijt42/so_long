OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o map_rendering.o \
						sprites_parsing.o map_rendering_passes.o category_pass_helpers.o \
						category_pass_updaters.o wall_pass_helpers.o wall_sprite_functions.o \
						wall_sprite_functions_part_two.o wall_edge_sprite_functions.o \
						bitmask_helpers.o sprite_management.o render_helpers.o lava_pass.o \
						floor_pass.o floor_tile_helpers.o exit_pass.o collectible_helpers.o \
						shadow_pass.o shadow_sprite_helpers.o shadow_sprites_part_two.o \
						player_rendering.o animations.o movement.o key_hook.o \
						gameplay_checks.o north_walls.o
VPATH     = obj
FLAGS    := -Werror -Wall -Wextra -g -I lib
LIBFT_A  := lib/libft/libft.a
MLX42_A  := lib/mlx42/libmlx42.a
NAME     := so_long

ifeq ($(OS), Windows_NT)
	FW_FLAGS := -lglfw3 -lopengl32 -lgdi32
	CC = gcc
	NAME := so_long.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		FW_FLAGS := -ldl -lglfw -pthread -lm
	else ifeq ($(UNAME_S), Darwin)
		FW_FLAGS := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -fsanitize=address
	else
		$(error OS: $(OS) - Is not supported!)
	endif
endif

$(NAME) : $(LIBFT_A) $(MLX42_A) $(OBJFILES) so_long.h
ifeq ($(OS), Windows_NT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES) $(LIBFT_A) $(MLX42_A) $(FW_FLAGS)
else
	@mkdir -p obj
	$(CC) $(FLAGS) -o $(NAME) obj/*.o $(LIBFT_A) $(MLX42_A) $(FW_FLAGS)
endif

all : $(NAME)

re : fclean all

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME)
	make -C lib/libft fclean
	make -C lib/mlx42 fclean

$(LIBFT_A) :
	make -C lib/libft

$(MLX42_A) :
	make -C lib/mlx42

%.o : %.c
ifeq ($(OS), Windows_NT)
	$(CC) -c $(FLAGS) -o $@ $^
else
	@mkdir -p obj
	$(CC) -c $(FLAGS) -o obj/$@ $^
endif

.PHONY : clean fclean re

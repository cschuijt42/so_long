OBJFILES := free_functions.o helpers.o main.o map_parser.o map_solvability.o \
						map_struct_functions.o map_validations.o map_rendering.o \
						sprites_parsing.o map_rendering_passes.o category_pass_helpers.o \
						category_pass_updaters.o wall_pass_helpers.o wall_sprite_functions.o \
						wall_sprite_functions_part_two.o wall_edge_sprite_functions.o \
						bitmask_helpers.o sprite_management.o render_helpers.o lava_pass.o \
						floor_pass.o floor_tile_helpers.o exit_pass.o collectible_helpers.o \
						shadow_pass.o shadow_sprite_helpers.o shadow_sprites_part_two.o \
						player_rendering.o animations.o movement_keys.o key_hook.o \
						gameplay_checks.o north_walls.o movement.o map_name.o map_fitting.o \
						gui.o text_rendering.o map_content_validation.o patrols.o \
						map_struct_helpers.o patrol_rendering.o patrol_movement.o \
						patrol_movement_helpers.o map_struct_freeing_functions.o \
						patrol_validation.o collectible_rendering.o game_end.o
FLAGS    := -Werror -Wall -Wextra -g -I lib
LIBFT_A  := lib/libft/libft.a
NAME     := so_long

ifeq ($(OS), Windows_NT)
	FW_FLAGS := -lglfw3 -lopengl32 -lgdi32
	CC = gcc
	NAME := so_long.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		FW_FLAGS := -lmlx42 -lglfw
	else ifeq ($(UNAME_S), Darwin)
		FW_FLAGS := -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
	else
		$(error OS: $(OS) - Is not supported!)
	endif
endif

$(NAME) : $(OBJFILES) $(LIBFT_A) so_long.h
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES) $(LIBFT_A) $(FW_FLAGS)

all : $(NAME)

re : fclean all

clean :
	rm -f $(OBJFILES) libft.a

fclean :
	rm -f $(NAME) $(OBJFILES)

$(LIBFT_A) :
	make -C lib/libft

%.o : %.c so_long.h
	$(CC) -c $(FLAGS) -o $@ $<

.PHONY : clean fclean re

NAME = cub3D

INC =	cub3d.h \
		cub3d_game.h \
		cub3d_world.h

SRCS =	cub_check.c \
		cub_check_path.c \
		cub_draw.c \
		cub_error.c \
		cub_get_line.c \
		cub_import_settings.c \
		cub_init.c \
		cub_init_player.c \
		cub_mlx_keyhook.c \
		cub_load_objects.c \
		cub_load_xpm.c \
		cub_minimap.c \
		cub_minimap_player.c \
		cub_player_look.c \
		cub_player_move.c \
		cub_player_move_bonus.c \
		cub_print_info.c \
		cub_quit.c \
		cub_ray_floor.c \
		cub_ray_sprites.c \
		cub_ray_sprites_sort.c \
		cub_ray_texture.c \
		cub_raycasting.c \
		cub_read_map.c \
		cub_settings.c \
		cub_settings_utils.c \
		cub_utils.c \
		cub_utils_colors.c \
		test.c

CC = clang

MLX = libmlx.a

LIBFT = libft.a

CFLAGS = -Wall -Werror -Wextra -g

LIB = -lmlx -lXext -lX11 -lm -lbsd

MEM = -fsanitize=address

OBJDIR = objs

SRCDIR = src

INCDIR = inc

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

NORM = $(addprefix ${SRCDIR}/,${SRCS})
NORM2 = $(addprefix ${INCDIR}/,${INC})

all : ${NAME}

mlx :
		@echo -n "Compiling minilibx"
		@make -s -Cmlx_linux > /dev/null 2>&1
		@echo "\033[32m\t\t\t[OK]\033[0m"
		@echo -n "Copy libmlx.a to working directory"
		@cp mlx_linux/libmlx_Linux.a libmlx.a
		@echo "\033[32m\t[OK]\033[0m"

libft :
		@echo -n "Compiling libft"
		@make -s -Clibft
		@echo "\033[32m\t\t\t\t[OK]\033[0m"
		@echo -n "Copy libft.a to working directory"
		@cp libft/libft.a libft.a
		@echo "\033[32m\t[OK]\033[0m"

$(NAME) : mlx libft ${OBJS}
		@echo -n  "Generating ${NAME}"
		@${CC} ${OBJS} -I./inc ${CFLAGS} ${MEM} ${MLX} ${LIBFT} ${LIB} -o ${NAME} 
		@echo "\033[32m\t\t\t[OK]\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@mkdir -p ${OBJDIR}
		@${CC} ${CFLAGS} -I./inc -c $< -o $@

norm :
		@~/.norminette/norminette.rb ${NORM}
		@~/.norminette/norminette.rb ${NORM2}

clean :	
		@echo -n "deleting mlx object files"
		@make clean -s -Cmlx_linux > /dev/null
		@echo "\033[32m\t[OK]\033[0m"
		@echo -n "deleting libft object files"
		@make clean -s -Clibft > /dev/null
		@echo "\033[32m\t[OK]\033[0m"
		@echo -n "deleting object files"
		@rm -rf ${OBJDIR} > /dev/null
		@echo "\033[32m\t\t[OK]\033[0m"

fclean : clean
		@rm -rf ${NAME} ${MLX} ${LIBFT}
		@echo "full clean\033[32m\t\t[OK]\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re, libft

NAME = cub3D

INC =	cub3d.h \
		cub3d_game.h \
		cub3d_world.h

SRCS =	cub_game.c \
		engine/cub_draw.c \
		engine/cub_keyhook.c \
		engine/cub_look.c \
		engine/cub_move.c \
		engine/cub_quit.c \
		engine/cub_raycasting.c \
		engine/cub_sprites.c \
		engine/cub_sprites_sort.c \
		engine/cub_textures.c \
		hud/cub_minimap.c \
		hud/cub_minimap_player.c \
		init/cub_init.c \
		init/cub_init_player.c \
		init/cub_init_utils.c \
		init/cub_load_objects.c \
		init/cub_load_xpm.c \
		settings/cub_check_map.c \
		settings/cub_check_path.c \
		settings/cub_error.c \
		settings/cub_import_settings.c \
		settings/cub_read_map.c \
		settings/cub_settings.c \
		utils/cub_get_line.c \
		utils/cub_save_bmp.c \
		utils/cub_utils.c \
		utils/cub_utils_colors.c

BONUS = cub_floor_bonus.c \
		cub_mouse_bonus.c

MLX = libmlx.a
LIBFT = libft.a

CC = clang
CFLAGS = -Wall -Werror -Wextra -g
LIB = -lmlx -lXext -lX11 -lm -lbsd
MEM = -fsanitize=address

OBJDIR = objs
SRCDIR = src
INCDIR = inc
BONUSDIR = bonus

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})
BONUSOBJS = $(addprefix ${OBJDIR}/,${BONUS:.c=.o})

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

$(NAME) : mlx libft ${OBJS} ${BONUSOBJS}
		@echo -n  "Generating ${NAME}"
		@${CC} ${OBJS} ${BONUSOBJS} -I./inc ${CFLAGS} ${MEM} ${MLX} ${LIBFT} ${LIB} -o ${NAME} 
		@echo "\033[32m\t\t\t[OK]\033[0m"

bonus : FBONUS = -DBONUS=1

bonus : mlx libft ${OBJS} ${BONUSOBJS}
		@echo -n  "Generating ${NAME}"
		@${CC} ${CFLAGS} ${MEM} ${OBJS} ${BONUSOBJS} -I./inc ${MLX} ${LIBFT} ${LIB} -o ${NAME} 
		@echo "\033[32m\t\t\t[OK]\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@mkdir -p ${@D}
		@${CC} ${CFLAGS} ${FBONUS} -I./inc -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c
		@${CC} ${CFLAGS} ${FBONUS} -I./inc -c $< -o $@
		
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

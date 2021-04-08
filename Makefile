NAME = cub3D

INC =	cub3d.h \
		cub3d_error.h \
		cub3d_game.h \
		cub3d_world.h

SRCS =	ft_read_map.c \
		ft_settings.c \
		ft_settings_utils.c \
		ft_init.c \
		ft_raycast.c \
		ft_set_texture.c \
		draw.c \
		ft_sort_sprites.c \
		ft_check_map.c \
		ft_check_paths.c \
		ft_init_player.c \
		ft_get_line.c \
		ft_quit.c \
		ft_keyhook.c \
		ft_move.c \
		ft_utils.c \
		ft_minimap.c \
		ft_minimap_player.c \
		ft_load_xpm.c \
		ft_load_objects.c \
		ft_set_sprites.c \
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
		@make -s -Cmlx_linux > /dev/null
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

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@mkdir -p ${OBJDIR}
		@${CC} ${CFLAGS} -I./inc -c $< -o $@

norm :
		@~/.norminette/norminette.rb ${NORM}
		@~/.norminette/norminette.rb ${NORM2}

clean :	
		@rm -rf ${OBJDIR} > /dev/null
		@echo "deleting object files\033[32m\t[OK]\033[0m"

fclean : clean
		@rm -rf ${NAME} ${MLX} ${LIBFT}
		@echo "full clean\033[32m\t\t[OK]\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re, libft

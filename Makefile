NAME =cub3D

SRCS = src/read_map.c \
	   src/test.c \
	   src/ft_setparams.c \
	   src/draw.c \
	   src/ft_parse_map.c

CC = clang

MLX = libmlx.a

LIBFT = libft.a

INC = cub3d.h

CFLAGS = -Wall -Werror -Wextra -g

LIB = -lmlx -lXext -lX11 -lm -lbsd

MEM = -fsanitize=address

OBJS = ${SRCS:.c=.o}

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
	${CC} ${CFLAGS} -I./inc -c $< -o ${<:.c=.o}

clean :	
		@rm -rf ${OBJS} > /dev/null
		@echo "deleting object files\033[32m\t[OK]\033[0m"

fclean : clean
		@rm -rf ${NAME} ${MLX} ${LIBFT}
		@echo "full clean\033[32m\t\t[OK]\033[0m"

re : fclean all

.PHONY: all, clean, fclean, re, libft

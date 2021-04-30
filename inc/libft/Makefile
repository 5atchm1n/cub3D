# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 00:09:13 by sshakya           #+#    #+#              #
#    Updated: 2021/04/30 04:07:08 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SONAME = libft.so

INCLUDE = libft.h

SRCS =	libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \

BONUS =	bonus/ft_lstadd_front.c \
		bonus/ft_lstadd_back.c \
		bonus/ft_lstclear.c \
		bonus/ft_lstdelone.c \
		bonus/ft_lstiter.c \
		bonus/ft_lstlast.c \
		bonus/ft_lstmap.c \
		bonus/ft_lstnew.c \
		bonus/ft_lstsize.c \

GNL = get_next_line/get_next_line.c \
	  get_next_line/get_next_line_utils.c \

MYFN = libft/ft_fmin.c \
	   libft/ft_fmax.c \
	   libft/ft_isspace.c \
	   libft/ft_strcmp.c \

GNLOBJS = ${GNL:.c=.o}

BONUSOBJS = ${BONUS:.c=.o}

MYFNOBJS = ${MYFN:.c=.o}

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS	= -Wall -Wextra -Werror

$(NAME) : ${OBJS} ${GNLOBJS} ${MYFNOBJS}
	ar rcs $@ $?

.c.o:
	${CC} ${CFLAGS} -I./inc/ -c $< -o ${<:.c=.o}

all : ${NAME}


bonus:	${BONUSOBJS} ${OBJS} ${MYFNOBJS}
		ar rcs ${NAME} $?

norm :
	@~/.norminette/norminette.rb ${SRCS} ${BONUS} ${GNL} ${MYFN} inc/${INCLUDE}

so :
	${CC} -fPIC -c ${CFLAGS} ${SRCS} ${BONUS} ${MYFNOBJS}
	gcc -shared -o ${SONAME} ${OBJS} ${BONUSOBJS} ${MYFNOBJS}

clean :
	${RM} ${OBJS} ${BONUSOBJS} ${GNLOBJS} ${MYFNOBJS} 

fclean : clean
	${RM} ${NAME} ${SONAME}

re : fclean all

.PHONY : all clean re fclean so norm bonus

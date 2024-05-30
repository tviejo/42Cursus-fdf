# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:53:05 by tviejo            #+#    #+#              #
#    Updated: 2024/05/30 10:39:00 by tviejo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf


SRC_DIR		=	./srcs/
    
SRC		=	ft_atoi.c ft_parse.c  ft_split.c ft_utils.c close.c\
			get_next_line.c get_next_line_utils.c color.c \
			coorconvert.c render.c key.c init_view.c main.c	

SRCS		=	${addprefix ${SRC_DIR}, ${SRC}}

OBJS		=	${SRCS:.c=.o}

CC		=	cc

CFLAGS		=	 -Wall -Wextra -Werror

RM		=	rm -f

INCLUDES	= 	-I/includes/fdf.h -I/opt/X11/include -Imlx

MLX_FLAGS	=	-Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

${NAME}:		${OBJS}
				$(CC) -lm $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

all:			${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re

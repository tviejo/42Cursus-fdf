# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:53:05 by tviejo            #+#    #+#              #
#    Updated: 2024/05/26 12:28:23 by tviejo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
    
SRC		=	ft_atoi.c ft_parse.c  ft_split.c ft_strlcpy.c \
			get_next_line.c get_next_line_utils.c \
			main.c	

OBJS		=	${SRC:.c=.o}

CC		=	cc

CFLAGS		=	 -Wall -Wextra

RM		=	rm -f

INCLUDES	=	-I/opt/X11/include -Imlx

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

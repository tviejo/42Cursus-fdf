NAME		=	fdf


SRC_DIR		=	srcs/

OBJ_DIR         =       objs/
 
SRCS		=	ft_atoi.c ft_parse.c  ft_split.c ft_utils.c close.c\
			get_next_line.c get_next_line_utils.c color.c parse_color.c\
			coorconvert.c render.c key.c init_view.c main.c	

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	cc

CFLAGS		=	 -Wall -Wextra -Werror

RM		=	rm -f

INCLUDES	= 	-I/includes/fdf.h -I/opt/X11/include -Imlx

MLX_FLAGS	=	-lm -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

all:                    ${NAME}

${NAME}:                ${OBJS}
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(MLX_FLAGS)

$(OBJS):                $(OBJ_DIR)%.o: %.c
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
			$(RM) -r $(OBJ_DIR)
			${RM} ${OBJS} ${BOBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re

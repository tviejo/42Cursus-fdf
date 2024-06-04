NAME		=	fdf


SRC_DIR		=	srcs/

OBJ_DIR         =       objs/
 
SRCS		=	Parsing/ft_atoi.c Parsing/ft_parse.c Parsing/ft_split.c Parsing/parse_color.c \
				Parsing/get_next_line.c Parsing/get_next_line_utils.c\
				Color/color.c Color/color_line.c Color/colorconvert.c \
				Coordinate/coorconvert.c Coordinate/rotate.c \
				Main/main.c Main/key.c Main/init_view.c \
				Render/render.c Render/render_line.c \
				Utils/ft_utils.c \
				Close/close.c

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	cc

CFLAGS		=	 -Wall -Wextra -Werror -g3

RM		=	rm -f

INCLUDES	= 	-I/includes/fdf.h -I/opt/X11/include -Imlx

MLX_FLAGS	=	-lm -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

all:                    ${NAME}

${NAME}:                ${OBJS}
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(MLX_FLAGS)

$(OBJS):                $(OBJ_DIR)%.o: %.c
				mkdir -p $(OBJ_DIR)
				mkdir -p objs/Parsing/
				mkdir -p objs/Color/
				mkdir -p objs/Close/
				mkdir -p objs/Coordinate/
				mkdir -p objs/Main/
				mkdir -p objs/Render/
				mkdir -p objs/Utils/
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
			$(RM) -r $(OBJ_DIR)
			${RM} ${OBJS} ${BOBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re

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


ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

all:                    ${NAME}
						@$(ECHO) All done

${NAME}:                ${OBJS}
				$(MAKE) -C ./mlx/
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(MLX_FLAGS)
				

$(OBJS):                $(OBJ_DIR)%.o: %.c
						$(ECHO) Compiling $@
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
			$(MAKE) clean -C ./mlx/
			@$(ECHO) Clean done

fclean:			clean
				${RM} ${NAME}
				@$(ECHO) Fclean done

re:				fclean all

.PHONY:			all clean fclean re
.SILENT:

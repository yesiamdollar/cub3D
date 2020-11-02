
SRCS = PRIMARY/key.c \
		PRIMARY/map.c \
		PRIMARY/player.c \
		PRIMARY/primary.c \
		PRIMARY/ray.c \
		PRIMARY/sprite.c \
		PRIMARY/wall3d.c \
		READ/read_ceilling.c \
		READ/reader.c \
		READ/reader2.c \
		READ/reader_floor.c \
		READ/reader_s.c \
		SRCS/additional.c \
		SRCS/error.c \
		SRCS/spt.c \
		SRCS/util_fun.c \
		SRCS/util_fun2.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		screenshot.c \
		main.c \

INCL = -INCLUDES/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror   

all : $(NAME)

$(NAME) : ${OBJS}
		@gcc  ${FLAGS} -I/usr/local/include ${OBJS} -o$(NAME) -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT
.c.o : ${SRCS}
		@gcc ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		@rm ${OBJS}
fclean : clean
		@rm $(NAME)
re : fclean
		make all

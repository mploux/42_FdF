# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mploux <mploux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 06:04:58 by mploux            #+#    #+#              #
#    Updated: 2016/12/15 15:15:40 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FILES = main.c\
		fdf.c\
		error.c\
		loader.c\
		input.c\
		maths/vec2.c\
		maths/vec3.c\
		maths/vec4.c\
		maths/mat4.c\
		maths/transform.c\
		maths/projection.c\
		maths/maths.c\
		graphics/renderer.c\
		graphics/vertex.c\
		graphics/mesh.c\
		graphics/triangle.c\
		graphics/color.c\
		graphics/camera.c\
		graphics/scanline.c\
		graphics/line.c\
		graphics/zbuffer.c\
		graphics/bitmap.c

REPS = 	maths\
		graphics

BIN = bin/
DIRS = $(addprefix $(BIN),$(REPS))
SRC = $(addprefix src/,$(FILES))
OBJ = $(addprefix $(BIN),$(FILES:.c=.o))

INCLUDES = -I includes/ -I libmlx/ -I libft/
LIBS = -L libmlx/ -L libft/

CFLAGS = -lmlx -lft -lm -framework OpenGl -framework AppKit
FLAGS = -Wall -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN) $(OBJ)
	@make -C libft/
	@make -C libmlx/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBS) $(CFLAGS)

$(BIN):
	@mkdir $(BIN)
	@mkdir -p $(DIRS)

bin/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -rf $(BIN)

fclean: clean
	rm -rf $(NAME)

re: fclean all

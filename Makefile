# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 23:38:41 by ilarbi            #+#    #+#              #
#    Updated: 2018/03/05 23:38:45 by ilarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d
INC=wolf3d.h 
LIB=printf/libftprintf.a
MLX= minilibx_macos/libmlx.a
CFLAGS=-Wall -Wextra -Werror 
SRC=ft_put_px.c \
	ft_draw_line.c \
	ft_delete.c \
	ft_getout.c \
	init.c \
	gettextures.c \
	applytext.c \
	launch.c \
	raycaster.c \
	display.c \
	draw_wall.c \
	main.c 

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(GBJ)
	$(MAKE) -C minilibx_macos
	$(MAKE) -C printf
	gcc $(CFLAGS) -L ./printf -lftprintf -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -I $(INC) -o $@ -c $<

clean:
	$(RM) -f $(OBJ)
	$(MAKE) -C printf clean

fclean: clean
	$(RM) -f $(MLX) $(NAME)
	$(MAKE) -C printf fclean

re: fclean all
.PHONY: all clean fclean re

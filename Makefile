# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makelfile                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 13:53:45 by nneronin          #+#    #+#              #
#    Updated: 2020/02/21 19:04:24 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = ./main.c\
	   ./read_file.c\
	   ./matrix.c\
	   ./rotation_matrix.c\
	   ./ft_atoi_base.c\
	   ./info.c\
	   ./key.c\
	   ./draw.c\
	   ./mouse.c\
	   ./malloc.c\
	   ./rgb.c\
	   ./image_to_window.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		make -C ./libft/	
		gcc -o $(NAME) $(SRCS) $(INCLUDES) -lmlx -framework OpenGL -framework AppKit

clean:
		/bin/rm -f $(OBJS)
		make -C ./libft/ clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all

.PHONY: clean, all, re, fclean

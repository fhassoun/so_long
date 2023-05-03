# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 09:45:00 by fhassoun          #+#    #+#              #
#    Updated: 2023/05/03 10:40:43 by fhassoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = 	main.c 					\
			images.c				\
			maps.c					\
			map_checker.c			\
			map_utils.c				\
			path_checker.c			\
			load_map.c

LIBFT_PATH = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_PATH)/lib$(LIBFT_NAME).a

MLX_PATH = ./MLX42/build
MLX_NAME = mlx42
MLX = $(MLX_PATH)/lib$(MLX_NAME).a

CC = cc
CFLAGS = -Wall -Wextra -Werror
#LDFLAGS for linux
#LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread
#LDFLAGS for MacOS
#LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

ifeq ($(shell uname), Linux)
	LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread
else
	LDFLAGS = -L$(LIBFT_PATH) -l$(LIBFT_NAME) -L$(MLX_PATH) -l$(MLX_NAME) -lglfw -ldl -lm -pthread -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
endif

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFT) $(MLX)

$(LIBFT): $(LIBFT_PATH)/*.c
	make -C $(LIBFT_PATH)

$(MLX): $(MLX_PATH)/Makefile
	make -C $(MLX_PATH)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all clean

.PHONY: all clean fclean re
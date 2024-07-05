# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:27:08 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/05 13:11:24 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SOURCE	=	mlx_init.c
LIBFT_DIR	=	libft
LIBMLX	=	./MLX42

OBJECTS	=	$(SOURCE:.c=.o)
LIBFT	=	$(LIBFT_DIR)/libft.a

CC		=	cc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror
MLX_FLAGS := -L./MLX42/build -lmlx42 -I../MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT_DIR)

all:		$(NAME)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME):	mlx $(OBJECTS) $(LIBFT)
			@$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $@ $(LIBFT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re mlx

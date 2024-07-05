# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:27:08 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/05 14:20:49 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SOURCE			=	mlx_init.c
LIBMLX_DIR		=	./MLX42
LIBFT_DIR		=	libft
PRINTF_DIR		=	ft_printf
GNL_DIR			=	get_next_line

OBJECTS			=	$(SOURCE:.c=.o)
LIBFT			=	$(LIBFT_DIR)/libft.a
PRINTF			=	$(PRINTF_DIR)/ft_printf.a
GNL				=	$(GNL_DIR)/get_next_line.a

CC				=	cc

RM				=	rm -f

FLAGS			=	-Wall -Wextra -Werror
MLX_FLAGS 		:= -L./MLX42/build -lmlx42 -I../MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

HEADERS 		:= -I ./include -I $(LIBMLX_DIR)/include -I $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)

all:			$(NAME)

mlx:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

$(NAME):	mlx $(OBJECTS) $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)
			@$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $@ $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF_DIR):
	@make -C $(PRINTF_DIR)

$(GNL_DIR):
	@make -C $(GNL_DIR)

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(GNL_DIR) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@make -C $(GNL_DIR) fclean

re:				fclean all

.PHONY:			all clean fclean re mlx

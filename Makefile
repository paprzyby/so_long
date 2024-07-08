# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:27:08 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/08 14:13:27 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SOURCE			=	mlx_init.c
LIBMLX_DIR		=	./MLX42
LIBFT_DIR		=	libft
FT_PRINTF_DIR	=	./$(LIBFT_DIR)/ft_printf

OBJECTS			=	$(SOURCE:.c=.o)
LIBFT			=	$(LIBFT_DIR)/libft.a
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a

CC				=	cc

RM				=	rm -f

FLAGS			=	-Wall -Wextra -Werror
MLX_FLAGS 		:= -L./MLX42/build -lmlx42 -I../MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

HEADERS 		:= -I ./include -I $(LIBMLX_DIR)/include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

all:			$(NAME)
	@echo ""
	@echo "$(NAME) built successfully!"
	@echo ""

mlx:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

$(NAME):	mlx $(OBJECTS) $(LIBFT) $(FT_PRINTF)
			@$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $@ $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF): $(LIBFT)
	@make -C $(FT_PRINTF_DIR)

clean:
	@$(RM) $(OBJECTS)
	@$(RM) -rf $(LIBMLX_DIR)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean:	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@echo ""
	@echo "All files cleaned successfully!"
	@echo ""

re:				fclean all

.PHONY:			all clean fclean re mlx

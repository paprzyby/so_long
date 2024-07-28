# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 11:27:08 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/28 13:22:10 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SOURCE			=	main.c check_the_map.c print_the_moves.c \
					returns.c render_the_textures.c keys.c map_init.c

LIBMLX_DIR		=	./MLX42
LIBFT_DIR		=	libft
FT_PRINTF_DIR	=	ft_printf
GNL_DIR			=	get_next_line

OBJECTS			=	$(SOURCE:.c=.o)
LIBFT			=	$(LIBFT_DIR)/libft.a
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a
GNL				=	$(GNL_DIR)/get_next_line.a

CC				=	cc

RM				=	rm -f
RMDIR			=	rm -rf

FLAGS			=	-Wall -Wextra -Werror
MLX_FLAGS		:=	-L./MLX42/build -lmlx42 -I./MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

HEADERS			:=	-I ./include -I $(LIBMLX_DIR)/include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(GNL_DIR)

MLX_REPO		=	https://github.com/codam-coding-college/MLX42.git

all:			$(NAME)

mlx:			$(LIBMLX_DIR)/build/stamp

$(LIBMLX_DIR)/build/stamp: $(LIBMLX_DIR)
	@cd $(LIBMLX_DIR) && git pull
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
	@make -C $(LIBMLX_DIR)/build -j4
	@touch $@

$(LIBMLX_DIR):
	@if [ ! -d $(LIBMLX_DIR) ]; then \
		git clone $(MLX_REPO) $(LIBMLX_DIR); \
	fi

$(NAME):	mlx $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(GNL)
	@if [ ! -d $(NAME) ]; then \
		$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $@ $(LIBFT) $(FT_PRINTF) $(GNL); \
	fi

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):	$(LIBFT)
	@make -C $(FT_PRINTF_DIR)

$(GNL):		$(LIBFT)
	@make -C $(GNL_DIR)

clean:
	@$(RM) $(OBJECTS)
	@$(RMDIR) $(LIBMLX_DIR)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	@make -C $(GNL_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RMDIR) $(LIBMLX_DIR)
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	@make -C $(GNL_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re mlx

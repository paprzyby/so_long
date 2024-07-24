# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 13:25:30 by paprzyby          #+#    #+#              #
#    Updated: 2024/07/24 12:59:16 by paprzyby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

SOURCE			=	ft_specifier.c ft_print_char.c ft_print_str.c \
					ft_print_ptr.c ft_printf.c ft_print_num.c \
					ft_print_hexa.c ft_print_unsigned.c

OBJS			=	$(SOURCE:.c=.o)

CC				=	cc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(OBJS)
					ar rcs $(NAME) $(OBJS)

%.o:				%.c
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re

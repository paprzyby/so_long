/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:15:00 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 09:46:58 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG_H)
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct	s_lst
{
	char	**map;
	char	**map_copy;
	int		column;
	int		row;
}				t_lst;

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

bool	read_the_map(char *map, t_lst *game);
bool	free_and_close(int fd, char *line, char *lines, bool check);
bool	count_map_size(char *line, t_lst *game);
bool	check_the_map(t_lst *game);
bool	check_the_size(t_lst *game);
bool	check_the_chars(t_lst *game);
bool	check_the_walls(t_lst *game);
bool	flood_fill(t_lst *game, t_pos *position);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:15:00 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/16 12:58:17 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG_H)
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
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
	mlx_t	*mlx;
}				t_lst;

typedef struct	s_flood
{
	int	c;
	int	p;
	int e;
}				t_flood;

typedef struct	s_textures
{
	mlx_image_t	*collectible;
	mlx_image_t	*empty_space;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*wall;
}				t_textures;

void	read_the_map(char *map, t_lst *game);
void	ft_return(int fd, char *line, char *lines, bool check);
bool	count_map_size(char *line, t_lst *game);
void	check_the_map(t_lst *game);
bool	check_the_size(t_lst *game);
bool	check_the_chars(t_lst *game);
bool	check_the_walls(t_lst *game);
void	flood_init(t_lst *game);
void	flood_fill(char **map, t_lst *game, int x, int y, t_flood *flood);
void	ft_error(t_lst *game);
void	ft_flood_error(t_flood *flood, t_lst *game);
void	render_the_textures(t_lst *game);

#endif

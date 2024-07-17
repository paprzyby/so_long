/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:15:00 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/17 19:56:38 by paprzyby         ###   ########.fr       */
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
	int		position_x;
	int		position_y;
	int		c_count;
	int		p_count;
	int		e_count;
	mlx_t	*mlx;
}				t_lst;

typedef struct	s_textures
{
	mlx_texture_t	*collectible;
	mlx_texture_t	*empty_space;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
}				t_textures;

void	read_the_map(char *map, t_lst *game);
void	ft_return(int fd, char *line, char *lines, bool check);
bool	count_map_size(char *line, t_lst *game);
void	map_init(char *map, t_lst *game);
bool	check_the_chars(t_lst *game);
bool	check_the_walls(t_lst *game);
bool	check_bottom_wall(t_lst *game);
void	flood_fill(char **map, t_lst *game, int x, int y);
void	ft_error(t_lst *game);
void	ft_flood_error(t_lst *game);
void	render_the_textures(t_lst *game);
void	keys(mlx_key_data_t keydata, void *param);
void	move_up(t_lst *game);
void	move_down(t_lst *game);
void	move_left(t_lst *game);
void	move_right(t_lst *game);
mlx_image_t	*render_the_textures2(t_lst *game, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:27:48 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/16 13:43:43 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_the_textures(t_lst *game)
{
	t_textures	*textures;
	mlx_image_t		*img;
	int					x;
	int					y;

	textures = ft_calloc(1, sizeof(t_textures));
	textures->collectible = mlx_load_png("./images/collectible.png");
	textures->empty_space = mlx_load_png("./images/empty_space.png");
	textures->exit = mlx_load_png("./images/exit.png");
	textures->player = mlx_load_png("./images/player.png");
	textures-> wall = mlx_load_png("./images/wall.png");
	x = 0;
	y = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '1')
				img = textures->wall;
			else if (game->map[x][y] == '0')
				img = textures->empty_space;
			else if (game->map[x][y] == 'P')
				img = textures->player;
			else if (game->map[x][y] == 'C')
				img = textures->collectible;
			else if (game->map[y][y] == 'E')
				img = textures->exit;
			mlx_image_to_window(game->mlx, img, x * 50, y * 50);
			y++;
		}
		x++;
	}
}

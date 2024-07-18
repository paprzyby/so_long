/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:27:48 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 09:54:56 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*render_the_textures2(t_lst *game, mlx_image_t	*img, char c)
{
	if (c == '1')
		img = mlx_texture_to_image(game->mlx, game->wall);
	else if (c == '0')
		img = mlx_texture_to_image(game->mlx, game->empty_space);
	else if (c == 'P')
		img = mlx_texture_to_image(game->mlx, game->player);
	else if (c == 'C')
		img = mlx_texture_to_image(game->mlx, game->collectible);
	else
		img = mlx_texture_to_image(game->mlx, game->exit);
	return (img);
}

void	delete_the_textures(t_lst *game)
{
	mlx_delete_texture(game->wall);
	mlx_delete_texture(game->empty_space);
	mlx_delete_texture(game->player);
	mlx_delete_texture(game->collectible);
	mlx_delete_texture(game->exit);
}

mlx_image_t	*texture_to_image(t_lst *game, mlx_image_t	*img, int x, int y)
{
	if (game->map[x][y] == '1')
		img = mlx_texture_to_image(game->mlx, game->wall);
	else if (game->map[x][y] == '0')
		img = mlx_texture_to_image(game->mlx, game->empty_space);
	else if (game->map[x][y] == 'P')
		img = mlx_texture_to_image(game->mlx, game->player);
	else if (game->map[x][y] == 'C')
		img = mlx_texture_to_image(game->mlx, game->collectible);
	else
		img = mlx_texture_to_image(game->mlx, game->exit);
	return (img);
}

void	load_the_textures(t_lst *game)
{
	game->collectible = mlx_load_png("./images/collectible.png");
	game->empty_space = mlx_load_png("./images/empty_space.png");
	game->exit = mlx_load_png("./images/exit.png");
	game->player = mlx_load_png("./images/player.png");
	game->wall = mlx_load_png("./images/wall.png");
}

void	render_the_textures(t_lst *game)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	x = 0;
	load_the_textures(game);
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			img = texture_to_image(game, img, x, y);
			mlx_image_to_window(game->mlx, img, y * 50, x * 50);
			y++;
		}
		x++;
	}
	delete_the_textures(game);
}

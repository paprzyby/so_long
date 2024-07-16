/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:27:48 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/16 14:41:30 by paprzyby         ###   ########.fr       */
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
				img = mlx_texture_to_image(game->mlx, textures->wall);
			else if (game->map[x][y] == '0')
				img = mlx_texture_to_image(game->mlx, textures->empty_space);
			else if (game->map[x][y] == 'P')
				img = mlx_texture_to_image(game->mlx, textures->player);
			else if (game->map[x][y] == 'C')
				img = mlx_texture_to_image(game->mlx, textures->collectible);
			else
				img = mlx_texture_to_image(game->mlx, textures->exit);
			mlx_image_to_window(game->mlx, img, y * 50, x * 50);
			y++;
		}
		x++;
	}
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->empty_space);
	mlx_delete_texture(textures->player);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->exit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:32:25 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/17 19:08:45 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*render_the_textures2(t_lst *game, char c)
{
	t_textures	*textures;
	mlx_image_t		*img;

	textures = ft_calloc(1, sizeof(t_textures));
	textures->collectible = mlx_load_png("./images/collectible.png");
	textures->empty_space = mlx_load_png("./images/empty_space.png");
	textures->exit = mlx_load_png("./images/exit.png");
	textures->player = mlx_load_png("./images/player.png");
	textures-> wall = mlx_load_png("./images/wall.png");
	if (c == '1')
		img = mlx_texture_to_image(game->mlx, textures->wall);
	else if (c == '0')
		img = mlx_texture_to_image(game->mlx, textures->empty_space);
	else if (c == 'P')
		img = mlx_texture_to_image(game->mlx, textures->player);
	else if (c == 'C')
		img = mlx_texture_to_image(game->mlx, textures->collectible);
	else
		img = mlx_texture_to_image(game->mlx, textures->exit);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->empty_space);
	mlx_delete_texture(textures->player);
	mlx_delete_texture(textures->collectible);
	mlx_delete_texture(textures->exit);
	return (img);
}

void	move_right(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y][game->position_x + 1] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
		return ;
	}
	if (game->map[game->position_y][game->position_x + 1] != '1')
	{
		img = render_the_textures2(game, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_x = game->position_x + 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, 'P');
		mlx_image_to_window(game->mlx, img, game->position_x * 50, game->position_y * 50);
	}
}

void	move_left(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y][game->position_x - 1] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
		return ;
	}
	if (game->map[game->position_y][game->position_x - 1] != '1')
	{
		img = render_the_textures2(game, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_x = game->position_x - 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, 'P');
		mlx_image_to_window(game->mlx, img, game->position_x * 50, game->position_y * 50);
	}
}

void	move_down(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y + 1][game->position_x] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
		return ;
	}
	if (game->map[game->position_y + 1][game->position_x] != '1')
	{
		img = render_the_textures2(game, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_y = game->position_y + 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, 'P');
		mlx_image_to_window(game->mlx, img, game->position_x * 50, game->position_y * 50);
	}
}

void	move_up(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y - 1][game->position_x] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
		return ;
	}
	if (game->map[game->position_y - 1][game->position_x] != '1')
	{
		img = render_the_textures2(game, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_y = game->position_y - 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, 'P');
		mlx_image_to_window(game->mlx, img, game->position_x * 50, game->position_y * 50);
	}
}

void	keys(mlx_key_data_t keydata, void *param)
{
	t_lst	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(1);
}

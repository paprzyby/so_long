/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:32:25 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/23 19:02:04 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_lst *game)
{
	mlx_image_t	*img;

	img = NULL;
	if (game->map[game->position_y][game->position_x + 1] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
	}
	else if (game->map[game->position_y][game->position_x + 1] != '1')
	{
		img = render_the_textures2(game, img, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_x = game->position_x + 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, img, 'P');
		mlx_image_to_window(game->mlx, img,
			game->position_x * 50, game->position_y * 50);
		game->moves_count++;
		ft_printf("Current number of moves: %d\n", game->moves_count);
	}
}

void	move_left(t_lst *game)
{
	mlx_image_t	*img;

	img = NULL;
	if (game->map[game->position_y][game->position_x - 1] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
	}
	else if (game->map[game->position_y][game->position_x - 1] != '1')
	{
		img = render_the_textures2(game, img, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_x = game->position_x - 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, img, 'P');
		mlx_image_to_window(game->mlx, img,
			game->position_x * 50, game->position_y * 50);
		game->moves_count++;
		ft_printf("Current number of moves: %d\n", game->moves_count);
	}
}

void	move_down(t_lst *game)
{
	mlx_image_t	*img;

	img = NULL;
	if (game->map[game->position_y + 1][game->position_x] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
	}
	else if (game->map[game->position_y + 1][game->position_x] != '1')
	{
		img = render_the_textures2(game, img, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_y = game->position_y + 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, img, 'P');
		mlx_image_to_window(game->mlx, img,
			game->position_x * 50, game->position_y * 50);
		game->moves_count++;
		ft_printf("Current number of moves: %d\n", game->moves_count);
	}
}

void	move_up(t_lst *game)
{
	mlx_image_t	*img;

	img = NULL;
	if (game->map[game->position_y - 1][game->position_x] == 'E')
	{
		if (game->c_count == 0)
			exit(1);
	}
	else if (game->map[game->position_y - 1][game->position_x] != '1')
	{
		img = render_the_textures2(game, img, '0');
		mlx_image_to_window(game->mlx, img, game->position_x * 50,
			game->position_y * 50);
		game->position_y = game->position_y - 1;
		if (game->map[game->position_y][game->position_x] == 'C')
		{
			game->map[game->position_y][game->position_x] = '0';
			game->c_count--;
		}
		img = render_the_textures2(game, img, 'P');
		mlx_image_to_window(game->mlx, img,
			game->position_x * 50, game->position_y * 50);
		game->moves_count++;
		ft_printf("Current number of moves: %d\n", game->moves_count);
	}
}

void	keys(mlx_key_data_t keydata, void *param)
{
	t_lst	*game;

	game = param;
	load_the_textures(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		delete_the_textures(game);
		free_everything(game);
		exit(0);
	}
	delete_the_textures(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:32:25 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/28 13:22:45 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_the_textures(t_lst *game, char c)
{
	mlx_image_t	*img;

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
	mlx_image_to_window(game->mlx, img, game->position_x * 50,
		game->position_y * 50);
}

void	move_right(t_lst *game)
{
	if (game->map[game->position_y][game->position_x] == 'E')
		render_the_textures(game, 'E');
	else
		render_the_textures(game, '0');
	if (game->map[game->position_y][game->position_x + 1] == 'E')
	{
		if (game->c_count == 0)
		{
			print_the_moves(game);
			exit(1);
		}
	}
	game->position_x = game->position_x + 1;
	if (game->map[game->position_y][game->position_x] == 'C')
	{
		game->map[game->position_y][game->position_x] = '0';
		game->c_count--;
	}
	render_the_textures(game, 'P');
	print_the_moves(game);
}

void	move_left(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y][game->position_x] == 'E')
		render_the_textures(game, 'E');
	else
		render_the_textures(game, '0');
	if (game->map[game->position_y][game->position_x - 1] == 'E')
	{
		if (game->c_count == 0)
		{
			print_the_moves(game);
			exit(1);
		}
	}
	game->position_x = game->position_x - 1;
	if (game->map[game->position_y][game->position_x] == 'C')
	{
		game->map[game->position_y][game->position_x] = '0';
		game->c_count--;
	}
	render_the_textures(game, 'P');
	print_the_moves(game);
}

void	move_down(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y][game->position_x] == 'E')
		render_the_textures(game, 'E');
	else
		render_the_textures(game, '0');
	if (game->map[game->position_y + 1][game->position_x] == 'E')
	{
		if (game->c_count == 0)
		{
			print_the_moves(game);
			exit(1);
		}
	}
	game->position_y = game->position_y + 1;
	if (game->map[game->position_y][game->position_x] == 'C')
	{
		game->map[game->position_y][game->position_x] = '0';
		game->c_count--;
	}
	render_the_textures(game, 'P');
	print_the_moves(game);
}

void	move_up(t_lst *game)
{
	mlx_image_t	*img;

	if (game->map[game->position_y][game->position_x] == 'E')
		render_the_textures(game, 'E');
	else
		render_the_textures(game, '0');
	if (game->map[game->position_y - 1][game->position_x] == 'E')
	{
		if (game->c_count == 0)
		{
			print_the_moves(game);
			exit(1);
		}
	}
	game->position_y = game->position_y - 1;
	if (game->map[game->position_y][game->position_x] == 'C')
	{
		game->map[game->position_y][game->position_x] = '0';
		game->c_count--;
	}
	render_the_textures(game, 'P');
	print_the_moves(game);
}

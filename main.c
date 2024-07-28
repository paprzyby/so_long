/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/28 13:26:20 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keys(mlx_key_data_t keydata, void *param)
{
	t_lst	*game;

	game = param;
	load_the_textures(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& game->map[game->position_y - 1][game->position_x] != '1')
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& game->map[game->position_y + 1][game->position_x] != '1')
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& game->map[game->position_y][game->position_x - 1] != '1')
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& game->map[game->position_y][game->position_x + 1] != '1')
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		delete_the_textures(game);
		free_the_maps(game);
		free(game);
		exit(0);
	}
	delete_the_textures(game);
}

void	init_t_lst(t_lst *game)
{
	game->column = 0;
	game->row = 0;
	game->position_x = 0;
	game->position_y = 0;
	game->c_count = 0;
	game->p_count = 0;
	game->e_count = 0;
	game->moves_count = 0;
}

void	check_the_extension(char *str)
{
	char	*extension;

	extension = ft_strrchr(str, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_printf("Error\nWrong file name\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_lst	*game;
	mlx_t	*mlx;

	if (ac == 2)
	{
		check_the_extension(av[1]);
		game = ft_calloc(1, sizeof(t_lst));
		init_t_lst(game);
		map_init(av[1], game);
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		mlx = mlx_init(game->column * 50, game->row * 50, "so_long", true);
		if (!mlx)
			mlx_error(game);
		game->mlx = mlx;
		render_the_map(game);
		mlx_key_hook(mlx, &keys, game);
		mlx_loop(mlx);
		mlx_terminate(game->mlx);
		free_the_maps(game);
		free(game);
		return (0);
	}
	ft_printf("Error\nInvalid number of parameters\n");
	return (1);
}

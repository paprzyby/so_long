/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/24 13:01:25 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_lst *game, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->c_count++;
	if (map[y][x] == 'P')
		game->p_count++;
	if (map[y][x] == 'E')
		game->e_count++;
	map[y][x] = '1';
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
}

void	map_init(char *map, t_lst *game)
{
	read_the_map(map, game);
	if (check_the_chars(game) == false)
		ft_error(game);
	if (check_the_walls(game) == false)
		ft_error(game);
	flood_fill(game->map_copy, game, 1, 1);
	if (game->p_count != 1 || game->e_count != 1
		|| game->c_count == 0)
		ft_error(game);
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
		render_the_textures(game);
		mlx_key_hook(mlx, &keys, game);
		mlx_loop(mlx);
		mlx_terminate(game->mlx);
		free_everything(game);
		return (0);
	}
	ft_printf("Error\nInvalid number of parameters\n");
	return (1);
}

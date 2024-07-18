/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/18 10:34:18 by paprzyby         ###   ########.fr       */
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
	if (game->p_count != 1 || game->e_count != 1)
		ft_flood_error(game);
}

int	main(int ac, char **av)
{
	t_lst	*game;
	mlx_t	*mlx;

	if (ac == 2)
	{
		game = ft_calloc(1, sizeof(t_lst));
		map_init(av[1], game);
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		mlx = mlx_init(game->column * 50, game->row * 50, "so_long", true);
		game->mlx = mlx;
		render_the_textures(game);
		mlx_key_hook(mlx, &keys, game);
		mlx_loop(mlx);
		mlx_terminate(game->mlx);
		return (0);
	}
	ft_printf("Error\nInvalid number of parameters\n");
	return (1);
}

//fix te makefile so that it will only build mlx either when types 'make re' or if the mlx library is not built
//check the memory leak
//case if the collectible is not accesible
//CC				=	cc -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
//memory leaks while \n
//at least 1 collectible
//count the moves
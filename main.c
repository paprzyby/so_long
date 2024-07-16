/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/16 13:11:07 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_lst	*game;
	mlx_t	*mlx;

	if (ac == 2)
	{
		game = ft_calloc(1, sizeof(t_lst));
		read_the_map(av[1], game);
		check_the_map(game);
		flood_init(game);
		ft_printf("Valid map\n");
		mlx = mlx_init((game->column - 1) * 50, game->row * 50, "so_long", true);
		game->mlx = mlx;
		render_the_textures(game);
		//clear the list
		mlx_loop(mlx);
		return (0);
	}
	ft_printf("Error\nInvalid number of parameters\n");
	return (1);
}

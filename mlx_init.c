/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/08 14:54:50 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	int		fd;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\nError while opening the map\n\n");
		return (1);
	}
	if (ac == 2)
	{
		mlx = mlx_init(1920, 1080, "Hello world!", true);
		mlx_loop(mlx);
		return (0);
	}
	else
	{
		ft_printf("\n%s\n\n", get_next_line(fd));
		close(fd);
		ft_printf("\nError:\nInvalid number of parameters\n\n");
		return (1);
	}
}

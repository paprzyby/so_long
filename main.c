/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/08 15:06:43 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_the_map(char *map)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\nError while opening the map\n\n");
		return ;
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_printf("\n%s\n\n", line);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;

	if (ac == 2)
	{
		read_the_map(av[1]);
		mlx = mlx_init(1920, 1080, "Hello world!", true);
		mlx_loop(mlx);
		return (0);
	}
	ft_printf("\nError:\nInvalid number of parameters\n\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/09 09:47:12 by paprzyby         ###   ########.fr       */
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
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		read_the_map(av[1]);
		return (0);
	}
	ft_printf("\nError:\nInvalid number of parameters\n\n");
	return (1);
}

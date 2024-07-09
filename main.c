/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/09 15:23:59 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_the_map(char *map)
{
	char	*line;
	char	*first_line;
	int		fd;
	int		width;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Problem when opening the map\n");
		return ;
	}
	first_line = get_next_line(fd);
	line = get_next_line(fd);
	if (!line && !first_line)
	{
		ft_printf("Error: Invalid map\n");
		close(fd);
		return ;
	}
	width = ft_strlen(first_line);
	while (line)
	{
		ft_printf("%s\n", line);
		ft_printf("%d\n", width);
		if (width != ft_strlen(line))
		{
			ft_printf("Error: Invalid map\n");
			close(fd);
			return ;
		}
		line = get_next_line(fd);
	}
	ft_printf("The map is valid\n");
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		read_the_map(av[1]);
		return (0);
	}
	ft_printf("Error: Invalid number of parameters\n");
	return (1);
}

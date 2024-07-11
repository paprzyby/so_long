/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/11 15:25:48 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_the_map(char *map)
{
	char	*lines;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	lines = ft_calloc(1 , 1);
	while (line)
	{
		lines = ft_strjoin(lines, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (lines);
}

bool	check_the_map(char *map, t_lst *game)
{
	char	*lines;

	lines = read_the_map(map);
	game->map = lines;
	free(lines);
	ft_printf("%s\n", game->map);
	return (true);
}

int	main(int ac, char **av)
{
	t_lst	*game;

	if (ac == 2)
	{
		game = calloc(1, sizeof(t_lst));
		if (check_the_map(av[1], game) == false)
			ft_printf("Error: Invalid map\n");
		else
			ft_printf("Valid map\n");
		return (0);
	}
	ft_printf("Error: Invalid number of parameters\n");
	return (1);
}

//things to check in the map:
//size
//charachters
//number of exits itp.
//walls around the map
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/11 16:46:46 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	count_map_size(char *line, t_lst *game)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0 || line[0] == '\n')
		return (false);
	game->width = len;
	game->height++;
	return (true);
}

bool	read_the_map(char *map, t_lst *game)
{
	char	*lines;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
	{
		free(line);
		close(fd);
		return (false);
	}
	lines = ft_calloc(1 , 1);
	while (line)
	{
		lines = ft_strjoin(lines, line);
		if (count_map_size(line, game) == false)
			return (false);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_split(lines, '\n');
	game->map_copy = ft_split(lines, '\n');
	ft_printf("%s\n", lines);
	free(line);
	free(lines);
	return (true);
}

int	main(int ac, char **av)
{
	t_lst	*game;

	if (ac == 2)
	{
		game = calloc(1, sizeof(t_lst));
		if (read_the_map(av[1], game) == false)
			ft_printf("Error: Invalid map\n");
		if (check_the_map(game))
			ft_printf("Error: Invalid map\n");
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
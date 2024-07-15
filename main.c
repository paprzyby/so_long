/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:26:17 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 09:46:47 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	flood_fill(t_lst *game, t_pos *position)
{
	return (true);
}

bool	count_map_size(char *line, t_lst *game)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0 || line[0] == '\n')
		return (false);
	game->column = len;
	game->row++;
	return (true);
}

bool	free_and_close(int fd, char *line, char *lines, bool check)
{
	if (check == true)
	{
		free(line);
		free(lines);
		close(fd);
		return (true);
	}
	else if (!lines)
	{
		free(line);
		close(fd);
		return (false);
	}
	else
		free(line);
		free(lines);
		close(fd);
		return (false);
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
		return (free_and_close(fd, line, lines, false));
	lines = ft_calloc(1 , 1);
	while (line)
	{
		lines = ft_strjoin(lines, line);
		if (count_map_size(line, game) == false)
			return (free_and_close(fd, line, lines, false));
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(lines, '\n');
	game->map_copy = ft_split(lines, '\n');
	return (!free_and_close(fd, line, lines, true));
}

int	main(int ac, char **av)
{
	t_lst	*game;
	t_pos	*position;

	if (ac == 2)
	{
		game = calloc(1, sizeof(t_lst));
		if (read_the_map(av[1], game) == false)
			ft_printf("Error: Invalid map\n");
		if (check_the_map(game) == false)
			ft_printf("Error: Invalid map\n");
		if (flood_fill(game, position) == false)
			ft_printf("Error: Flood fill error\n");
		else
			ft_printf("Valid map\n");
		return (0);
	}
	ft_printf("Error: Invalid number of parameters\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:46:36 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/19 14:57:47 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_bottom_wall(t_lst *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i == 0 && game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	check_the_walls(t_lst *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->column - 1] != '1')
			return (false);
		if (check_bottom_wall(game) == false)
			return (false);
		if (i == game->row - 1)
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					return (false);
				j++;
			}
		}
		i++;
	}
	return (true);
}

bool	check_the_chars(t_lst *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->position_x = j;
				game->position_y = i;
			}
			else if (game->map[i][j] != '1' && game->map[i][j] != '0'
						&& game->map[i][j] != 'C' && game->map[i][j] != 'E')
				return (false);
			j++;
		}
		i++;
	}
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

void	read_the_map(char *map, t_lst *game)
{
	char	*lines;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(game);
	line = get_next_line(fd);
	lines = ft_calloc(1, 1);
	if (!line || line[0] == '\n')
		ft_return(fd, line, lines, false);
	while (line)
	{
		lines = ft_strjoin(lines, line);
		if (count_map_size(line, game) == false)
			ft_return(fd, line, lines, false);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(lines, '\n');
	game->map_copy = ft_split(lines, '\n');
	ft_return(fd, line, lines, true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:35:46 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 11:55:11 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_return(fd, line, lines, false);
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		ft_return(fd, line, lines, false);
	lines = ft_calloc(1 , 1);
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

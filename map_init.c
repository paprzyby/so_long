/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:17:41 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/28 13:20:09 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_lst *game, int x, int y)
{
	if (x < 0 || y < 0 || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->c_count++;
	if (map[y][x] == 'P')
		game->p_count++;
	if (map[y][x] == 'E')
		game->e_count++;
	map[y][x] = '1';
	flood_fill(map, game, x, y - 1);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x + 1, y);
}

bool	check_map_size(char *line, t_lst *game, int first)
{
	int		len;

	len = ft_strlen(line);
	if (len == 0 || line[0] == '\n')
		return (false);
	if (line[len - 1] == '\n')
		len--;
	if (len != first)
		return (false);
	game->column = len;
	game->row++;
	return (true);
}

int	file_descriptor_init(char *map, t_lst *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		fd_error(game);
	return (fd);
}

void	read_the_map(char *map, t_lst *game)
{
	char	*lines;
	char	*line;
	char	*tmp;
	int		fd;
	int		first;

	fd = file_descriptor_init(map, game);
	line = get_next_line(fd);
	first = ft_strlen(line) - 1;
	lines = ft_calloc(1, 1);
	if (!line || line[0] == '\n')
		ft_error(game, fd, line, lines);
	while (line)
	{
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(tmp);
		if (check_map_size(line, game, first) == false)
			ft_error(game, fd, line, lines);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(lines, '\n');
	game->map_copy = ft_split(lines, '\n');
	ft_return(game, fd, line, lines);
}

void	map_init(char *map, t_lst *game)
{
	read_the_map(map, game);
	if (check_the_chars(game) == false)
	{
		free_the_maps(game);
		free(game);
		ft_printf("Error\nInvalid map\n");
		exit(1);
	}
	if (check_the_walls(game) == false)
	{
		free_the_maps(game);
		free(game);
		ft_printf("Error\nInvalid map\n");
		exit(1);
	}
	flood_fill(game->map_copy, game, 1, 1);
	if (game->p_count != 1 || game->e_count != 1
		|| game->c_count == 0)
	{
		free_the_maps(game);
		free(game);
		ft_printf("Error\nInvalid map\n");
		exit(1);
	}
}

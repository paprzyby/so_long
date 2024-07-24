/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/24 14:37:47 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_return(t_lst *game, int fd, char *line, char *lines)
{
	if (!game->map[1])
	{
		if (lines)
			free(lines);
		if (line)
			free(line);
		free_the_maps(game);
		free(game);
		ft_printf("Error\nInvalid map\n");
		exit(1);
	}
	if (lines)
		free(lines);
	if (line)
		free(line);
	close(fd);
}

void	ft_error(t_lst *game, int fd, char *line, char *lines)
{
	if (lines)
		free(lines);
	if (line)
		free(line);
	close(fd);
	if (game->map)
		free_the_maps(game);
	free(game);
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	mlx_error(t_lst *game)
{
	free_the_maps(game);
	free(game);
	ft_printf("Error\nwhile initialing the MiniLibX library\n");
	exit(1);
}

void	free_the_maps(t_lst *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	i = 0;
	while (game->map_copy[i])
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
}

void	fd_error(t_lst *game)
{
	free(game);
	ft_printf("Error\nwith the file descriptor\n");
	exit(1);
}

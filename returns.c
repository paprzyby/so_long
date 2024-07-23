/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/23 19:04:38 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_return(t_lst *game, int fd, char *line, char *lines, bool check)
{
	if (check == true)
	{
		free(line);
		free(lines);
		close(fd);
		return ;
	}
	if (lines)
		free(lines);
	free(line);
	free_everything(game);
	close(fd);
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	ft_error(t_lst *game)
{
	free_everything(game);
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	mlx_error(t_lst *game)
{
	free_everything(game);
	ft_printf("Error\nwhile initialing the MiniLibX library\n");
	exit(1);
}

void	free_everything(t_lst *game)
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
	free(game);
}

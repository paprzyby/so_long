/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:46:36 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/28 13:17:12 by paprzyby         ###   ########.fr       */
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

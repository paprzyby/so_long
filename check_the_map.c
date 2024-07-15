/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:46:36 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 08:31:01 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (game->map[i][j] == '1')
				j++;
			else if (game->map[i][j] == '0')
				j++;
			else if (game->map[i][j] == 'P')
				j++;
			else if (game->map[i][j] == 'C')
				j++;
			else if (game->map[i][j] == 'E')
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_the_size(t_lst *game)
{
	int	row;
	int	len1;
	int	len2;

	row = 0;
	len1 = 0;
	len2 = ft_strlen(game->map[row]);
	while (game->map[row])
	{
		row++;
		if (!game->map[row])
			return (true);
		len1 = ft_strlen(game->map[row]);
		if (len1 != len2)
			return (false);
	}
	return (true);
}

bool	check_the_map(t_lst *game)
{
	if (check_the_size(game) == false)
		return (false);
	if (check_the_chars(game) == false)
		return (false);
	return (true);
}
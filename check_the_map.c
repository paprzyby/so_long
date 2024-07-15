/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:46:36 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 08:02:45 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_the_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				return (true);
			}
			else if (map[i][j] == '0')
			{
				return (true);
			}
			else
				return (false);
			j++;
		}
		i++;
	}
	return (false);
}

bool	check_the_size(char **map)
{
	int	height;
	int	len1;
	int	len2;

	height = 0;
	len1 = 0;
	len2 = ft_strlen(map[height]);
	while (map[height])
	{
		height++;
		if (!map[height])
			return (true);
		len1 = ft_strlen(map[height]);
		if (len1 != len2)
			return (false);
	}
	return (true);
}

bool	check_the_map(char **map)
{
	if (check_the_size(map) == false)
		return (false);
	if (check_the_chars(map) == false)
		return (false);
	return (true);
}
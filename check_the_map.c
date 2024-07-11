/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:46:36 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/11 17:48:18 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_the_map(char **map)
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
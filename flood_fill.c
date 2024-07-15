/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:56 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 11:30:23 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_lst *game, int x, int y, t_flood *flood)
{
	if (x < 0 || y < 0 || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		flood->c++;
	if (map[y][x] == 'P')
		flood->p++;
	if (map[y][x] == 'E')
		flood->e++;
	map[y][x] = '1';
	flood_fill(map, game, x, y - 1, flood);
	flood_fill(map, game, x, y + 1, flood);
	flood_fill(map, game, x - 1, y, flood);
	flood_fill(map, game, x + 1, y, flood);
}

bool	flood_init(t_lst *game)
{
	t_flood	*flood;

	flood = ft_calloc(1, sizeof(t_flood));
	flood_fill(game->map_copy, game, 1, 1, flood);
	if (flood->p != 1 || flood->e != 1)
		return (free(flood), false);
	return (free(flood), true);
}

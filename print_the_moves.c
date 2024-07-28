/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_the_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:20:42 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/28 13:20:44 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_the_moves(t_lst *game)
{
	game->moves_count++;
	ft_printf("Current number of moves: %d\n", game->moves_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/19 18:55:27 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_return(int fd, char *line, char *lines, bool check)
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
	close(fd);
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	ft_error(t_lst *game)
{
	ft_printf("Error\nInvalid map\n");
	free(game);
	exit(1);
}

void	mlx_error(t_lst *game)
{
	ft_printf("Error\nwhile initialing the MiniLibX library\n");
	free(game);
	exit(1);
}

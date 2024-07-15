/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:03 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 12:12:58 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_return(int fd, char *line, char *lines, bool check)
{
	if (fd == -1)
	{
		ft_printf("Error\nFailed, while opening the file\n");
		exit(1);
	}
	if (check == true)
	{
		free(line);
		free(lines);
		close(fd);
		return ;
	}
	if (lines)
		free(line);
	free(line);
	close(fd);
	ft_printf("Error\nInvalid map\n");
	exit(1);
}

void	ft_error(t_lst *game)
{
	ft_printf("Error\nInvalid map\n");
	free(game);
	//clear the list
	exit(1);
}

void	ft_flood_error(t_flood *flood, t_lst *game)
{
	ft_printf("Error\nInvalid map\n");
	free(game);
	free(flood);
	//clear the list
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:41 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/16 13:06:50 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_the_textures(mlx_t *mlx)
{
	t_textures	*textures;

	textures = ft_calloc(1, sizeof(t_textures));
	textures->collectible = mlx_load_png("./images/collectible.png");
	textures->empty_space = mlx_load_png("./images/empty_space.png");
	textures->exit = mlx_load_png("./images/exit.png");
	textures->player = mlx_load_png("./images/player.png");
	textures-> wall = mlx_load_png("./images/wall.png");
}

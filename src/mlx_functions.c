/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:41:00 by albegar2          #+#    #+#             */
/*   Updated: 2025/09/15 16:41:59 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	call_minilibx(t_game *game)
{
	int	w;
	int	h;

	w = game->columns * TILE_SIZE;
	h = game->rows * TILE_SIZE;
	game->mlx = mlx_init(w, h, "solongcito", false);
	if (!game->mlx)
		return (-1);
	if (load_images(game) == -1)
		return (-1);
	if (load_textures(game) == -1)
		return (-1);
	return (0);
}

void	mlxerror(t_game *game)
{
	free_images(game);
	mlx_terminate(game->mlx);
	free_all(game);
}

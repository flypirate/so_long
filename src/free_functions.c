/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:58:08 by albegar2          #+#    #+#             */
/*   Updated: 2025/09/15 16:36:36 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (game->map)
	{
		if (game->map[i])
		{
			while (game->map[i])
				free(game->map[i++]);
		}
		free(game->map);
		game->map = NULL;
	}
	if (game->imgindex)
	{
		free(game->imgindex);
		game->imgindex = NULL;
	}
	free_flood(game);
	free_buffer(game);
	free(game);
}

void	free_textures(t_game *game)
{
	if (game->floor)
		mlx_delete_texture(game->floor);
	if (game->npc)
		mlx_delete_texture(game->npc);
	if (game->wall)
		mlx_delete_texture(game->wall);
	if (game->collectible)
		mlx_delete_texture(game->collectible);
	if (game->exit)
		mlx_delete_texture(game->exit);
}

void	free_images(t_game *game)
{
	int	i;

	free_textures(game);
	if (game->img_npc)
		mlx_delete_image(game->mlx, game->img_npc);
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	if (game->img_exit)
		mlx_delete_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_delete_image(game->mlx, game->img_floor);
	i = game->totalcoll - 1;
	if (game->img_collectible)
	{
		while (i >= 0)
			mlx_delete_image(game->mlx, game->img_collectible[i--]);
		mlx_delete_image(game->mlx, *game->img_collectible);
		free(game->img_collectible);
	}
}

void	free_buffer(t_game *game)
{
	int	i;

	i = 0;
	if (game->buffer)
	{
		while (i < game->rows)
		{
			free(game->buffer[i]);
			game->buffer[i] = NULL;
			i++;
		}
	}
	free(game->buffer);
}

void	free_flood(t_game *game)
{
	int	i;

	i = 0;
	if (!game->ffchecker)
		return ;
	while (i < game->rows)
		free(game->ffchecker[i++]);
	free(game->ffchecker);
}

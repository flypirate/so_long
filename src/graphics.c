/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:30:26 by albegar2          #+#    #+#             */
/*   Updated: 2025/10/29 19:36:07 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->img_floor = mlx_texture_to_image(game->mlx, game->floor);
	game->img_wall = mlx_texture_to_image(game->mlx, game->wall);
	game->img_npc = mlx_texture_to_image(game->mlx, game->npc);
	game->img_exit = mlx_texture_to_image(game->mlx, game->exit);
	if (!game->img_floor || !game->img_wall || !game->img_npc
		|| !game->img_exit)
		return (-1);
	game->img_collectible = malloc(sizeof(mlx_image_t *) * game->collectibles);
	if (!game->img_collectible)
		return (-1);
	while (i < game->collectibles)
	{
		game->img_collectible[i] = mlx_texture_to_image(game->mlx,
				game->collectible);
		i++;
	}
	return (0);
}

int	load_images(t_game *game)
{
	int	i;

	i = 0;
	game->floor = mlx_load_png("textures/png/floor.png");
	game->wall = mlx_load_png("textures/png/wall.png");
	game->npc = mlx_load_png("textures/png/player.png");
	game->collectible = mlx_load_png("textures/png/collectible.png");
	game->exit = mlx_load_png("textures/png/exit.png");
	if (!game->floor || !game->wall || !game->npc || !game->exit)
		return (-1);
	return (0);
}

int	render_images(t_game *game, int x, int y, int i)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (game->map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img_wall, px, py);
	if (game->map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx, game->img_collectible[i],
			px, py);
		game->imgindex[y * game->columns + x] = i;
		i++;
	}
	if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, px, py);
	if (game->map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->img_npc, px, py);
	return (i);
}

void	render_floor(t_game *game)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			px = x * TILE_SIZE;
			py = y * TILE_SIZE;
			if (game->map[y][x])
				mlx_image_to_window(game->mlx, game->img_floor, px, py);
			x++;
		}
		y++;
	}
}

void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_W)
			move_up(game);
		if (keydata.key == MLX_KEY_S)
			move_down(game);
		if (keydata.key == MLX_KEY_A)
			move_left(game);
		if (keydata.key == MLX_KEY_D)
			move_right(game);
	}
}

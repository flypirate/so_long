/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:11:53 by albegar2          #+#    #+#             */
/*   Updated: 2025/09/13 23:22:07 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	game->player_y -= 1;
	if (check_move(game, game->player_y, game->player_x) == -1)
	{
		game->player_y += 1;
		return ;
	}
	game->img_npc->instances[0].x = game->player_x * TILE_SIZE;
	game->img_npc->instances[0].y = game->player_y * TILE_SIZE;
	game->moves = game->moves + 1;
	ft_printf("Total movements = %d\n", game->moves);
}

void	move_down(t_game *game)
{
	game->player_y += 1;
	if (check_move(game, game->player_y, game->player_x) == -1)
	{
		game->player_y -= 1;
		return ;
	}
	game->img_npc->instances[0].x = game->player_x * TILE_SIZE;
	game->img_npc->instances[0].y = game->player_y * TILE_SIZE;
	game->moves = game->moves + 1;
	ft_printf("Total movements = %d\n", game->moves);
}

void	move_left(t_game *game)
{
	game->player_x -= 1;
	if (check_move(game, game->player_y, game->player_x) == -1)
	{
		game->player_x += 1;
		return ;
	}
	game->img_npc->instances[0].x = game->player_x * TILE_SIZE;
	game->img_npc->instances[0].y = game->player_y * TILE_SIZE;
	game->moves = game->moves + 1;
	ft_printf("Total movements = %d\n", game->moves);
}

void	move_right(t_game *game)
{
	game->player_x += 1;
	if (check_move(game, game->player_y, game->player_x) == -1)
	{
		game->player_x -= 1;
		return ;
	}
	game->img_npc->instances[0].x = game->player_x * TILE_SIZE;
	game->img_npc->instances[0].y = game->player_y * TILE_SIZE;
	game->moves = game->moves + 1;
	ft_printf("Total movements = %d\n", game->moves);
}

int	check_move(t_game *game, int next_y, int next_x)
{
	int	indx;

	indx = game->imgindex[next_y * game->columns + next_x];
	if (check_cases(game, next_y, next_x) == -1)
		return (-1);
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectibles--;
		game->map[next_y][next_x] = '0';
		mlx_delete_image(game->mlx, game->img_collectible[indx]);
	}
	if (game->map[next_y][next_x] == 'E')
	{
		if (game->collectibles == 0)
			mlx_close_window(game->mlx);
		else
			return (-1);
	}
	return (0);
}

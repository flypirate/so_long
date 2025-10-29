/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:54:25 by albegar2          #+#    #+#             */
/*   Updated: 2025/09/13 21:10:34 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	prepare_ff(t_game *game)
{
	int	posy;
	int	posx;
	int	x;

	x = 0;
	player_position(game);
	posy = game->player_y;
	posx = game->player_x;
	game->ffchecker = ft_calloc(game->rows, sizeof(char *));
	if (!game->ffchecker)
		return (-1);
	while (x < game->rows)
	{
		game->ffchecker[x] = ft_strdup(game->map[x]);
		if (!game->ffchecker[x])
			return (-1);
		x++;
	}
	flood_fill(game, posy, posx);
	if (check_valid_path(game))
		return (-1);
	return (0);
}

void	flood_fill(t_game *game, int posy, int posx)
{
	if (posx >= game->columns || posy >= game->rows
		|| posx < 0 || posy < 0)
		return ;
	if (game->ffchecker[posy][posx] == 'E')
	{
		game->ffchecker[posy][posx] = 'X';
		return ;
	}
	if (game->ffchecker[posy][posx] == '1' ||
			game->ffchecker[posy][posx] == 'X')
		return ;
	game->ffchecker[posy][posx] = 'X';
	flood_fill(game, posy - 1, posx);
	flood_fill(game, posy, posx - 1);
	flood_fill(game, posy + 1, posx);
	flood_fill(game, posy, posx + 1);
}

int	check_valid_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->map[i][j] == 'E' && game->ffchecker[i][j] != 'X')
				return (1);
			if (game->map[i][j] == 'C' && game->ffchecker[i][j] != 'X')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

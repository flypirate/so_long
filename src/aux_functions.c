/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:51:33 by albegar2          #+#    #+#             */
/*   Updated: 2025/09/19 16:38:14 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cases(t_game *game, int next_y, int next_x)
{
	if (next_y >= game->rows)
		return (-1);
	if (next_x >= game->columns)
		return (-1);
	if (next_y < 0)
		return (-1);
	if (next_x < 0)
		return (-1);
	if (game->map[next_y][next_x] == '1')
		return (-1);
	else
		return (0);
}

int	copy_and_validate(t_game *game, char *buffer[])
{
	size_t	len;
	int		i;

	game->bufferlines = 0;
	if (malloc_map(game, buffer) == -1)
		return (free_all(game), -1);
	len = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->rows)
	{
		game->map[i] = ft_strdup(buffer[i]);
		if (!game->map[i])
			return (free_all(game), -1);
		if (len != ft_strlen(game->map[i]))
		{
			free_all(game);
			return (ft_printf("Error\nNot rectangular map\n"), -1);
		}
		game->bufferlines++;
		i++;
	}
	game->map[game->rows] = NULL;
	game->columns = len;
	return (0);
}

void	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	count_char(const char *line, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (line[i])
	{
		if (line[i] == c)
			result++;
		i++;
	}
	return (result);
}

int	check_char(t_game *game, int i, int j)
{
	while (j < game->columns)
	{
		if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
			&& game->map[i][j] != 'C' && game->map[i][j] != '0'
			&& game->map[i][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

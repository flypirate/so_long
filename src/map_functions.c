/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:09:49 by albegar2          #+#    #+#             */
/*   Updated: 2025/09/15 16:16:17 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i++] != '1')
			return (ft_printf("Error\nMap top wall error\n"), -1);
	}
	i = 0;
	while (map->map[map->rows - 1][i])
	{
		if (map->map[map->rows - 1][i++] != '1')
			return (ft_printf("Error\nMap low wall error\n"), -1);
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1')
			return (ft_printf("Error\nMap left wall error\n"), -1);
		if (map->map[i++][map->columns - 1] != '1')
			return (ft_printf("Error\nMap right wall error\n"), -1);
	}
	return (0);
}

int	count_rows(int mapfd, t_game *game)
{
	char	*newline;
	char	*line;

	line = get_next_line(mapfd);
	game->rows = 0;
	if (!line)
		return (ft_printf("Error\nEmpty map\n"), -1);
	while (line)
	{
		newline = ft_strrchr(line, '\n');
		if (newline)
			*newline = '\0';
		game->rows++;
		free(line);
		line = get_next_line(mapfd);
	}
	return (game->rows);
}

char	**fill_map(int mapfd, t_game *game)
{
	char	*newline;
	char	*line;
	int		rows;

	rows = 0;
	if (game->rows < 1)
		return (NULL);
	game->buffer = ft_calloc(1, sizeof(char *) * game->rows);
	if (!game->buffer)
		return (NULL);
	line = get_next_line(mapfd);
	if (!line)
		return (ft_printf("Error\nEmpty map\n"), NULL);
	while (line)
	{
		newline = ft_strrchr(line, '\n');
		if (newline)
			*newline = '\0';
		game->buffer[rows++] = ft_strdup(line);
		free(line);
		line = get_next_line(mapfd);
	}
	return (game->buffer);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	px;
	int	py;
	int	i;

	render_floor(game);
	i = 0;
	y = 0;
	game->imgindex = ft_calloc(1, game->rows * game->columns * sizeof(int));
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			px = x * TILE_SIZE;
			py = y * TILE_SIZE;
			i = render_images(game, x, y, i);
			x++;
		}
		y++;
	}
}

int	malloc_map(t_game *game, char *buffer[])
{
	int	i;

	i = 0;
	game->map = ft_calloc(1, sizeof(char *) * (game->rows + 1));
	if (!game->map)
	{
		free_all(game);
		return (-1);
	}
	game->map[i] = ft_strdup(buffer[i]);
	return (0);
}

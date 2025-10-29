/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:12:33 by albertogm         #+#    #+#             */
/*   Updated: 2025/09/15 16:52:05 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	process_map(char *filename, t_game *game)
{
	int		mapfd;

	game->buffer = NULL;
	mapfd = open(filename, O_RDONLY);
	if (mapfd < 0)
		return (-1);
	game->rows = count_rows(mapfd, game);
	close(mapfd);
	mapfd = open(filename, O_RDONLY);
	game->buffer = fill_map(mapfd, game);
	if (!game->buffer)
		return (close(mapfd), -1);
	if (copy_and_validate(game, game->buffer) == -1)
		return (close(mapfd), -2);
	if (special_chars(game, game->rows) == -1)
		return (close(mapfd), -1);
	if (check_walls(game) == -1)
		return (close(mapfd), -1);
	close(mapfd);
	return (0);
}

int	special_chars(t_game *game, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		game->player += (count_char(game->map[i], 'P'));
		game->exits += (count_char(game->map[i], 'E'));
		game->collectibles += (count_char(game->map[i], 'C'));
		if (check_char(game, i, j) == -1)
			return (ft_printf("Error\nInvalid char in map\n"), -1);
		i++;
	}
	if (game->player != 1)
		return (ft_printf("Error\nInvalid player amount\n"), -1);
	if (game->exits != 1)
		return (ft_printf("Error\nInvalid exit amount\n"), -1);
	if (game->collectibles < 1)
		return (ft_printf("Error\nInvalid collectibles amount\n"), -1);
	game->totalcoll = game->collectibles;
	return (0);
}

int	parsing(int argc, char **argv)
{
	int	filelen;
	int	file;

	if (argc != 2)
		return (ft_printf("Error\nIncorrect ARGC\n"), -1);
	filelen = ft_strlen(argv[1]);
	if (filelen < 5)
		return (ft_printf("Error\nIncorrect map file\n"), -1);
	if (ft_strncmp(argv[1] + (filelen - 4), ".ber", 4) != 0)
		return (ft_printf("Error\nNot .ber file\n"), -1);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		return (ft_printf("Error\nFile does not exist\n"), -1);
	close(file);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		read_status;

	game = ft_calloc(1, sizeof(*game));
	if (!game)
		return (free_all(game), ft_printf("Error\nFailed calloc\n"), -1);
	if (parsing(argc, argv) != 0)
		return (free_all(game), -1);
	read_status = process_map(argv[1], game);
	if (read_status == -1)
		return (free_all(game), -1);
	else if (read_status == -2)
		return (-1);
	if (prepare_ff(game) == -1)
		return (free_all(game), ft_printf("Error\nFlood fill error\n"), -1);
	if (call_minilibx(game) == -1)
		return (mlxerror(game), ft_printf("Error\nMLX error\n"), -1);
	render_map(game);
	mlx_key_hook(game->mlx, key_callback, game);
	mlx_loop(game->mlx);
	free_images(game);
	mlx_terminate(game->mlx);
	free_all(game);
	return (0);
}

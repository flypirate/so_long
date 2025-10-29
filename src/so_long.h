/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:47:49 by albertogm         #+#    #+#             */
/*   Updated: 2025/09/15 16:46:57 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**buffer;
	int				rows;
	int				columns;
	int				exits;
	int				collectibles;
	int				totalcoll;
	int				player;
	int				player_x;
	int				player_y;
	int				moves;
	int				*imgindex;
	char			**ffchecker;
	int				bufferlines;
	//	TEXTURES
	mlx_texture_t	*floor;
	mlx_texture_t	*npc;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	//	IMAGES
	mlx_image_t		*img_floor;
	mlx_image_t		*img_npc;
	mlx_image_t		*img_wall;
	mlx_image_t		**img_collectible;
	mlx_image_t		*img_exit;
}	t_game;

void		free_all(t_game *game);
void		free_images(t_game *game);
void		free_buffer(t_game *game);
void		free_textures(t_game *game);
void		free_flood(t_game *game);
int			call_minilibx(t_game *game);
int			special_chars(t_game *game, int rows);
int			count_char(const char *line, char c);
int			check_walls(t_game *map);
char		**fill_map(int mapfd, t_game *game);
int			process_map(char *filename, t_game *game);
void		render_map(t_game *game);
int			count_rows(int mapfd, t_game *game);
int			copy_and_validate(t_game *game, char *buffer[]);
void		key_callback(mlx_key_data_t keydata, void *param);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			check_move(t_game *game, int next_y, int next_x);
void		player_position(t_game *game);
void		render_floor(t_game *game);
int			load_textures(t_game *game);
int			load_images(t_game *game);
int			malloc_map(t_game *game, char *buffer[]);
int			check_cases(t_game *game, int next_y, int next_x);
int			render_images(t_game *game, int x, int y, int i);
void		flood_fill(t_game *game, int posy, int posx);
int			prepare_ff(t_game *game);
int			check_char(t_game *game, int i, int j);
void		mlxerror(t_game *game);
int			parsing(int argc, char **argv);
int			check_valid_path(t_game *game);

#endif

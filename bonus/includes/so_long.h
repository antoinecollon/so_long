/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:23:34 by acollon           #+#    #+#             */
/*   Updated: 2025/06/19 18:58:50 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include "X11/keysym.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	char	*filename;
	int		map_width;
	int		map_height;
	void	*img_wall;
	void	*img_floor;
	void	*img_play1;
	void	*img_play2;
	int		anim_state;
	void	*img_exit;
	void	*img_coin;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		move_count;
	int		total_collectible;
	int		nb_player;
	int		nb_exit;
	int		collected;
}	t_game;

typedef struct s_flood
{
	int		collected;
	int		exit_reached;
	int		player_x;
	int		player_y;
	char	**map_copy;
}	t_flood;

//PARSING
/* read_map.c */
int		read_map(int fd, t_game *game);
void	free_map(char **map);
int		count_line(int fd, t_game *game);

/* parse_map.c*/
int		validate_shape(t_game *game);
int		validate_characters(t_game *game);
int		validate_elements(t_game *game);
void	analyze_line(char *line, t_game *game);
int		validate_border(t_game *game);

/* validate_path.c */

int		validate_map(t_game *game, t_flood *flood);
int		copy_map(t_game *game, t_flood *flood);
void	find_player_pos(t_game *game, t_flood *flood);
void	flood_fill(t_flood *flood, int x, int y);
int		validate_path(t_flood *flood, t_game *game);

/* error_handler.c */
void	free_and_exit(char *msg, t_game *game);
int		file_type(t_game *game);
void	free_all(t_game *game);
void	exit_clean(char *msg, t_game *game);

// DISPLAY
/* render_map.c */
void	load_images(t_game *g);
void	render_map(t_game *g);
void	init_game(t_game *g);
void	put_tile(t_game *g, char tile, int x, int y);

/* handle_input.c */
int		handle_close(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int x, int y);
int		handle_tile_effect(t_game *game, int x, int y);
int		can_move(t_game *game, int x, int y);

// BONUS
/* display_move.c */
void	display_move(t_game *game);

#endif
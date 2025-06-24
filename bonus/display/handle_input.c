/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:58:04 by acollon           #+#    #+#             */
/*   Updated: 2025/06/24 16:22:02 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_close(t_game *game)
{
	exit_clean("Game closed\n", game);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_clean("Escaped\n", game);
	if (keycode == XK_w || keycode == XK_Up)
	{
		game->anim_state = 0;
		move_player(game, 0, -1);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		game->anim_state = 1;
		move_player(game, 0, 1);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		game->anim_state = 2;
		move_player(game, -1, 0);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		game->anim_state = 3;
		move_player(game, 1, 0);
	}
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (!can_move(game, new_x, new_y))
		return ;
	if (!handle_tile_effect(game, new_x, new_y))
		return ;
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	update_enemies(game);
	// ft_printf("Move : %d\n", game->move_count);
	render_map(game);
}

int	handle_tile_effect(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == 'C')
	{
		game->total_collectible--;
		game->map[y][x] = '0';
	}
	else if (tile == 'E')
	{
		if (game->total_collectible == 0)
			exit_clean("You Win\n", game);
	}
	else if (tile == 'T')
		exit_clean("You Lost\n", game);
	return (1);
}

int	can_move(t_game *game, int x, int y)
{
	if (y < 0 || x < 0)
		return (0);
	if (!game->map[y] ||!game->map[y][x])
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

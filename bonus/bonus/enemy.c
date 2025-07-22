/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:21:34 by acollon           #+#    #+#             */
/*   Updated: 2025/07/22 15:39:32 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemy_texture(t_game *game)
{
	int		w;
	int		h;

	game->img_enemy1 = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy1.xpm", &w, &h);
	game->img_enemy2 = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy2.xpm", &w, &h);
	if (!game->img_enemy1 || !game->img_enemy2)
		free_and_exit("Error charging sprites\n", game);
}

void	init_enemies(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'T')
			{
				ft_enemy_add_back(game, ft_enemy_new(x, y));
				game->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	draw_all_enemies(t_game *game)
{
	t_enemies	*e;

	e = game->enemies;
	while (e)
	{
		get_enemy_anim(game, e);
		e = e->next;
	}
}

void	update_enemies(t_game *game)
{
	t_enemies	*e;

	choose_direction(game);
	e = game->enemies;
	while (e)
	{
		e->next_x = e->enemy_x;
		e->next_y = e->enemy_y;
		if (e->enemy_dir == 0)
			e->next_y--;
		if (e->enemy_dir == 1)
			e->next_y++;
		if (e->enemy_dir == 2)
			e->next_x--;
		if (e->enemy_dir == 3)
			e->next_x++;
		check_colision(e, game);
		e = e->next;
	}
}

void	choose_direction(t_game *game)
{
	t_enemies	*e;

	e = game->enemies;
	while (e)
	{
		update_enemy_direction(game, e);
		e = e->next;
	}
}

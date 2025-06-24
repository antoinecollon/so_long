/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:21:34 by acollon           #+#    #+#             */
/*   Updated: 2025/06/24 16:48:52 by acollon          ###   ########.fr       */
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
	int	y, x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'T')
				ft_enemy_add_back(game, ft_enemy_new(x, y));
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
		mlx_put_image_to_window(game->mlx, game->window, game->img_enemy1,
			e->enemy_x * 32, e->enemy_y * 32);
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
	//	ft_printf("Avant déplacement : enemy (%d, %d) dir=%d\n", e->enemy_x, e->enemy_y, e->enemy_dir);
		if (e->enemy_dir == 0)
			e->enemy_y--;
		if (e->enemy_dir == 1)
			e->enemy_y++;
		if (e->enemy_dir == 2)
			e->enemy_x--;
		if (e->enemy_dir == 3)
			e->enemy_x++;
	//	ft_printf("Après déplacement : enemy (%d, %d)\n", e->enemy_x, e->enemy_y);
		if (e->enemy_x == game->player_x && e->enemy_y == game->player_y)
			exit_clean("You Lost\n", game);
		e = e->next;
	}
}

void	choose_direction(t_game *game)
{
	t_enemies	*e;
	int			dist[4];
	int			max;
	int			dir;
	int			i;
	int	total = 0;
	
	i = 0;
	max = 0;
	e = game->enemies;
	while (e)
	{
		dist[0] = get_distance(game, e->enemy_x, e->enemy_y, 0, -1);
		dist[1] = get_distance(game, e->enemy_x, e->enemy_y, 0, 1);
		dist[2] = get_distance(game, e->enemy_x, e->enemy_y, -1, 0);
		dist[3] = get_distance(game, e->enemy_x, e->enemy_y, 1, 0);
		while (i <= 3)
		{
			if (dist[i] > max)
			{
				max = dist[i];
				dir = i;
			}
			i++;
		}
		e->enemy_dir = dir;
		total++;
		e = e->next;
	}
	ft_printf("Choix direction enemy (%d,%d) : %d\n", e->enemy_x, e->enemy_y, dir);
	ft_printf("Nombre total d'ennemis traités : %d\n", total);
}

int		get_distance(t_game *game, int x, int y, int dx, int dy)
{
	int	dist;

	dist = 0;
	while (1)
	{
		y = y + dy;
		x = x + dx;
		if (x < 0 || y < 0 || y > game->map_height || x > game->map_width)
			break ;
		if (game->map[y][x] == '1')
			break ;
		if (is_enemy(game, x, y))
			break ;
		dist++;
	}
	return (dist);
}

int	is_enemy(t_game *game, int x, int y)
{
	t_enemies	*tmp;

	tmp = game->enemies;
	while (tmp)
	{
		if (tmp->enemy_x == x && tmp ->enemy_y == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:15:12 by acollon           #+#    #+#             */
/*   Updated: 2025/06/25 17:16:18 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	opposite_dir(int dir)
{
	if (dir == 0)
		return (1);
	if (dir == 1)
		return (0);
	if (dir == 2)
		return (3);
	if (dir == 3)
		return (2);
	return (-1);
}

void	compute_distances(t_game *game, t_enemies *e, int dist[4])
{
	dist[0] = get_distance(game, e, 0, -1);
	dist[1] = get_distance(game, e, 0, 1);
	dist[2] = get_distance(game, e, -1, 0);
	dist[3] = get_distance(game, e, 1, 0);
}

int	choose_best_direction(int *dist, int last_dir)
{
	int	i;
	int	max;
	int	dir;
	int	opposite;

	i = 0;
	max = -1;
	dir = last_dir;
	opposite = opposite_dir(last_dir);
	while (i < 4)
	{
		if (i != opposite && dist[i] > max)
		{
			max = dist[i];
			dir = i;
		}
		i++;
	}
	return (dir);
}

void	update_enemy_direction(t_game *game, t_enemies *e)
{
	int	dist[4];
	int	new_dir;

	compute_distances(game, e, dist);
	new_dir = choose_best_direction(dist, e->enemy_dir);
	e->last_dir = e->enemy_dir;
	e->enemy_dir = new_dir;
}

int	get_distance(t_game *game, t_enemies *e, int dx, int dy)
{
	int	dist;
	int	x;
	int	y;

	x = e->enemy_x;
	y = e->enemy_y;
	dist = 0;
	while (1)
	{
		y += dy;
		x += dx;
		if (x < 0 || y < 0 || y >= game->map_height || x >= game->map_width)
			break ;
		if (game->map[y][x] == '1')
			break ;
		if (is_enemy(game, x, y))
			break ;
		dist++;
	}
	return (dist);
}

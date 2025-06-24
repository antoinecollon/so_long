/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:21:34 by acollon           #+#    #+#             */
/*   Updated: 2025/06/23 09:59:38 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemy_texture(t_game *game, t_enemies *e)
{
	int		w;
	int		h;

	e->img_enemy1 = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy1.xpm", &w, &h);
	e->img_enemy2 = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy2.xpm", &w, &h);
	e->frame = 0;
	if (!e->img_enemy1 || !e->img_enemy2)
		free_and_exit("Error charging sprites\n", game);
}

// void	anim_enemies(t_game *g, t_enemies *e) // copie de get_anim a modifier pour liste chainee
// {
// 	if (g->anim_state == 0) // UP
// 		mlx_put_image_to_window(g->mlx, g->window, g->img_play1,
// 			g->player_x * 32, g->player_y * 32);
// 	if (g->anim_state == 1) // Down
// 		mlx_put_image_to_window(g->mlx, g->window, g->img_play2,
// 			g->player_x * 32, g->player_y * 32);
// 	if (g->anim_state == 2) //Left
// 		mlx_put_image_to_window(g->mlx, g->window, g->img_play3,
// 			g->player_x * 32, g->player_y * 32);
// 	if (g->anim_state == 3) //Right		
// 		mlx_put_image_to_window(g->mlx, g->window, g->img_play4,
// 			g->player_x * 32, g->player_y * 32);
// }

void	update_enemies(t_game *game, int x, int y)
{

}
void	choose_direction(t_game *game) // trop long modif possible ? besoin d'un autre fichier donc disision ?
{
	t_enemies	*e;
	int			dist[4];
	int			max;
	int			dir;
	int			i;

	i = 0;
	max = 0;
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
	e = e->next;	
	}
}

int		get_distance(t_game *game, int x, int y, int dx, int dy)
{
	int	dist;
	
	dist = 0;
	while (1)
	{
		y = y + dy;
		x = x + dx;
		if (x < 0 || y < 0 || y >= game->map_height || x >= game->map_width)
			break;
		if (game->map[y][x] == '1')
			break;
		if (is_ennemy(game, x, y))
			break;
		dist++;
	}
	return (dist);
}

int	is_enemy(t_game *game, int x, int y)
{
	t_enemies *tmp; 
	
	tmp = game->enemies;
	while (tmp)
	{
		if (tmp->enemy_x == x && tmp ->enemy_y == y)
			return (1);
		tmp->next;
	}
	return (0);
}
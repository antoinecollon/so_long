/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:00:26 by acollon           #+#    #+#             */
/*   Updated: 2025/06/23 10:01:53 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_anim(t_game *g)
{
	if (g->anim_state == 0)
		mlx_put_image_to_window(g->mlx, g->window, g->img_play1,
			g->player_x * 32, g->player_y * 32);
	if (g->anim_state == 1)
		mlx_put_image_to_window(g->mlx, g->window, g->img_play2,
			g->player_x * 32, g->player_y * 32);
	if (g->anim_state == 2)
		mlx_put_image_to_window(g->mlx, g->window, g->img_play3,
			g->player_x * 32, g->player_y * 32);
	if (g->anim_state == 3)
		mlx_put_image_to_window(g->mlx, g->window, g->img_play4,
			g->player_x * 32, g->player_y * 32);
}

void	get_enemy_anim(t_game *g, t_enemies *e)
{
	if (e->frame == 0)
	{
		mlx_put_image_to_window(g->mlx, g->window, g->img_enemy1,
			e->enemy_x * 32, e->enemy_y * 32);
		e->frame = 1;
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->window, g->img_enemy2,
			e->enemy_x * 32, e->enemy_y * 32);
		e->frame = 0;
	}
}

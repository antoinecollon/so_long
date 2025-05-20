/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:30:55 by acollon           #+#    #+#             */
/*   Updated: 2025/05/15 17:38:03 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->img_coin = mlx_xpm_file_to_image(g->mlx, "assets/coin.xpm", &w, &h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "assets/fruit.xpm", &w, &h);
	g->floor = mlx_xpm_file_to_image(g->mlx, "assets/floor_tile.xpm", &w, &h);
	g->img_wall = mlx_xpm_to_image(g->mlx, "assets/wall", &w, &h);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "assets/knight.xpm", &w, &h);
	if (!g->img_coin || !g->img_exit || !g->img_player
		|| !g->img_wall || !g->floor)
		free_and_exit("Error charging sprites", g);
}


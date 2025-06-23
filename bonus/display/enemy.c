/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:21:34 by acollon           #+#    #+#             */
/*   Updated: 2025/06/23 09:59:38 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_enemy_texture(t_game *game)
{
	int		w;
	int		h;

	game->enemy.img_enemy1 = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy1.xpm", &w, &h);
	game->enemy.img_enemy2 = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy2.xpm", &w, &h);
	game->enemy.frame = 0;
	if (!game->enemy.img_enemy1 || !game->enemy.img_enemy2)
		free_and_exit("Error charging sprites\n", game);
}

void	display_enemy(t_game *game,int x, int y)
{
	void	*img;

	if (game->enemy.frame == 0)
	{
		img = game->enemy.img_enemy1;
		game->enemy.frame = 1;
	}
	else if (game->enemy.frame == 1)
	{
		img = game->enemy.img_enemy2;
		game->enemy.frame = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, img, x * 32, y * 32);
}

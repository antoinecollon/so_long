/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:19:53 by acollon           #+#    #+#             */
/*   Updated: 2025/06/24 16:50:52 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->enemies)
		ft_enemy_clear(&(game->enemies));
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_entities(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	exit_clean(char *msg, t_game *game)
{
	free_all(game);
	if (msg)
		write(1, msg, ft_strlen(msg));
	exit(EXIT_SUCCESS);
}

void	free_and_exit(char *msg, t_game *game)
{
	free_all(game);
	write (2, "Error\n", 6);
	if (msg)
		write (2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	file_type(t_game *game)
{
	int	len;

	if (!game->filename)
		return (1);
	len = ft_strlen(game->filename);
	if (len <= 4)
		return (1);
	if (ft_strcmp(game->filename + (len - 4), ".ber") != 0)
		free_and_exit("Wrong type of file, need .ber\n", game);
	return (0);
}

void	free_entities(t_game *game)
{
	if (game->img_play1)
		mlx_destroy_image(game->mlx, game->img_play1);
	if (game->img_play2)
		mlx_destroy_image(game->mlx, game->img_play2);
	if (game->img_play3)
		mlx_destroy_image(game->mlx, game->img_play3);
	if (game->img_play4)
		mlx_destroy_image(game->mlx, game->img_play4);
	if (game->img_enemy1)
		mlx_destroy_image(game->mlx, game->img_enemy1);
	if (game->img_enemy2)
		mlx_destroy_image(game->mlx, game->img_enemy2);
}

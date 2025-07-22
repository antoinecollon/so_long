/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:19:53 by acollon           #+#    #+#             */
/*   Updated: 2025/07/22 19:31:09 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_game *g)
{
	if (!g)
		return ;
	if (!g->map || !g->img_coin || !g->img_exit || !g->img_player
		|| !g->img_floor || !g->img_wall || !g->window)
		return ;
	if (g->map)
		free_map(g->map);
	if (g->img_coin)
		mlx_destroy_image(g->mlx, g->img_coin);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
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

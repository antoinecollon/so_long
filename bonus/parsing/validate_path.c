/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:50:48 by acollon           #+#    #+#             */
/*   Updated: 2025/05/24 13:41:57 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(t_game *game, t_flood *flood)
{
	if (file_type(game))
		return (1);
	if (validate_shape(game))
		return (1);
	if (validate_border(game))
		return (1);
	if (validate_characters(game))
		return (1);
	if (validate_elements(game))
		return (1);
	if (validate_path(flood, game))
		return (1);
	return (0);
}

int	copy_map(t_game *game, t_flood *flood)
{
	int		i;

	i = 0;
	flood->map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!flood->map_copy)
		return (1);
	while (i < game->map_height)
	{
		flood->map_copy[i] = ft_strdup(game->map[i]);
		if (!flood->map_copy[i])
		{
			flood->map_copy[i] = NULL;
			free_map(flood->map_copy);
			return (1);
		}
		i++;
	}
	flood->map_copy[i] = NULL;
	flood->map_height = game->map_height;
	flood->map_width = game->map_width;
	return (0);
}

void	find_player_pos(t_game *game, t_flood *flood)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				flood->player_x = x;
				flood->player_y = y;
				game->player_x = x;
				game->player_y = y;
				game->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_flood *flood, int x, int y)
{
	char	tile;

	if (x < 0 || y < 0 || flood->map_height <= y || flood->map_width <= x)
		return ;
	tile = flood->map_copy[y][x];
	if (tile == 'X' || tile == '1' || tile == 'T')
		return ;
	if (tile == 'C')
		flood->collected++;
	if (tile == 'E')
		flood->exit_reached = 1;
	flood->map_copy[y][x] = 'X';
	flood_fill(flood, x - 1, y);
	flood_fill(flood, x + 1, y);
	flood_fill(flood, x, y - 1);
	flood_fill(flood, x, y + 1);
}

int	validate_path(t_flood *flood, t_game *game)
{
	if (copy_map(game, flood))
		return (1);
	find_player_pos(game, flood);
	flood->collected = 0;
	flood->exit_reached = 0;
	flood_fill(flood, flood->player_x, flood->player_y);
	if (flood->collected != game->total_collectible || flood->exit_reached == 0)
	{
		free_map(flood->map_copy);
		free_and_exit("Map not resolvable\n", game);
	}
	free_map(flood->map_copy);
	return (0);
}

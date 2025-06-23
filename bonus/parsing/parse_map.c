/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:20:05 by acollon           #+#    #+#             */
/*   Updated: 2025/05/24 13:36:37 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//à tester avec read_map.c

#include "../includes/so_long.h"

int	validate_shape(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len != game->map_width)
		{
			free_and_exit("Map is not rectangular\n", game);
			return (1);
		}
		i++;
	}
	return (0);
}

int	validate_characters(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		str = game->map[i];
		while (str[j])
		{
			if (str[j] != 'C' && str[j] != 'P' && str[j] != 'E'
				&& str[j] != '1' && str[j] != '0' && str[j] != 'T')
			{
				free_and_exit("Wrong character in map", game);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_elements(t_game *game)
{
	int	i;

	i = 0;
	game->total_collectible = 0;
	game->nb_exit = 0;
	game->nb_player = 0;
	while (game->map[i])
	{
		analyze_line(game->map[i], game);
		i++;
	}
	if (game->nb_exit != 1)
		free_and_exit("Too much or not enough exit\n", game);
	if (game->nb_player != 1)
		free_and_exit("Too much or not enough player\n", game);
	if (game->total_collectible < 1)
		free_and_exit("Map must contain collectible\n", game);
	return (0);
}

void	analyze_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'P')
			game->nb_player++;
		else if (line[j] == 'E')
			game->nb_exit++;
		else if (line[j] == 'C')
			game->total_collectible++;
		j++;
	}
}

int	validate_border(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			free_and_exit("Border of the map aren't closed\n", game);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			free_and_exit("Border of map aren't closed\n", game);
		i++;
	}
	return (0);
}

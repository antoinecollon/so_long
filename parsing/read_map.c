/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:20:17 by acollon           #+#    #+#             */
/*   Updated: 2025/05/23 16:29:14 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	game->map_height = count;
	if (count == 0)
		return (1);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free (map);
}

int	read_map(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i])
		{
			free_map(game->map);
			return (1);
		}
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	game->map_width = ft_strlen(game->map[0]);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int		i;
// 	int		fd;
// 	t_game	game;
// 	t_flood	flood;

// 	i = 0;
// 	if (ac != 2)
// 	{
// 		write (2, "Need a file to work\n", ft_strlen("Need a file to work\n"));
// 		return (0);
// 	}
// 	else
// 	{
// 		game.filename = av[1];
// 		fd = open(av[1], O_RDONLY);
// 		if (fd < 0)
// 			return (1);
// 		if (!count_line(fd, &game))
// 		{
// 			close(fd);
// 			fd = open(av[1], O_RDONLY);
// 			if (fd < 0)
// 				return (1);
// 			read_map(fd, &game);
// 		}
// 		close(fd);
// 	}
// 	if (!validate_map(&game, &flood))
// 	{
// 		while (game.map[i])
// 		{
// 			printf("%s|\n", game.map[i]);
// 			i++;
// 		}
// 		printf ("%d\n", game.map_height);
// 		printf ("%d\n", game.map_width);
// 	}
// 	free_map(game.map);
// 	return (0);
// }

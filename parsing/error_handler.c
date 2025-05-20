/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:19:53 by acollon           #+#    #+#             */
/*   Updated: 2025/05/13 13:41:31 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_and_exit(char *msg, t_game *game)
{
	if (game && game->map)
		free_map(game->map);
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

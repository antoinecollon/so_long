/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:31:48 by acollon           #+#    #+#             */
/*   Updated: 2025/06/26 12:15:27 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_move(t_game *game)
{
	char	*str;

	str = ft_itoa(game->move_count);
	if (!str)
		return ;
	mlx_string_put(game->mlx, game->window, 10, 10, 0xFFFFFF, "Moves :");
	mlx_string_put(game->mlx, game->window , 80, 10, 0xFFFFFF, str);
	free (str);
}

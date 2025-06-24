/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:55:42 by acollon           #+#    #+#             */
/*   Updated: 2025/06/23 18:01:14 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemies	*ft_enemy_new(int x, int y)
{
	t_enemies	*enemy;

	enemy = malloc(sizeof(t_enemies));
	if (!enemy)
		return (NULL);
	enemy->enemy_x = x;
	enemy->enemy_y = y;
	enemy->direction = get_direction(); // à écrire
	enemy->frame = 0;
	enemy->next = NULL;
	return (enemy);
}

void	ft_enemy_add_back(t_game *game, t_enemies *new)
{
	t_enemies	*last;

	if (!game || !new)
		return ;
	if (game->enemies == NULL)
		game->enemies = new;
	else
	{
		last = game->enemies;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	ft_enemy_clear(t_enemies **enemy)
{
	t_enemies	*tmp;

	if (!enemy || !*enemy)
		return ;
	while (*enemy)
	{
		tmp = (*enemy)->next;
		free(*enemy);
		*enemy = tmp;
	}
}

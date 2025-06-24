/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:55:42 by acollon           #+#    #+#             */
/*   Updated: 2025/06/24 16:50:09 by acollon          ###   ########.fr       */
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
	enemy->enemy_dir = 0;
	enemy->frame = 0;
	enemy->next = NULL;
	return (enemy);
}

void	ft_enemy_add_back(t_game *game, t_enemies *new)
{
	t_enemies	*tmp;

	if (!game || !new)
		return ;
	if (!game->enemies)
		game->enemies = new;
	else
	{
		tmp = game->enemies;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
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

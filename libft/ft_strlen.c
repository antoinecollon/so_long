/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:48:03 by acollon           #+#    #+#             */
/*   Updated: 2025/04/10 19:18:17 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		i = ft_strlen(&av[1][i]);
		printf("%s : taille = %d\n", av[1], i);
	}
	return (0);
}*/

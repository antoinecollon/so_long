/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:54:12 by acollon           #+#    #+#             */
/*   Updated: 2025/06/24 18:02:03 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include "includes/so_long.h"
#include <mlx.h>
#include <unistd.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	write(1, "Start test\n", 11);
	mlx = mlx_init();
	if (!mlx)
	{
		write(2, "mlx_init failed\n", 16);
		return (1);
	}
	write(1, "mlx_init OK\n", 12);

	win = mlx_new_window(mlx, 300, 300, "MLX Test");
	if (!win)
	{
		write(2, "mlx_new_window failed\n", 23);
		return (1);
	}
	write(1, "mlx_new_window OK\n", 19);

	mlx_loop(mlx);
	return (0);
}


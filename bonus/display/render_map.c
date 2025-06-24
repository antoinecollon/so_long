/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollon <acollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:30:55 by acollon           #+#    #+#             */
/*   Updated: 2025/06/19 19:06:26 by acollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *g)
{
	int		fd;
	t_flood	flood;

	fd = open(g->filename, O_RDONLY);
	if (fd < 0)
		free_and_exit("Failed to open file\n", g);
	if (count_line(fd, g))
		free_and_exit("Empy map\n", g);
	close (fd);
	fd = open(g->filename, O_RDONLY);
	if (fd < 0)
		free_and_exit("Failed to reopen file\n", g);
	if (read_map(fd, g) || validate_map(g, &flood))
		return ;
	g->mlx = mlx_init();
	if (!g->mlx)
		free_and_exit("Failed to iniate mlx\n", g);
	g->window = mlx_new_window(g->mlx, g->map_width * 32,
			g->map_height * 32, "so_long");
	if (!g->window)
		free_and_exit("Failed to create window\n", g);
	load_images(g);
	render_map(g);
}

void	load_images(t_game *g)
{
	int	w;
	int	h;

	g->img_coin = mlx_xpm_file_to_image(g->mlx, "assets/coin.xpm", &w, &h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "assets/exit.xpm", &w, &h);
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xpm", &w, &h);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "assets/wall.xpm", &w, &h);
	g->img_play1 = mlx_xpm_file_to_image(g->mlx, "assets/knight1.xpm", &w, &h);
	g->img_play2 = mlx_xpm_file_to_image(g->mlx, "assets/knight2.xpm", &w, &h);
	g->img_play3 = mlx_xpm_file_to_image(g->mlx, "assets/knight3.xpm", &w, &h);
	g->img_play4 = mlx_xpm_file_to_image(g->mlx, "assets/knight4.xpm", &w, &h);
	init_enemy_texture(g);
	g->anim_state = 0;
	if (!g->img_coin || !g->img_exit || !g->img_play1
		|| !g->img_wall || !g->img_floor || !g->img_play2)
		free_and_exit("Error charging sprites\n", g);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			put_tile(g, g->map[y][x], x * 32, y * 32);
			x++;
		}
		y++;
	}
	get_anim(g);
	display_move(g);
}

void	put_tile(t_game *g, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->window, g->img_wall, x, y);
	if (tile == '0')
		mlx_put_image_to_window(g->mlx, g->window, g->img_floor, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->window, g->img_coin, x, y);
	if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->window, g->img_exit, x, y);
	if (tile == 'T')
		mlx_put_image_to_window(g->mlx, g->window, g->enemy.img_enemy1, x, y);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
	{
		ft_putstr_fd("File .ber needed\n", 2);
		return (1);
	}
	game.filename = argv[1];
	game.move_count = 0;
	init_game(&game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_hook(game.window, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}

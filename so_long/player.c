/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:19:12 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 13:37:21 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_player(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->grass, x * 64, y * 64);
	game->g_img_t = mlx_load_png("imgs/golem.png");
	game->g_img = mlx_texture_to_image(game->mlx, game->g_img_t);
	game->g_img2_t = mlx_load_png("imgs/golem_1.png");
	game->g_img2 = mlx_texture_to_image(game->mlx, game->g_img2_t);
	game->g_img3_t = mlx_load_png("imgs/reverse_golem.png");
	game->g_img3 = mlx_texture_to_image(game->mlx, game->g_img3_t);
	game->g_img4_t = mlx_load_png("imgs/reverse_golem_1.png");
	game->g_img4 = mlx_texture_to_image(game->mlx, game->g_img4_t);
	mlx_image_to_window(game->mlx, game->g_img, x * 64, y * 64);
	mlx_image_to_window(game->mlx, game->g_img2, x * 64, y * 64);
	mlx_image_to_window(game->mlx, game->g_img3, x * 64, y * 64);
	mlx_image_to_window(game->mlx, game->g_img4, x * 64, y * 64);
	game->g_img3->instances[0].enabled = 0;
	game->g_img4->instances[0].enabled = 0;
	game->x_pos = x;
	game->y_pos = y;
	game->nb_p++;
}

int	ft_colision(t_game *game, int c)
{
	if (c == 'w')
	{
		if (game->map[game->y_pos - 1][game->x_pos] != '1')
			return (1);
	}
	if (c == 's')
	{
		if (game->map[game->y_pos + 1][game->x_pos] != '1')
			return (1);
	}
	if (c == 'a')
	{
		if (game->map[game->y_pos][game->x_pos - 1] != '1')
			return (1);
	}
	if (c == 'd')
	{
		if (game->map[game->y_pos][game->x_pos + 1] != '1')
			return (1);
	}
	return (0);
}

void	ft_exit(t_game *game)
{
	if (game->map[game->y_pos][game->x_pos] == 'E')
	{
		if (game->nb_colectible == game->c)
		{
			ft_printf("Gagné\n");
			mlx_close_window(game->mlx);
		}
	}
}

void	ft_colectible(t_game *game)
{
	int	i;

	game->d++;
	i = -1;
	if (game->map[game->y_pos][game->x_pos] == 'C')
	{
		while (++i < game->c)
		{
			if (game->croquette_grass->instances[i].x / 64 == game->x_pos
				&& game->croquette_grass->instances[i].y / 64 == game->y_pos)
			{
				game->croquette_grass->instances[i].enabled = 0;
				game->map[game->y_pos][game->x_pos] = 'c';
				game->nb_colectible += 1;
			}
		}
	}
}

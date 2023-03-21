/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:52:19 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 15:06:48 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_up(t_game *game)
{
	game->g_img->instances[0].y -= 64;
	game->g_img2->instances[0].y -= 64;
	game->g_img3->instances[0].y -= 64;
	game->g_img4->instances[0].y -= 64;
	game->y_pos -= 1;
	ft_utils(game);
}

void	ft_down(t_game *game)
{
	game->g_img->instances[0].y += 64;
	game->g_img2->instances[0].y += 64;
	game->g_img3->instances[0].y += 64;
	game->g_img4->instances[0].y += 64;
	game->y_pos += 1;
	ft_utils(game);
}

void	ft_left(t_game *game)
{
	game->g_img->instances[0].enabled = 0;
	game->g_img2->instances[0].enabled = 0;
	game->g_img3->instances[0].enabled = 1;
	game->g_img->instances[0].x -= 64;
	game->g_img2->instances[0].x -= 64;
	game->g_img3->instances[0].x -= 64;
	game->g_img4->instances[0].x -= 64;
	game->x_pos -= 1;
	ft_utils(game);
}

void	ft_right(t_game *game)
{
	game->g_img3->instances[0].enabled = 0;
	game->g_img4->instances[0].enabled = 0;
	game->g_img->instances[0].enabled = 1;
	game->g_img->instances[0].x += 64;
	game->g_img2->instances[0].x += 64;
	game->g_img3->instances[0].x += 64;
	game->g_img4->instances[0].x += 64;
	game->x_pos += 1;
	ft_utils(game);
}

void	ft_space(t_game *game)
{
	int		i;

	game->str = "/kill Axolotl_gold";
	i = 0;
	game->commande = mlx_put_string(game->mlx, game->str, 128, 0);
	game->co++;
	while (i < game->e)
	{
		game->enemy->instances[i].enabled = 0;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:43:27 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 15:46:59 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	frame2(t_game *game)
{
	if (game->frame == 40 && game->g_img2->instances[0].enabled == 1)
	{
		game->g_img2->instances[0].enabled = 0;
		game->g_img->instances[0].enabled = 1;
		game->frame = 0;
	}
	if (game->frame == 20 && game->g_img3->instances[0].enabled == 1)
	{
		game->g_img3->instances[0].enabled = 0;
		game->g_img4->instances[0].enabled = 1;
	}
	if (game->frame == 40 && game->g_img4->instances[0].enabled == 1)
	{
		game->g_img4->instances[0].enabled = 0;
		game->g_img3->instances[0].enabled = 1;
		game->frame = 0;
	}
}

void	frame(void *param)
{
	t_game	*game;

	game = param;
	if (game->frame == 20 && game->g_img->instances[0].enabled == 1)
	{
		game->g_img->instances[0].enabled = 0;
		game->g_img2->instances[0].enabled = 1;
	}
	frame2(game);
	if (game->frame == 41)
		game->frame = 0;
	game->frame++;
}

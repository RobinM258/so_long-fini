/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:16:41 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 18:01:42 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
}	t_player;

typedef struct s_game
{
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*grass;
	mlx_image_t		*golem_grass;
	mlx_image_t		*wall;
	mlx_image_t		*box;
	mlx_image_t		*enemy;
	mlx_image_t		*classement_colectible;
	mlx_image_t		*exit;
	mlx_image_t		*croquette_grass;
	mlx_image_t		*mouvement;
	mlx_image_t		*commande;
	mlx_image_t		*g_img;
	mlx_image_t		*g_img2;
	mlx_image_t		*g_img3;
	mlx_image_t		*g_img4;
	mlx_texture_t	*grass_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*croquette_grass_t;
	mlx_texture_t	*enemy_t;
	mlx_texture_t	*box_t;
	mlx_texture_t	*g_img_t;
	mlx_texture_t	*g_img2_t;
	mlx_texture_t	*g_img3_t;
	mlx_texture_t	*g_img4_t;

	char			**map;
	char			**fluid;
	char			*mov;
	char			*str;
	int				y_size;
	int				x_size;
	int				c;
	int				x_pos;
	int				y_pos;
	int				nb_colectible;
	int				e;
	int				d;
	int				nb_p;
	int				nb_e;
	int				cro;
	int				ex;
	int				co;
	int				frame;
	int				j;
	int				i;
}	t_game;

#endif
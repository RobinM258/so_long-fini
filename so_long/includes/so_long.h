/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:25:56 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 17:59:05 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "structs.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# include <memory.h>

char	*ft_itoa(int n);
void	key_hook(mlx_key_data_t keydata, void *param);
void	ft_up(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
void	ft_down(t_game *game);
void	ft_space(t_game *game);
void	ft_exit(t_game *game);
void	init_textures(t_game *game);
void	reinit_textures(t_game *game);
void	ft_deplacement(t_game *game);
void	ft_colectible(t_game *game);
void	ft_touch_enemy(t_game *game);
void	ft_utils(t_game *game);
void	ft_space(t_game *game);
void	init_map_size(t_game *game, char **av);
void	init_map_fluid(t_game *game, char **av);
void	ft_exit(t_game *game);
void	ft_colectible(t_game *game);
void	ft_deplacement(t_game *game);
void	ft_touch_enemy(t_game *game);
void	init_player(t_game *game, int y, int x);
void	frame(void *param);
int		ft_fluid_filler(t_game *game, int x, int y);
int		parsing(t_game *game);
int		map_height(char **av);
int		ft_colision(t_game *game, int c);

#endif
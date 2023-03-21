/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:42:02 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 18:04:21 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	game_0(t_game *game)
{
	game->nb_colectible = 0;
	game->d = 0;
	game->nb_p = 0;
	game->cro = 0;
	game->co = 0;
	game->ex = 0;
	game->frame = 0;
	game->y_pos = 0;
	game->x_pos = 0;
	game->i = -1;
}

void	check_map(t_game *game)
{
	if (ft_fluid_filler(game, game->x_pos, game->y_pos) == 0)
	{
		mlx_close_window(game->mlx);
		ft_printf("MAP ERROR\n");
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	(void) ac;
	if (!av[1])
	{
		ft_printf("MAP ERROR\nMAP LINK ERROR");
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game_0(game);
	init_map_size(game, av);
	game->mlx = mlx_init((game->x_size) * 64, game->y_size * 64, "MLX42", true);
	init_textures(game);
	init_map_fluid(game, av);
	mlx_loop_hook(game->mlx, &frame, game);
	if (parsing(game) == 1)
		check_map(game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

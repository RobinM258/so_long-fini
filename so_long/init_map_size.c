/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:09 by romartin          #+#    #+#             */
/*   Updated: 2023/03/21 18:03:22 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	map_height(char **av)
{
	int		fd;
	int		y;
	char	*tmp;

	y = 0;
	fd = open(av[1], O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		y++;
		free (tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (y);
}

void	init_map_size(t_game *game, char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR\n MAP LINK");
		exit(EXIT_FAILURE);
	}
	game->y_size = map_height(av);
	game->map = ft_calloc(game->y_size + 1, sizeof (char *));
	while (++game->i < game->y_size)
	{
		game->map[game->i] = get_next_line(fd);
		game->j = ft_strlen(game->map[game->i]);
		if (game->map[game->i][game->j - 1] == '\n')
			game->j--;
		if (game->i == 0)
			game->x_size = game->j;
		if (game->j != game->x_size)
		{
			ft_printf("ERROR\n MAP");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
}

void	init_map_fluid(t_game *game, char **av)
{
	int		fd;
	char	*tmp;
	int		i;	

	fd = open(av[1], O_RDONLY);
	i = 0;
	game->fluid = malloc((game->y_size + 1) * sizeof (char *));
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->fluid[i++] = tmp;
		tmp = get_next_line(fd);
	}
	game->fluid[i] = NULL;
	close(fd);
}

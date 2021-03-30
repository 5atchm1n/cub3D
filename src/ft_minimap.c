/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 21:40:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		map_grid(t_cub *game)
{
	int			k;
	int			l;
	float		offset;

	offset = game->settings.offset * MAP_SIZE;
	l = 0;
	while (l < game->settings.size_y)
	{
		k = 0;
		while (k < game->settings.res.x * MAP_SIZE)
		{
			ft_pixelput(&game->img, k, l * offset, 0x00000000);
			k++;
		}
		l++;
	}
	l = 0;
	while (l < game->settings.size_x)
	{
		k = 0;
		while (k < game->settings.size_y * offset)
		{
			ft_pixelput(&game->img, l * offset, k, 0x00000000);
			k++;
		}
		l++;
	}
}

static void		map_wall(t_cub *game, int x, int y, int colour)
{
	int			k;
	int			l;
	float		offset;

	offset = game->settings.offset * MAP_SIZE;
	k = 0;
	while (k < offset)
	{
		l = 0;
		while (l < offset)
		{
			ft_pixelput(&game->img, x * offset + k, y * offset + l, colour);
			l++;
		}
		k++;
	}
}

void			ft_draw_map(t_cub *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			if (game->map[i][j] == '0')
				map_wall(game, j, i, 0x00000000);
			if (game->map[i][j] == ' ')
				map_wall(game, j, i, 0x000000FF);
			if (game->map[i][j] == '1')
				map_wall(game, j, i, 0x00FF0000);
			if (game->map[i][j] == '2')
				map_wall(game, j, i, 0x0000FF00);
			j++;
		}
		i++;
	}
	map_grid(game);
}

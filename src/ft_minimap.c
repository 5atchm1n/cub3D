/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/19 20:31:16 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_grid(t_cub *game)
{
	int		k;
	int		l;
	float	offset;

	offset = game->settings.offset * MAP_SIZE;
	l = 0;
	while (l < game->settings.size_y)
	{
		k = 0;
		while(k < game->settings.res.x * MAP_SIZE)
		{
			my_pixel_put(&game->img, k, l * offset, 0x00000000);
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
			my_pixel_put(&game->img, l * offset, k, 0x00000000);
			k++;
		}
		l++;
	}
}

void		put_wall(t_cub *game, int x, int y, int colour)
{
	int		k;
	int		l;
	float	offset;

	offset = game->settings.offset * MAP_SIZE;
	k = 0;
	while (k < offset)
	{
		l = 0;
		while (l < offset)
		{
			my_pixel_put(&game->img, x * offset + k, y * offset + l, colour);
			l++;
		}
		k++;
	}
}

void		draw_map(t_cub *game)
{

	int		i;
	int		j;

	i = 0;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			if (game->map[i][j] == '0')
				put_wall(game, j, i, 0x00000000);
			if (game->map[i][j] == ' ')
				put_wall(game, j, i, 0x000000FF);
			if (game->map[i][j] == '1')
				put_wall(game, j, i, 0x00FF0000);
			if (game->map[i][j] == '2')
				put_wall(game, j, i, 0x0000FF00);
			j++;
		}
		i++;
	}
}

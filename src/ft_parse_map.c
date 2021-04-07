/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:10:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 20:12:19 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void			ft_player_pos(t_player *player, t_world *world)
{
	int			i;
	int			j;

	i = 0;
	while (i < world->msize.y)
	{
		j = 0;
		while (j < world->msize.x)
		{
			if (world->map[i][j] == 'N')
			{
				player->vector.x = (double)j + 0.5;
				player->vector.y = (double)i + 0.5;
				player->vector.dx = -1;
				player->vector.dy = 0;
				player->camera.px = 0.0;
				player->camera.py = 0.66;
				world->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

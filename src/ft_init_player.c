/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:10:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:44:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_init_world(t_world *world, t_mlx mlx, char *map_path)
{
	world->offset = (float)mlx.res.x / (float)world->msize.x;
	world->map = ft_copy_map(map_path, world);
	world->scount = ft_nobject(world);
	world->floor.color = ft_rgb_to_int(world->floor);
	world->ceiling.color = ft_rgb_to_int(world->ceiling);
}

static void		ft_init_move(t_move *move)
{
	move->right = 0;
	move->left = 0;
	move->up = 0;
	move->down = 0;
	move->turn_l = 0;
	move->turn_l = 0;
}

void			ft_init_player(t_player *player, t_world *world)
{
	int			i;
	int			j;

	i = 0;
	ft_init_move(&player->move);
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

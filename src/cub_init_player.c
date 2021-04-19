/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:10:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/19 07:14:09 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_player_dir_ew(t_player *player, char dir)
{
	if (dir == 'E')
	{
		player->vector.dx = 0;
		player->vector.dy = 1;
		player->camera.px = 0.66;
		player->camera.py = 0.0;
	}
	if (dir == 'W')
	{
		player->vector.dx = 0;
		player->vector.dy = -1;
		player->camera.px = -0.66;
		player->camera.py = 0.00;
	}
}

static void		cub_set_player_dir_ns(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->vector.dx = -1;
		player->vector.dy = 0;
		player->camera.px = 0.0;
		player->camera.py = 0.66;
	}
	if (dir == 'S')
	{
		player->vector.dx = 1;
		player->vector.dy = 0;
		player->camera.px = 0.0;
		player->camera.py = -0.66;
	}
}

static void		cub_init_player_pos(t_player *player, int x, int y)
{
	player->vector.x = (double)x + 0.5;
	player->vector.y = (double)y + 0.5;
	player->vector.posz = 0.0;
	player->vector.pitch = 0.0;
	player->move = 0;
}

void			cub_init_player(t_player *player, t_world *world,
		t_error *error)
{
	int			x;
	int			y;

	y = 0;
	while (y < world->msize.y)
	{
		x = 0;
		while (x < world->msize.x)
		{
			if (cub_isdir(world->map[y][x]) == 1)
			{
				cub_init_player_pos(player, x, y);
				cub_set_player_dir_ns(player, world->map[y][x]);
				cub_set_player_dir_ew(player, world->map[y][x]);
				world->map[y][x] = '0';
				error->dir += 1;
				if (error->dir > 1)
					return (cub_error_set(error, MUL_ST));
			}
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:10:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 04:21:36 by sshakya          ###   ########.fr       */
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

static void		ft_init_player_move(t_move *move)
{
	move->right = 0;
	move->left = 0;
	move->up = 0;
	move->down = 0;
	move->turn_l = 0;
	move->turn_l = 0;
	move->u = 0;
	move->d = 0;
}

static void		ft_set_player_dir(t_player *player, char dir)
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
	if (dir == 'E')
	{
		player->vector.dx = 0;
		player->vector.dy = -1;
		player->camera.px = 0.66;
		player->camera.py = 0.0;
	}
	if (dir == 'W')
	{
		player->vector.dx = 0;
		player->vector.dy = 1;
		player->camera.px = -0.66;
		player->camera.py = 0.00;
	}
}

static void		ft_init_player_pos(t_player *player, int x, int y)
{
	player->vector.x = (double)x + 0.5;
	player->vector.y = (double)y + 0.5;
	player->vector.posz = 0.0;
	player->vector.pitch = 0.0;
}

void			ft_init_player(t_player *player, t_world *world)
{
	int			x;
	int			y;

	y = 0;
	ft_init_player_move(&player->move);
	while (y < world->msize.y)
	{
		x = 0;
		while (x < world->msize.x)
		{
			if (ft_isdir(world->map[y][x]) == 1)
			{
				ft_init_player_pos(player, x, y);
				ft_set_player_dir(player, world->map[y][x]);
				world->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

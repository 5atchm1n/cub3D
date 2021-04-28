/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 02:22:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/28 03:45:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_move_sprite_init(t_sprite *s, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		if (s[i].id != 0 && s[i].dist < 25.0)
		{
			s[i].state |= (1 << 0);
			s[i].state |= (1 << 1);
		}
		else
			s[i].state &= ~(1 << 1);
		i++;
	}
}

static void		cub_move_enemy(t_world *world, t_vector v, t_mlx mlx)
{
	double		x;
	double		y;
	int			i;

	i = 0;
	while (i < world->scount)
	{
		x = world->sprite[i].x - v.dx * mlx.move_speed;
		y = world->sprite[i].y - v.dy * mlx.move_speed;
		if (world->map[(int)y][(int)x] == '0' && world->sprite[i].state & (1 << 1) && world->sprite[i].id == 2)
		{
			world->sprite[i].x -= v.dx * mlx.move_speed;
			world->sprite[i].y -= v.dy * mlx.move_speed;
		}
		i++;
	}
}

void			cub_sprite_move(t_world *world, t_player *player, t_mlx mlx)
{
	cub_move_sprite_init(world->sprite, world->scount);
	cub_move_enemy(world, player->vector, mlx);
//	cub_move_friendly(&world->sprite, player->vector, mlx);
}

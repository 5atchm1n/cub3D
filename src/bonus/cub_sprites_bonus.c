/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 02:22:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:33:06 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_move_sprite_init(t_sprite *s, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (s[i].id != 0)
		{
			s[i].state |= S_ON;
			if (s[i].dist < 81.0 && (s[i].state & S_BACK) == 0)
				s[i].state |= S_MOVE;
			if (s[i].state & S_BACK && s[i].dist > 5.0 && s[i].dist < 6.0)
				s[i].state &= ~S_BACK;
		}
		if (s[i].id != 0 && s[i].dist >= 81.0)
			s[i].state &= ~S_ON;
		i++;
	}
}

static void	cub_enemy_forward(t_sprite *sprite, t_vector v, t_speed speed,
		char **map)
{
	double	x;
	double	y;

	x = sprite->x - v.dx * speed.move * (LEVEL / 10.0);
	y = sprite->y - v.dy * speed.move * (LEVEL / 10.0);
	if (map[(int)y][(int)x] == '0')
	{
		sprite->x -= v.dx * speed.move * (LEVEL / 10.0);
		sprite->y -= v.dy * speed.move * (LEVEL / 10.0);
	}
	else
	{
		sprite->state &= ~(S_MOVE);
		sprite->state |= S_BACK;
	}
}

static void	cub_enemy_back(t_sprite *sprite, t_vector v, t_speed speed,
		char **map)
{
	double	x;
	double	y;

	x = sprite->x + v.dx * speed.move;
	y = sprite->y + v.dy * speed.move;
	if (x > 0 && y > 0 && map[(int)y][(int)x] == '0')
	{
		sprite->x += v.dx * speed.move;
		sprite->y += v.dy * speed.move;
	}
	else
	{
		sprite->state &= ~(S_BACK);
		sprite->state |= S_MOVE;
	}
}

void	cub_sprite_move(t_world *world, t_player *player)
{
	int	i;

	cub_move_sprite_init(world->sprite, world->info.scount);
	i = 0;
	while (i < world->info.scount)
	{
		if (world->sprite[i].id == 2 && world->sprite[i].state & S_MOVE)
			cub_enemy_forward(&world->sprite[i], player->vector, player->speed,
				world->map);
		if (world->sprite[i].id == 2 && world->sprite[i].state & S_BACK)
			cub_enemy_back(&world->sprite[i], player->vector, player->speed,
				world->map);
		cub_kill(&world->sprite[i], player->move);
		i++;
	}
	cub_collision(world->sprite, world->info.scount, player);
}

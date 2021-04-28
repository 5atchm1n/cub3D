/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 02:22:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/28 21:49:21 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_move_sprite_init(t_sprite *s, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		if (s[i].id != 0)
		{
			s[i].state |= (1 << 0);
			if (s[i].dist < 81.0 && (s[i].state & (1 << 2)) == 0)
				s[i].state |= (1 << 1);
			if (s[i].state & (1 << 2) && s[i].dist > 5.0 && s[i].dist < 6.0)
				s[i].state &= ~(1 << 2);
		}
		if (s[i].id != 0 && s[i].dist >= 81.0)
			s[i].state &= ~(1 << 1);
		i++;
	}
}

static void		cub_enemy_forward(t_sprite *sprite, t_vector v, t_mlx mlx,
		char **map)
{
	double		x;
	double		y;

	x = sprite->x - v.dx * mlx.move_speed * (LEVEL / 10.0);
	y = sprite->y - v.dy * mlx.move_speed * (LEVEL / 10.0);
	if (map[(int)y][(int)x] == '0')
	{
		sprite->x -= v.dx * mlx.move_speed * (LEVEL / 10.0);
		sprite->y -= v.dy * mlx.move_speed * (LEVEL / 10.0);
	}
}

static void		cub_enemy_back(t_sprite *sprite, t_vector v, t_mlx mlx,
		char **map)
{
	double		x;
	double		y;

	x = sprite->x + v.dx * mlx.move_speed;
	y = sprite->y + v.dy * mlx.move_speed;
	if (map[(int)y][(int)x] == '0')
	{
		sprite->x += v.dx * mlx.move_speed;
		sprite->y += v.dy * mlx.move_speed;
	}
}

static void		cub_move_enemy(t_world *world, t_vector v, t_mlx mlx)
{
	int			i;

	i = 0;
	while (i < world->scount)
	{
		if (world->sprite[i].id == 2 && world->sprite[i].state & (1 << 1))
			cub_enemy_forward(&world->sprite[i], v, mlx, world->map);
		if (world->sprite[i].id == 2 && world->sprite[i].state & (1 << 2))
			cub_enemy_back(&world->sprite[i], v, mlx, world->map);
		i++;
	}
}

static void		cub_collision(t_sprite *sprite, int count, t_player *player)
{
	int			hit;
	int			i;

	hit = 0;
	i = 0;
	while (i < count)
	{
		if (sprite[i].id == 2 && sprite[i].dist < 0.5 && sprite[i].dist > 0)
		{
			hit += 5;
			sprite[i].state |= (1 << 2);
			sprite[i].state &= ~(1 << 1);
		}
		i++;
	}
	player->health -= hit;
}

void			cub_sprite_move(t_world *world, t_player *player, t_mlx mlx)
{
	cub_move_sprite_init(world->sprite, world->scount);
	cub_move_enemy(world, player->vector, mlx);
	cub_collision(world->sprite, world->scount, player);
}

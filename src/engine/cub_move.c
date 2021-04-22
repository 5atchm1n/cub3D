/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/20 01:15:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_move_up(t_vector *v, char **map)
{
	double		x;
	double		y;
	double		offset[2];

	cub_player_offset(v, offset);
	x = v->x + v->dx * MOVE_SPEED + offset[0];
	y = v->y + v->dy * MOVE_SPEED + offset[1];
	if (map[(int)y][(int)x] == '0')
	{
		v->x += v->dx * MOVE_SPEED;
		v->y += v->dy * MOVE_SPEED;
	}
}

static void		cub_move_down(t_vector *v, char **map)
{
	double		x;
	double		y;

	x = v->x - v->dx * MOVE_SPEED;
	y = v->y - v->dy * MOVE_SPEED;
	if (map[(int)y][(int)x] == '0')
	{
		v->x -= v->dx * MOVE_SPEED;
		v->y -= v->dy * MOVE_SPEED;
	}
}

static void		cub_move_right(t_vector *v, char **map)
{
	double		x;
	double		y;

	x = v->x + v->dy * MOVE_SPEED;
	y = v->y - v->dx * MOVE_SPEED;
	if (map[(int)y][(int)x] == '0')
	{
		v->x += v->dy * MOVE_SPEED;
		v->y -= v->dx * MOVE_SPEED;
	}
}

static void		cub_move_left(t_vector *v, char **map)
{
	double		x;
	double		y;

	x = v->x - v->dy * MOVE_SPEED;
	y = v->y + v->dx * MOVE_SPEED;
	if (map[(int)y][(int)x] == '0')
	{
		v->x -= v->dy * MOVE_SPEED;
		v->y += v->dx * MOVE_SPEED;
	}
}

int				cub_move(t_cub *game)
{
	cub_look_left_right(&game->player.vector, &game->player.camera,
			game->player.move);
	cub_look_up_down(&game->player.vector, game->mlx, game->player.move);
	if (game->player.move & M_UP)
		cub_move_up(&game->player.vector, game->world.map);
	if (game->player.move & M_DOWN)
		cub_move_down(&game->player.vector, game->world.map);
	if (game->player.move & M_LEFT)
		cub_move_left(&game->player.vector, game->world.map);
	if (game->player.move & M_RIGHT)
		cub_move_right(&game->player.vector, game->world.map);
	cub_render(game);
	if (game->mlx.on == 0)
		cub_quit(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 17:31:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		cub_look_left_right(t_vector *v, t_camera *cam, uint_fast8_t move)
{
	double		dir;
	double		p;

	if (move & L_RIGHT)
	{
		dir = v->dx;
		v->dx = v->dx * cos(-TURN_SPEED) - v->dy * sin(-TURN_SPEED);
		v->dy = dir * sin(-TURN_SPEED) + v->dy * cos(-TURN_SPEED);
		p = cam->px;
		cam->px = cam->px * cos(-TURN_SPEED) - cam->py * sin(-TURN_SPEED);
		cam->py = p * sin(-TURN_SPEED) + cam->py * cos(-TURN_SPEED);
	}
	if (move & L_LEFT)
	{
		dir = v->dx;
		v->dx = v->dx * cos(TURN_SPEED) - v->dy * sin(TURN_SPEED);
		v->dy = dir * sin(TURN_SPEED) + v->dy * cos(TURN_SPEED);
		p = cam->px;
		cam->px = cam->px * cos(TURN_SPEED) - cam->py * sin(TURN_SPEED);
		cam->py = p * sin(TURN_SPEED) + cam->py * cos(TURN_SPEED);
	}
	return (0);
}

static void		cub_look_up_down(t_vector *v, t_mlx mlx, uint_fast8_t move)
{
	if (move & L_UP)
	{
		v->pitch += (mlx.res.y / 2) * MOVE_SPEED;
		if (v->pitch > mlx.res.y / 4)
			v->pitch = mlx.res.y / 4;
	}
	if (move & L_DOWN)
	{
		v->pitch -= (mlx.res.y / 2) * MOVE_SPEED;
		if (v->pitch < -mlx.res.y / 4)
			v->pitch = -mlx.res.y / 4;
	}
	if (v->pitch > 0)
		ft_fmax(0, v->pitch - 100 * MOVE_SPEED);
	if (v->pitch < 0)
		ft_fmin(1, v->pitch + 100 * MOVE_SPEED);
}

static void		cub_player_offset(t_vector *v, double *offset)
{
	if (v->dx > 0)
		offset[0] = PLAYER_SIZE;
	else
		offset[0] = -PLAYER_SIZE;
	if (v->dy > 0)
		offset[1] = PLAYER_SIZE;
	else
		offset[1] = -PLAYER_SIZE;
}

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
	cub_look_left_right(&game->player.vector, &game->player.camera, game->player.move);
	cub_look_up_down(&game->player.vector, game->mlx, game->player.move);
	if (game->player.move & M_UP)
		cub_move_up(&game->player.vector, game->world.map);
	if (game->player.move & M_DOWN)
		cub_move_down(&game->player.vector, game->world.map);
	if (game->player.move & M_LEFT)
		cub_move_left(&game->player.vector, game->world.map);
	if (game->player.move & M_RIGHT)
		cub_move_right(&game->player.vector, game->world.map);
	cub_floor_casting(&game->player, &game->world, &game->mlx);
	cub_raycasting(game);
	cub_cast_sprites(game);
	cub_minimap(game);
	cub_draw(&game->mlx);
	if (game->mlx.on == 0)
		cub_quit(game);
	return (0);
}

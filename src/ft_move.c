/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/06 00:37:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_update_fov(t_vector *v, t_camera *cam, t_move *move)
{
	double		dir;
	double		p;

	if (move->turn_r)
	{
		dir = v->dx;
		v->dx = v->dx * cos(-TURN_SPEED) - v->dy * sin(-TURN_SPEED);
		v->dy = dir * sin(-TURN_SPEED) + v->dy * cos(-TURN_SPEED);
		p = cam->px;
		cam->px = cam->px * cos(-TURN_SPEED) - cam->py * sin(-TURN_SPEED);
		cam->py = p * sin(-TURN_SPEED) + cam->py * cos(-TURN_SPEED);
	}
	if (move->turn_l)
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

static void		ft_player_offset(t_vector *v, double *offset)
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

static void		ft_move_up(t_vector *v, char **map)
{
	double		x;
	double		y;
	double		offset[2];

	ft_player_offset(v, offset);
	x = v->x + v->dx * MOVE_SPEED + offset[0];
	y = v->y + v->dy * MOVE_SPEED + offset[1];
	if (map[(int)y][(int)x] != '1')
	{
		v->x += v->dx * MOVE_SPEED;
		v->y += v->dy * MOVE_SPEED;
	}
}

static void		ft_move_down(t_vector *v, char **map)
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

static void		ft_move_right(t_vector *v, char **map)
{
	double		x;
	double		y;

	x = v->x + (v->dy * MOVE_SPEED);
	y = v->y - (v->dx * MOVE_SPEED);
	if (map[(int)y][(int)x] == '0')
	{
		v->x += v->dy * MOVE_SPEED;
		v->y -= v->dx * MOVE_SPEED;
	}
}

static void		ft_move_left(t_vector *v, char **map)
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

int				ft_move(t_cub *game)
{
	ft_update_fov(&game->player.vector, &game->player.camera, &game->player.move);
	if (game->player.move.up)
		ft_move_up(&game->player.vector, game->world.map);
	if (game->player.move.down)
		ft_move_down(&game->player.vector, game->world.map);
	if (game->player.move.left)
		ft_move_left(&game->player.vector, game->world.map);
	if (game->player.move.right)
		ft_move_right(&game->player.vector, game->world.map);
// SPLIT FILES HERE //	
	ft_raycasting(game);
	ft_cast_sprites(game);
	ft_minimap(game);
	ft_draw(&game->mlx);
	if (game->mlx.on == 0)
		ft_quit(game);
	return (0);
}

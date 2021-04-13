/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:02:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/13 03:48:56 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_player_offset(t_vector *vector, double *offset)
{
	if (vector->dx > 0)
		offset[0] = PLAYER_SIZE;
	else
		offset[0] = -PLAYER_SIZE;
	if (vector->dy > 0)
		offset[1] = PLAYER_SIZE;
	else
		offset[1] = -PLAYER_SIZE;
}

void			cub_look_up_down(t_vector *v, t_mlx mlx, uint_fast8_t move)
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

void			cub_look_left_right(t_vector *v, t_camera *cam, uint_fast8_t move)
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
}

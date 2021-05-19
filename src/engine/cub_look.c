/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:02:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:36:52 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_player_offset(t_vector *vector, double *offset)
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

void	cub_look_up_down(t_vector *v, t_mlx mlx, uint_fast16_t move,
		t_speed speed)
{
	if (move & L_UP)
	{
		v->pitch += (mlx.res.y / 2) * speed.move;
		if (v->pitch > mlx.res.y / 4)
			v->pitch = mlx.res.y / 4;
	}
	if (move & L_DOWN)
	{
		v->pitch -= (mlx.res.y / 2) * speed.move;
		if (v->pitch < -mlx.res.y / 4)
			v->pitch = -mlx.res.y / 4;
	}
	if (v->pitch > 0)
		ft_fmax(0, v->pitch - 100 * speed.move);
	if (v->pitch < 0)
		ft_fmin(0, v->pitch + 100 * speed.move);
}

void	cub_look_left_right(t_vector *v, t_camera *cam, uint_fast16_t move,
		t_speed speed)
{
	double	dir;
	double	p;

	if (move & L_RIGHT)
	{
		dir = v->dx;
		v->dx = v->dx * cos(-speed.turn) - v->dy * sin(-speed.turn);
		v->dy = dir * sin(-speed.turn) + v->dy * cos(-speed.turn);
		p = cam->px;
		cam->px = cam->px * cos(-speed.turn)
			- cam->py * sin(-speed.turn);
		cam->py = p * sin(-speed.turn) + cam->py * cos(-speed.turn);
	}
	if (move & L_LEFT)
	{
		dir = v->dx;
		v->dx = v->dx * cos(speed.turn) - v->dy * sin(speed.turn);
		v->dy = dir * sin(speed.turn) + v->dy * cos(speed.turn);
		p = cam->px;
		cam->px = cam->px * cos(speed.turn) - cam->py * sin(speed.turn);
		cam->py = p * sin(speed.turn) + cam->py * cos(speed.turn);
	}
}

void	cub_jump_crouch(t_vector *v, uint_fast16_t move, t_speed speed)
{
	if (move & M_JUMP)
		v->posz = 200;
	if (move & M_CROUCH)
		v->posz = -200;
	if (v->posz > 0)
		v->posz = ft_fmax(0, v->posz - 100 * speed.move * 4);
	if (v->posz < 0)
		v->posz = ft_fmin(0, v->posz + 100 * speed.move * 4);
}

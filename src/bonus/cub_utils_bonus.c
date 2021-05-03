/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:36:35 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/04 00:31:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		cub_mouse_stop(t_player *player)
{
	player->move &= ~L_LEFT;
	player->move &= ~L_RIGHT;
	player->move &= ~L_DOWN;
	player->move &= ~L_UP;
}

void		cub_mouse_move(int x, int y, t_player *player, t_mlx mlx)
{
	if (x < mlx.mouse.x)
		player->move |= L_LEFT;
	if (x > mlx.mouse.x)
		player->move |= L_RIGHT;
	if (y > mlx.mouse.y)
		player->move |= L_DOWN;
	if (y < mlx.mouse.y)
		player->move |= L_UP;
}

void		cub_collision(t_sprite *sprite, int count, t_player *player)
{
	int		hit;
	int		i;

	hit = 0;
	i = 0;
	while (i < count)
	{
		if (sprite[i].id == 2 && sprite[i].dist < 0.5 && sprite[i].dist > 0
				&& (sprite[i].state & S_KILL) == 0)
		{
			hit += 5;
			sprite[i].state |= S_BACK;
			sprite[i].state &= ~S_MOVE;
		}
		i++;
	}
	player->health -= hit;
}

void		cub_kill(t_sprite *sprite, uint_fast16_t move)
{
	if (sprite->id == 2 && move & M_HIT && sprite->dist < 0.8)
		sprite->state |= S_KILL;
}

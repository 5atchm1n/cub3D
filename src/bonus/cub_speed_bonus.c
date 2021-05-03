/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_speed_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:30:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/03 18:14:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_speed(t_cub *game)
{
	clock_t		oldtime;
	double		ticks;

	oldtime = game->mlx.time;
	game->mlx.time = clock();
	if (BONUS)
		ticks = ((double)(game->mlx.time - oldtime)) / CLOCKS_PER_SEC;
	else
		ticks = (double)game->mlx.res.y / (double)game->mlx.res.x / 25;
	game->player.speed.turn = ticks / (10.0 / TURN_SPEED);
	game->player.speed.move = ticks / (10.0 / MOVE_SPEED);
}

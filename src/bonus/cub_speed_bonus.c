/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_speed_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:30:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/14 10:47:21 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_speed(t_cub *game)
{
	clock_t		oldtime;
	double		ticks;
	double		oldelapsed;

	oldtime = game->mlx.time.cycle;
	oldelapsed = (double)game->mlx.time.cycle / CLOCKS_PER_SEC;
	game->mlx.time.cycle = clock();
	if (BONUS)
		ticks = ((double)(game->mlx.time.cycle - oldtime)) / CLOCKS_PER_SEC;
	else
		ticks = (double)game->mlx.res.y / (double)game->mlx.res.x / 25;
	game->player.speed.turn = ticks / (10.0 / TURN_SPEED);
	game->player.speed.move = ticks / (10.0 / MOVE_SPEED);
}

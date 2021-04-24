/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:32:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/23 04:45:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			cub_keypress(int keycode, t_cub *game)
{
	if (keycode == KEY_LOOK_RIGHT)
		game->player.move |= L_RIGHT;
	if (keycode == KEY_LOOK_LEFT)
		game->player.move |= L_LEFT;
	if (keycode == KEY_LOOK_UP)
		game->player.move |= L_UP;
	if (keycode == KEY_LOOK_DOWN)
		game->player.move |= L_DOWN;
	if (keycode == KEY_ESC_QUIT)
		game->mlx.on = 0;
	if (keycode == KEY_MOVE_UP)
		game->player.move |= M_UP;
	if (keycode == KEY_MOVE_DOWN)
		game->player.move |= M_DOWN;
	if (keycode == KEY_MOVE_LEFT)
		game->player.move |= M_LEFT;
	if (keycode == KEY_MOVE_RIGHT)
		game->player.move |= M_RIGHT;
	return (0);
}

int			cub_keyrelease(int keycode, t_cub *game)
{
	if (keycode == KEY_LOOK_RIGHT)
		game->player.move &= ~L_RIGHT;
	if (keycode == KEY_LOOK_LEFT)
		game->player.move &= ~L_LEFT;
	if (keycode == KEY_LOOK_UP)
		game->player.move &= ~L_UP;
	if (keycode == KEY_LOOK_DOWN)
		game->player.move &= ~L_DOWN;
	if (keycode == KEY_MOVE_UP)
		game->player.move &= ~M_UP;
	if (keycode == KEY_MOVE_DOWN)
		game->player.move &= ~M_DOWN;
	if (keycode == KEY_MOVE_LEFT)
		game->player.move &= ~M_LEFT;
	if (keycode == KEY_MOVE_RIGHT)
		game->player.move &= ~M_RIGHT;
	return (0);
}

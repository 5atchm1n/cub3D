/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:32:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/26 15:44:32 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_keypress(int keycode, t_cub *game)
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
	if (keycode == KEY_JUMP)
		game->player.move |= M_JUMP;
	if (keycode == KEY_CROUCH)
		game->player.move |= M_CROUCH;
	return (0);
}

static int	cub_keyrelease(int keycode, t_cub *game)
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
	if (keycode == KEY_JUMP)
		game->player.move &= ~M_JUMP;
	if (keycode == KEY_CROUCH)
		game->player.move &= ~M_CROUCH;
	return (0);
}

void		cub_mlx_hooks(t_cub *game)
{
	mlx_hook(game->mlx.win.win, 2, 1L << 0, &cub_keypress, game);
	mlx_hook(game->mlx.win.win, 3, 1L << 1, &cub_keyrelease, game);
	mlx_hook(game->mlx.win.win, 33, 1L << 2, &cub_quit, game);
	if (BONUS)
	{
		mlx_mouse_get_pos(game->mlx.win.mlx, game->mlx.win.win,
				&game->mlx.mouse.x, &game->mlx.mouse.y);
		mlx_hook(game->mlx.win.win, 6, 1L << 6, &cub_mouse, game);
	}
	mlx_loop_hook(game->mlx.win.mlx, &cub_move, game);
	mlx_loop(game->mlx.win.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:32:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 10:57:59 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_turn_start(int keycode, t_player *player)
{
	if (keycode == KEY_LOOK_RIGHT)
		player->move |= L_RIGHT;
	if (keycode == KEY_LOOK_LEFT)
		player->move |= L_LEFT;
	if (keycode == KEY_LOOK_UP)
		player->move |= L_UP;
	if (keycode == KEY_LOOK_DOWN)
		player->move |= L_DOWN;
	return (0);
}

static int	cub_move_start(int keycode, t_player *player, t_mlx *mlx)
{
	if (keycode == KEY_ESC_QUIT)
		mlx->on = 0;
	if (keycode == KEY_MOVE_UP)
		player->move |= M_UP;
	if (keycode == KEY_MOVE_DOWN)
		player->move |= M_DOWN;
	if (keycode == KEY_MOVE_LEFT)
		player->move |= M_LEFT;
	if (keycode == KEY_MOVE_RIGHT)
		player->move |= M_RIGHT;
	return (0);
}

static int	cub_turn_stop(int keycode, t_player *player)
{
	if (keycode == KEY_LOOK_RIGHT)
		player->move &= ~L_RIGHT;
	if (keycode == KEY_LOOK_LEFT)
		player->move &= ~L_LEFT;
	if (keycode == KEY_LOOK_UP)
		player->move &= ~L_UP;
	if (keycode == KEY_LOOK_DOWN)
		player->move &= ~L_DOWN;
	return (0);
}

static int	cub_move_stop(int keycode, t_player *player)
{
	int		i;

	i = 0;
	if (keycode == KEY_MOVE_UP)
		player->move &= ~M_UP;
	if (keycode == KEY_MOVE_DOWN)
		player->move &= ~M_DOWN;
	if (keycode == KEY_MOVE_LEFT)
		player->move &= ~M_LEFT;
	if (keycode == KEY_MOVE_RIGHT)
		player->move &= ~M_RIGHT;
	return (0);
}

int			cub_keypress(int keycode, t_cub *game)
{
	cub_turn_start(keycode, &game->player);
	cub_move_start(keycode, &game->player, &game->mlx);
	return (0);
}

int			cub_keyrelease(int keycode, t_cub *game)
{
	cub_turn_stop(keycode, &game->player);
	cub_move_stop(keycode, &game->player);
	return (0);
}

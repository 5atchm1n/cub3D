/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:02:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/28 22:11:21 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		cub_mouse_stop(t_player *player)
{
	player->move &= ~L_LEFT;
	player->move &= ~L_RIGHT;
	player->move &= ~L_DOWN;
	player->move &= ~L_UP;
	return (0);
}

static void		cub_mouse_move(int x, int y, t_player *player, t_mlx mlx)
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

int				cub_mouse(int x, int y, t_cub *game)
{
	mlx_mouse_hide(game->mlx.win.mlx, game->mlx.win.win);
	if (x == game->mlx.res.x / 2 || y == game->mlx.res.y / 2)
	{
		cub_mouse_stop(&game->player);
		return (0);
	}
	cub_mouse_move(x, y, &game->player, game->mlx);
	game->mlx.mouse.y = y;
	game->mlx.mouse.x = x;
	mlx_mouse_move(game->mlx.win.mlx, game->mlx.win.win,
			game->mlx.res.x / 2, game->mlx.res.y / 2);
	return (0);
}

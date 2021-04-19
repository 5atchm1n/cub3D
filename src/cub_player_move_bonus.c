/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player_move_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:02:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/19 22:49:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
static int		cub_mouse_stop(int x, int y, t_player *player, t_mlx mlx)
{
	if (x < mlx.mouse.x)
		player->move &= ~L_LEFT;
	if (x > mlx.mouse.x)
		player->move &= ~L_RIGHT;
	if (y > mlx.mouse.y)
		player->move &= ~L_DOWN;
	if (y < mlx.mouse.y)
		player->move &= ~L_UP;
	return (0);
}
*/

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
	if (x <= 1 || y <= 1 || x >= game->mlx.res.x - 1 ||
			y >= game->mlx.res.y - 1)
	{
		mlx_mouse_move(game->mlx.win.mlx, game->mlx.win.win,
				game->mlx.res.x / 2, game->mlx.res.y / 2);
		game->mlx.mouse.x = game->mlx.res.x / 2;
		game->mlx.mouse.y = game->mlx.res.y / 2;
		return (0);
	}
	if (x == game->mlx.mouse.x)
	{
		game->player.move &= ~L_LEFT;
		game->player.move &= ~L_RIGHT;
	}
	if (y == game->mlx.mouse.y)
	{
		game->player.move &= ~L_UP;
		game->player.move &= ~L_DOWN;
	}
	if (x == game->mlx.mouse.x && y == game->mlx.mouse.y)
		return (0);
	cub_mouse_move(x, y, &game->player, game->mlx);
	game->mlx.mouse.x = x;
	game->mlx.mouse.y = y;
	return (0);
}

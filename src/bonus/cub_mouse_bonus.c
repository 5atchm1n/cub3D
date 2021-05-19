/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:02:32 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:31:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cub_mouse(int x, int y, t_cub *game)
{
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

static int	cub_mouse_press(int button, int x, int y, t_cub *game)
{
	if (button == 1)
		game->player.move |= M_HIT;
	game->mlx.mouse.x = x;
	game->mlx.mouse.y = y;
	return (0);
}

static int	cub_mouse_release(int button, int x, int y, t_cub *game)
{
	if (button == 1)
		game->player.move &= ~M_HIT;
	game->mlx.mouse.x = x;
	game->mlx.mouse.y = y;
	return (0);
}

void	cub_mouse_hook(t_cub *game)
{
	mlx_mouse_hide(game->mlx.win.mlx, game->mlx.win.win);
	mlx_mouse_get_pos(game->mlx.win.mlx, game->mlx.win.win,
		&game->mlx.mouse.x, &game->mlx.mouse.y);
	mlx_hook(game->mlx.win.win, 6, 1L << 6, &cub_mouse, game);
	mlx_hook(game->mlx.win.win, 4, 1L << 2, &cub_mouse_press, game);
	mlx_hook(game->mlx.win.win, 5, 1L << 3, &cub_mouse_release, game);
	mlx_mouse_move(game->mlx.win.mlx, game->mlx.win.win,
		game->mlx.res.x / 2, game->mlx.res.y / 2);
}

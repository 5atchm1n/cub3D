/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:17:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/12 04:12:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
/*
static int		cub_mouse_stop(t_player *player)
{
	player->move &= ~L_UP;
	player->move &= ~L_DOWN;
	player->move &= ~L_LEFT;
	player->move &= ~L_RIGHT;
	return (1);
}
*/
static int		cub_mouse(int x, int y, t_cub *game)
{
	mlx_mouse_hide(game->mlx.win.mlx, game->mlx.win.win);
	if (x == game->mlx.mouse.x)
	{
		game->player.move &= ~L_LEFT;
		game->player.move &= ~L_RIGHT;
	}
	if (y == game->mlx.mouse.x)
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

int				main(int argc, char **argv)
{
	t_cub		game;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		return (0);
	if (argc == 2)
		cub_settings(argv[1], &game);
	cub_init(&game, argv[1]);
	cub_check(&game.world, &game);
	mlx_hook(game.mlx.win.win, 2, 1L << 0, &cub_keypress, &game);
	mlx_hook(game.mlx.win.win, 3, 1L << 1, &cub_keyrelease, &game);
	mlx_hook(game.mlx.win.win, 33, 1L << 2, &cub_quit, &game);
	mlx_hook(game.mlx.win.win, 6, 1L << 6, &cub_mouse, &game);
	//mlx_mouse_hook(win.win, mouse_hook, &win);
	//mlx_key_hook(game.mlx.win.win, key_hook, &game);
	mlx_loop_hook(game.mlx.win.mlx, &cub_move, &game);
	cub_print_info(&game);
	mlx_loop(game.mlx.win.mlx);
	return (0);
}

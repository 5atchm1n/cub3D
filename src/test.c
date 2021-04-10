/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:17:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 12:42:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
	//mlx_mouse_hook(win.win, mouse_hook, &win);
	//mlx_key_hook(game.mlx.win.win, key_hook, &game);
	mlx_hook(game.mlx.win.win, 33, 1L << 2, &cub_quit, &game);
	mlx_loop_hook(game.mlx.win.mlx, &cub_move, &game);
	cub_print_info(&game);
	mlx_loop(game.mlx.win.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:17:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/01 05:11:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				key_hook(int keycode, t_win *win)
{
	if (win && keycode)
		write(1 , "#", 1);
	printf("%d\n", keycode);
	return (0);
}

static void		ft_print_info(t_cub *game)
{
	int			j;
	int			i;

	i = 0;
	while (i < game->world.size_y)
	{
		j = 0;
		while (j < game->world.size_x)
		{
			printf("%c", game->world.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	// PRINT SETTINGS AND INITLA POSITION
	printf("map size = map[%d][%d]\n", game->world.size_y, game->world.size_x);
	printf("res_x = %d\n", game->mlx.res.x);
	printf("res_y = %d\n", game->mlx.res.y);
	printf("floor = %d | %#.8x \n", game->world.floor, game->world.floor);
	printf("ceiling = %d | %#.8x\n", game->world.ceiling, game->world.ceiling);
	printf("x = %.5f\n", game->player.vector.x);
	printf("y = %.5f\n", game->player.vector.y);
	printf("dx = %.5f\n", game->player.vector.dx);
	printf("dy = %.5f\n", game->player.vector.dy);
	printf("px = %.5f\n", game->player.camera.px);
	printf("py = %.5f\n", game->player.camera.py);
	printf("offset = %.5f\n", game->world.offset);
}

int				main(int argc, char **argv)
{
	t_cub		game;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		return (0);
	if (argc == 2)
		ft_settings(argv[1], &game.world, &game.mlx);
	ft_init(&game, argv[1]);
	ft_minimap(&game);
	ft_raycasting(&game);
	mlx_put_image_to_window(game.mlx.win.mlx, game.mlx.win.win, game.mlx.img.img, 0, 0);
	mlx_hook(game.mlx.win.win, 2, 1L << 0, &ft_keypress, &game);
	mlx_hook(game.mlx.win.win, 3, 1L << 1, &ft_keyrelease, &game);
	//	mlx_mouse_hook(win.win, mouse_hook, &win);
	//	mlx_key_hook(game.win.win, key_hook, &game);
	mlx_loop_hook(game.mlx.win.mlx, &ft_move, &game);
	ft_print_info(&game);
	mlx_loop(game.mlx.win.mlx);
	return (0);
}

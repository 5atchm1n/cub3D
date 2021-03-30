/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:18:41 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 02:43:32 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_hook(int keycode, t_win *win)
{
	if (win && keycode)
		write(1 , "#", 1);
	printf("%d\n", keycode);
	
	return (0);
}

static void		ft_player_pos(t_player *player, t_settings *settings, char **map)
{
	int			i;
	int			j;

	i = 0;
	while (i < settings->size_y)
	{
		j = 0;
		while (j < settings->size_x)
		{
			if (map[i][j] == 'N')
			{
			//	game->player.dir = M_PI / 2;
				player->vector.x = j + 0.5;
				player->vector.y = i + 0.5;
				player->vector.dx = -1;
				player->vector.dy = 0;
				player->camera.planex = 0;
				player->camera.planey = 0.66;
				map[i][j] = '0';
			//	game->player.dir = tan(game->camera.dirx / game->camera.diry);
			}
			j++;
		}
		i++;
	}
}

int			main (int argc, char **argv)
{
	t_cub		game;
	int			i;

	i = 0;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2)
		return (0);
	if (argc == 2)
		ft_settings(argv[1], &game.settings);
	ft_init(&game);
	game.map = ft_parse_map(argv[1], &game);
	ft_player_pos(&game.player, &game.settings, game.map);
// PRINT MAP	
	int			j;
	i = 0;
	while (i < game.settings.size_y)
	{
		j = 0;
		while (j < game.settings.size_x)
		{
			printf("%c", game.map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
// INIT MLX
	game.win.mlx = mlx_init();
	game.win.win = mlx_new_window(game.win.mlx, game.settings.res.x,
			game.settings.res.y, "cub3D");
	game.img.img = mlx_new_image(game.win.mlx, game.settings.res.x, game.settings.res.y);
	game.img.add = mlx_get_data_addr(game.img.img, &game.img.bpp, &game.img.len, &game.img.endian);
//	DRAW START POSITION
/*
	draw_map(&game);
	put_grid(&game);
	my_player(&game.img, game.player.vector.x, game.player.vector.y);
	player_fov(&game);
*/
	ft_minimap(&game);
// PUT TO WINDOW
	mlx_put_image_to_window(game.win.mlx , game.win.win, game.img.img, 0 , 0);
// START KEYHOOKS
	mlx_hook(game.win.win, 2, 1L<<0, &ft_keypress, &game);
	mlx_hook(game.win.win, 3, 1L<<1, &ft_keyrelease, &game);
//	mlx_mouse_hook(win.win, mouse_hook, &win);
//	mlx_key_hook(game.win.win, key_hook, &game);
	mlx_loop_hook(game.win.mlx, &ft_move, &game);
// PRINTF INITIAL POSITION AND SETTINGS
	printf("map size = map[%d][%d]\n" , game.settings.size_y, game.settings.size_x);
	printf("res_x = %d\n", game.settings.res.x);
	printf("res_y = %d\n", game.settings.res.y);
	printf("floor = %d | %#.8x \n" , game.settings.floor, game.settings.floor);
	printf("ceiling = %d | %#.8x\n" , game.settings.ceiling, game.settings.ceiling);
	printf("x = %.5f\n", game.player.vector.x);
	printf("y = %.5f\n", game.player.vector.y);
	printf("dx = %.5f\n", game.player.vector.dx);
	printf("dy = %.5f\n", game.player.vector.dy);
	printf("px = %.5f\n", game.player.camera.planex);
	printf("py = %.5f\n", game.player.camera.planey);
	printf("offset = %.5f\n", game.settings.offset);
// MAIN LOOP FUNCTION		
	mlx_loop(game.win.mlx);

	return(0);
}

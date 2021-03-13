/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:18:41 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/13 17:14:06 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_map(t_cub *game)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			game->map[i][j] = ' ';;
			j++;
		}
		i++;
	}
}

static void ft_player_pos(t_cub *game)
{
	int		offset;
	int		i;
	int		j;

	i = 0;
	offset = game->settings.res.x / game->settings.size_x;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			if (game->map[i][j] == 'N')
			{
				game->player.dir = M_PI_2;
				game->player.pos_x = (j * offset) + (offset / 2);
				game->player.pos_y = (i * offset) + (offset / 2);
			}
			j++;
		}
		i++;
	}
}


int		key_hook(int keycode, t_win *win)
{
	if (win && keycode)
		write(1 , "#", 1);
	printf("%d\n", keycode);
	
	return (0);
}

void	ft_init_move(t_move *move)
{
	move->right = 0;
	move->left = 0;
	move->up = 0;
	move->down = 0;
	move->turn_l = 0;
	move->turn_l = 0;
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
	
	game.map = (char **)malloc(sizeof(char *) * game.settings.size_y);
	while (i < game.settings.size_y)
	{
		game.map[i] = (char *)malloc(sizeof(char) * game.settings.size_x);
		i++;
	}
	
	ft_init_map(&game);
	ft_init_move(&game.player.move);
	ft_parse_map(argv[1], &game);
/*
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
*/		
	game.win.mlx = mlx_init();
	game.win.win = mlx_new_window(game.win.mlx, game.settings.res.x,
			game.settings.res.y, "cub3D");

	ft_player_pos(&game);

	game.img.img = mlx_new_image(game.win.mlx, game.settings.res.x, game.settings.res.y);
	
	game.img.add = mlx_get_data_addr(game.img.img, &game.img.bpp, &game.img.len, &game.img.endian);
/*
	mlx_key_hook(game.win.win, key_hook, &game);
	mlx_mouse_hook(win.win, mouse_hook, &win);
*/

	draw_map(&game);
	my_player(&game.img, game.player.pos_x, game.player.pos_y);
	player_fov(&game);
	mlx_put_image_to_window(game.win.mlx , game.win.win, game.img.img, 0 , 0);

	mlx_hook(game.win.win, 2, 1L<<0, &ft_keypress, &game);
	mlx_hook(game.win.win, 3, 1L<<1, &ft_keyrelease, &game);
	
/*
	printf("map size = map[%d][%d]\n" , game.settings.size_y, game.settings.size_x);
	printf("res_x = %d\n", game.settings.res.x);
	printf("res_y = %d\n", game.settings.res.y);	
	printf("floor = %d | %#x \n" , game.settings.floor, game.settings.floor);
	printf("ceiling = %d | %#x\n" , game.settings.ceiling, game.settings.ceiling);
*/	
		
	mlx_loop(game.win.mlx);


	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:17:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/19 21:49:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_render(t_cub *game)
{
	if (BONUS)
		cub_floor_casting(&game->player, &game->world, &game->mlx);
	cub_raycasting(game);
	cub_cast_sprites(game);
	cub_minimap(game);
	cub_draw(&game->mlx);
}

static void		cub_mlx_hooks(t_cub *game)
{
	mlx_hook(game->mlx.win.win, 2, 1L << 0, &cub_keypress, game);
	mlx_hook(game->mlx.win.win, 3, 1L << 1, &cub_keyrelease, game);
	mlx_hook(game->mlx.win.win, 33, 1L << 2, &cub_quit, game);
	if (BONUS)
		mlx_hook(game->mlx.win.win, 6, 1L << 6, &cub_mouse, game);
	mlx_loop_hook(game->mlx.win.mlx, &cub_move, game);
	mlx_loop(game->mlx.win.mlx);
}

static void		cub_play(t_cub *game, char *map_path)
{
	if (cub_check_map_arg(map_path) == 0)
		printf("ERROR\n");
	cub_settings(map_path, game);
	cub_init(game, map_path); 
	cub_check(&game->world, game);
	cub_mlx_hooks(game);
}

static void		cub_save(t_cub *game, char *map_path, char *save_arg)
{
	if (cub_check_save_arg(save_arg) == 0)
		return ;
	cub_settings(map_path, game);
	cub_init(game, map_path);
	cub_check(&game->world, game);
	cub_render(game);
	cub_save_bmp(game);
	cub_quit(game);
}

int				main(int argc, char **argv)
{
	t_cub		game;

	ft_memset(&game, 0, sizeof(game));
	if (argc != 2 && argc != 3)
		return (0);
	if (argc == 2)
		cub_play(&game, argv[1]);
	if (argc == 3)
		cub_save(&game, argv[1], argv[2]);	
	return (0);
}

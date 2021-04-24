/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:17:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/24 15:11:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_play(t_cub *game, char *map_path)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(error));
	if (cub_check_map_arg(map_path) == 0)
		return (cub_error_msg(INV_MAP, error));
	cub_settings(map_path, game);
	cub_init(game, map_path);
	cub_check(&game->world, game);
	if (TEST)
		cub_print_info(game);
	cub_mlx_hooks(game);
}

static void		cub_save(t_cub *game, char *map_path, char *save_arg)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(error));
	if (cub_check_map_arg(map_path) == 0)
		return (cub_error_msg(INV_MAP, error));
	if (cub_check_save_arg(save_arg) == 0)
		return (cub_error_msg(INV_SAVE, error));
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
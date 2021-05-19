/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:17:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 04:11:47 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_play(t_cub *game, char *map_path)
{
	t_error	error;
	int		err;

	ft_memset(&error, 0, sizeof(error));
	if (cub_check_map_arg(map_path) == 0)
		return (cub_error_msg(INV_MAP, error));
	err = cub_settings(map_path, game);
	if (err)
		return ;
	cub_init(game, map_path);
	cub_start_mlx(&game->mlx);
	cub_check(&game->world, game);
	cub_mlx_hooks(game);
}

static void	cub_save(t_cub *game, char *map_path, char *save_arg)
{
	t_error	error;
	int		err;

	ft_memset(&error, 0, sizeof(error));
	if (cub_check_map_arg(map_path) == 0)
		return (cub_error_msg(INV_MAP, error));
	if (cub_check_save_arg(save_arg) == 0)
		return (cub_error_msg(INV_SAVE, error));
	err = cub_settings(map_path, game);
	if (err)
		return ;
	cub_init(game, map_path);
	cub_check(&game->world, game);
	cub_render(game);
	cub_save_bmp(game);
	cub_quit(game);
}

int	main(int argc, char **argv)
{
	t_cub	game;

	ft_memset(&game, 0, sizeof(game));
	cub_init_structs(&game);
	if (argc != 2 && argc != 3)
		return (0);
	if (argc == 2)
		cub_play(&game, argv[1]);
	if (argc == 3)
		cub_save(&game, argv[1], argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:48:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/03 04:52:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_free_map(t_world *world)
{
	int			i;

	i = 0;
	while (i < world->info.msize.y)
	{
		free(world->map[i]);
		i++;
	}
	free(world->map);
}

void			cub_free_world(t_world *world)
{
	int			i;

	i = 0;
	while (i < TEXTURES)
	{
		free(world->objs.tex[i]);
		free(world->objs.tpath[i]);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		free(world->objs.spath[i]);
		free(world->objs.spr[i]);
		i++;
	}
	free(world->objs.spath);
	free(world->objs.spr);
	free(world->objs.tex);
	free(world->objs.tpath);
}

int				cub_quit(t_cub *game)
{
	int			i;

	i = 0;
	mlx_mouse_show(game->mlx.win.mlx, game->mlx.win.win);
	mlx_loop_end(game->mlx.win.mlx);
	while (i < game->mlx.res.y)
	{
		free(game->mlx.buffer[i]);
		i++;
	}
	free(game->mlx.buffer);
	cub_free_world(&game->world);
	cub_free_map(&game->world);
	free(game->world.objs.sky);
	free(game->world.objs.skybox);
	free(game->world.objs.ground);
	free(game->world.objs.weapon);
	mlx_destroy_image(game->mlx.win.mlx, game->mlx.img.img);
	mlx_destroy_window(game->mlx.win.mlx, game->mlx.win.win);
	exit(0);
	return (0);
}

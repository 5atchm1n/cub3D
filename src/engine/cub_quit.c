/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:48:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/04 00:49:30 by sshakya          ###   ########.fr       */
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

void			cub_free_utils(t_world *world)
{
	int			i;

	free(world->objs.sky);
	free(world->objs.skybox);
	free(world->objs.ground);
	i = 0;
	while (i < WEAPONS * 2)
	{
		free(world->objs.weapons[i]);
		i++;
	}
	free(world->objs.weapons);
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
	if (BONUS)
		cub_free_utils(&game->world);
	mlx_destroy_image(game->mlx.win.mlx, game->mlx.img.img);
	mlx_destroy_window(game->mlx.win.mlx, game->mlx.win.win);
	exit(0);
	return (0);
}

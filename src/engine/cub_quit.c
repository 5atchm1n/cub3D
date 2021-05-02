/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:48:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/02 23:00:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_free_map(t_world *world)
{
	int			i;

	i = 0;
	while (i < world->msize.y)
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
		free(world->tex[i]);
		free(world->tpath[i]);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		free(world->objpath[i]);
		free(world->obj[i]);
		i++;
	}
	free(world->objpath);
	free(world->obj);
	free(world->tex);
	free(world->tpath);
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
	free(game->world.sky);
	free(game->world.skybox);
	free(game->world.ground);
	free(game->world.weapon);
	mlx_destroy_image(game->mlx.win.mlx, game->mlx.img.img);
	mlx_destroy_window(game->mlx.win.mlx, game->mlx.win.win);
	exit(0);
	return (0);
}

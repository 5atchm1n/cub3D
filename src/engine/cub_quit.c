/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:48:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 17:55:36 by sshakya          ###   ########.fr       */
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
		if (world->objs.tex != NULL)
			free(world->objs.tex[i]);
		if (world->objs.tpath != NULL)
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
	free(world->sprite);
}

void			cub_free_utils(t_world *world)
{
	int			i;

	i = 0;
	while (i < WEAPONS * 2)
	{
		free(world->objs.weapons[i]);
		i++;
	}
	free(world->objs.weapons);
	i = 0;
	while (i < BONUS_OBJECTS)
	{
		free(world->objs.bpath[i]);
		i++;
	}
	free(world->objs.bpath);
	free(world->objs.skypath);
	free(world->objs.sky);
	free(world->objs.skybox);
	free(world->objs.ground);
}

void			cub_quit_bonus(t_cub *game)
{
	mlx_mouse_show(game->mlx.win.mlx, game->mlx.win.win);
	cub_win(game->world.info, game->world.sprite, game->player);
	cub_free_utils(&game->world);
}

int				cub_quit(t_cub *game)
{
	int			i;

	i = 0;
	if (game->mlx.buffer != NULL)
	{
	while (i < game->mlx.res.y)
	{
		if (game->mlx.buffer[i] != NULL)
			free(game->mlx.buffer[i]);
		i++;
	}
	free(game->mlx.buffer);
	}
	if (BONUS)
		cub_quit_bonus(game);
	if (game->mlx.on == 1)
	{
		mlx_destroy_image(game->mlx.win.mlx, game->mlx.img.img);
		cub_free_map(&game->world);
		cub_free_world(&game->world);
		mlx_loop_end(game->mlx.win.mlx);
		mlx_clear_window(game->mlx.win.mlx, game->mlx.win.win);
		mlx_destroy_window(game->mlx.win.mlx, game->mlx.win.win);
	}
	exit(0);
	return (0);
}

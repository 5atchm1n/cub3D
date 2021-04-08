/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:48:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 05:01:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_world(t_world *world)
{
	int		i;

	i = 0;
	while (i < world->msize.y)
	{
		free(world->map[i]);
		i++;
	}
	free(world->map);
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
		i++;
	}
}

int			ft_quit(t_cub *game)
{
	int		i;

	i = 0;
	while (i < game->mlx.res.y)
	{
		free(game->mlx.buffer[i]);
		i++;
	}
	free(game->mlx.buffer);
	ft_free_world(&game->world);
	free(game->world.objpath);
	free(game->world.tex);
	free(game->world.tpath);
	mlx_destroy_image(game->mlx.win.mlx, game->mlx.img.img);
	mlx_destroy_window(game->mlx.win.mlx, game->mlx.win.win);
	exit(0);
	return (0);
}

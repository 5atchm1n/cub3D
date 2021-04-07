/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:48:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 17:34:32 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_quit(t_cub *game)
{
	int		i;

	i = 0;
	while (i < game->world.msize.y)
	{
		free(game->world.map[i]);
		i++;
	}
	free(game->world.map);
	i = 0;
	while (i < game->mlx.res.y)
	{
		free(game->mlx.buffer[i]);
		i++;
	}
	free(game->mlx.buffer);
	i = 0;
	while (i < TEXTURES)
	{
		free(game->world.tex[i]);
		free(game->world.tpath[i]);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		free(game->world.objpath[i]);
		i++;
	}
	free(game->world.objpath);
	free(game->world.tex);
	free(game->world.tpath);
	mlx_destroy_image(game->mlx.win.mlx, game->mlx.img.img);
	mlx_destroy_window(game->mlx.win.mlx, game->mlx.win.win);
	exit(0);
	return (0);
}

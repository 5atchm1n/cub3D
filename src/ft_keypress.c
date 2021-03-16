/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:32:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/16 04:22:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_turn(int keycode, t_cub *game)
{
	if (keycode == 65361)
		game->player.move.turn_r = 1;
	if (keycode == 65363)
		game->player.move.turn_l = 1;
		return (0);
}

static int		ft_move(int keycode, t_cub *game)
{
	int			i;

	i = 0;
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(game->win.mlx, game->win.win);
		while(i < game->settings.size_y)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		exit(0);
	}
	if (keycode == 119 || keycode == 65362)
		game->player.move.up = 1;
	if (keycode == 115 || keycode == 65364)
		game->player.move.down = 1;
	if (keycode == 97)
		game->player.move.left = 1;
	if (keycode == 100)
		game->player.move.right = 1;

	return (0);
}

int		ft_keypress(int keycode, t_cub *game)
{
	game->show = 0;
	ft_turn(keycode, game);
	ft_move(keycode, game);

	return (0);
}

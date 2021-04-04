/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyrelease.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:33:52 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/04 23:44:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_turn_stop(int keycode, t_cub *game)
{
	if (keycode == 65363)
		game->player.move.turn_r = 0;
	if (keycode == 65361)
		game->player.move.turn_l = 0;
	return (0);
}

static int	ft_move_stop(int keycode, t_cub *game)
{
	int		i;

	i = 0;
	if (keycode == 119 || keycode == 65362)
		game->player.move.up = 0;
	if (keycode == 115 || keycode == 65364)
		game->player.move.down = 0;
	if (keycode == 97)
		game->player.move.left = 0;
	if (keycode == 100)
		game->player.move.right = 0;
	return (0);
}

int			ft_keyrelease(int keycode, t_cub *game)
{
	ft_turn_stop(keycode, game);
	ft_move_stop(keycode, game);
	return (0);
}

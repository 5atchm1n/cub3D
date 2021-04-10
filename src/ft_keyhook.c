/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:32:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 03:57:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_turn_start(int keycode, t_cub *game)
{
	if (keycode == 65363)
		game->player.move.turn_r = 1;
	if (keycode == 65361)
		game->player.move.turn_l = 1;
	if (keycode == 65362)
		game->player.move.u = 1;
	if (keycode == 65364)
		game->player.move.d = 1;
	return (0);
}

static int	ft_move_start(int keycode, t_player *player, t_mlx *mlx)
{
	if (keycode == 0xff1b)
		mlx->on = 0;
	if (keycode == 119)
		player->move.up = 1;
	if (keycode == 115)
		player->move.down = 1;
	if (keycode == 97)
		player->move.left = 1;
	if (keycode == 100)
		player->move.right = 1;
	return (0);
}

static int	ft_turn_stop(int keycode, t_cub *game)
{
	if (keycode == 65363)
		game->player.move.turn_r = 0;
	if (keycode == 65361)
		game->player.move.turn_l = 0;
	if (keycode == 65362)
		game->player.move.u = 0;
	if (keycode == 65364)
		game->player.move.d = 0;
	return (0);
}

static int	ft_move_stop(int keycode, t_cub *game)
{
	int		i;

	i = 0;
	if (keycode == 119)
		game->player.move.up = 0;
	if (keycode == 115)
		game->player.move.down = 0;
	if (keycode == 97)
		game->player.move.left = 0;
	if (keycode == 100)
		game->player.move.right = 0;
	return (0);
}

int			ft_keypress(int keycode, t_cub *game)
{
	ft_turn_start(keycode, game);
	ft_move_start(keycode, &game->player, &game->mlx);
	return (0);
}

int			ft_keyrelease(int keycode, t_cub *game)
{
	ft_turn_stop(keycode, game);
	ft_move_stop(keycode, game);
	return (0);
}

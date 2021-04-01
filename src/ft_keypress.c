/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:32:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/01 05:19:23 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_turn_start(int keycode, t_cub *game)
{
	if (keycode == 65361)
		game->player.move.turn_r = 1;
	if (keycode == 65363)
		game->player.move.turn_l = 1;
	return (0);
}

static int	ft_move_start(int keycode, t_world *world, t_player *player, t_mlx *mlx)
{
	int		i;

	i = 0;
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(mlx->win.mlx, mlx->win.win);
		while (i < world->size_y)
		{
			free(world->map[i]);
			i++;
		}
		free(world->map);
		exit(0);
	}
	if (keycode == 119 || keycode == 65362)
		player->move.up = 1;
	if (keycode == 115 || keycode == 65364)
		player->move.down = 1;
	if (keycode == 97)
		player->move.left = 1;
	if (keycode == 100)
		player->move.right = 1;
	return (0);
}

int			ft_keypress(int keycode, t_cub *game)
{
	ft_turn_start(keycode, game);
	ft_move_start(keycode, &game->world, &game->player, &game->mlx);
	return (0);
}

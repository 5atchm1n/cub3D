/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:47:00 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/13 17:05:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_turn(int keycode, t_cub *game)
{
	if (keycode == 65361)
		game->player.move.turn_r = 1;
	if (keycode == 65363)
		game->player.move.turn_l = 1;
		return (0);
}

int		ft_move(int keycode, t_cub *game)
{
	int	i;
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
	if (keycode == 119)
		game->player.move.up = 1;
	if (keycode == 115)
		game->player.move.down = 1;
	if (keycode == 97)
		game->player.move.left = 1;
	if (keycode == 100)
		game->player.move.right = 1;

	return (0);
}

int		ft_turn_stop(int keycode, t_cub *game)
{
	if (keycode == 65361)
		game->player.move.turn_r = 0;
	if (keycode == 65363)
		game->player.move.turn_l = 0;
		return (0);
}

int		ft_move_stop(int keycode, t_cub *game)
{
	int	i;
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

int		ft_keypress(int keycode, t_cub *game)
{
	ft_turn(keycode, game);
	ft_move(keycode, game);
	ft_update_pos(game);

	return (0);
}

int		ft_keyrelease(int keycode, t_cub *game)
{
	ft_turn_stop(keycode, game);
	ft_move_stop(keycode, game);
	ft_update_pos(game);

	return (0);
}

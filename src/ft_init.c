/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/18 10:24:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_init_move(t_move *move)
{
	move->right = 0;
	move->left = 0;
	move->up = 0;
	move->down = 0;
	move->turn_l = 0;
	move->turn_l = 0;
}

static void		ft_init_map(t_cub *game)
{
	int			i;
	int			j;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * game->settings.size_y);
	while (i < game->settings.size_y)
	{
		game->map[i] = (char *)malloc(sizeof(char) * game->settings.size_x);
		i++;
	}
	i = 0;
	while (i < game->settings.size_y)
	{
		j = 0;
		while (j < game->settings.size_x)
		{
			game->map[i][j] = ' ';;
			j++;
		}
		i++;
	}
}

void			ft_init(t_cub *game)
{
	ft_init_map(game);
	ft_init_move(&game->player.move);
	game->settings.offset = (float)game->settings.res.x / (float)game->settings.size_x;
}

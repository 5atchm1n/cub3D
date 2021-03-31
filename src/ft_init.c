/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/31 16:50:38 by sshakya          ###   ########.fr       */
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
			game->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void		ft_player_pos(t_player *player, t_settings *settings,
		char **map)
{
	int			i;
	int			j;

	i = 0;
	while (i < settings->size_y)
	{
		j = 0;
		while (j < settings->size_x)
		{
			if (map[i][j] == 'N')
			{
				player->vector.x = j + 0.5;
				player->vector.y = i + 0.5;
				player->vector.dx = -1;
				player->vector.dy = 0;
				player->camera.px = 0;
				player->camera.py = 0.66;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void			ft_init(t_cub *game, char *map)
{
	ft_init_map(game);
	ft_init_move(&game->player.move);
	game->settings.offset = (float)game->settings.res.x /
		(float)game->settings.size_x;
	game->map = ft_parse_map(map, game);
	game->win.mlx = mlx_init();
	game->win.win = mlx_new_window(game->win.mlx, game->settings.res.x,
			game->settings.res.y, "cub3D");
	game->img.img = mlx_new_image(game->win.mlx, game->settings.res.x,
			game->settings.res.y);
	game->img.add = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.len, &game->img.endian);
	ft_player_pos(&game->player, &game->settings, game->map);
}

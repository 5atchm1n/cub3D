/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/01 05:24:41 by sshakya          ###   ########.fr       */
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

static void		ft_init_map(t_world *world)
{
	int			i;
	int			j;

	i = 0;
	world->map = (char **)malloc(sizeof(char *) * world->size_y);
	while (i < world->size_y)
	{
		world->map[i] = (char *)malloc(sizeof(char) * world->size_x);
		i++;
	}
	i = 0;
	while (i < world->size_y)
	{
		j = 0;
		while (j < world->size_x)
		{
			world->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void		ft_player_pos(t_player *player, t_world *world)
{
	int			i;
	int			j;

	i = 0;
	while (i < world->size_y)
	{
		j = 0;
		while (j < world->size_x)
		{
			if (world->map[i][j] == 'N')
			{
				player->vector.x = j + 0.5;
				player->vector.y = i + 0.5;
				player->vector.dx = -1;
				player->vector.dy = 0;
				player->camera.px = 0;
				player->camera.py = 0.66;
				world->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

static void		ft_init_mlx(t_mlx *mlx)
{
	mlx->win.mlx = mlx_init();
	mlx->win.win = mlx_new_window(mlx->win.mlx, mlx->res.x,
			mlx->res.y, "cub3D");
	mlx->img.img = mlx_new_image(mlx->win.mlx, mlx->res.x,
			mlx->res.y);
	mlx->img.add = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.len, &mlx->img.endian);
}


void			ft_init(t_cub *game, char *map)
{
	ft_init_map(&game->world);
	ft_init_move(&game->player.move);
	ft_init_mlx(&game->mlx);
	
	game->world.offset = (float)game->mlx.res.x /
		(float)game->world.size_x;
	game->world.map = ft_parse_map(map, &game->world);

	ft_player_pos(&game->player, &game->world);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/03 04:50:07 by sshakya          ###   ########.fr       */
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

static void		ft_init_mlx(t_mlx *mlx)
{
	mlx->win.mlx = mlx_init();
	mlx->win.win = mlx_new_window(mlx->win.mlx, mlx->res.x,
			mlx->res.y, "cub3D");
	mlx->img.img = mlx_new_image(mlx->win.mlx, mlx->res.x,
			mlx->res.y);
	mlx->img.add = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.len, &mlx->img.endian);
	mlx->on = 1;
}

static void		ft_init_img_buffer(t_mlx *mlx)
{
	int			i;
	int			j;

	i = 0;
	mlx->buffer = (int **)malloc(sizeof(int *) * mlx->res.y);
	while (i < mlx->res.y)
	{
		mlx->buffer[i] = (int *)malloc(sizeof(int) * mlx->res.x);
		i++;
	}
	i = 0;
	while (i < mlx->res.y)
	{
		j = 0;
		while (j < mlx->res.x)
		{
			mlx->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void		ft_init_textures(t_world *world)
{
	int			i;
	int			j;

	i = 0;
	world->tex = (int **)malloc(sizeof(int *) * TEXTURES);
	while (i < TEXTURES)
	{
		world->tex[i] = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
		i++;
	}
	i = 0;
	while (i < TEXTURES)
	{
		j = 0;
		while (j < TEX_X * TEX_Y)
		{
			world->tex[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			ft_init(t_cub *game, char *map)
{
	ft_init_map(&game->world);
	ft_init_move(&game->player.move);
	ft_init_mlx(&game->mlx);
	ft_init_img_buffer(&game->mlx);
	ft_init_textures(&game->world);
	
	game->world.offset = (float)game->mlx.res.x /
		(float)game->world.size_x;
	game->world.map = ft_parse_map(map, &game->world);

	ft_player_pos(&game->player, &game->world);
	ft_load_textures(&game->mlx, &game->world);
}

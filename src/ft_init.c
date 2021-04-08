/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:39:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void		ft_init_map(t_world *world)
{
	int			i;
	int			j;

	i = 0;
	world->map = (char **)malloc(sizeof(char *) * world->msize.y);
	while (i < world->msize.y)
	{
		world->map[i] = (char *)malloc(sizeof(char) * world->msize.x);
		i++;
	}
	i = 0;
	while (i < world->msize.y)
	{
		j = 0;
		while (j < world->msize.x)
		{
			world->map[i][j] = ' ';
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

void			ft_init(t_cub *game, char *map_path)
{
	ft_init_map(&game->world);
	ft_init_mlx(&game->mlx);
	ft_init_img_buffer(&game->mlx);
	ft_init_textures(&game->world);
	ft_init_object(&game->world);
	ft_init_world(&game->world, game->mlx, map_path);
	ft_init_player(&game->player, &game->world);
	ft_load_objects(&game->world);
	ft_load_textures(&game->mlx, &game->world);
}

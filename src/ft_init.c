/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 05:54:21 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_init_mlx(t_mlx *mlx)
{
	int			screenx;
	int			screeny;

	mlx->win.mlx = mlx_init();
	mlx_get_screen_size(mlx->win.mlx, &screenx, &screeny);
	if (screenx < mlx->res.x)
		mlx->res.x = screenx;
	if (screeny < mlx->res.x)
		mlx->res.y = screeny;
	mlx->win.win = mlx_new_window(mlx->win.mlx, mlx->res.x,
			mlx->res.y, "cub3D");
	mlx->img.img = mlx_new_image(mlx->win.mlx, mlx->res.x,
			mlx->res.y);
	mlx->img.add = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.len, &mlx->img.endian);
	mlx->on = 1;
}

static void		cub_init_img_buffer(t_mlx *mlx)
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

static void		cub_init_map(t_world *world)
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

static void		cub_init_sky_ground(t_world *world)
{
	int			i;

	world->ground = (int *)malloc(sizeof(int) * TEX_X * TEX_Y);
	world->sky = (int *)malloc(sizeof(int) * TEX_X * TEX_Y);
	i = 0;
	while (i < TEX_X * TEX_Y)
	{
		world->ground[i] = 0;
		world->sky[i] = 0;
		i++;
	}
}

static void		cub_init_textures(t_world *world)
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

static void		cub_test_game(t_cub *game, t_error *error)
{
	t_img		img;
	int			i;

		i = 0;
	while (i < TEXTURES)
	{
		img.img = mlx_xpm_file_to_image(game->mlx.win.mlx, game->world.tpath[i],
				&img.x, &img.endian);
		if (img.img == NULL)
			error->id = MLX_ERR2;
		mlx_destroy_image(game->mlx.win.mlx, img.img);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		img.img = mlx_xpm_file_to_image(game->mlx.win.mlx,
				game->world.objpath[i], &img.x, &img.endian);
		if (img.img == NULL)
			error->id = MLX_ERR2;
		mlx_destroy_image(game->mlx.win.mlx, img.img);
		i++;
	}
}

void			cub_init(t_cub *game, char *map_path)
{
	t_error		error;

	cub_init_map(&game->world);
	cub_init_mlx(&game->mlx);
	cub_init_img_buffer(&game->mlx);
	cub_init_textures(&game->world);
	cub_init_sky_ground(&game->world);
	cub_init_object(&game->world);
	cub_init_world(&game->world, game->mlx, map_path);
	cub_init_player(&game->player, &game->world);
	cub_test_game(game, &error);
	if (error.id != 0)
		cub_error(error, game, 1);
	cub_load_objects(&game->world);
	cub_load_textures(&game->mlx, &game->world);
}

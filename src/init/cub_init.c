/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 19:31:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_init_mlx(t_mlx *mlx, t_error *error)
{
	int			screenx;
	int			screeny;

	mlx->win.mlx = mlx_init();
	if (mlx->win.mlx == NULL)
		return (cub_error_set(error, 14));
	mlx_get_screen_size(mlx->win.mlx, &screenx, &screeny);
	if (screenx < mlx->res.x)
		mlx->res.x = screenx;
	if (screeny < mlx->res.y)
		mlx->res.y = screeny;
	if (mlx->res.y <= 0 || mlx->res.x <= 0)
		return (cub_error_set(error, MI_RES));
	mlx->img.img = mlx_new_image(mlx->win.mlx, mlx->res.x,
			mlx->res.y);
	mlx->img.add = (int *)mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.len, &mlx->img.endian);
}

static void		cub_init_img_buffer(t_mlx *mlx, t_error *error)
{
	int			i;
	int			j;

	i = 0;
	mlx->buffer = (int **)malloc(sizeof(int *) * mlx->res.y);
	if (mlx->buffer == NULL)
		return (cub_error_set(error, MEM_FAIL));
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

static void		cub_init_map(t_world *world, t_error *error)
{
	int			i;
	int			j;

	i = 0;
	world->map = (char **)malloc(sizeof(char *) * world->info.msize.y);
	if (world->map == NULL)
		return (cub_error_set(error, MEM_FAIL));
	while (i < world->info.msize.y)
	{
		world->map[i] = (char *)malloc(sizeof(char) * world->info.msize.x);
		if (world->map[i] == NULL)
			return (cub_error_set(error, MEM_FAIL));
		i++;
	}
	i = 0;
	while (i < world->info.msize.y)
	{
		j = 0;
		while (j < world->info.msize.x)
		{
			world->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void		cub_init_textures(t_world *world, t_error *error)
{
	int			i;
	int			j;

	i = 0;
	world->objs.tex = (int **)malloc(sizeof(int *) * TEXTURES);
	if (world->objs.tex == NULL)
		return (cub_error_set(error, MEM_FAIL));
	while (i < TEXTURES)
	{
		world->objs.tex[i] = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
		if (world->objs.tex[i] == NULL)
			return (cub_error_set(error, MEM_FAIL));
		i++;
	}
	i = 0;
	while (i < TEXTURES)
	{
		j = 0;
		while (j < TEX_X * TEX_Y)
		{
			world->objs.tex[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			cub_init(t_cub *game, char *map_path)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(error));
	cub_init_mlx(&game->mlx, &error);
	if (error.id != 0)
		cub_error(error, game);
	cub_init_map(&game->world, &error);
	cub_init_img_buffer(&game->mlx, &error);
	cub_init_textures(&game->world, &error);
	cub_init_object(&game->world, &error);
	if (BONUS)
		cub_init_bonus(&game->world, &game->mlx, &error);
	if (error.id != 0)
		cub_error(error, game);
	cub_init_world(&game->world, game->mlx, map_path, &error);
	if (error.id != 0)
		cub_error(error, game);
	cub_init_player(&game->player, &game->world, &error);
	cub_test_xpm(game, &error);
	if (error.id != 0)
		cub_error(error, game);
	cub_load_objects(&game->world);
	cub_load_textures(&game->mlx, &game->world);
}

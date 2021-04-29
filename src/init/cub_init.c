/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:06:12 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/29 14:22:34 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	world->map = (char **)malloc(sizeof(char *) * world->msize.y);
	if (world->map == NULL)
		return (cub_error_set(error, MEM_FAIL));
	while (i < world->msize.y)
	{
		world->map[i] = (char *)malloc(sizeof(char) * world->msize.x);
		if (world->map[i] == NULL)
			return (cub_error_set(error, MEM_FAIL));
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

static void		cub_init_sky_ground(t_world *world, t_error *error)
{
	int			i;

	world->ground = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
	if (world->ground == NULL)
		return (cub_error_set(error, MEM_FAIL));
	world->sky = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
	if (world->sky == NULL)
		return (cub_error_set(error, MEM_FAIL));
	world->skybox = (int *)malloc(sizeof(int) * (SKY_X * SKY_Y));
	if (world->skybox == NULL)
		return (cub_error_set(error, MEM_FAIL));
	i = 0;
	while (i < TEX_X * TEX_Y)
	{
		world->ground[i] = 0;
		world->sky[i] = 0;
		i++;
	}
	i = 0;
	while (i++ < SKY_X * SKY_Y)
		world->skybox[i] = 0;
}

static void		cub_init_textures(t_world *world, t_error *error)
{
	int			i;
	int			j;

	i = 0;
	world->tex = (int **)malloc(sizeof(int *) * TEXTURES);
	if (world->tex == NULL)
		return (cub_error_set(error, MEM_FAIL));
	while (i < TEXTURES)
	{
		world->tex[i] = (int *)malloc(sizeof(int) * (TEX_X * TEX_Y));
		if (world->tex[i] == NULL)
			return (cub_error_set(error, MEM_FAIL));
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

void			cub_init(t_cub *game, char *map_path)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(error));
	cub_init_mlx(&game->mlx, &error);
	if (error.id != 0)
		cub_error(error, game, 0);
	cub_init_map(&game->world, &error);
	cub_init_img_buffer(&game->mlx, &error);
	cub_init_textures(&game->world, &error);
	cub_init_sky_ground(&game->world, &error);
	cub_init_object(&game->world, &error);
	if (error.id != 0)
		cub_error(error, game, 2);
	cub_init_world(&game->world, game->mlx, map_path, &error);
	if (error.id != 0)
		cub_error(error, game, 2);
	cub_init_player(&game->player, &game->world, &error);
	cub_test_xpm(game, &error);
	if (error.id != 0)
		cub_error(error, game, 2);
	cub_load_objects(&game->world);
	cub_load_textures(&game->mlx, &game->world);
}
